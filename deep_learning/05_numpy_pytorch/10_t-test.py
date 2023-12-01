import numpy as np
import matplotlib.pyplot as plt

import scipy.stats as stats

#* parameters
n1 = 30             #* samples in dataset1
n2 = 40             #* samples in dataset2
mu1 = 1             #* population mean in dataset1
mu2 = 2             #* population mean in dataset2

#* generate data
data1 = mu1 + np.random.randn(n1)
data2 = mu2 + np.random.randn(n2)

#* plot+
plt.plot(np.zeros(n1), data1, 'ro', markerfacecolor='w', markersize=14)
plt.plot(np.ones(n2), data2, 'bs', markerfacecolor='w', markersize=14)
plt.xlim([-1,2])
plt.xticks([0,1], labels=["Group 1", "Group 2"])
plt.show()

#* t-test via stats package
#* _ind = independent samples
t,p = stats.ttest_ind(data1,data2)
print(t)
print(p)
#* il t-test ci dice che il gruppo 2 ha una media (mean) molto maggiore del gruppo 1
#* Il valore di t è negativo perchè data1-data2<0 visto che data2 >data1, invertendoli nella funzione diventa positivo

#*Modo più comune per mostrare i risultati del t-test
fig = plt.figure(figsize=(10,4))
plt.rcParams.update({'font.size':12})   #* Modifica la dimensione del font

plt.plot(0+np.random.randn(n1)/15, data1, 'ro', markerfacecolor='w', markersize=14)
plt.plot(1+np.random.randn(n2)/15, data2, 'bs', markerfacecolor='w', markersize=14)
plt.xlim([-1,2])
plt.xticks([0,1], labels=["Group 1", "Group 2"])

#*Setta il titolo per includere i valori di t e p
plt.title(f't={t:.2f}, p={p:.3f}')

plt.show()