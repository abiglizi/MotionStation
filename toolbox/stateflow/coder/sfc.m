function varargout = sfc( method, varargin)
% This is an entry point into Stateflow Code Generator
% for internal use only and not for general use.
% Help text is suppressed intentionally as
% this function is called by Stateflow internal code.
% Please refer to Stateflow API documentation for details
% on command line interface to code-generation.
%

%
%   Copyright 1995-2004 The MathWorks, Inc.
%
   if(nargin<1)
       help(mfilename);
       return;
   end
   switch(lower(method))
       case 'coder_options'
           varargout = cell(1,max(1,nargout));
           varargout{:} = coder_options(varargin{:});
           return;
       case 'private'
           if(length(varargin)<1)
               construct_coder_error([],'',1);
               return;
           end
           fcnName = varargin{1};
           inArgs = varargin(2:end);
           if(nargout>0)
               varargout = cell(1,nargout);
               [varargout{:}] = feval(fcnName,inArgs{:});
           else
               feval(fcnName,inArgs{:});
           end
           return;
       case 'revision'
           varargout{1} = '$Revision: 1.72.2.10.2.1 $  $Date: 2004/04/13 03:12:40 $';
           return;
       case 'language'
           varargout{1} = 'ANSI-C';
           return;
       case {'clean_objects','clean','code','codeincremental','codenonincremental','filenameinfo','makeinfo'}
           %WISH error check nargin
           if(length(varargin)<1)
               errorMsg = sprintf('Usage: sfc(methodName,targetId[,parentTargetId])');
               construct_coder_error([], errorMsg,1);
               return;
           end

           target = varargin{1};

           if(length(target)~=1 | ~sf('ishandle',target))
               errorMsg = sprintf('sfc invoked with invalid target id %d.',target);
               construct_coder_error([], errorMsg,1);
               return;
           end

           if(length(varargin)>1)
               parentTarget = varargin{2};
           else
               parentTarget = target;
           end
           if(length(varargin)>=3)
               mainMachineId = varargin{3};
           else
               mainMachineId = 0;
           end
           if(length(varargin)>=4)
               libraryIndex = varargin{4};
           else
               libraryIndex = 0;
           end
           if(length(varargin)>=5)
               inferenceChartId = varargin{5};
           else
               inferenceChartId = 0;
           end

           if(length(parentTarget)~=1 | ~sf('ishandle',parentTarget))
               errorMsg = sprintf('sfc invoked with invalid parent target id %d.',parentTarget);
               construct_coder_error([], errorMsg,1);
           end
       otherwise,
           construct_coder_error([],'',1);
           return;
   end

   sf('Private','coder_error_count_man','reset');

   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   %%%%%%%%%%%%%%%%%%%%% GLOBAL FLAGS AND ARRAYS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

   global gTargetInfo gChartInfo gDataInfo gMachineInfo

   %%%%%%%BEGIN: MINIMAL STUFF THAT NEEDS TO BE DONE%%%%%%%
   gMachineInfo.target = target;
   gMachineInfo.parentTarget = parentTarget;
   gMachineInfo.targetName = sf('get',target,'target.name');
   gMachineInfo.mainMachineId = mainMachineId;
   if(isempty(gMachineInfo.mainMachineId))
       gMachineInfo.mainMachineId = 0;
   end
   gMachineInfo.machineId = sf('get',gMachineInfo.target,'target.machine');
   if(gMachineInfo.mainMachineId==0)
      gMachine.simulatingMachineId = gMachineInfo.machineId;
   else
      gMachine.simulatingMachineId = gMachineInfo.mainMachineId;
   end

   gTargetInfo.target = target;
   gTargetInfo.parentTarget = parentTarget;
   %%%%%%%END:  MINIMAL STUFF THAT NEEDS TO BE DONE%%%%%%%

   switch(method)
   case 'clean'
      [status varargout{1}] = cdr_stage1;
      clean_code_gen_dir(varargout{1}.targetDirName');
      cdr_stage4; 
   case 'clean_objects'
      [status varargout{1}] = cdr_stage1;
      clean_code_gen_dir(varargout{1}.targetDirName,1);
      cdr_stage4;               
   case {'code','codeIncremental','codeNonIncremental'}
       switch(method)
           case {'code','codeIncremental'}
               codingRebuildAll=0;
           case {'codeNonIncremental'}
               codingRebuildAll=1;
   end
      [status varargout{1}] = cdr_stage1;
      if ~status
          cdr_stage2;
          cdr_stage3(varargout{1},codingRebuildAll);
      end
      cdr_stage4;
   case 'filenameinfo'
      [status varargout{1}] = cdr_stage1;
      cdr_stage4;
   case 'makeinfo'
      [status makeInfo.fileNameInfo] =  cdr_stage1;
       varargout{1} = makeInfo;
      cdr_stage4;
   otherwise,
       construct_coder_error([],'',1);
   end

   return;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [status fileNameInfo] = cdr_stage1
    status = 0;
    try 
        compute_target_info;
        compute_machine_info;
    catch
        status = 1;
    end
    fileNameInfo = create_file_name_info;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function cdr_stage2
      construct_context_for_machine;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function cdr_stage3(fileNameInfo,codingRebuildAll)
      generate_code_for_charts_and_machine(fileNameInfo,codingRebuildAll);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function cdr_stage4
      global gMachineInfo
      sf('set',gMachineInfo.machineId,'machine.activeTarget',0);
      sf('set',gMachineInfo.machineId,'machine.activeParentTarget',0);
   clear global gMachineInfo gTargetInfo gChartInfo gDataInfo


