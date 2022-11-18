	.arch msp4302553
	.p2align 1,0
	.data
highOn:
	.byte 0
	.text
buzzer_update_sound:
	cmp #0, &highOn
	jz buzzer_else
	mov #0, &highOn
	mov #750, r12
	call buzzer_set_period
	ret
buzzer_else:
	mov #1, &highOn
	mov #250, r12
	call buzzer_set_period
	ret
