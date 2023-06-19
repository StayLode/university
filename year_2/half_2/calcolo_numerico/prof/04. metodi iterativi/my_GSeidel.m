% Funzione che calcola la soluzione del sistema lineare Ax=b con il metodo
% di Gauss-Seidel.
% x0 è il punto di partenza, Kmax è la soglia di salvaguardia, tau è la
% tolleranza per gestire i criteri di arresto.

function [x0,k] = my_GSeidel(A,b,x0,Kmax,tau)

D_E = tril(A);
F = -triu(A,1);
normb = norm(b); % norma 2
for k=1:Kmax
    p =  F * x0 + b;
    x = my_ltri_sol(D_E, p); % x0 gioca il ruolo di xk, x quello di xk+1
    % x = D_E \ p;  % in alternativa posso usare mldivide di matlab
    dist = norm(x - x0);
    res = norm(b - A * x0);
    if ( dist < tau*norm(x) && res < tau*normb )
        return % x è l'ultima iterata
    end
    x0 = x; % nella prossima iterata xk sarà l'attuale xk+1
end
error("parametro di salvaguardia superato!!");