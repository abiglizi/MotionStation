function enableMenus(this)

%   Copyright 1996-2003 The MathWorks, Inc.
%   $Revision: 1.1.6.2 $  $Date: 2004/02/01 21:56:36 $

selectAllMenu = findall(this.EditMenu,'Tag','select all');
set(selectAllMenu,'Enable','on');

