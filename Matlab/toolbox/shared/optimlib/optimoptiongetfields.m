function optimfields = optimoptiongetfields
%OPTIMOPTIONGETFIELDS Fieldnames of options in Optimization Toolbox but not in
% MATLAB.
%
% This is a helper function for OPTIMSET and OPTIMGET.

%   [OPTIMFIELDS,OPTIMINDEX,MATLABINDEX] = OPTIMOPTIONGETFIELDS returns a cell 
%   array OPTIMFIELDS of the fieldnames of options in the Optimization Toolbox 
%   but not in MATLAB. OPTIMINDEX gives the indexing order of the OPTIMFIELDS,
%   and MATLABINDEX gives the indexing order of the fields in MATLAB, to produce
%   one sorted list of fieldnames.
%
%   See also OPTIMSET, OPTIMGET.

%   Copyright 1990-2004 The MathWorks, Inc. 
%   $Revision: 1.1.4.1 $  $Date: 2004/03/26 13:27:23 $

optimfields =   {...
    'ActiveConstrTol'; ...
    'NoStopIfFlatInfeas'; ...
    'BranchStrategy';  ...
    'DerivativeCheck';  ...
    'Diagnostics';  ...
    'DiffMaxChange';  ...
    'DiffMinChange';  ...
    'GoalsExactAchieve';  ...
    'GradConstr';  ...
    'GradObj';  ...
    'Hessian';  ...
    'HessMult';  ...
    'HessPattern';  ...
    'HessUpdate';  ...
    'InitialHessType';  ...
    'InitialHessMatrix';  ...
    'Jacobian';  ...
    'JacobMult';  ...
    'JacobPattern';  ...
    'LargeScale';  ...
    'LevenbergMarquardt';  ...
    'LineSearchType';  ...
    'MaxNodes';  ...
    'MaxPCGIter';  ...
    'MaxRLPIter';  ...
    'MaxSQPIter';  ...
    'MaxTime';  ...
    'MeritFunction';  ...
    'MinAbsMax';  ...
    'NodeDisplayInterval';  ...
    'NodeSearchStrategy';  ...
    'NonlEqnAlgorithm';  ...
    'PhaseOneTotalScaling'; ...
    'Preconditioner';  ...
    'PrecondBandWidth';  ...
    'RelLineSrchBnd'; ...
    'RelLineSrchBndDuration'; ...
    'ShowStatusWindow';  ...
    'Simplex';  ...
    'TolCon';  ...
    'TolPCG';  ...
    'TolRLPFun';  ...
    'TolXInteger';  ...
    'TypicalX'};
