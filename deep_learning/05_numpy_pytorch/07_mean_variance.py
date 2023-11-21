import numpy as np

x = [1,2,4,6,5,4,0]
n = len(x)

#* Mean
mean1 = np.mean(x)
mean2 = np.sum(x)/n

print("Mean:")
print(mean1, mean2);print()

#* Variance
var1 = np.var(x)
var2 = (1/(n-1)) * np.sum((x-mean1)**2)

print("Variance: ")
print(var1, var2)
#! Si nota come non diano lo stesso risultato, infatti:

#* np.var ha un secondo input che specifica il grado di libertà, ovvero il numero che va sottratto ad n nella prima frazione
#* np.var(x) (==np.var(x, ddof=0)) permette di calcolare la varianza detta "biased variance", a noi serve quella "unbiased"

var3 = np.var(x, ddof=1)
print(var3);print()

#* Ovviamente questo bias ha valore quando l'insieme dei valori è ridotto, più diventa grande l'insieme più il -1 è ininfluente