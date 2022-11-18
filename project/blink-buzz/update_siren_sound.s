	.arch msp430g2553
	p2align 1,0
	.data
highOn:	.byte 0
	.text
updateSirenSound:
	cmp #0, &highOn
	jz sirenElse
	mov #0, &highOn
	mov #750, r12
	call buzzer_set_period
	jmp sirenEnd
sirenElse:
	mov #1, &highOn
	mov #250, r12
	call buzzer_set_period
	jmp sirenEnd
sirenEnd:
	pop r0
