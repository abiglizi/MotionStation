function code_chart_header_file(fileNameInfo,...
										  chart)


%   Copyright 1995-2002 The MathWorks, Inc.
%   $Revision: 1.51.2.2.4.1 $  $Date: 2004/04/13 03:12:38 $

	
	global gTargetInfo
    
   if(gTargetInfo.codingSFunction)
      code_chart_header_file_sfun(fileNameInfo,chart);
   elseif(gTargetInfo.codingRTW)
        code_chart_header_file__rtw(fileNameInfo,chart);
   else
      code_chart_header_file_custom(fileNameInfo,chart);   
	end

