function hlabel = hglabel(h,LabelType)
%HGLABEL  Returns handle(s) of visible HG labels of a given type.

%   Copyright 1986-2004 The MathWorks, Inc.
%   $Revision: 1.1.6.2 $ $Date: 2004/04/11 00:17:32 $
hlabel = get(h.Axes2d,LabelType);
hlabel = cat(1,hlabel{:});
