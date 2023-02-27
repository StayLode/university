.globl main

.text
	main:
		addi sp,sp,-16
		sw ra, 0(sp)
		sw s0, 4(sp)
		sw s1, 8(sp)
		sw s2, 12(sp)
		
		li a0, -55
		
		beq a0, zero, endZero
		blt a0, zero, endNeg
		
		li s0, 0
		li s1, 1
		li s2, 0
		mv s0, a0
	
	loop:	blt s0,s1, exit
		mv a0, s1
		jal ra, elev
		add s2, a0, s2
		addi s1, s1, 1
		j loop
		
	exit: 	mv a0, s2
		
		lw ra, 0(sp)
		lw s0, 4(sp)
		lw s1, 8(sp)
		lw s2, 12(sp)
		addi sp,sp, 16
		jalr zero, 0(ra)
		
	endNeg:	li a0,-1
		jalr zero,0(ra)
		
	endZero: li a0, 0
		jalr zero, 0(ra)
		
	elev:	li t0,1
		mv t1, a0
		mv t2, a0
	loop1:	mul t1, a0, t1
		addi t0,t0,1
		blt t0, a0, loop1
		mv a0, t1
		jalr zero, 0(ra)