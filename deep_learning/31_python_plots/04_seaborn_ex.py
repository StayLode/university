import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns                   #Lavora al di sopra di Matplotlib e fornisce plotting utility

n = 200                                 #200 data points

D = np.zeros((n,2))                     #matrice 200x2 di 0

#Incremento lineare con rumore
D[:,0] = np.linspace(0,10,n) + np.random.randn(200) #Popola la prima colonna di D con numeri compresi tra 0 e 10 equamente spaziati con un po' di rumore

#Quadrato dei termini con rumore
D[:,1] = D[:,0]**2 + np.random.randn(200)*10        #Popola la seconda colonna di D con il quadrato della prima con un po' di rumore (maggiore della prima)
"""
#?JointPlot
#sns.jointplot(D[:,0], D[:,1])                       

#Il grafico interno rimane uguale a fare con plt.plot(...), 
#ma aggiunge un istogramma sull'asse x e y che mostra la distribuzione dei punti
#sui due assi

#plt.plot(D[:,0], D[:,1],'o')

#! Seaborn e Pandas lavorano bene insieme
#!Conversione del data set in Pandas data frame
df = pd.DataFrame(data=D, columns=['var1', 'var2'])
#print(df)


#sns.jointplot(x=df.columns[0], y=df.columns[1], data=df)                                  #Aggiunge il noe sugli assi
#sns.jointplot(x=df.columns[0], y=df.columns[1], data=df, kind = 'kde', color='purple')    #kde: kernel density estimation --> metodo non lineare per stimare la probabilità di densità
plt.show()
"""
"""
#?ScatterPlot

x = np.linspace(-1,1,n)                 #Nota come questa x non venga utilizzata come x del grafico, ma usata con linear grid delle altre funzioni
y1 = x**2
y2 = np.sin(3*x)
y3 = np.exp(-10*x**2)

sns.scatterplot(x=y1,y=y2, hue=y3, legend=False, palette='Spectral')
plt.show()
"""
#?RegressionPlot
df = pd.DataFrame(data=D, columns=['var1', 'var2'])
sns.regplot(x=df.columns[0], y=df.columns[1], data=df, color='green')
plt.title(f'Regression of {df.columns[0]} on {df.columns[1]}')
plt.show()
