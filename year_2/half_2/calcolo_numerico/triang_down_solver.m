
function x = triang_down_solver(L,b)
if (istril(L)==false)
    errore("La matrice in input non è triangolare inferiore! ");
end

n = length(b);
x = zeros(n,1);
for j=1:n
    x(j) = ( b(j) - L(j,1:j-1) * x(1:j-1) ) / L(j,j); %il * è una moltiplicazione tra i vettori L(j,1:j-1) e x(1:j-1)
    %{
    il primo è un vettore riga (1xj-1) e il secondo è un vettore colonna (j-1x1) 
    si tratta quindi di un prodotto riga per colonna

    Per testarlo basta fare L*z(soluzione) e vedere se è uguale a b
    %}
end