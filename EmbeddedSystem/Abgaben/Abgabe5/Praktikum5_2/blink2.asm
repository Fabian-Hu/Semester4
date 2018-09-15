
blink.elf:     file format elf32-littlearm

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         00000344  00000000  00000000  00010000  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 .init         00000004  00000344  00000344  00010344  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  2 .fini         00000004  00000348  00000348  00010348  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  3 .bss          00000104  20000000  20000000  00020000  2**2
                  ALLOC
  4 .ARM.attributes 0000002a  00000000  00000000  0001034c  2**0
                  CONTENTS, READONLY
  5 .comment      0000007f  00000000  00000000  00010376  2**0
                  CONTENTS, READONLY

Disassembly of section .text:

00000000 <_text>:
   0:	20000100 	.word	0x20000100
   4:	000002e9 	.word	0x000002e9
   8:	000002dd 	.word	0x000002dd
   c:	000002e1 	.word	0x000002e1
  10:	000002e5 	.word	0x000002e5
  14:	000002e5 	.word	0x000002e5
  18:	000002e5 	.word	0x000002e5
	...
  2c:	000002e5 	.word	0x000002e5
  30:	000002e5 	.word	0x000002e5
  34:	00000000 	.word	0x00000000
  38:	000002e5 	.word	0x000002e5
  3c:	000002e5 	.word	0x000002e5
  40:	000002e5 	.word	0x000002e5
  44:	000002e5 	.word	0x000002e5
  48:	000002e5 	.word	0x000002e5
  4c:	000002e5 	.word	0x000002e5
  50:	000002e5 	.word	0x000002e5
  54:	000002e5 	.word	0x000002e5
  58:	000002e5 	.word	0x000002e5
  5c:	000002e5 	.word	0x000002e5
  60:	000002e5 	.word	0x000002e5
  64:	000002e5 	.word	0x000002e5
  68:	000002e5 	.word	0x000002e5
  6c:	000002e5 	.word	0x000002e5
  70:	000002e5 	.word	0x000002e5
  74:	000002e5 	.word	0x000002e5
  78:	000002e5 	.word	0x000002e5
  7c:	000002e5 	.word	0x000002e5
  80:	000002e5 	.word	0x000002e5
  84:	000002e5 	.word	0x000002e5
  88:	000002e5 	.word	0x000002e5
  8c:	000002e5 	.word	0x000002e5
  90:	000002e5 	.word	0x000002e5
  94:	000002e5 	.word	0x000002e5
  98:	000002e5 	.word	0x000002e5
  9c:	000002e5 	.word	0x000002e5
  a0:	000002e5 	.word	0x000002e5
  a4:	000002e5 	.word	0x000002e5
  a8:	000002e5 	.word	0x000002e5
  ac:	000002e5 	.word	0x000002e5
  b0:	000002e5 	.word	0x000002e5
  b4:	000002e5 	.word	0x000002e5
  b8:	000002e5 	.word	0x000002e5
  bc:	000002e5 	.word	0x000002e5
  c0:	000002e5 	.word	0x000002e5
  c4:	000002e5 	.word	0x000002e5
  c8:	000002e5 	.word	0x000002e5
  cc:	000002e5 	.word	0x000002e5
  d0:	000002e5 	.word	0x000002e5
  d4:	000002e5 	.word	0x000002e5
  d8:	000002e5 	.word	0x000002e5
  dc:	000002e5 	.word	0x000002e5
  e0:	000002e5 	.word	0x000002e5
  e4:	000002e5 	.word	0x000002e5
  e8:	00000000 	.word	0x00000000
  ec:	000002e5 	.word	0x000002e5
  f0:	000002e5 	.word	0x000002e5
  f4:	000002e5 	.word	0x000002e5
  f8:	000002e5 	.word	0x000002e5
  fc:	000002e5 	.word	0x000002e5
 100:	000002e5 	.word	0x000002e5
 104:	000002e5 	.word	0x000002e5
 108:	000002e5 	.word	0x000002e5
 10c:	000002e5 	.word	0x000002e5
	...
 118:	000002e5 	.word	0x000002e5
 11c:	000002e5 	.word	0x000002e5
 120:	000002e5 	.word	0x000002e5
 124:	000002e5 	.word	0x000002e5
 128:	000002e5 	.word	0x000002e5
 12c:	000002e5 	.word	0x000002e5
 130:	000002e5 	.word	0x000002e5
 134:	000002e5 	.word	0x000002e5
 138:	000002e5 	.word	0x000002e5
 13c:	000002e5 	.word	0x000002e5
	...
 150:	000002e5 	.word	0x000002e5
 154:	000002e5 	.word	0x000002e5
 158:	000002e5 	.word	0x000002e5
 15c:	000002e5 	.word	0x000002e5
	...
 1b0:	000002e5 	.word	0x000002e5
 1b4:	000002e5 	.word	0x000002e5
 1b8:	000002e5 	.word	0x000002e5
 1bc:	000002e5 	.word	0x000002e5
 1c0:	000002e5 	.word	0x000002e5
 1c4:	000002e5 	.word	0x000002e5
 1c8:	000002e5 	.word	0x000002e5
 1cc:	000002e5 	.word	0x000002e5
 1d0:	000002e5 	.word	0x000002e5
 1d4:	000002e5 	.word	0x000002e5
 1d8:	000002e5 	.word	0x000002e5
 1dc:	000002e5 	.word	0x000002e5
 1e0:	000002e5 	.word	0x000002e5
 1e4:	000002e5 	.word	0x000002e5
 1e8:	000002e5 	.word	0x000002e5
	...
 1f4:	000002e5 	.word	0x000002e5
 1f8:	000002e5 	.word	0x000002e5
 1fc:	000002e5 	.word	0x000002e5
 200:	000002e5 	.word	0x000002e5
 204:	000002e5 	.word	0x000002e5
	...
 210:	000002e5 	.word	0x000002e5
 214:	000002e5 	.word	0x000002e5
 218:	000002e5 	.word	0x000002e5
 21c:	000002e5 	.word	0x000002e5
 220:	000002e5 	.word	0x000002e5
 224:	000002e5 	.word	0x000002e5
 228:	000002e5 	.word	0x000002e5
 22c:	000002e5 	.word	0x000002e5
 230:	000002e5 	.word	0x000002e5
 234:	000002e5 	.word	0x000002e5
 238:	000002e5 	.word	0x000002e5
 23c:	000002e5 	.word	0x000002e5
 240:	000002e5 	.word	0x000002e5
 244:	000002e5 	.word	0x000002e5
 248:	000002e5 	.word	0x000002e5
 24c:	000002e5 	.word	0x000002e5
 250:	000002e5 	.word	0x000002e5
 254:	000002e5 	.word	0x000002e5
 258:	000002e5 	.word	0x000002e5
 25c:	000002e5 	.word	0x000002e5
 260:	000002e5 	.word	0x000002e5
 264:	000002e5 	.word	0x000002e5
 268:	000002e5 	.word	0x000002e5

