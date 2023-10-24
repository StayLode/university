function [p,alpha] = coeff_indeterminati(x,y,v)
V = vandermonde(x);
alpha = V\y;
p = polyval(alpha(end:-1:1),v);
