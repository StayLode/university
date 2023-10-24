clear all
close all

m = 3.5; q = 1.5;
a = -5; b = 5;
N_nodi = 5;
x_nodi = linspace (a,b,N_nodi)';
y_nodi = m*x_nodi + q;

plot(x_nodi,y_nodi, 'or');

x = linspace(a,b, 50);
[y,alpha] = coeff_indeterminati(x_nodi, y_nodi, x); 
% alpha contiene i coefficienti del polinomio di interpolazione 
% che è stato calcolato, nella rappresentazione canonica, e sono
% nell'ordine dalla potenza di x di grado più basso, cioè dal termine noto,
% alle potenze più alte 
% conterrà 1,5 -> q e 3,5 --> m, abbiamo 3 coefficienti nulli ovvero
% abbiamo individuato una retta perchè i punti sono allineati

hold on;
plot(x,y,"b");

y__pert = y_nodi + randn(size(y_nodi));
plot(x_nodi,y__pert, 'ok');
[y2,alpha2] = coeff_indeterminati(x_nodi, y__pert, x); 
plot(x,y2, 'k');

