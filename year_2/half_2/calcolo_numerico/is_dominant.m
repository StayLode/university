function [s, y] = is_dominant (A)

n=length(A);


y=true;
for i=1:n 
    s=0;
    for j=1:n
        s = s+A(i,j);
    end
    if(s-A(i,i)>=A(i,i))
       y=false;
       break;
    end
end

