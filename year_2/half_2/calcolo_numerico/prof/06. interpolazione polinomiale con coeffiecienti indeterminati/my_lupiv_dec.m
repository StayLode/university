% Funzione che calcola la fattorizzazione LU di una matrice A
% utilizzando l'algoritmo di fattorizzazione di Gauss con pivoting parziale.
% Ritorna le matrici L, U e P tali che L*U = P*A

function [L,U,P] = my_lupiv_dec(A)
n = length(A);
P = eye(n);
for k = 1:n-1
    [~,r] = max( abs(A(k:n,k)) );
    r = r + k-1;
    if (r ~= k) % r diverso da k
        tmp = A(k,:); 
        A(k,:) = A(r,:); 
        A(r,:) = tmp;

        tmp = P(k,:); 
        P(k,:) = P(r,:); 
        P(r,:) = tmp;
    end
    if(abs(A(k,k))< eps)
        error("\n Fattorizzazione non eseguibile \n");
    end
    A(k+1:n,k) = A(k+1:n,k) / A(k,k);
    A(k+1:n,k+1:n) =  A(k+1:n,k+1:n)  -  A(k+1:n,k) * A(k,k+1:n);
end

L = tril(A,-1); 
L = L + eye(n); 
U = triu(A);