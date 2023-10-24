
close all
clear variables

figure(1)

% estremi dell'intervallo di definizione della funzione
a=-2;
b=2;

% stampa della funzione da campionare in entrabi i grafici
n_plot = 1000;
x_plot = linspace(a, b, n_plot)';
y_plot = my_function(x_plot);

subplot(2,2,1);
plot(x_plot,y_plot);
hold on
title("nodi equispaziati");

subplot(2,2,2);
plot(x_plot,y_plot);
hold on
title("nodi Cebichev");

subplot(2,2,3);
hold on
title("resto con nodi equispaziati");

subplot(2,2,4);
hold on
title("resto con nodi di Cebichev");

max_pts = 20;
for n_pti_camp = 2 : max_pts     
    
    % creazione dei nodi di interpolazione
    
    % a) nodi equispaziati
    x_camp = linspace(a, b, n_pti_camp)';
    y_camp = my_function(x_camp);
    
    subplot(2,2,1);
    pl_nod_eq = plot(x_camp,y_camp,'ro'); % stampa dei nodi equispaziati
    
    % b) nodi di Cebichev
    x_ceb = my_ceb_nodes(a, b, n_pti_camp);
    y_ceb = my_function(x_ceb);
    
    subplot(2,2,2);
    pl_nod_ceb = plot(x_ceb,y_ceb,'ro'); % stampa dei nodi Cebichev
    
    % Interpolazione
    % a) interpolazione con i nodi equispaziati 
    y_lagr = zeros(n_plot,1);
    for i=1:n_plot
        y_lagr(i) = my_lagrange_interpol(x_camp, y_camp, x_plot(i));
    end

    % calcolo la funzione resto: Rn(x)
    Rnx = y_plot - y_lagr; % memo. y_plot = f(x_plot), y_lagr = pn(x_plot)
    
    % stampa polinomio di interpolazione con i nodi equispaziati
    subplot(2,2,1);
    pl_pol_eq = plot(x_plot, y_lagr, 'g');

    % stampa il resto di interpolazione con i nodi equispaziati
    subplot(2,2,3);
    pl_rn_eq = plot(x_plot, Rnx, 'b');
    
    % b) interpolazione con i nodi di Cebichev 
    % sovrascrivo il vettore con le y del polinomio precedente
    for i=1:n_plot
        y_lagr(i) = my_lagrange_interpol(x_ceb, y_ceb, x_plot(i));
    end

    % calcolo la funzione resto: Rn(x)
    Rnx = y_plot - y_lagr; % memo. y_plot = f(x_plot), y_lagr = pn(x_plot)
    
    % stampa polinomio di interpolazione
    subplot(2,2,2);
    pl_pol_ceb = plot(x_plot, y_lagr, 'g');

     % stampa il resto di interpolazione con i nodi di Cebichev
    subplot(2,2,4);
    pl_rn_ceb = plot(x_plot, Rnx, 'b');

    %pause() % ferma l'esecuzione finché non viene premuto un pulsante CON QUALE??

    if n_pti_camp < max_pts
        % pulire le figure dai nodi e dai polinomi di interpolazione per 
        % evitare che vengano sovrapposti a quelli che saranno stampati 
        % al prossimo giro
        delete( pl_nod_eq )
        delete( pl_nod_ceb )
        delete( pl_rn_eq )
        delete( pl_pol_eq )
        delete( pl_pol_ceb )
        delete( pl_rn_ceb )
    end

end
