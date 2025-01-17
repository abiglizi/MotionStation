function addpar(this,Name,Nominal)
% Adds parameter to grid.

%   $Revision: 1.1.6.2 $ $Date: 2004/02/06 00:40:49 $
%   Copyright 1986-2004 The MathWorks, Inc.
aNom = abs(Nominal) + (Nominal==0);
this.Parameters = [this.Parameters ; struct(...
   'Name',Name,...
   'Nominal',mat2str(Nominal,4),...
   'Min',mat2str(Nominal-0.1*aNom,4),...
   'Max',mat2str(Nominal+0.1*aNom,4))];
