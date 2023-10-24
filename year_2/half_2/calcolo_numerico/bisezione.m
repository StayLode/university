function c = bisezione(a,b,t,func_name)

n = ceil(log2((b-a)/t));
fa=feval(func_name, a);
fb=feval(func_name,b);

if( fa * fb >= 0 ) 
    error("la funzione non cambia segno agli estemi dell'intervallo [a,b]");
end

for i=1:n
    c=a+(b-a)/2;
    fc=feval(func_name,c);
    if fc == 0
        return
    end
    if (fc*fb)<0
        a=c;
        fa=fc;
    else
        b=c;
        fb=fc;
    end
end
