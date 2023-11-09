import numpy as np
import torch
import torch.nn as nn                   #* Neural Network
import matplotlib.pyplot as plt

#!NumPy
#?Manually
"""
#* Esempio appunti
z = [1,2,3]

num = np.exp(z)
den = np.sum(np.exp(z))
sigma = num/den

print(sigma, np.sum(sigma))
"""
"""
#* Uguale a prima ma con numeri interi random

z = np.random.randint(-5, high=15, size=25)
print(z)
num = np.exp(z)
den = np.sum(num)
sigma = num / den

plt.plot(z, sigma, 'ko')
plt.xlabel('Original Number (z)')
plt.ylabel('Softmaxified $\sigma$')
plt.yscale('log')                                                     #* si nota come la softmax si una trasformazione lineare in un spazio logaritmico
plt.title(f'$\sum\sigma$ = {np.round(np.sum(sigma),1)}')
plt.show()
"""
#! PyTorch

z = np.random.randint(-5, high=15, size=25)
num = np.exp(z)
den = np.sum(np.exp(z))
sigma = num/den

#* Creazione di un oggetto della classe Softmax di torch.nn
softfun = nn.Softmax(dim=0)

#* Passaggio dei dati di input alla funzione
sigmaT = softfun(torch.Tensor(z))

print(sigmaT)
plt.plot(z, sigmaT, 'ko')
plt.xlabel('"Manual" softmax')
plt.ylabel('Pytorch nn.Softmax')
plt.title(f'The two methods are correlate at r = {np.round(np.corrcoef(sigma,sigmaT)[0,1], 2)}')
plt.show()