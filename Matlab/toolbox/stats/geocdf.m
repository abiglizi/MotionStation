function y = geocdf(x,p)
%GEOCDF Geometric cumulative distribution function.
%   Y = GEOCDF(X,P) returns the cdf of the geometric distribution with
%   probability parameter P, evaluated at the values in X.  The size of Y
%   is the common size of the input arguments.  A scalar input functions as
%   a constant matrix of the same size as the other input.
%
%   See also CDF, GEOINV, GEOPDF, GEORND, GEOSTAT.

%   References:
%      [1] Abramowitz, M. and Stegun, I.A. (1964) Handbook of Mathematical
%          Functions, Dover, New York, 1046pp., sec. 26.1.24.
%      [2] Evans, M., Hastings, N., and Peacock, B. (1993) Statistical
%          Distributions, 2nd ed., Wiley, 170pp.

%   Copyright 1993-2004 The MathWorks, Inc. 
%   $Revision: 2.10.4.2 $  $Date: 2004/01/16 20:09:20 $

if nargin < 2
    error('stats:geocdf:TooFewInputs','Requires two input arguments.');
end

% Return NaN for out of range parameters.
p(p <= 0 | 1 < p) = NaN;

% Force a zero for negative x.
x(x < 0) = -1;

if ~isfloat(x)
   x = double(x);
end

try
    y = 1 - (1 - p) .^ (floor(x) + 1);
catch
    error('stats:geocdf:InputSizeMismatch',...
          'Non-scalar arguments must match in size.');
end
