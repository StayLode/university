
function [L,U] = lu_dec(A)
n = length (A);
for k = 1:n-1
    if(abs(A(k,k))<eps) %Per verificare che l'elemento è == 0, eps corrisponde alla precisione di macchina, in quanto non è detto che abbiamo un numero pari a 0.0000000
                        %In questo modo consideriamo come 0 un qualcosa più
                        %piccolo del numero minimo rappresentabile con
                        %floating point
        error("\n La fattorizzazione non è eseguibile \n");
    end
    %Passo di eliminazione di Gauss
    A(k+1:n,k) = A(k+1:n,k) / A(k,k); %Calcolo n-k+1 moltiplicatori: Elemento della colonna sotto al pivot, Riga da k+1 fino ad n, diviso per il pivot 
    A(k+1:n, k+1:n) = A(k+1:n, k+1:n) - A(k+1:n, k) * A(k,k+1:n) %Combinazioni lineari 
                      %                  (n-k+1)x1     1x(n-k+1) = (n-k+1)x(n-k+1)  
end
%Finito il ciclo avro la matrice U nel triangolo superiore e L in quello
%inferiore
L = tril(A, -1); % -1 serve per prendere una diagonale in meno, quindi non prende la diagonale principale
L = L + eye(n); % La matrice L non è completa, gli manca la diagonale principale;   
                % Si sommano gli 1 della matrice identità agli 0 della L, 
                % in modo da avere nella diagonale principale tutti 1
U = triu(A);    % Con triu() per togliere le diagonali bisogna fra +1,+2 ....