.globl main
.data
	
.text
	main:
		li a1, 3
		li a0, 4
		
		bge, zero, a0 endZero
		addi sp, sp, -20
		sw ra, 0(sp)
		sw s0, 4 (sp)
		sw s1, 8(sp)
		sw s2, 12(sp)
		
		
		mv s0, a0
		li s1, 0
		li s2, 0
	loop:	sub t0, zero, s2
		mv a0, s0
		add a0, a0, t0
		bge zero, a0, exit
		sw t0, 16(sp)
		jal ra, pow
		add s1, s1, a0
		lw t0, 16(sp)
		addi s2, s2, 1
		j loop
	exit:
		mv a0, s1
		lw ra, 0(sp)
		lw s0, 4 (sp)
		lw s1, 8(sp)
		lw s2, 12(sp)
		addi sp, sp, 20
		
		jalr zero, 0(ra)
	
	endZero: mv a0, zero
		jalr zero, 0(ra)		
		
	pow:	mv t0, a0
		mv t1, a1
		li t2, 1
		beq t0, t2, endOne
		beq t0, zero, endOne
	loop1: 	bge t2, t1, end
		mul a0, a0, t0
		addi t2,t2,1
		j loop1

	end:
		jalr zero, 0(ra)
	endOne:
		li a0, 1
		jalr zero, 0(ra)
	
	