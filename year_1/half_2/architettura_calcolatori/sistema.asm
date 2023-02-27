#a0 ==> O
#a1 ==> n
.globl main
.data
	O: .word 1
	n: .word 16
.text
	main:
		la t0, O
		la t1, n
		lw a0, 0(t0)			#a0=O
		lw a1, 0(t1)			#a1=n
		li t0, 1			#t0=1
		li t1, 0			#t1=0
		mv t2, a1			#t2=a1=n
		beq a0, t0, log			#se a0==1 salta a log
		bne a0, zero, end		#se a0!=0 salta alla fine
	
		sll a0, t0, a1			#shift a sx t0=1 di a1 posizioni
		j end				#salta alla fine

	log:	srli t2,t2,1			#shift a dx t2=n di 1 posizione
		addi t1,t1,1			#t1+=1
		bgt t2, t0, log			#se t2>1 salta a log
		mv a0, t1
	
	end:
	