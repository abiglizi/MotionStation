function [TI_Types,qTI_Types,ML_Types] = C24x_DataTypes(obj)

% Copyright 2003 The MathWorks, Inc.
%   $Revision: 1.1 $  $Date: 2003/07/07 17:30:25 $

TI_Types = { ...
	'char',             16,...
	'signed char',      16,...
	'unsigned char',    16,...
	'short',            16,...
	'signed short',     16,...
	'unsigned short',   16,...
	'int',              16,...
	'signed int',       16,...
	'unsigned int',     16,...
	'long',             32,...
	'signed long',      32,...
	'unsigned long',    32,...
	'float',            32,...   
	'double',           32,...
	'long double',      32 ...
};
% Does not apply:
% 	'void',             [],...
% 	'long long',        [],...
% 	'unsigned long long', [],...

qTI_Types = { ...
	'Q0.15',    16,...
	'Q0.31',    32 ...
};

ML_Types = { ...
	'int16',    16,...
	'uint16',   16,...
	'int32',    32,...
	'uint32',   32,...
	'single',   32 ...
};
% Does not apply:
% 	'int8',     [],...
% 	'uint8',    [],...
% 	'int64',    [],...
% 	'uint64',   [],...
% 	'double',   [] ...
