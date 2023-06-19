% Funzione che risolve il problema dei minimi quadrati (caso generale lineare)
% Valida per il caso "non degenere", ossia quando il rango della matrice 
% rettangolare "associata al modello" è pari al numero dei parametri.

function alpha = my_minq(x, y, f, check_rank)

% NOTA. supponiamo x,y vettori colonna.

n = length(f); % il modello è una combinazione delle funzioni di base: a1 * f1(x) + a2 * f2(x) + ..
m = length(x); % NOTA. si deve avere length(y) = length(x)

if(n > m) 
    error("errore: length(x) deve essere maggiore di n_param.")
end

% Costruisco la matrice collegata alla "distribuzione dei dati"
A = zeros(m,n);
for j=1:n
    A(:,j) = f{j}(x); 
end

if check_rank && ( rank(A) < n )
     error("errore: caso degenere.")
end

% Fattorizzazione QR di A: uso la funzione qr di matlab (vedi help qr)
[Q,R] = qr(A);
R = R(1:n, 1:n); % la funzione qr per matrici non quadrate ritorna come
                 % R una matrice rettangolare mxn 
                 % le preime n righe e n colonne di R formasno una mtarice 
                 % quadrata triangolare superiore.

y_tilde = Q' * y;
alpha = my_utri_sol(R, y_tilde(1:n));
%alpha = R \ y_tilde(1:n); % in alternativa ala linea precedente

