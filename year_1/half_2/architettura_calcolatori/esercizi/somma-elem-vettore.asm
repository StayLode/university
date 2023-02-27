.globl main
.data
	arr: .word 10, 3, 4, 2, 1
	n: .word 5
.text
	main:
		addi sp, sp, -16
		sw s0, 0(sp)
		sw s1, 4(sp)
		sw s2, 8(sp)
		sw s3, 12(sp)
		
		li s0, 0
		la s1, n
		la s2, arr
		li s3, 0
		lw s1, 0(s1)
	loop: 
		bge s0, s1, end
		slli s3, s0, 2
		add s3, s2, s3
		lw t0, 0(s3)
		add t1, t1, t0
		addi s0, s0, 1
		bge zero, zero, loop

	end:
		mv a0, t1
		
		lw s0, 0(sp)
		lw s1, 4(sp)
		lw s2, 8(sp)
		lw s3, 12(sp)
		addi sp, sp, 16
		
		

