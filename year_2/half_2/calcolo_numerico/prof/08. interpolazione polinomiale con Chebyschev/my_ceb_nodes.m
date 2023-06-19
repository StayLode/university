% genera n nodi di Cebichev nell'intervallo [a,b]
function t = my_ceb_nodes(a,b,n)
% creare i nodi di Cebichev in [-1,1]
%t = zeros(n,1);
%for i = 1 : n
%    t(i) = cos( (2 * (i-1) +1) * pi / (2*n) );
%end
t = cos( (2*(0:n-1) +1) * pi / (2*n) ); % equivalente al ciclo precedente
t = (b-a)/2 * t + (a+b)/2; % trasposrta i nodi di Cebichev nell'intervallo [a,b]
t = t'; % rende t un vettore colonna