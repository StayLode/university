function plot_my_function_zero(func_name, a, b, n_pts, zero)
figure % apre una nuova figura vuota
x = linspace(a,b,n_pts); % vettore con n elementi equispaziati tra a e b.
y = feval(func_name, x); % vettore con n elementi y(i) = f( x(i) )
% OOPURE
%y = zeros(1,length(x));
%for i=1:length(x)
%    y(i) = feval(func_name, x(i));
%end

hold on % permette stampe multiple sulla stessa figura
plot(x,y,'b'); % stampo il grafico della funzione 
plot(x,zeros(1,length(x)),'k'); % stampo l'asse x
plot(zero,0,'or'); % stampo il punto corrispondente allo zero trovato dal metodo di bisezione
axis equal
