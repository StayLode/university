function [xcorr, k] = jacobi(xcorr, A, b, t, N)

d=diag(A);
A1=tril(A,-1)+triu(A,1);

for k=0:N
    r=b-A*xcorr;
    xnew=(b-(A1*xcorr))./d;

    if(norm(xnew-xcorr)/norm(xnew))<t & (norm(r)/norm(b))<t
        return 
    end
    xcorr=xnew;
end