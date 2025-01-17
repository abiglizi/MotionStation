% sys = sdiag(sys1,sys2,...)
%
% 単一システムSYSにシステムSYS1, SYS2 ,...を付加します。
%
%           _______________________
%           |       ________      |
%           |       |      |      |
%       ----------->| sys1 |----------->
%           |       |______|      |
%           |          :          |
%           |          :          |
%           |       ________      |
%           |       |      |      |
%       ----------->| sysk |----------->
%           |       |______|      |
%           |_____________________|
%
%                     SYS
%
% これらのシステムの内の1つ(あるいは1つ以上)は、ポリトピックシステム、ま
% たは、パラメータ依存システムでも構いません。SDIAGは、最大10個の入力引
% 数をもちます。
%
% 参考：    LTISYS, SADD, SMULT, SDIAG, PSYS.



% Copyright 1995-2002 The MathWorks, Inc. 
