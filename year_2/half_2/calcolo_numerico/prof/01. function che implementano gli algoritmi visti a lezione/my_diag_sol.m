% Funzione che risolve il sistema Dx = b con D matrice diagonale.
% Si assume b vettore colonna.
% Ritorna il vettore colonna delle soluzioni x.

function x = my_diag_sol(D,b)
if(isdiag(D)==false) 
    error("La matrice in input non è diagonale");
end
d = diag(D); % d è un vettore colonna con gli elementi della diagonale di D.
x = b ./ d;