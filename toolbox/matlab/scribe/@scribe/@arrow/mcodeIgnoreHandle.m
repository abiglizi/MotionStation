function res = mcodeIgnoreHandle(this,h)
%MCODEIGNOREHANDLE Code generation customization

%   Copyright 1984-2003 The MathWorks, Inc. 

if isequal(double(this),double(h))
    res = false;
else
    res = true;
end

