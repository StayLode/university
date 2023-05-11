%close all %chiude tutte le figure precedenti
figure(1)
hold on %Per sovrapporre più strati e non sovrascrivere quelli precedenti

%Estremi dell'intervallo di definizione della funzione
a=-2;
b=2;

n_plot = 1000;

x_plot = linspace(a,b, n_plot)'; %Vettore equispaziato da -2 a 2 con 1000 punti
y_plot = my_function(x_plot); %Calcola il vettore i cui elementi sono la f(x) degli elementi del vettore precedente

plot(x_plot,y_plot);

% Campionamento, maggiore è il grado del polinomio, ovvero il numero di punti del campionamento, interpolante migliore è
% l'approssimazione alla funzione iniziale

%Con la funzione di runge invece maggiore è il numero di punti di interpolazione peggiore è 
%l'approssimazione

n_pti_camp = 3; %Numero di punti di campionamento ==> se ho 3 punti (nodi) --> polinomio di secondo grado
x_camp = linspace(a,b,n_pti_camp)'; %Vettore equispaziato da -2 a 2 con 3 punti
y_camp = my_function(x_camp);

plot(x_camp,y_camp, 'ro'); %Opzione 'ro' è per fare un pallino rosso, in questo modo non unisce i punti

%Polinomio che interpola i punti

y_lagr= zeros(n_plot,1);
for i=1:n_plot
    y_lagr(i) = my_lagrange_interpol(x_camp,y_camp, x_plot(i));
end
plot(x_plot, y_lagr, 'r');

