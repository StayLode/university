import matplotlib.pyplot as plt
import numpy as np
"""
#! Non la useremo mai
plt.subplot(2,2,1)                     #plt.subplot(row, column, index) --> l'indice parte da 1
plt.plot(np.random.randn(10))

plt.subplot(2,2,4)
plt.plot(np.random.randn(10))
plt.show()
"""
"""
fig,ax = plt.subplots(1,2,figsize=(10,4)) #Le misure sono in pollici, ma dipende dal monitor

x=np.arange(10)                        #Genera numeri da 1 a 10 --> 1 2 3 4 5 6 7 8 9 10

ax[0].plot(x,x**2,'b')
ax[0].plot(x,x,'k')
ax[1].plot(x,np.sqrt(x),'r')
plt.show()
"""
"""
fig,ax = plt.subplots(2,2)
ax[0,0].plot(np.random.randn(4,4))
ax[0,1].plot(np.random.randn(4,4))
ax[1,0].plot(np.random.randn(4,4))
ax[1,1].plot(np.random.randn(4,4))


plt.tight_layout()                      #Serve per evitare che i numeri sugli assi si sovrappongano 
plt.show()

"""

fig,ax = plt.subplots(3,3, figsize=(7,7))

for i in ax.flatten():
   i.plot(np.random.randn(3,10))
plt.show()