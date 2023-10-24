% Funzione che calcola la soluzione del sistema lineare Ax=b con il metodo
% di Jacobi.
% x0 è il punto di partenza, Kmax è la soglia di salvaguardia, tau è la
% tolleranza per gestire i criteri di arresto.

function [x0,k] = my_jacobi(A,b,x0,Kmax,tau)

M = diag(diag(A));
N = D - A; % diag(d) matrice diagonle con diagonale d; A1 = -E -F
tau_normb = tau*norm(b); % norma 2

for k = 1:Kmax
    res = norm(b - A * x0);
    p = N*x0 + b; % vettore dei termini noti per ricavare l'iterata successiva
    x = my_diag_sol(M, p); % x0 gioca il ruolo di xk, x quello di xk+1
    dist = norm(x - x0);
    
    if ( dist < tau*norm(x)  &&  res < tau_normb )
        return % x è l'ultima iterata
    end
    x0 = x; % nella prossima iterata xk sarà l'attuale xk+1
end
error("parametro di salvaguardia superato!!");