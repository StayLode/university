%creates n chebichev nodes between [a,b]
function t = my_ceb_nodes(a,b,n)

%t = zeros(n+1,1);
%for i = 1 : n+1
%    t(i) = cos( (2*i+1) * pi / (2*(n + 1)) );
%end

% nodi di chebychev nell'intervallo [-1:1]
t = cos( (2*(0:n-1)+1) * pi / (2*n) ); %equivalente al ciclo precedente
t = (b-a)/2 *t + (a+b)/2; %trasporta i nodi di chebiychev nell'intervallo generico [a,b]