% Funzione che dati n+1 punti di R^2, valuta il polinomio di grado n 
% interpolante in x_eval. Il polinomio è calcolato rispetto alla base di 
% Lagrange.
% Assumiamo che i vettori siano tutti colonna.

function y_eval = my_lagrange_interpol(nodi, y_nodi, x_eval)

m = length(nodi); % m = n+1 
L = zeros(m,1); % L(k) conterrà il valore del k-simo elemnto (polinomio) 
                % della base di Lagrange valutato in x_eval: L_k(x_eval) 

%omega_n = 1;
%for i = 1:m
%    omega_n = omega_n * ( x_eval - nodi(i) ); 
%end
% ora omega_n = (x_eval - nodi(1)) * ... * (x_eval - nodi(n+1))
omega_n = prod( x_eval - nodi ); % equivalente al ciclo delle righe 12-15

% Calcolo tutti gli L_k(x_eval)
for k = 1:m

    den = 1; % denominatore di L(i) (senza il fattore (x_eval - nodi(k)))
    for i = 1:m
        if(i~=k)
            den = den * (nodi(k) - nodi(i));
        end
    end

    L(k) = omega_n / (den * (x_eval - nodi(k))); % Divido per (x_eval - nodi(k)) per
                                                 % correggere il numeratore
end

y_eval = y_nodi' * L; % yeval = p_n(x_eval) = y_nodi(0) * L(0) + ... + y_nodi(m) * L(m)


