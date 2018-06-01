# Praktikum 5 (10 Punkte) - Assembler

## Aufgabe 1

#### -O0

Reduce compilation time and make debugging produce the expected results. This is the default.

#### -O2

Optimize even more. GCC performs nearly all supported optimizations that do not involve a space-speed tradeoff. As com

pared to -O, this option increases both compilation time and the performance of the generated code.

-O2 turns on all optimization flags specified by -O. It also turns on the following optimization flags:

#### -Os

Optimize for size. -Os enables all -O2 optimizations that do not typically increase code size. It also performs further optimizations designed to reduce code size.

-Os disables the following optimization flags:

-falign-functions  -falign-jumps  -falign-loops 
-falign-labels  -freorder-blocks  -freorder-blocks-algorithm=stc 
-freorder-blocks-and-partition  -fprefetch-loop-arrays

### Code

```assembly
2ae:	4b0d      	ldr	r3, [pc, #52]	; (2e4 <main+0x48>)
2b0:	2208      	movs	r2, #8
2b2:	601a      	str	r2, [r3, #0]
2b4:	4b0c      	ldr	r3, [pc, #48]	; (2e8 <main+0x4c>)
2b6:	2208      	movs	r2, #8
2b8:	601a      	str	r2, [r3, #0]
2ba:	4a0c      	ldr	r2, [pc, #48]	; (2ec <main+0x50>)
2bc:	4b0b      	ldr	r3, [pc, #44]	; (2ec <main+0x50>)
2be:	681b      	ldr	r3, [r3, #0]
2c0:	f043 0308 	orr.w	r3, r3, #8
2c4:	6013      	str	r3, [r2, #0]
2c6:	f7ff ffd1 	bl	26c <delay>
2ca:	4a08      	ldr	r2, [pc, #32]	; (2ec <main+0x50>)
2cc:	4b07      	ldr	r3, [pc, #28]	; (2ec <main+0x50>)
2ce:	681b      	ldr	r3, [r3, #0]
2d0:	f023 0308 	bic.w	r3, r3, #8
2d4:	6013      	str	r3, [r2, #0]
2d6:	f7ff ffc9 	bl	26c <delay>
2da:	e7ee      	b.n	2ba <main+0x1e>
```



Die erste Spalte ist die Befehlsadresse im Code.

Die zweite Spalte ist der Befehl in Maschinensprache, hier in Hexadezimal, dabei gibt es zwei verschiedene Längen.

Die dritte Spalte zeigt den Befehl

Die vierte Spalte zeigt die Register

Die fünfte Spalte beinhaltet die benutzten Operatoren

Alles nach einem Semikolon ist ein Kommentar