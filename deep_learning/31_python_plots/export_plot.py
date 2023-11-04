import matplotlib.pyplot as plt
import numpy as np

from IPython import display
display.set_matplotlib_formats('svg')                  #Il formato di matplotlib diventa vector graphic invece che pixel graphic
                                                       #Migliora la qualità del grafico, meno pixe

x = np.linspace(.5,5,10)
y1 = np.log(x) 
y2 = 2-np.sqrt(x)


plt.plot(x,y1, 'bo-', label='log')
plt.plot(x,y2, 'rs-', label='sqrt')

plt.legend()
plt.savefig("test.pdf")                                  #Per salvare il file nella cartella corrente
plt.savefig("test.png")
plt.show()
