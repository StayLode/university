import numpy as np
import matplotlib.pyplot as plt

"""
#* Definizione di un set di punti da valutare
x = np.linspace(.0001, 1, 200)

#* Calcolo del logaritmo
logx = np.log(x)

fig = plt.figure(figsize=(10,4))

plt.rcParams.update({'font.size':15})
plt.plot(x, logx, 'ks-', markerfacecolor='w')
plt.xlabel('x')
plt.ylabel('log(x)')
plt.show()
"""
#Dimostrazione che il logaritmo e l'esponenziale sono inversi
x = np.linspace(.0001, 1, 20)
logx = np.log(x)
expx = np.exp(x)
plt.plot(x,x, color=[.8,.8,.8])
plt.plot(x, np.exp(logx), 'o', markersize=8)
plt.plot(x, np.log(expx), 'x', markersize=8)
plt.xlabel('x')
plt.ylabel('f(g(x))')
plt.legend(['unity','exp(log(x))','log(exp(x))'])
plt.show()