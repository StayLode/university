.data
	vett1: .word 1, 2, 3, 4
	vett2: .word 2, 2, 2, 2
	n:.word 4

.text
	
	li s0, 0
	li s1, 0
	li s2, 0
	li s3, 0

	la a0, vett1
	la a1, vett2
	la a2, n
	lw a2, 0(a2)
	
	loop: 
	bge s0, a2, exit
	slli s1, s0, 2			#offset
	add s2, a1, s1
	add s1, a0, s1
	
	lw s1, 0(s1)			
	lw s2, 0(s2)
	mul s1, s1, s2
	add s3, s1, s3
	addi s0, s0, 1
	j loop
	
	exit:
	
	
	
