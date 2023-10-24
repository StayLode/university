function x=diagonal_solver(D,b)
if(isdiag(D)==false)
    error("D non è diagonale!");
end

 

%{
 a = vettore riga (1xn)
 b = vettore colonna (nx1)
 a*b = c --> scalare (1x1)
 b*a = M --> matrice (nxn)
 d = vettore colonna (nx1)
 visto che b e d hanno stessa dimensione si può usare la notazione
 puntuale
 b.*d = h --> vettore colonna (nx1)
 hi = bi*di --> ovvero il prodotto di ogni coppia di elementi
 
 d=diag(D) ==> se D è una matrice diagonale, d diventa un vettore colonna
 costituito dagli elementi della diagonale principale di D
%}

%{
METODO C ==> NON VA BENE ALL'ESAME IN QUESTO CASO

n=length(b);
x=zeros(n,1);

for i=1:n
    x(i)=b(i)/D(i,i);
end
%}

%METODO MATLAB ==> utilizzo operatori puntuali
d = diag(D);
x = b ./ d;


