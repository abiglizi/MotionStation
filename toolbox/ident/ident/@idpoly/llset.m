function ms = llset(m,field,value)
%LLSET  obsolete function

%   Copyright 1986-2001 The MathWorks, Inc.
%   $Revision: 1.7 $  $Date: 2001/04/06 14:22:19 $

ms=m;
for kk=1:length(field)
 eval(['ms.',field{kk},'=','value{kk};']);
end
