function [s,x,y] = dspblktri(fcn)

% Setup port label structure:

% Copyright 1995-2002 The MathWorks, Inc.
% $Revision: 1.6 $
switch(fcn)
   case 1,
   % Upper
	   x = [.87 .87 .58 .87 NaN 0.12 0.45 0.45 0.12 0.12 NaN 0.525 0.525 0.475 0.475 0.525 0.525 0.565 0.525 ];
		y = [0.2 0.8 0.8 0.2 NaN 0.2 0.2 0.8 0.8 0.2 NaN 0.435 0.475 0.475 0.525 0.525 0.565 0.5 0.435];
      s = 'U';
   case 2,
      % Lower:
      x = [.58 .87 .58 .58 NaN 0.12 0.45 0.45 0.12 0.12 NaN 0.525 0.525 0.475 0.475 0.525 0.525 0.565 0.525 ];
      y = [0.2 0.2 0.8 0.2 NaN 0.2 0.2 0.8 0.8 0.2 NaN 0.435 0.475 0.475 0.525 0.525 0.565 0.5 0.435];
      s = 'L';
end
