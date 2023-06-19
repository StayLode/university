% funzione che approssima lo zero della funzione di 1 variabile reale 
% definita in my_func.m nell'intervallo [a,b].

function [c,N] = my_bisection(func_name,a,b,tau)

% verifico l'ipotesi di segno discorde agli estermi di [a,b]
f_a = feval( func_name , a );
f_b = feval( func_name , b );
if( f_a * f_b >= 0 ) 
    error("la funzione non cambia segno agli estemi dell'intervallo [a,b]");
end

% numero di iterate per ottenere la precisione |x_zero - sol_esatta| < tau
N = ceil( log2( (b-a)/tau ) );

for n = 1 : N
    c = a + (b-a)/2; % punto medio di [a,b] con la formula stabile
    f_c = feval(func_name, c); 

    if(f_c == 0)
        return;
    end

    if(f_c * f_b < 0) 
        a = c;
        %f_a = f_c; %non serve perché if(f_a * f_c < 0) è sostituito dall'else
    else
        b = c;
        f_b = f_c;
    end
end