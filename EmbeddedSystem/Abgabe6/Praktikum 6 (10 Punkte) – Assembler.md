# Praktikum 6 (10 Punkte) – Assembler

Von Tim Steven Meier und Fabian Husemann

## Aufgabe 1

| Befehl | Taktzyklus |
| ------ | ---------- |
| mov    | 1          |
| cmp    | 1          |
| ite    | 1          |
| moveq  | 1          |
| addne  | 1          |

Der Assemblerteil benötigt 5 Taktzyklen für jedes durchlaufen des loop().

## Aufgabe 2

| Befehl | Taktzyklus |
| ------ | ---------- |
| mov    | 1          |
| ldr    | 2          |
| add    | 1          |
| str    | 2          |
| cmp    | 1          |
| it     | 1          |
| bne    | 1 + P      |



Der Assemblerteil benötigt 11 * (14 + P) +1 Taktzyklen.



Der "memory" - Tag bewirkt, dass die Register die alten Werte am Ende wieder laden.