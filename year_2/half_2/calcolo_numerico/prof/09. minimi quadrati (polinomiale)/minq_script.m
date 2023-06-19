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
vol = 0.3; % amplificatore/riduttore del rumore 
y = y + vol * randn(m,1); % aggiungo alle ordinate il rumore per simulare errori sperimentali

% regressione
grad_mod = 1; % grado del modello: 1-retta, 2-parabola, 3-cubica, etc.
alpha = my_minq_poli(x,y,grad_mod+1,true);

% stampa
figure
hold on
plot(x,y,'or'); %stamnpa dei dati
n_plot = 1000; % punti per la stampa (molti più dei nodi)
x_plot = linspace(a, b, n_plot)'; % ascisse per la stampa del polnomio
y_plot = polyval( alpha( length(alpha):-1:1 ), x_plot); % ordinate per la stampa del polinomio
plot(x_plot,y_plot,'b');
