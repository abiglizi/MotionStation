function ctxInfo = construct_context

% Copyright 2004 The MathWorks, Inc.

global gMachineInfo gTargetInfo

if gTargetInfo.codingRTW
    timeVarName = '%<LibSFGetCurrentTaskTime(block)>';
else
    timeVarName = '_sfTime_';
end


ctxInfo.machine = gMachineInfo.machineId;
ctxInfo.eventVariableName = gMachineInfo.eventVariableName;
ctxInfo.eventVariableType = gMachineInfo.eventVariableType;
ctxInfo.timeVariableName       = timeVarName;
ctxInfo.complexityThresholdMin = coder_options('inlineThreshold');
ctxInfo.complexityThresholdMax = coder_options('inlineThresholdMax');
ctxInfo.codingNoEcho = gTargetInfo.codingNoEcho;
ctxInfo.codingComments = gTargetInfo.codingComments;
ctxInfo.codingAutoComments = gTargetInfo.codingAutoComments;
ctxInfo.codingEmitObjectDescriptions = gTargetInfo.codingEmitObjectDescriptions;
ctxInfo.codingEmitObjectRequirements = gTargetInfo.codingEmitObjectRequirements;
ctxInfo.codingSFunction = gTargetInfo.codingSFunction;
ctxInfo.codingRTW = gTargetInfo.codingRTW;
ctxInfo.rtwMultiInstancedERT = gTargetInfo.isErtMultiInstanced;
ctxInfo.codingDebug = gTargetInfo.codingDebug;
ctxInfo.codingForTestGen = gTargetInfo.codingForTestGen;
ctxInfo.codingOverflow = gTargetInfo.codingOverflow;
ctxInfo.codingTelemetry = 0;
ctxInfo.codingStateBitsets = gTargetInfo.codingStateBitsets;
ctxInfo.codingDataBitsets = gTargetInfo.codingDataBitsets;
ctxInfo.codingWatcomCompiler = gTargetInfo.codingWatcomMakefile;
ctxInfo.ignoreUnsafeTAs = sfpref('ignoreUnsafeTransitionActions');
ctxInfo.dataflowAnalysisThreshold = coder_options('dataflowAnalysisThreshold');
ctxInfo.machineNumberVarName = gMachineInfo.machineNumberVariableName;
ctxInfo.codingLogicalOps = gTargetInfo.codingLogicalOps;
ctxInfo.codingElseIfDetection = gTargetInfo.codingElseIfDetection;
ctxInfo.codingConstantFolding = gTargetInfo.codingConstantFolding;
ctxInfo.codingRedundantElim = gTargetInfo.codingRedundantElim;
ctxInfo.codingGlobalIO = gTargetInfo.codingGlobalIO;
ctxInfo.codingPackedIO = gTargetInfo.codingPackedIO;
ctxInfo.codingPreserveConstantNames = gTargetInfo.codingPreserveConstantNames;
[algorithmWordsizes,targetWordsizes,algorithmHwInfo,targetHwInfo] = get_word_sizes_local;

ctxInfo.algorithmWordsizes = algorithmWordsizes;
ctxInfo.targetWordsizes = targetWordsizes;

ctxInfo.algorithmHwDeviceType = ...
  algorithmHwInfo.hwDeviceType;
ctxInfo.algorithmDivByZeroProtectionNotWanted = ...
  algorithmHwInfo.divByZeroProtectionNotWanted;
ctxInfo.algorithmSignedDivRounding = ...
  algorithmHwInfo.signedDivRounding;

ctxInfo.targetHwDeviceType = ...
  targetHwInfo.hwDeviceType;
ctxInfo.targetDivByZeroProtectionNotWanted = ...
  targetHwInfo.divByZeroProtectionNotWanted;
ctxInfo.targetSignedDivRounding = ...
  targetHwInfo.signedDivRounding;

ctxInfo.exportedFcnInfo = gMachineInfo.exportedFcnInfo;

gMachineInfo.ctxInfo = ctxInfo;

try,
    sf('Cg','construct_context',ctxInfo);
catch,
    sf('Private','coder_error_count_man','add',1);
    return;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [algorithmWordsizes,targetWordsizes,algorithmHwInfo,targetHwInfo] = get_word_sizes_local

global gMachineInfo

relevantMachineName = sf('get',get_relevant_machine,'machine.name');

[algorithmWordsizes,targetWordsizes,algorithmHwInfo,targetHwInfo] = get_word_sizes(relevantMachineName,gMachineInfo.targetName);

