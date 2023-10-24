clear all
close all

n = 21; % Nr di punti di interpolazione
x = linspace(-1,1,n)'; %intervallo tra -1 e 1 equispazionato in n parti, inverso in quanto restituisce un vettore riga

y = 1./(1 + 25*x.^2);

v = linspace(-1,1,100)';
p = coeff_indeterminati(x,y,v);

plot(v,p,"-r");
hold on;
plot(x,y,'ok');
plot(v,1./(1 + 25*v.^2),'-b');
legend('polinomio di interpolazione', 'punti', 'funzione');