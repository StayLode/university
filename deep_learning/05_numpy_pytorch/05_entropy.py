import numpy as np
import matplotlib.pyplot as plt

#!Numpy
#*Probabilità che un evento accada
p = .25

#* formula SCORRETTA nonostante sembri giusta
H = - (p * np.log(p))
print ("Wrong entropy "+ str(H))        #* Manca la probabilità che l'evento non si verifichi

#* formula CORRETTA
x = [.25, .75]

H = 0
#* Se abbiamo probabilità multiple
for p in x:
	H += - p*np.log(p)

#* Per N=2 eventi, Entropia Binaria
#? H = -(p*np.log(p) + (1-p)*np.log(1-p)) 	#Usata per la Entropia Incrociata Binaria


print('Correct Entropy: '+ str(H))