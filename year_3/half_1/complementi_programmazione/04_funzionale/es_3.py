"""
Considerare ora 10 stringhe molte lunghe e contare la frequenza cumulativa di ogni lettera
"""
import functools as f
seq = "jfndjsn fma sdmfasnfdnaskfdnksfksndfkanlkeflgkrtohryjigeakrowefrgthgfdsfgboijdmelrtgpofdikjsnm"

map_f = lambda seq: f.reduce(lambda x,y: x | {y:x.get(y,0)+1}, seq, {})
lista_s=[seq for i in range(10)]

print(len(list(map(map_f, lista_s))))
print(list(map(map_f, lista_s))[0])

reduce_f = lambda x,y: x | {k:x.get(k,0)+v for k,v in y.items()}
print(f.reduce(reduce_f, map(map_f, lista_s)))