function boo = isvisible(this)
%ISVISIBLE  Determines actual visibility of dataview object(s).

%  Copyright 1986-2004 The MathWorks, Inc.
%  $Revision: 1.1.6.2 $ $Date: 2004/04/11 00:27:03 $

% Vectorized
boo = strcmp(this.Visible,'on') & this(1).Parent.isvisible;
