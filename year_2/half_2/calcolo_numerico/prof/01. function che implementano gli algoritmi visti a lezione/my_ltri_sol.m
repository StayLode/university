% Funzione che risolve il sistema Lx = b con L matrice triangolare 
% inferiore: utilizza l'algoritmo di sostituzione in avanti.
% Ritorna il vettore colonna delle soluzioni x.

function x = my_ltri_sol(L,b)
if(istril(L)==false) 
    error("La matrice in input non è triangolare inferiore");
end
n = length(b);
x = zeros(n,1);
for j=1:n
    x(j) = ( b(j) - L(j,1:j-1) * x(1:j-1) ) / L(j,j);
end