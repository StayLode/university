import numpy as np
import matplotlib.pyplot as plt

#!Numpy
#*NB: tutte le probabilità sommate devono dare 1
p = [1,0]           #* sum = 1 -> probabilità che la foto sia un gatto o no
q = [.25, .75]      #* sum = 1 -> probabilità che il modello dica che sia o meno un gatto

H = [0]
for i in range (len(p)):
	H += -(p[i]*np.log(q[i]))
print('Cross entropy: '+ str(H))

#? Entropia incrociata binaria, N=2 eventi
#? H = -(p[0]*np.log(q[0]) + p[1]*np.log(q[1]))
#* siccome p[1]=0 e p[1]=1 semplifichiamo:
#? H = -np.log(q[0])


#!PyTorch
import torch
import torch.nn.functional as F

#* gli input devono essere dei Tensor
q_tensor = torch.Tensor(q)					#* q=model predicted probability that the picture is a cat or isn't
p_tensor = torch.Tensor(p)					#* p=category label: is a cat or isn't
print(F.binary_cross_entropy(q_tensor,p_tensor))