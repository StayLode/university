import numpy as np
import sympy as sym

#* Per rendere le equzioni più belle da vedere
from IPython.display import display

x = sym.symbols('x')

fx = 2*x**2
gx = 4*x**3-3*x**4

df = sym.diff(fx)
dg = sym.diff(gx)

#* regola del prodotto (manuale)
manual = df*gx + fx*dg
thewrongway = df*dg

#* regola del prodotto (sympy)
viasympy = sym.diff(fx*gx)
print("Le funzioni:")
display(fx)
display(gx)
print()
print("Le loro derivate:")
display(df)
display(dg)
print()
print("Prodotto manuale:")
display(manual)
print()
print("Prodotto con sympy:")
display(viasympy)
print()
print("Metodo sbagliato:")
display(thewrongway)
print()

#* Regola della catena
gx = ( x**2 + 4*x**3 )
fx = (gx)**5
print("La funzione:")
display(fx)
print()
print("La sua derivata:")
display(sym.diff(fx))