#include <Energia.h>

#if defined(PART_TM4C129XNCZAD)
#include "inc/tm4c129xnczad.h"
#elif defined(PART_TM4C1294NCPDT)
#include "inc/tm4c1294ncpdt.h"
#elif defined(PART_TM4C1233H6PM) || defined(PART_LM4F120H5QR)
#include "inc/tm4c123gh6pm.h"
#else
#error "**** No PART defined or unsupported PART ****"
#endif

#include "inc/hw_gpio.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/eeprom.h"

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

#ifdef __cplusplus
extern "C" {

void _init(void) {
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);
	if (ROM_EEPROMInit() == EEPROM_INIT_ERROR) {
		if (ROM_EEPROMInit() != EEPROM_INIT_ERROR)
			EEPROMMassErase();
	}

	timerInit();

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOQ);
#ifdef TARGET_IS_SNOWFLAKE_RA0
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOR);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOS);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOT);
#endif

	//Unlock and commit NMI pins PD7 and PF0
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0x4C4F434B;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x1;
	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0x4C4F434B;
	HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;

	// Deep Sleep mode init
	// DSLP clock = PIOSC / 16 = 1MHz
	// Note: Couldn't find the define constants for SysCtlDeepSleepPowerSet in the driverlib.
	//
#ifdef TARGET_IS_BLIZZARD_RB1
	ROM_SysCtlDeepSleepClockSet(SYSCTL_DSLP_DIV_16 | SYSCTL_DSLP_OSC_INT);
	SysCtlDeepSleepPowerSet(0x21); // FLASHPM = LOW_POWER_MODE, SRAMPM = STANDBY_MODE
	SysCtlLDODeepSleepSet(SYSCTL_LDO_1_00V); // Going lower tends to be very flaky and cause continual resets
	// particularly when measuring MCU current.
#endif
	//
#ifdef TARGET_IS_SNOWFLAKE_RA0
	ROM_SysCtlDeepSleepClockConfigSet(16, SYSCTL_DSLP_OSC_INT);
	SysCtlDeepSleepPowerSet(0x121); // TSPD, FLASHPM = LOW_POWER_MODE, SRAMPM = STANDBY_MODE
#endif
	//
} /* void _init(void) */

} /* extern "C" */
#endif

const uint8_t tempPin = PD_0;
const uint8_t brightnessPin = PD_1;
const uint8_t heatingPin = PC_4;

const TickType_t heatingWaitTime = 1000 / portTICK_PERIOD_MS;
const TickType_t brightnessWaitTime = 2000 / portTICK_PERIOD_MS;

const uint16_t lowTemp = 300;
const uint16_t highTemp = 600;
const uint16_t changeBrightness = 200;

enum HeatingState { COOLING, HEATING };
enum BrightnessState { DARK, BRIGHT };

bool light = false;

HeatingState stateH = COOLING;
BrightnessState stateB = DARK;

void setupBrightnessControl() {
	Serial.begin(9600);
	pinMode(brightnessPin, INPUT);
}

void loopBrightnessControl() {
	switch(stateB) {
	case DARK:
	  if(analogRead(brightnessPin) >= changeBrightness) {
		  light = true;
		  stateB = BRIGHT;
	  }
	  break;
	case BRIGHT:
	  if(analogRead(brightnessPin) < changeBrightness) {
		  light = false;
		  stateB = DARK;
	  }
	  break;
	}
	Serial.print("BrightnessPin: ");
	Serial.println(analogRead(brightnessPin));
}

void setupHeatingControl() {
	Serial.begin(9600);
	pinMode(tempPin, INPUT);
	pinMode(heatingPin, OUTPUT);
}

void loopHeatingControl() {
	switch(stateH) {
	case COOLING:
	  if(analogRead(tempPin) < lowTemp && !light) {
		  digitalWrite(heatingPin, HIGH);
		  stateH = HEATING;
	  }
	  break;
	case HEATING:
	  if(analogRead(tempPin) > highTemp || light) {
		  digitalWrite(heatingPin, LOW);
		  stateH = COOLING;
	  }
	  break;
	}
	Serial.print("HeatingPin: ");
	Serial.println(analogRead(tempPin));
}

void taskBrightnessControl(void *pvParameters) {
	for (;;) {
		loopBrightnessControl();
		if (serialEventRun)
			serialEventRun();
		vTaskDelay(brightnessWaitTime);
	}
}

void taskHeatingControl(void *pvParameters) {
	for (;;) {
		loopHeatingControl();
		if (serialEventRun)
			serialEventRun();
		vTaskDelay(heatingWaitTime);
	}
}


int main(void) {
	setupBrightnessControl();
	setupHeatingControl();

	xTaskCreate(taskHeatingControl, "Heating Control", configMINIMAL_STACK_SIZE + 100, NULL, tskIDLE_PRIORITY + 1UL, NULL);
	xTaskCreate(taskBrightnessControl, "Brightness Control", configMINIMAL_STACK_SIZE + 100, NULL, tskIDLE_PRIORITY + 2UL, NULL);
	vTaskStartScheduler();
}
