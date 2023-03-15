
function x = triang_up_solver(U,b)
if (istriu(U)==false)
    errore("La matrice in input non è triangolare superiore! ");
end

n = length(b);
x = zeros(n,1);
x(n) = b(n)/ U(n,n);

for j=n-1:-1:1
    x(j) = ( b(j) - U(j,j+1:n) * x(j+1:n) ) / U(j,j); %il * è una moltiplicazione tra i vettori U(j,1:j-1) e x(1:j-1)
    %{
    il primo è un vettore riga (1xj-1) e il secondo è un vettore colonna (j-1x1) 
    si tratta quindi di un prodotto riga per colonna

    Per testarlo basta fare U*z(soluzione) e vedere se è uguale a b
    %}
end