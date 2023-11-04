import matplotlib.pyplot as plt
import numpy as np
import imageio.v3 as iio
m = 3
n = 5

M = np.random.randint(10, size=(m,n))

print(M)
plt.imshow(M)                 #Crea una immagine che rappresenta i colori/ mappa i valori degli elementi della matrice come colori
                              #Più il valore è basso più la cella è scura, 0 nella matrice --> cella più scura
for i in range(m):
	for j in range(n):
    	#Vanno invertite i e j, le colonne equivalgono alla x e le righe alla y
		plt.text(j,i,str(M[i,j]), 
           		fontsize=20,
           		horizontalalignment='center',
           		verticalalignment='center')		
  		


plt.colorbar()                #Mostra una colorbar che aiuta a mappare i valori in colori
plt.show()

img = iio.imread("https://upload.wikimedia.org/wikipedia/en/8/86/Einstein_tongue.jpg")
#Notare come questa immagine sia un matrice di valori
#print(img)
#print(img.shape)
plt.imshow(img)
plt.title('That smart guy')
plt.show()

plt.hist(img.flatten(),bins=100)		#Istogramma che sull'asse x mostra il valore del colore e sull'asse y il numero di volte che appare
												#Siccome i colori scuri hanno valore più basso si nota come l'immagine sia principalmente scura
plt.show()

plt.imshow(img, cmap='gray', vmin=80, vmax=200)			#cmap = color map, vmin e vmax smallest/largest color value displayed, 
																		#quelli minori e maggiori di vmin e vmax verrano messi a nero(0) e a bianco (255)
																		#Effetto ottenuto -> aumento del contrasto

plt.xticks([])						#Per settare i valori sull'asse x, se vuoto non scrive niente
plt.yticks([])						#Per settare i valori sull'asse y, se vuoto non scrive niente
plt.show()

#!Mostrare la matrice di Hilbert H(i,j)=1/(i+j-1) con seaborn (H[10x10])
import seaborn as sns

n = 10
H = np.zeros((n,n))

for i in range(n):
   for j in range(n):
      H[i,j] = 1/((i+1)+(j+1)-1) 

sns.heatmap(H, vmax=.4)
plt.show()