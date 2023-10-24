% Funzione che risolve il problema dei minimi quadrati (caso polinomiale)
% Valida per il caso "non degenere", ossia quando il rango della matrice 
% rettangolare "associata al modello" è pari al numero dei parametri.

function alpha = my_minq_poli(x, y, n_param, check_rank)

% NOTA. supponiamo x,y vettori colonna.

n = n_param; % il modello è un polinomio di grado n-1 e ha n elementi di base (infatti: retta y = a0 x^0 + a1 x^1, parabola y = a0 x^0 + a1 x^1 + a2 x^2, etc.. )
m = length(x); % NOTA. si deve avere length(y) = length(x)

if(n > m) 
    error("errore: length(x) deve essere maggiore di n_param.")
end

% Calcolo la matrice collegata alla "distribuzione dei dati"
A = ones(m, n); % inizializzazione di A
for j=2:n
    A(:,j) = A(:,j-1) .* x;
end

if check_rank && (rank(A)<n_param)
     error("errore: caso degenere.")
end

% Fattorizzazione QR di A: uso la funzione qr di matlab (vedi help qr)
[Q,R] = qr(A);
y_tilde = Q' * y;
R = R(1:n, 1:n); % la funzione qr per matrici non quadrate ritorna come
                 % R una matrice rettangolare mxn 
                 % le preime n righe e n colonne di R formasno una mtarice 
                 % quadrata triangolare superiore.
y_tilde = y_tilde(1:n);
alpha = my_utri_sol(R, y_tilde);
%alpha = R \ y_tilde(1:n); % in alternativa ala linea precedente
