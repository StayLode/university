close all

figure(1)
hold on

% estremi dell'intervallo di definizione della funzione
a=-2;
b=2;

n_plot = 1000;
x_plot = linspace(a, b, n_plot)';
y_plot = my_function(x_plot);
plot(x_plot,y_plot);

n_pti_camp = 30;
x_camp = linspace(a, b, n_pti_camp)';
y_camp = my_function(x_camp);
plot(x_camp,y_camp,'ro');

y_lagr = zeros(n_plot,1);
for i=1:n_plot
    y_lagr(i) = my_lagrange_interpol(x_camp, y_camp, x_plot(i));
end
plot(x_plot, y_lagr, 'r');
