.globl main

.data
	str: .string "Ciao"
	reverse: .string ""

.text
	main:
		la a0, str
		la a1, reverse
		
	revert:	
		addi sp, sp, -20
		sw ra, 0(sp)
		sw s0, 4(sp)
		sw s1, 8(sp)
		sw s2, 12(sp)
		sw s3, 16(sp)
		
		li s0, 0		#i = 0
		mv s1, a0		#per non perdere indirizzo str
	
		li a0, 4		#jal ra, strlen		chiamata funzione strlen, ora in a0 ho lunghezza stringa


	loop:
		bge s0, a0, exit	#if(i>=l)
		
		add s3, s1, s0		#s1=s1+s0
		lb s3, 0(s3)
		addi s2, a0, -1		#s2=l-1
		sub s2, s2, s0		#s2=l-1-i
		add s2, a1, s2		#s2=reverse+s2
		
		sb s3, 0(s2)		#reverse+s2=s1=str[i]
		addi s0, s0, 1
		j loop
	exit:
		add s2, a1, a0
		sb zero, 0(s2)
		
		mv a0, a1
				
		lw ra, 0(sp)
		lw s0, 4(sp)
		lw s1, 8(sp)
		lw s2, 12(sp)
		lw s3, 16(sp)
		addi sp, sp, 20

		jalr zero, 0(ra)	#ritorno al chiamante di revert