0000026c <main>:
 26c:	4a15      	ldr	r2, [pc, #84]	; (2c4 <main+0x58>)
 26e:	4b16      	ldr	r3, [pc, #88]	; (2c8 <main+0x5c>)
 270:	4c16      	ldr	r4, [pc, #88]	; (2cc <main+0x60>)
 272:	4d17      	ldr	r5, [pc, #92]	; (2d0 <main+0x64>)
 274:	4817      	ldr	r0, [pc, #92]	; (2d4 <main+0x68>)
 276:	4918      	ldr	r1, [pc, #96]	; (2d8 <main+0x6c>)
 278:	2620      	movs	r6, #32
 27a:	6016      	str	r6, [r2, #0]
 27c:	6812      	ldr	r2, [r2, #0]
 27e:	601a      	str	r2, [r3, #0]
 280:	2208      	movs	r2, #8
 282:	6022      	str	r2, [r4, #0]
 284:	2400      	movs	r4, #0
 286:	602a      	str	r2, [r5, #0]
 288:	6802      	ldr	r2, [r0, #0]
 28a:	f042 0208 	orr.w	r2, r2, #8
 28e:	6002      	str	r2, [r0, #0]
 290:	601c      	str	r4, [r3, #0]
 292:	681a      	ldr	r2, [r3, #0]
 294:	428a      	cmp	r2, r1
 296:	d805      	bhi.n	2a4 <main+0x38>
 298:	681a      	ldr	r2, [r3, #0]
 29a:	3201      	adds	r2, #1
 29c:	601a      	str	r2, [r3, #0]
 29e:	681a      	ldr	r2, [r3, #0]
 2a0:	428a      	cmp	r2, r1
 2a2:	d9f9      	bls.n	298 <main+0x2c>
 2a4:	6802      	ldr	r2, [r0, #0]
 2a6:	f022 0208 	bic.w	r2, r2, #8
 2aa:	6002      	str	r2, [r0, #0]
 2ac:	601c      	str	r4, [r3, #0]
 2ae:	681a      	ldr	r2, [r3, #0]
 2b0:	428a      	cmp	r2, r1
 2b2:	d8e9      	bhi.n	288 <main+0x1c>
 2b4:	681a      	ldr	r2, [r3, #0]
 2b6:	3201      	adds	r2, #1
 2b8:	601a      	str	r2, [r3, #0]
 2ba:	681a      	ldr	r2, [r3, #0]
 2bc:	428a      	cmp	r2, r1
 2be:	d9f9      	bls.n	2b4 <main+0x48>
 2c0:	e7e2      	b.n	288 <main+0x1c>
 2c2:	bf00      	nop
 2c4:	400fe108 	.word	0x400fe108
 2c8:	20000100 	.word	0x20000100
 2cc:	40025400 	.word	0x40025400
 2d0:	4002551c 	.word	0x4002551c
 2d4:	400253fc 	.word	0x400253fc
 2d8:	00030d3f 	.word	0x00030d3f

000002dc <NmiSR>:
 2dc:	e7fe      	b.n	2dc <NmiSR>
 2de:	bf00      	nop

000002e0 <FaultISR>:
 2e0:	e7fe      	b.n	2e0 <FaultISR>
 2e2:	bf00      	nop

000002e4 <IntDefaultHandler>:
 2e4:	e7fe      	b.n	2e4 <IntDefaultHandler>
 2e6:	bf00      	nop

000002e8 <ResetISR>:
 2e8:	4b10      	ldr	r3, [pc, #64]	; (32c <zero_loop+0x1a>)
 2ea:	4a11      	ldr	r2, [pc, #68]	; (330 <zero_loop+0x1e>)
 2ec:	4293      	cmp	r3, r2
 2ee:	d20c      	bcs.n	30a <ResetISR+0x22>
 2f0:	43d8      	mvns	r0, r3
 2f2:	4410      	add	r0, r2
 2f4:	f020 0003 	bic.w	r0, r0, #3
 2f8:	3004      	adds	r0, #4
 2fa:	4a0e      	ldr	r2, [pc, #56]	; (334 <zero_loop+0x22>)
 2fc:	4418      	add	r0, r3
 2fe:	f852 1b04 	ldr.w	r1, [r2], #4
 302:	f843 1b04 	str.w	r1, [r3], #4
 306:	4283      	cmp	r3, r0
 308:	d1f9      	bne.n	2fe <ResetISR+0x16>
 30a:	480c      	ldr	r0, [pc, #48]	; (33c <zero_loop+0x2a>)
 30c:	490c      	ldr	r1, [pc, #48]	; (340 <zero_loop+0x2e>)
 30e:	f04f 0200 	mov.w	r2, #0

00000312 <zero_loop>:
 312:	4288      	cmp	r0, r1
 314:	bfb8      	it	lt
 316:	f840 2b04 	strlt.w	r2, [r0], #4
 31a:	dbfa      	blt.n	312 <zero_loop>
 31c:	4a06      	ldr	r2, [pc, #24]	; (338 <zero_loop+0x26>)
 31e:	6813      	ldr	r3, [r2, #0]
 320:	f443 0370 	orr.w	r3, r3, #15728640	; 0xf00000
 324:	6013      	str	r3, [r2, #0]
 326:	f7ff bfa1 	b.w	26c <main>
 32a:	bf00      	nop
 32c:	20000000 	.word	0x20000000
 330:	20000000 	.word	0x20000000
 334:	00000344 	.word	0x00000344
 338:	e000ed88 	.word	0xe000ed88
 33c:	20000000 	.word	0x20000000
 340:	20000104 	.word	0x20000104

Disassembly of section .init:

00000344 <_init>:
 344:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 346:	bf00      	nop

Disassembly of section .fini:

00000348 <_fini>:
 348:	b5f8      	push	{r3, r4, r5, r6, r7, lr}
 34a:	bf00      	nop
