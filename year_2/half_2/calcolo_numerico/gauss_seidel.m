function [x,k] = gauss_seidel(A, b, xcorr, tol, Nmax)

D_E = tril(A);  %--> D-E
F = -triu(A,1); %--> F

for k = 0:Nmax
    %Calcolo quantità per i criteri d'arresto
    res=b-A*xcorr;

    xnew = (F/D_E)*xcorr+b/D_E;
    dist = xnew-xcorr;

    if norm(res)<tol*norm(b) & norm(dist)<tol*norm(xnew)
        break
    end
    xcorr=xnew;
end
