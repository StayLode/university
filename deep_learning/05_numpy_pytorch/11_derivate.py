import numpy as np
import matplotlib.pyplot as plt

#* sympy = symbolic math in Python
import sympy as sym
import sympy.plotting.plot as symplot

"""#* creazione di una variabile simbolica
x = sym.symbols('x')

#* creazione di una funzione
fx = 2*x**2

#* calcolo della derivata
df = sym.diff(fx,x)

print(fx)
print(df)

#* Plot della funzione e della derivata
p = symplot(fx,(x,-4,4), label="The function", show=False, line_color='blue')
p.extend(symplot(df,(x,-4,4), label="Its derivative", show=False, line_color='red'))
p.legend = True
p.show()"""

#!ReLU e Sigmoide
#* creazione di una variabile simbolica
x = sym.symbols('x')

#* creazione funzioni simboliche
relu = sym.Max(0,x)
sigmoid = 1 / (1+sym.exp(-x))

#* plot della funzione
p = symplot(relu, (x,-4,4), label = 'ReLU', show=False, line_color='blue')
p.extend(symplot(sigmoid, (x,-4,4), label='Sigmoid', show=False, line_color='red'))
p.legend = True
p.title = 'The functions'
p.show()

#* plot della derivata
p = symplot(sym.diff(relu), (x,-4,4), label = 'df(ReLU)', show=False, line_color='blue')
p.extend(symplot(sym.diff(sigmoid), (x,-4,4), label='df(Sigmoid)', show=False, line_color='red'))
p.legend = True
p.title = 'The derivatives'
p.show()