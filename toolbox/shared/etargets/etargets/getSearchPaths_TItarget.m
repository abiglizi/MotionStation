function searchPaths = getSearchPaths_TItarget()
% Returns list of directories in which to search for
% source files that are to be included in the generated CCS project.

% $RCSfile: getSearchPaths_TItarget.m,v $
% $Revision: 1.1.6.2 $ $Date: 2004/04/08 21:08:02 $
% Copyright 2001-2003 The MathWorks, Inc.

if exist('tmpTiMatlabRoot.m','file'),
    mlroot_ti_tmp = tmpTiMatlabRoot;
else
    mlroot_ti_tmp = matlabroot;
end


searchPaths = {pwd, ...
                [mlroot_ti_tmp '\toolbox\rtw\targets\tic6000\tic6000\rtlib'], ...
                [mlroot_ti_tmp '\toolbox\rtw\targets\tic6000\tic6000\src'], ...
                [matlabroot '\rtw\c\src'], ...
                [matlabroot '\rtw\c\libsrc'], ...
                [matlabroot '\toolbox\comm\commshr\src\legacy'], ...
                [matlabroot '\toolbox\commblks\sim\sfun'], ...
                [matlabroot '\toolbox\commblks\sim\src\legacy'], ...
                [matlabroot '\toolbox\fixpoint'], ...
                [matlabroot '\toolbox\fuzzy\fuzzy\src'], ...
                [matlabroot '\simulink\src']};

% [EOF] getSearchPaths_TItarget.m
