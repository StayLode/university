clear variables
close all

% estermi intervallo
a=0;
b=10;

% crea i dati senza rumore
m = 6; % numero di dati
x = rand(m,1) * (b-a) + a; % ascisse: m punti presi a caso in [a,b]
% x = linspace(a,b,m); % OPPURE m punti equispaziati in [a,b] : da usare in
                      % alternativa alla riga precednte.
y = my_function(x); % ordinate: i valori esatti

% "sporcare" i dati
vol = 0.7; % amplificatore/riduttore del rumore 
y = y + vol * randn(m,1); % aggiungo alle ordinate il rumore per simulare errori sperimentali

% regressione
n_param = 2;
f = cell(n_param, 1);
f{1} = @(t) t.^0;
f{2} = @(t) t.^1;

alpha = my_minq(x,y,f,true);

% stampa
figure
hold on
plot(x,y,'or'); %stamnpa dei dati
n_plot = 1000; % punti per la stampa (molti più dei nodi)
x_plot = linspace(a, b, n_plot)'; % ascisse per la stampa del polnomio
fij = zeros(n_plot, n_param);
for j=1:n_param
    fij(:,j) = f{j}(x_plot);
end
y_plot = fij * alpha; % ordinate per la stampa del polinomio
plot(x_plot,y_plot,'b');