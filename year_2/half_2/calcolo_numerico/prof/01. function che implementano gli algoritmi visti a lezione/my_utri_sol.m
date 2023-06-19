% Funzione che risolve il sistema Lx = b con L matrice triangolare 
% superiore: utilizza l'algoritmo di sostituzione all'indietro.
% Ritorna il vettore colonna delle soluzioni x.

function x = my_utri_sol(U,b)
if(istriu(U)==false) 
    error("La matrice in input non è triangolare superiore");
end
n = length(b);
x = zeros(n,1);
x(n)=b(n)/U(n,n);
for j=n-1:-1:1
    x(j) = ( b(j) - U(j,j+1:n) * x(j+1:n) ) / U(j,j);
end