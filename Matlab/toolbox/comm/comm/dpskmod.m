function y = dpskmod(x,M,varargin)
% DPSKMOD Differential phase shift keying modulation.
%   Y = DPSKMOD(X,M) outputs the complex envelope of the modulation of the
%   message signal X using differential phase shift keying modulation.  M
%   is the alphabet size and must be an integer. The message signal must
%   consist of integers between 0 and M-1. For two-dimensional signals, the
%   function treats each column as 1 channel.
%
%   Y = DPSKMOD(X,M,PHASEROT) specifies the phase rotation (rad) of the
%   modulation. In this case, the total per-symbol phase shift is the sum
%   of PHASEROT and the phase generated by the differential modulation.
%
%   See also DPSKDEMOD, PSKMOD, PSKDEMOD.

%    Copyright 1996-2003 The MathWorks, Inc. 
%    $Revision: 1.1.6.1 $  $Date: 2003/02/14 20:50:28 $ 

% error checks
if(nargin>3)
    error('comm:dpskmod:numarg','Too many input arguments.');
end

%Check x, phaserot
if ( ~isreal(x) || any(any(ceil(x)~=x)) || ~isnumeric(x) ) 
    error('comm:dpskmod:Xreal','Elements of input X must be integers in [0, M-1].');
end

if(~isreal(M) || ~isscalar(M) || M<=0 || (ceil(M)~=M) || ~isnumeric(M) )
    error('comm:dpskmod:Mreal','M must be a positive integer.');
end

% check that X are all integers within range.
if (min(min(x)) < 0)  || (max(max(x)) > (M-1))
    error('comm:dpskmod:Xreal','Elements of input X must be integers in [0, M-1].');
end

if(nargin==3)
    Phase_Rotation = varargin{1};
    if(isempty(Phase_Rotation))
        Phase_Rotation = 0;
    elseif(~isreal(Phase_Rotation) || ~isscalar(Phase_Rotation) || ~isnumeric(Phase_Rotation) )
        error('comm:dpskmod:phaserotreal','PHASEROT must be a real scalar.');
    end
else 
    Phase_Rotation = 0;
end

% --- Assure that X, if one dimensional, has the correct orientation --- %
wid = size(x,1);
if(wid ==1)
    x = x(:);
end

% create a vector for the output.
y = zeros(size(x));

y(1,:) = exp(j*Phase_Rotation + j*2*pi*x(1,:)/M);

for(i=2:size(y,1))
     y(i,:) = y(i-1,:) .*exp(j*Phase_Rotation + j*2*pi*x(i,:)/M);
end


% --- restore the output signal to the original orientation --- %
if(wid == 1)
    y = y.';
end

% EOF
