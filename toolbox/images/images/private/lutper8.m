function lut = lutper8
%LUTPER8 Compute "perim8" look-up table.

%   Copyright 1993-2003 The MathWorks, Inc.  
%   $Revision: 1.10.4.2 $  $Date: 2003/08/23 05:54:05 $

lut = [ ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     0     0     0     0     1     1     1     1     1     1     1     1 ...
     1     1     1     1     1     1     1     1     0     0     0     0 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     1     1     1     1     0     0     0     0     0     0     0     0 ...
     0     0     0     0     0     0     0     0     1     1     1     1 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     0     0     0     0     1     1     1     1     1     1     1     1 ...
     1     1     1     1     1     1     1     1     0     0     0     0 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     1     1     1     1     0     0     0     0     0     0     0     0 ...
     0     0     0     0     0     0     0     0     1     1     1     1 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     0     0     0     0     1     1     1     1     1     1     1     1 ...
     1     1     1     1     1     1     1     1     0     0     0     0 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     1     1     1     1     0     0     0     0     0     0     0     0 ...
     0     0     0     0     0     0     0     0     1     1     1     1 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     0     0     0     0     1     1     1     1     1     1     1     1 ...
     1     1     1     1     1     1     1     1     0     0     0     0 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     1     1     1     1     0     0     0     0     0     0     0     0 ...
     0     0     0     0     0     0     0     0     1     1     1     1 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     0     0     0     0     1     1     1     1     1     1     1     1 ...
     1     1     1     1     1     1     1     1     0     0     0     0 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     1     1     1     1     0     0     0     0     0     0     0     0 ...
     0     0     0     0     0     0     0     0     1     1     1     1 ...
     1     1     1     1     1     1     1     1     1     1     1     1 ...
     0     0     0     0     0     0     0     0     0     0     0     0 ...
     0     0     0     0     1     1     1     1     1     1     1     1 ...
     1     1     1     1     1     1     1     0];

lut = lut(:);
