function V=vandermonde(x)

n=length(x);
V=ones(n);

for j=2:n 
    V(:,j)=V(:,j-1) .* x; %=x+^(j-1) --> è più costosa
end