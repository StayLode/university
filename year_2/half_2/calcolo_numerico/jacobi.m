function [xcorr, k] = jacobi(A, b, xcorr, tol, Nmax)

d = diag(A);
A1 = -(tril(A,-1)+triu(A,1)); %--> E+F

for k = 0:Nmax
    %Calcolo quantità per i criteri d'arresto
    res=b-A*xcorr;

    xnew = (A1*xcorr+b)./d;
    dist = xnew-xcorr;

    if dist<tol*norm(b) & norm(dist)<tol*norm(xnew)
        break
    end
    xcorr=xnew;
end
