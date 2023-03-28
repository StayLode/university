function [L, D] = fatt_mat_simm(A);
if (issymmetric(A)==0)
    error("Matrice non simmetrica!");
end

n = length(A);
P = zeros(n);
L = eye(n);
D = zeros(n,1);

for j = 1:n
    P(j,1:j-1) =  L(j,1:j-1) .* D(1:j-1)'; % .* Moltiplicazione elemento per elemento, ??LE SOMMATORIE SI FANNO CON IL PRODOTTO SCALARE??
    D(j) = A(j,j) - L(j,1:j-1) * P(j,1:j-1); % il ' trasforma il vettore riga in colonna
    if(abs(D(j))<eps)
        error("Fattorizzazione non eseguibile");
    end
    for i = j+1:n
        L(i,j) = { A(i,j) - L(i,1:j-1)*P(j,1:j-1)' } / D(j);
    end
end

D = diag(D);
