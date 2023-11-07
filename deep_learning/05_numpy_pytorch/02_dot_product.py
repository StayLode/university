import numpy as np
import torch

#!Numpy
print("Numpy:")
nv1 = np.array([1,2,3,4])
nv2 = np.array([0,1,0,-1])

#* prodotto puntuale attraverso funzione
print(np.dot(nv1,nv2))

#* prodotto puntuale attraverso computazione
print(np.sum(nv1*nv2))
print()

#!Pytorch
print("PyTorch:")
nv1 = torch.tensor([1,2,3,4])
nv2 = torch.tensor([0,1,0,-1])

#* prodotto puntuale attraverso funzione
print(torch.dot(nv1,nv2))

#* prodotto puntuale attraverso computazione
print(torch.sum(nv1*nv2))