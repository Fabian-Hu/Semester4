 

 ;GPIO_PORTF_DIR_R = 0x08;
 2ae:	4b0d      	ldr	r3, [pc, #52]	; (2e4 <main+0x48>)		;//berechnet eine Adresse aus dem PC-Wert und einem 
																;//Offset(52 (ein vielfaches von 4) und lädt dann ein Wort 
																;//aus dem Speicher und schreibt es in das Register r3
 2b0:	2208      	movs	r2, #8								;//Schreibt den Wert 8 in das Register r2
 2b2:	601a      	str	r2, [r3, #0]							;//Nimmt die Adresse aus register r3 und Schreibt den Wert, 
																;//der in dem Register r2 steht in den Speicher
											
 
 ;GPIO_PORTF_DEN_R = 0x08;
 2b4:	4b0c      	ldr	r3, [pc, #48]	; (2e8 <main+0x4c>)
 2b6:	2208      	movs	r2, #8
 2b8:	601a      	str	r2, [r3, #0]
 
 ;while(1)
	;GPIO_PORTF_DATA_R |= 0x08;
	 2ba:	4a0c      	ldr	r2, [pc, #48]	; (2ec <main+0x50>)
	 2bc:	4b0b      	ldr	r3, [pc, #44]	; (2ec <main+0x50>)
	 2be:	681b      	ldr	r3, [r3, #0]
	 2c0:	f043 0308 	orr.w	r3, r3, #8
	 2c4:	6013      	str	r3, [r2, #0]
	 
	 ;delay
	 2c6:	f7ff ffd1 	bl	26c <delay>
	 
	 
     ;GPIO_PORTF_DATA_R &= ~(0x08);
	 2ca:	4a08      	ldr	r2, [pc, #32]	; (2ec <main+0x50>)
	 2cc:	4b07      	ldr	r3, [pc, #28]	; (2ec <main+0x50>)
	 2ce:	681b      	ldr	r3, [r3, #0]
	 2d0:	f023 0308 	bic.w	r3, r3, #8
	 2d4:	6013      	str	r3, [r2, #0]
	 
	 ;delay
	 2d6:	f7ff ffc9 	bl	26c <delay>
	 
 2da:	e7ee      	b.n	2ba <main+0x1e>