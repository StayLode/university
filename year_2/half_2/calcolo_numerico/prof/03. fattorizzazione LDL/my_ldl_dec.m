% Funzione che calcola la fattorizzazione LDL di una matrice A simmetrica
% utilizzando l'algoritmo di fattorizzazione di Gauss per matrici 
% simmetriche.
% Ritorna le matrici L e D tali che L*D*L' = A

function [L,D] = my_ldl_dec(A)
if(issymmetric(A)==0)
    error("Matrice non simmerica");
end
n = length(A);
P = zeros(n);
L = eye(n);
D = zeros(n,1);
for j = 1:n
    P(j,1:j-1) = L(j,1:j-1) .* D(1:j-1)';
    D(j) = A(j,j) - L(j,1:j-1) * P(j,1:j-1)';
    if(abs(D(j))< eps)
        error("Fattorizzazione non eseguibile");
    end

    for i = j+1:n
        L(i,j) = ( A(i,j) - L(i,1:j-1)*P(j,1:j-1)' ) / D(j);
    end
end

D = diag(D);