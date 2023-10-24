function [c]=my_regula(a,b,f,t, Kmax)

fa=feval(f,a);
fb=feval(f,b);

for k = 1:Kmax
    c=(-fb)/((fb-fa)/b-a)+b;
    fc=feval(f,c);
    
    if fc == 0
        return
    end 
    if norm(fc)<t %Non so come aggiungere la c precedente per controllare 
        return 
    end
    if fa*fc<0
        b=c;
        fb=fc;
    else
        a=c;
        fa=fc;
    end

end