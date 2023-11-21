import matplotlib.pyplot as plt
import numpy as np

#* Creazione di una lista di numeri = Popolazione
x = [1,2,4,6,5,4,0,-4,5,-2,6,10,-9,1,3,-6]
n = len(x)

#* population mean
popmean = np.mean(x)

#* sample mean
sample = np.random.choice(x,size=5, replace = True)
sampmean = np.mean(sample)

print("Mean:")
print(popmean, sampmean);print()
#! Si nota come prendendo dei campioni piccoli si ottinee un valore non rappresentativo, per questo si fanno campionamenti molto grandi

#* Numero di esperimenti
nExpers = 10000

sampleMeans = np.zeros(nExpers)
for i in range(nExpers):
    #*Estrazione di un campione
	sample = np.random.choice(x, size=10, replace=True)
	
	#*Calcolo della sua media
	sampleMeans[i]=np.mean(sample)
 
plt.hist(sampleMeans, bins=40, density=True)
plt.plot([popmean,popmean],[0,.3], 'm--')
plt.ylabel('Count')
plt.xlabel('Sample mean')
plt.show()
