function result = sf_evalin_base(varName,rowOrColumn,chart)


%   Copyright 1995-2002 The MathWorks, Inc.
%   $Revision: 1.6.16.1 $  $Date: 2004/04/13 03:12:39 $
	if(nargin<3)
		chart = 0;
	end
	result = [];
	try,
		if(~chart)
			value = evalin('base',varName);
		else
			blockH = sf('Private','chart2block',chart);
			chartBlockPath = getfullname(blockH);
			value = slResolve(varName,chartBlockPath);
		end
	catch,
		error(sprintf('%s not defined in MATLAB workspace',varName)); 
	end
	if(isa(value,'Simulink.Parameter'))
		result = value.Value;
	else
		result = value;
	end
	% cast it to double as MATLABs functions
    % such as sprintf and floor croak on non-doubles
	result = double(result);

	 if(nargin>1)
	     switch(rowOrColumn)
	     case 'row'
	         result = result(:)';
	     case 'column'
	         result = result(:);
	     case ''
	     		% do nothing
	     end
	 end
