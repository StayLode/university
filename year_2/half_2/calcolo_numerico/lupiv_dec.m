% Funzione che calcola la fattorizzazione LU di una matrice A
% utilizzndo l'algoritmo di fattorizzazione di Gauss con pivoting parziale
% Ritorna le matrici L, U, e P tali che L*U = P*A
function [L,U,P] = lupiv_dec(A)

n = length (A);
P=eye(n);

for k = 1:n-1
    [~, r] = max( abs(A(k:n,k)) ); % [~, r] non ci interessa saper il più grande, ma la riga dell'elemento più grande
                                   % ~ ==> ignoro il primo ritorno che sarebbe il numero più grande         
    r = r + k-1;                   % Per riportare r all'indicizzazione dell'intera colonna, perchè r ha valore 1 per la riga del pivot che potrebbe essere
                                   % la quinta della matrice
    if (r ~= k)                    % r != k
        tmp = A(k,:);              % riga k in tmp
        A(k, :) = A(r,:);          % sovrascrivo la riga k con la r-esima, anche i moltiplicatori
        A(r, :) = tmp;

        %Faccio la stessa cosa nella matrice delle permutazioni elementari
        tmp = P(k,:);              
        P(k, :) = P(r,:);          
        P(r, :) = tmp; 
    end
    if(abs(A(k,k))<eps)
        error("\n La fattorizzazione non è eseguibile \n");
    end
    %Passo di eliminazione di Gauss
    A(k+1:n,k) = A(k+1:n,k) / A(k,k); %Calcolo n-k+1 moltiplicatori: Elemento della colonna sotto al pivot, Riga da k+1 fino ad n, diviso per il pivot 
    A(k+1:n, k+1:n) = A(k+1:n, k+1:n) - A(k+1:n, k) * A(k,k+1:n) %Combinazioni lineari 
  
end

L = tril(A, -1); % -1 serve per prendere una diagonale in meno, quindi non prende la diagonale principale
L = L + eye(n); % La matrice L non è completa, gli manca la diagonale principale;   
                % Si sommano gli 1 della matrice identità agli 0 della L, 
                % in modo da avere nella diagonale principale tutti 1
U = triu(A);    % Con triu() per togliere le diagonali bisogna fra +1,+2 ....