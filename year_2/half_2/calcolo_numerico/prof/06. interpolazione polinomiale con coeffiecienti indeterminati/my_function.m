function y = my_function(x)
%y = 2*x + 3/4;
%y = - x.^2 + 3*x - 2;   % in [-1,1.8]
%y = sin(x) - (x/2).^2;  % in [1,2]
%y = exp(-x+1) - 0.012;  % in [0,10]
y = 9*x.^2 .* sin(6*x) ./ (3*x + 4);   % in [-1,1]
%y = 1./(1 + 25*x.^2);   % in [-1,1]