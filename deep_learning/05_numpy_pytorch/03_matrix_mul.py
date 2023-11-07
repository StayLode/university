import numpy as np
import torch

#! NumPy
print("NumPy: ")

#* Creazione di matrici random
A = np.random.randn(3,4)
B = np.random.randn(4,5)
C = np.random.randn(3,7)

#* Moltiplicazioni
#print(np.round(A@B,2))                  #* A@B è una shortcut, il comando esteso sarebbe np.matmul(A,B)
#print(np.round(A@C,2))  
#print(np.round(B@C,2))  
print(np.round(C.T@A,2))  
print()

#! PyTorch
print("PyTorch: ")

#*Creazione Matrici random
A = torch.randn(3,4)
B = torch.randn(4,5)
C1 = np.random.randn(4,7)
C2 = torch.tensor(C1, dtype=torch.float)

#* Moltiplicazioni
#print(np.round(A@B, 2))
#print(np.round(A@B.T, 2))
#print(np.round(A@C1, 2))                          #* NumPy e PyTorch in questo caso possono essere confrontati e utilizzati insieme
print(np.round(A@C2, 2))
print()