import numpy as np
import torch
import torch.nn as nn
"""
#! NumPy
#?Array
v=np.array([1,40,2,-3])

#* trovare il valore minimo e massimo
minval = np.min(v)
maxval = np.max(v)
print('Min, Max: %g, %g' %(minval, maxval))

#* trovare la posizione del minimo e massimo
minidx = np.argmin(v)
maxidx = np.argmax(v)
print('Min, Max indici: %g, %g' %(minidx, maxidx));print()

#?Matrici
M = np.array([[0,1,10], 
              [20,8,5]])

minall = np.min(M)                         #* Minimo della matrice intera
mincolumn = np.min(M, axis=0)              #* Minimo di ogni colonna
minrow = np.min(M, axis=1)                 #* Minimo di ogni riga

print("Minimi della matrice:")
print(minall)
print(mincolumn)
print(minrow);print()

minidx_all = np.argmin(M)                         #* Minimo della matrice intera
minidx_column = np.argmin(M, axis=0)              #* Minimo di ogni colonna
minidx_row = np.argmin(M, axis=1)                 #* Minimo di ogni riga

print("Minimi indici della matrice:")
print(minidx_all)
print(minidx_column)
print(minidx_row);print()
"""

#! PyTorch
#?Array
v=torch.tensor([1,40,2,-3])

#* trovare il valore minimo e massimo
minval = torch.min(v)
maxval = torch.max(v)
print('Min, Max: %g, %g' %(minval, maxval))

#* trovare la posizione del minimo e massimo
minidx = torch.argmin(v)
maxidx = torch.argmax(v)
print('Min, Max indici: %g, %g' %(minidx, maxidx));print()


#?Matrici
M = torch.tensor([[0,1,10], 
              [20,8,5]])

minall = torch.min(M)                         #* Minimo della matrice intera
mincolumn = torch.min(M, axis=0)              #* Minimo di ogni colonna
minrow = torch.min(M, axis=1)                 #* Minimo di ogni riga

print("Minimo della matrice:")
print(minall);print()

print("Minimo per ogni colonna:")
print(mincolumn)
print("\t valori: ", end='');print(mincolumn.values)
print("\t posizioni: ", end='');print(mincolumn.indices);print()

print("Minimo per ogni riga:")
print(minrow)
print("\t valori: ", end='');print(minrow.values)
print("\t posizioni: ",end='');print(minrow.indices);print()

