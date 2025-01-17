function initialize_data_information(dataList,dataNumbers)
% INITIALIZE_DATA_INFORMATION(DATALIST,DATANUMBERS)


%   Copyright 1995-2003 The MathWorks, Inc.
%   $Revision: 1.43.4.5.2.1 $  $Date: 2004/04/13 03:12:39 $


	global gDataInfo

	%%%% WISH: revamp the data and event numbering scheme such that we dont have to hard code
	%%%% the maximum number of machine parented data and events. machine parented data and
	%%%% events can have negative numbers.


	dataCount = length(dataList);
	gDataInfo.dataList(dataNumbers+1) = dataList;
	
	for i = 1:dataCount
		dataNumber = dataNumbers(i);
		data = dataList(i);
		[dataSizeArray,firstIndex] = sf('get',data, ...
		                                'data.parsedInfo.array.size', ...
		                                'data.parsedInfo.array.firstIndex');

		gDataInfo.dataSizeArrays{dataNumber+1}  =  dataSizeArray;

		[gDataInfo.dataTypes{dataNumber+1}...
		,gDataInfo.sfDataTypes{dataNumber+1}...
		,gDataInfo.slDataTypes{dataNumber+1}] = data_type_conversion(data,dataSizeArray);
	end

   return;

function [cDataType,...
          sfDataType,...
          slDataType] = data_type_conversion( data,dataSizeArray)
%
%

	global gTargetInfo
	cDataType = 'real_T';
	sfDataType	= 'SF_DOUBLE';
	slDataType = 'SS_DOUBLE';
	[dataShortName,...
	 dataParent,...
	 dataScope,...
	 initialValue,...
	 initFromWS] = sf('get',data,'data.name'...
	                            ,'data.linkNode.parent'...
	                            ,'data.scope'...
	                            ,'data.parsedInfo.initialValue'...
	                            ,'data.initFromWorkspace');
	coderDataType = sf('CoderDataType',data);	
	%%WISH: temporary
	if(strcmp(coderDataType,'fixpt'))
		coderDataType = sf('FixPtProps',data);
	end
	
	cDataType = c_type_from_sf_type(coderDataType);
	sfDataType= sf_type_enum_from_name(coderDataType);
	slDataType= sl_type_enum_from_name(coderDataType);
	
	isMachineData = is_machine_data(data);

	[dataSizeArray,firstIndex] = sf('get',data,'data.parsedInfo.array.size','data.parsedInfo.array.firstIndex');
	if(length(dataSizeArray)>2 & ~isMachineData & initFromWS) 
		construct_coder_error(data,'Multidimensional arrays not allowed as chart workspace data',1);
	end
	if(initFromWS & ~gTargetInfo.codingSFunction) 
		if(isMachineData | ~gTargetInfo.codingRTW)
			try,
				initialValue = sf_evalin_base(dataShortName);
			catch,
				errorStr = sprintf('Error evaluating %s (#%d) in base workspace for data initialization',dataShortName,data);
				construct_coder_error(data,errorStr,1);
			end
		else
			initialValue = 0; % dummy value. we dont really need it
		end
		if(length(initialValue)==1)
			% scalar variable initializing a vector data item
		elseif(length(dataSizeArray)==1 & length(initialValue(:))==dataSizeArray(1))
		elseif (isequal(size(initialValue),dataSizeArray))
		else
			errorStr = sprintf('Workspace data %s must be initialized from either a scalar or vector of same dimensions',dataShortName);
			construct_coder_error(data,errorStr,1);				
		end	
		sf('set',data,'data.unique.initValue',initialValue);
	elseif(~initFromWS)
		initValue = sf('get',data,'data.parsed.initialValue');
		sf('set',data,'data.unique.initValue',initValue);		
	else
		sf('set',data,'data.unique.initValue',[]);	
	end
	
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 function isMachineData = is_machine_data(data)

	if(~isempty(sf('get',sf('get',data,'data.linkNode.parent'),'machine.id')))
		isMachineData = 1;
	else
		isMachineData = 0;
	end


