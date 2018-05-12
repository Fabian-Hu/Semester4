# Praktikum 2 - Elektronik

André Kirsch, Malte Riechmann

##Aufgabe 1

#### Teil a

**Strom**: ([I]=A) Der elektrische Strom gibt an wie viel elektrische Ladung in einer Sekunde durch einen Leiter fließt.

**Spannung**: ([U]=V) Die Spannung entspricht dem Ladungsunterschied (Potential) zwischen zwei Polen und ist Ursache für den elektrischen Strom.
![1a](1a.png)

#### Teil b

$$
R = \frac{U}{I}
$$
$$
R = \frac{12V}{500 * 10^{-6} A} = 24k\Omega
$$

*Der Widerstand des Verbrauchers beträgt $$ 24k \Omega $$*

#### Teil c

$$
P = U * I, U = R * I
$$
$$
P = R * I * I
$$
$$
I^2 = \frac{P}{R}
$$
$$
I = \sqrt{ \frac{P}{R} }
$$
$$
I = \sqrt { \frac{0.33W}{1 * 10^{6}\Omega}} = 574 \mu A
$$

*Die maximale Stromstärke beträgt $$ 547 \mu A $$*

## Aufgabe  2

#### Teil a

$$
I = \frac{P}{U}
$$
$$
I = \frac{60W}{12V} = 5A
$$

*Die maximale Stromstärke beträgt $$ 5A $$*

#### Teil b

Die Lampe kann nicht direkt an die Spannungsquelle angeschlossen werden, da die Batterie 18V Nennspannung hat, die Lampe allerdings nur 12V Betriebsspannung hat. Deswegen wird ein Vorwiderstand benötigt.

$$
R = \frac {U}{I}
$$
$$
\Delta U = U_{Ges} - U_L
$$
$$
I = \frac {P_L}{U_L}
$$
$$
R = \frac {\Delta U}{\frac {P_L}{U_L}}
$$
$$
R = \frac {6V}{\frac {60W}{12V}} = \frac {6}{5} \Omega
$$

*Der Vorwiderstand beträgt  $$ \frac {6}{5} \Omega $$*

#### Teil c

$$
t = \frac {Q}{I}
$$
$$
I = \frac {P}{U} = 5V
$$
$$
t = \frac {90Ah}{5A} = 18h
$$

*Die Schaltung kann $$ 18h $$ betrieben werden, bis die Batterie erschöpft ist*

## Aufgabe 3

Bauelemente:
* Widerstand (R1/R2)
* LED (D1)
* Schalter (S1)
* Transistor (Q1)
* Wenn der Schalter S1 geschlossen ist liegt Strom an dem Base-Anschluss des Transistors an fließt Strom vom Collector zum Emitter. Das Bedeutet, das der Stromkreis der LED geschlossen und sie beginnt zu leuchten. Die Widerstände verhindern einen Kurzschluss, in dem sie den Stromfluss vermindern.

#### Teil a

Angaben aus dem Datenblatt:
* Spannung:  2V (möglich von 1,6V-2,5V)
* Stromstärke: 20mA (möglich von 0mA bis 50mA)

#### Teil b

Pinbelegung:
1. Collector
2. Base
3. Emitter

(Von links nach rechts, wenn der Transistor mit der flachen Seite nach oben und den Pins zu einem zeigend liegt)

#### Teil c

$$
U_{dif} = 3.3V - 0.64V -2V = 0.66V
$$
$$
R = \frac{U_{dif}}{I}
$$
$$
R = \frac{0.66A}{20 * 10^{-3}A} = 33 \Omega
$$

*Der Vorwiderstand R1 sollte $$ 33 \Omega $$ betragen.*
