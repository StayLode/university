import numpy as np
import torch

# #! NumPy
# #*  Generazione di 5 numeri casuali
# print(np.random.randn(5));print()

# #* Fissiamo il seed, metodo vecchio ma ancora molto usato
# np.random.seed(17)
# print(np.random.randn(5))
# print(np.random.randn(5));print()
# #* Usciranno sempre queste
# #* [ 0.27626589 -1.85462808  0.62390111  1.14531129  1.03719047]
# #* [ 1.88663893 -0.11169829 -0.36210134  0.14867505 -0.43778315]

# print("Nuovo metodo:")
# randseed1 = np.random.RandomState(17)
# randseed2 = np.random.RandomState(20210530)

# print( randseed1.randn(5) )   #* Stessa sequenza
# print( randseed2.randn(5) )   #* Diversa da sompra, ma uguale ogni volta
# print( randseed1.randn(5) )   #* Stessa di due righe sopra
# print( randseed2.randn(5) )   #* Stessa di due riga sopra
# print( np.random.randn(5) )   #* Diversa ogni volta

#! PyTorch
print(torch.randn(5))

torch.manual_seed(17)
print(torch.randn(5))

#* il seed di torch non influenza numpy
print(np.random.randn(5))
