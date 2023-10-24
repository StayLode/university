x = linspace(-1,1,30)';
y = my_function(x);

V = my_vandermonde(x);
[L,U,P]=my_lupiv_dec(V);

csi=my_ltri_sol(L,P*y);
alpha=my_utri_sol(U,csi);

plot(x,y, 'or');
hold on;


x_plot=linspace(-1,1,1000);
y_plot=polyval(alpha(end:-1:1),x_plot);

plot(x_plot,y_plot,'g');

