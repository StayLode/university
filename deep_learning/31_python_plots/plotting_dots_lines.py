import matplotlib.pyplot as plt

"""
#! Parte 1
#?plt.plot(3,4, 'r^', label="red triangle")
#?plt.plot(2,4.2, 'bo', label="blue dot")
plt.plot(2,4.2, 'bo')
plt.plot(3,4, 'r^')
plt.legend(["blue","red"])
plt.show()
"""

""" 
#! Parte 2
x = [0,1,3]
y = [0,2,-1]
#Equivale a p1 = (0,0) e p2 = (1,2) uniti da una retta
plt.plot(x,y,'m') #Opzioni s: solo i puntini, con '-' ci aggiunge la linea, ':' dotted line
plt.show()
"""
import numpy as np
x = np.linspace(0,3*np.pi,101)
y = np.sin(x)
plt.plot(x,y)
plt.show()
plt.plot([0,1],[0,1],'m', linewidth=14)
plt.plot([0,1],[1,0],'m')
plt.axis('square')
plt.show()