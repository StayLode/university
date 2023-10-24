% Funzione che calcola la fattorizzazione LU di una matrice A
% utilizzando l'algoritmo di fattorizzazione di Gauss
% Ritorna le matrici L e U tali che L*U = A

function [L,U] = my_lu_dec(A)
n = length(A);
for k = 1:n-1 
    if(abs(A(k,k))< eps) % A(k,k) = 0
        error("\n Fattorizzazione non eseguibile \n");
    end
    A(k+1:n,k) = A(k+1:n,k) / A(k,k);  %Elementi della colonna sotto al pivot diventano i moltiplicatori
    A(k+1:n,k+1:n) =  A(k+1:n,k+1:n)  -  A(k+1:n,k) * A(k,k+1:n);
end

L = tril(A,-1); 
L = L + eye(n); 
U = triu(A);