function fileNameInfo = create_file_name_info
% FILENAMEINFO = CREATE_FILE_NAME_INFO

%   Copyright 1995-2004 The MathWorks, Inc.
%   $Revision: 1.29.2.11.2.1 $  $Date: 2004/04/13 03:12:39 $

	global gMachineInfo gTargetInfo

	%% root directory determination: get the model of the parentTarget
	%% get the filename property of the model which will give you
	%% model directory. this dir will be used for constructing abs path
	%% from relative paths in user source files, user incl dirs etc.

	parentTargetMachine = sf('get',gMachineInfo.parentTarget,'target.machine');
   modelH = sf('get',parentTargetMachine,'machine.simulinkModel');
   machineFullName = get_param(modelH,'filename');
   currentDirPath = pwd;

   if(isempty(machineFullName))
   	rootDirectory = currentDirPath;
   else
		% extract rootDirectory from machine's full name
		lastFileSep = max(find(machineFullName==filesep));
		if(~isempty(lastFileSep))
			rootDirectory = machineFullName(1:lastFileSep-1);
		else
			% machine full name does not have dir info, so it is a new machine
			rootDirectory = currentDirPath;
		end
   end

	baseName = [gMachineInfo.machineName,'_',gMachineInfo.targetName];
	if(gTargetInfo.codingRTW | gTargetInfo.codingSFunction)
   	fileNameInfo.mexFunctionName = baseName;
		fileNameInfo.sfDirName = fullfile(fullfile(pwd,'sfprj'),'build');
		fileNameInfo.machineDirName = fullfile(fileNameInfo.sfDirName,gMachineInfo.machineName);
		fileNameInfo.targetDirName = fullfile(fileNameInfo.machineDirName,gMachineInfo.targetName,'src');
		[dirName, success, errorCreateMsg] = sf('Private','create_directory_path',pwd,'sfprj','build',gMachineInfo.machineName,gMachineInfo.targetName,'src');
		if(~success)
            construct_dir_path_error(dirName,errorCreateMsg);
        end
		fileNameInfo.dllDirFromMakeDir = '..\..\..\..\..\';
	elseif(gTargetInfo.codingMEX)
		fileNameInfo.sfDirName = pwd;
		fileNameInfo.machineDirName = fileNameInfo.sfDirName;
		fileNameInfo.targetDirName = fileNameInfo.sfDirName;
		fileNameInfo.dllDirFromMakeDir = '.\';
	else
		codegenDir = sf('get',gMachineInfo.parentTarget,'target.codegenDirectory');
		if(isempty(codegenDir))
			fileNameInfo.sfDirName = fullfile(fullfile(pwd,'sfprj'),'build');
			fileNameInfo.machineDirName = fullfile(fileNameInfo.sfDirName,gMachineInfo.machineName);
			fileNameInfo.targetDirName = fullfile(fileNameInfo.machineDirName,gMachineInfo.targetName,'src');
			[dirName,success, errorCreateMsg] = sf('Private','create_directory_path',pwd,'sfprj','build',gMachineInfo.machineName,gMachineInfo.targetName,'src');
            if(~success)
                construct_dir_path_error(dirName,errorCreateMsg);
            end            
			fileNameInfo.dllDirFromMakeDir = '..\..\..\..\..\';
		else
			[codegenDir,errorStr] = sf('Private','tokenize',rootDirectory,codegenDir,'Code generation directory string');
			if(~isempty(errorStr))
				construct_coder_error(gMachineInfo.parentTarget,errorStr);
			end
			codegenDir = codegenDir{1};
			fileNameInfo.sfDirName = codegenDir;
			fileNameInfo.machineDirName = fileNameInfo.sfDirName;
			fileNameInfo.targetDirName = fileNameInfo.sfDirName;
			fileNameInfo.dllDirFromMakeDir = '.\';
		end
	end
   if(sf('Private','testing_stateflow_in_bat'))
       % make sure we are generating code in
       % MATLAB directories
       if(~isempty(findstr(lower(fileNameInfo.targetDirName),lower(matlabroot))))
           construct_coder_error([],'Code generation in MATLAB directories during Stateflow testing is prohibited.',1);
       end
   end

	if gTargetInfo.codingRTW
		fileNameInfo.headerExtension = '.tlh';
		fileNameInfo.sourceExtension = '.tlc';
	else
		fileNameInfo.headerExtension = '.h';
		fileNameInfo.sourceExtension = '.c';
	end
	if(gTargetInfo.codingSFunction)
		fileNameInfo.machineRegistryFile = [baseName,'_registry',fileNameInfo.sourceExtension];
	end

	if(gTargetInfo.codingDebug)
		fileNameInfo.sfDebugMacrosFile = [baseName,'_debug_macros',fileNameInfo.headerExtension];
	end
	fileNameInfo.machineHeaderFile = [baseName,fileNameInfo.headerExtension];
	fileNameInfo.machineSourceFile = [baseName,fileNameInfo.sourceExtension];
	fileNameInfo.chartHeaderFiles = cell(1,length(gMachineInfo.charts));
	fileNameInfo.chartSourceFiles = cell(1,length(gMachineInfo.charts));
	if gTargetInfo.codingRTW
		machineSourceFile = fileNameInfo.machineSourceFile;
		sf('set',gMachineInfo.machineId,'machine.rtwInfo.machineTLCFile',machineSourceFile(1:end-length(fileNameInfo.sourceExtension)));
	end
	for chart = gMachineInfo.charts
		chartNumber = sf('get',chart,'chart.number');
		chartUniqueName = sf('CodegenNameOf',chart);
		fileNameInfo.chartUniqueNames{chartNumber+1} = chartUniqueName;
		fileNameInfo.chartHeaderFiles{chartNumber+1} = [chartUniqueName,fileNameInfo.headerExtension];
		fileNameInfo.chartSourceFiles{chartNumber+1} = [chartUniqueName,fileNameInfo.sourceExtension];
		if(gTargetInfo.codingRTW)
			chartSourceFile = fileNameInfo.chartSourceFiles{chartNumber+1};
			sf('set',chart,'chart.rtwInfo.chartTLCFile',chartSourceFile(1:end-length(fileNameInfo.sourceExtension)));
			% G120999: Prepend chartUnqiueName by CS in order to differentiate the
			% first 31 chars of the typedef and the chart during function in case they
			% get truncated.
			chartInstanceStructName = ['CS',chartUniqueName,'_ChartStruct'];
			if(length(chartInstanceStructName)>31)
				chartInstanceStructName = chartInstanceStructName(1:31);
			end
			sf('set',chart,'chart.rtwInfo.chartInstanceTypedef',chartInstanceStructName);
			sf('set',chart,'chart.rtwInfo.chartOutputsFcn',['sf_',chartUniqueName]);
		end
 		if gTargetInfo.codingRTW | gTargetInfo.codingMEX
			sf('set',chart,'chart.rtwInfo.chartInitializeFcn',['initialize_',chartUniqueName]);
		end

	end

	compilerInfo = sf('Private','compilerman','get_compiler_info');

	fileNameInfo.mexOptsFile = compilerInfo.mexOptsFile;
	fileNameInfo.matlabRoot = sf('Private','sf_get_component_root','matlab');

	if(gTargetInfo.codingSFunction)
		fileNameInfo.makeBatchFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.bat'];
		fileNameInfo.msvcMakeFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.mak'];
		fileNameInfo.msvc50MakeFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.dsp'];
		fileNameInfo.msvc50dswFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.dsw'];
		fileNameInfo.machineDefFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.def'];
		fileNameInfo.SFunctionName = [gMachineInfo.machineName,'_',gMachineInfo.targetName];
		fileNameInfo.msvcMakeFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.mak'];
		fileNameInfo.unixMakeFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.mku'];
		fileNameInfo.watcomMakeFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.wmk'];
		fileNameInfo.borlandMakeFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.bmk'];
		fileNameInfo.lccMakeFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.lmk'];
		fileNameInfo.machineObjListFile = [gMachineInfo.machineName,'_',gMachineInfo.targetName,'.mol'];
   end
   if (~gTargetInfo.codingRTW)
      fileNameInfo.sfcMexLibInclude = fullfile(fileNameInfo.matlabRoot,'stateflow','c','mex','include');
      fileNameInfo.sfcMexLibLib = fullfile(fileNameInfo.matlabRoot,'stateflow','c','mex','lib');
      fileNameInfo.sfcDebugLibInclude = fullfile(fileNameInfo.matlabRoot,'stateflow','c','debugger','include');
      fileNameInfo.sfcDebugLibLib = fullfile(fileNameInfo.matlabRoot,'stateflow','c','debugger','lib');
      fileNameInfo.dspLibInclude = fullfile(fileNameInfo.matlabRoot,'toolbox','eml','lib','dsp');
      fileNameInfo.dspLibLib = fullfile(fileNameInfo.matlabRoot,'toolbox','dspblks','lib');
      archName = lower(computer);
      fileNameInfo.archName = '';
      if(strcmp(archName,'pcwin'))
         fileNameInfo.archName = 'win32';
      else
         if(exist(fullfile(fileNameInfo.sfcMexLibLib,archName),'dir'))
            fileNameInfo.archName = archName;
         end
      end
      if(~isempty(fileNameInfo.archName))
         fileNameInfo.dspLibLib = fullfile(fileNameInfo.dspLibLib,fileNameInfo.archName);
         fileNameInfo.sfcMexLibLib = fullfile(fileNameInfo.sfcMexLibLib,fileNameInfo.archName);
         fileNameInfo.sfcDebugLibLib = fullfile(fileNameInfo.sfcDebugLibLib,fileNameInfo.archName);
      end


      switch computer
      case 'PCWIN'
         switch compilerInfo.compilerName
         case 'lcc'
            libSuffix = 'lcc';
            dbgLib = 'sfc_debuglcc.lib';
            mexLib = 'sfc_mexlcc.lib';
            dspLib = 'dsp_dyn_rt_lcc.lib';
         case { 'msvc71'}
            dbgLib = 'sfc_debugmsvc71.lib';
            mexLib = 'sfc_mexmsvc71.lib';
            dspLib = 'dsp_dyn_rt_vc.lib';
         case { 'msvc50', 'msvc4x' }
            dbgLib = 'sfc_debugmsvc.lib';
            mexLib = 'sfc_mexmsvc.lib';
            dspLib = 'dsp_dyn_rt_vc.lib';
         case 'borland'
            dbgLib = 'sfc_debugbor.lib';
            mexLib = 'sfc_mexbor.lib';
            dspLib = 'dsp_dyn_rt_bc50.lib';
         case 'watcom'
            dbgLib = 'sfc_debugwat.lib';
            mexLib = 'sfc_mexwat.lib';
            dspLib = 'dsp_dyn_rt_watc106.lib';
         otherwise
            error('unexpected compiler');
         end
      otherwise
         dbgLib = 'sfc_debug.a';
         mexLib = 'sfc_mex.a';
         dspLib = 'dsp_sim_rt.a';
      end

      fileNameInfo.sfcMexLibFile = fullfile(fileNameInfo.sfcMexLibLib,mexLib);
      fileNameInfo.sfcDebugLibFile = fullfile(fileNameInfo.sfcDebugLibLib,dbgLib);
      fileNameInfo.dspLibFile = fullfile(fileNameInfo.dspLibLib,dspLib);

     if (~exist(fileNameInfo.dspLibInclude, 'dir') |...
         ~exist(fileNameInfo.dspLibLib, 'dir') |...
         ~exist(fileNameInfo.dspLibFile, 'file'))
        fileNameInfo.dspLibInclude ='';
        fileNameInfo.dspLibLib ='';
        fileNameInfo.dspLibFile ='';
     end
   else
      fileNameInfo.rtwDspLibInclude = fullfile(fileNameInfo.matlabRoot,'toolbox','eml','lib','dsp');
      fileNameInfo.rtwDspLibIncludeFileName = 'template_support_fcn_list.h';
   end


	%%% IMPORTANT: We use include directory paths as search paths for
	%%% source files (G85817). Hence, we must tokenize includeDirs before
	%%% user sources
	[fileNameInfo.userIncludeDirs,errorStr] = ...
         sf('Private','tokenize'...
                     ,rootDirectory...
                     ,sf('get',gMachineInfo.parentTarget,'target.userIncludeDirs')...
                     ,'custom include directory paths string'...
                     ,{});
	if(~isempty(errorStr))
		construct_coder_error(gMachineInfo.parentTarget,errorStr);
	end
	fileNameInfo.userIncludeDirs = [ ...
	     {fileNameInfo.targetDirName},{currentDirPath}, {rootDirectory} ...
	    ,fileNameInfo.userIncludeDirs];
	fileNameInfo.userIncludeDirs = ordered_unique_paths(fileNameInfo.userIncludeDirs);

	searchDirectories = sf('Private','tokenize','',path);
    if(ispc)
	    filterIndices = strncmp(lower(searchDirectories),lower(matlabroot),length(matlabroot));
    else
	    filterIndices = strncmp(searchDirectories,matlabroot,length(matlabroot));
    end
	searchDirectories(filterIndices) = [];
	searchDirectories = [fileNameInfo.userIncludeDirs,searchDirectories];
	searchDirectories = ordered_unique_paths(searchDirectories);

    customCodeString = sf('get',gMachineInfo.parentTarget,'target.customCode');
    if(~isempty(customCodeString))
        % If there is custom code, include MATLAB's search path in it
        % as it may be including files in these directories
        customCodeIncDirs = extract_relevant_dirs(rootDirectory,searchDirectories,customCodeString);
    else
        customCodeIncDirs = {};
    end
    fileNameInfo.userIncludeDirs = [fileNameInfo.userIncludeDirs,customCodeIncDirs];
	fileNameInfo.userIncludeDirs = ordered_unique_paths(fileNameInfo.userIncludeDirs);

	if(gTargetInfo.codingLibrary & gMachineInfo.parentTarget~=gMachineInfo.target)
		fileNameInfo.userSources = {};
	else
		[fileNameInfo.userSources,errorStr] = ...
         sf('Private','tokenize'...
                     ,rootDirectory...
                     ,sf('get',gMachineInfo.parentTarget,'target.userSources')...
                     ,'custom source files string'...
                     ,searchDirectories);
		if(~isempty(errorStr))
			construct_coder_error(gMachineInfo.parentTarget,errorStr);
		end
	end

	if(gTargetInfo.codingLibrary & gMachineInfo.parentTarget~=gMachineInfo.target)
		fileNameInfo.userLibraries = {};
	else
		[fileNameInfo.userLibraries,errorStr] = ...
         sf('Private','tokenize'...
                     ,rootDirectory...
                     ,sf('get',gMachineInfo.parentTarget,'target.userLibraries')...
                     ,'custom libraries string'...
                     ,searchDirectories);
		if(~isempty(errorStr))
			construct_coder_error(gMachineInfo.parentTarget,errorStr);
		end
	end

	[fileNameInfo.userMakefiles,errorStr] = ...
         sf('Private','tokenize'...
                     ,rootDirectory...
                     ,sf('get',gMachineInfo.parentTarget,'target.userMakefiles')...
                     ,'custom makefiles string'...
                     ,searchDirectories);
	if(~isempty(errorStr))
		construct_coder_error(gMachineInfo.parentTarget,errorStr);
	end
	fileNameInfo.userAbsSources = {};
	fileNameInfo.userAbsPaths = {};
	for i=1:length(fileNameInfo.userSources)
	  [fileNameInfo.userAbsPaths{i}...
     ,fileNameInfo.userAbsSources{i}...
     ,fileNameInfo.userSources{i}] = ...
         sf('Private','strip_path_from_name',fileNameInfo.userSources{i});
	end

	% get rid of duplicate paths preserving the order
	fileNameInfo.userAbsPaths = ordered_unique_paths(fileNameInfo.userAbsPaths);
	fileNameInfo.userIncludeDirs = [fileNameInfo.userIncludeDirs ...
	    ,fileNameInfo.userAbsPaths];
	fileNameInfo.userIncludeDirs = ordered_unique_paths(fileNameInfo.userIncludeDirs);

	fileNameInfo.linkMachines = {};
	fileNameInfo.linkMachineFullPaths = {};
	fileNameInfo.linkLibFullPaths	= {};
	fileNameInfo.linkMachinesInlinable = {};
	if(~gTargetInfo.codingLibrary)
		[fileNameInfo.linkMachines,fileNameInfo.linkMachineFullPaths,fileNameInfo.linkLibFullPaths] = sf('Private','get_link_machine_list',gMachineInfo.machineName,gMachineInfo.targetName);
		for i=1:length(fileNameInfo.linkMachines)
			infoStruct = sf('Private','infomatman','load','binary',fileNameInfo.linkMachines{i},gMachineInfo.targetName);
			fileNameInfo.linkMachinesInlinable{i} = infoStruct.machineInlinable;
		end
	end


function orderedList = ordered_unique_paths(orderedList)

  orderedList = sf('Private', 'ordered_unique_paths', orderedList);


function newSearchDirectories = extract_relevant_dirs(rootDirectory, searchDirectories, customCodeString)

  newSearchDirectories = sf('Private', 'extract_relevant_dirs', rootDirectory, searchDirectories, customCodeString);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function construct_dir_path_error(dirName,errorCreateMsg)
    errorMsg = sprintf('Unable to create directory: %s',dirName);
    errorMsg = [errorMsg,10,10,errorCreateMsg];
    sf('Private','construct_error',[], 'Build', errorMsg, 1, []);
