% Funzione che prende in ingresso un vettore x di lunghezza n
% che rappresenta le ascisse dei punti di interpolazione (nodi)
% e restituisce la matrice nxn di Vandermonde.

function V = my_vandermonde(x)

n = length(x);
V = ones( n );

for j = 2 : n
    V(:,j) = V(:,j-1) .* x;
end