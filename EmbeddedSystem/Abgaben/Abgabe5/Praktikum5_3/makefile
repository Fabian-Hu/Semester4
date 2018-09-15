
eins:
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -I/home/tim_meier/.energia15/packages/energia/hardware/tivac/1.0.3/system -std=gnu11 -c -o blink.o blink.c

zwei:
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -I/home/tim_meier/.energia15/packages/energia/hardware/tivac/1.0.3/system -std=gnu11 -c -o startup_gcc.o startup_gcc.c

drei:
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -T blink.ld -Xlinker --gc-sections -o blink.elf blink.o startup_gcc.o

vier:
	arm-none-eabi-size blink.elf

funf:
	arm-none-eabi-objdump -h -S blink.elf > blink3.asm

sechs:
	DSLite load -c EK-TM4C123GXL.ccxml blink.elf
