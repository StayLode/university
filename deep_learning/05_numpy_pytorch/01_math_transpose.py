import numpy as np
import torch

#! Vettori Numpy
print("Vettori Numpy:")

#* crea un vettore
nv = np.array([[1,2,3,4]])              #* la prima [] indica che stiamo inserendo una matrice, la seconda indica la prima riga
print(nv)

#* stampare il vettore trasposto, ma non salvato nella variabile
print(nv.T)                             #* oppure np.transpose(nv),

nvT = nv.T
print(nvT.T)
print()

#! Matrici Numpy
print("Matrici Numpy:")

#* crea una matrice
nM = np.array([[1,2,3,4],
               [5,6,7,8]])             
print(nM)

print(nM.T)                             

nMT = nM.T
print(nMT.T)

#! Vettori PyTorch
print("Vettori PyTorch:")

#* crea un vettore
tv = torch.tensor([[1,2,3,4]])             
print(tv)

print(tv.T)                             

tvT = tv.T
print(tvT.T)
print()

#! Matrici PyTorch
print("Matrici PyTorch:")

#* crea una matrice
tM = torch.tensor([[1,2,3,4],
                   [5,6,7,8]])             
print(tM)

print(tM.T)                             

tMT = tM.T
print(tMT.T)

#* Esaminiamo i tipi di dati
print(f'Variable nv is of type {type(nv)}')
print(f'Variable nM is of type {type(nM)}')
print(f'Variable tv is of type {type(tv)}')
print(f'Variable tM is of type {type(tM)}')