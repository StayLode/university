import matplotlib.pyplot as plt
import numpy as np

"""
#! Opzioni per plt.plot()   
        
x=np.linspace(-3,3,101)

plt.plot(x,x, label='y=x')
plt.plot(x,x**2, label='y=x**2')
plt.plot(x,x**3, label='y=x**3')

plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title("A really awesome plot.")

#plt.xlim([-3,3])                                  #Per rimuovere lo spazio tra la cornice del grafico e gli assi, scegli tu la dimensione in questo modo
plt.xlim([x[0],x[-1]])                             #Per rendere la dimensione dinamica
plt.ylim([-10,10]) 

#plt.axis('square')

plt.gca().set_aspect(0.2)                          #gca() --> get current axis, per accedere alle proprietà del current axis
                                                  #set_aspect(.3) --> per settare l'aspect ratio a 0.3, il valore corrisponde alla
                                                  #                   differenza di frequenza dei valori tra asse x e y, se settato
                                                  #                   a 1 la distanza tra i valori sull'asse x è uguale a quella sull'asse y
                                                  #                   'auto' è quella settata di default che equivale a non richiamare la funzione


plt.show()
"""
"""
#! Opzioni per plt.subplots()   
fig, ax = plt.subplots(1)                         #al momento non ci interessa avere più subplot

x=np.linspace(-3,3,101)
ax.plot(x,x, label='y=x')
ax.plot(x,x**2, label='y=x**2')
ax.plot(x,x**3, label='y=x**3')

ax.legend()
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title("A really awesome plot.")

ax.set_xlim([x[0],x[-1]]) 
ax.set_ylim([-10,10])
plt.show()
"""
fig, ax = plt.subplots(1) 

x = np.linspace(0,10,100)
for i in np.linspace(0,1,100):							#Sono 100 linee, 
	ax.plot(x,x**i,color=[i,0,i/2])						#nel primo ciclo i = 0 quindi sarà ax.plot(x,x**0=1)	che equivale alla linea nera (y=1)
																	#nell'ultimo ciclo i = 1 quindi sarà ax.plot(x,x**1=x)	che equivale alla linea piu chiara (y=x)
																	#color=[r,g,b]
plt.show()