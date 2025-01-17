function sf_echo_generating( componentName, fullFileName, printFullPath)

%   Copyright 1995-2003 The MathWorks, Inc.
%   $Revision: 1.9.2.2.4.1 $  $Date: 2004/04/13 03:12:39 $

	if(nargin<3)
		printFullPath = 0;
	end
  % Note: Need the extra space at the end of the display line so that
  %       the hyperlink hand is termintated correctly when moving to
  %       the right of the hyperlinked diagnostic line.
	[filePath,fileName,fileExt] = fileparts(fullFileName);
	if(printFullPath==0)
		sf('Private','sf_display',componentName,sprintf('     "%s%s"',fileName,fileExt));
	else
		sf('Private','sf_display',componentName,sprintf('     "%s"',fullFileName));
	end

	% delete the corresponding object file as
	% in order to get around gmake bugs with timestamp
	% checking on fast glnx machines G124842
	if(ispc)
		objFile = fullfile(filePath,[fileName,'.obj']);
	else
		objFile = fullfile(filePath,[fileName,'.o']);
	end
	if(exist(objFile,'file'))
        [prevErrMsg, prevErrId] = lasterr;
        [prevWarnMsg, prevWarnId] = lastwarn;
        warnFlag = warning;
        warning('off');
        try,
			sf('Private', 'sf_delete_file', objFile);
        catch,
            lasterr(prevErrMsg, prevErrId);
        end
        lastwarn(prevWarnMsg, prevWarnId);
        warning(warnFlag);
	end
	return;
