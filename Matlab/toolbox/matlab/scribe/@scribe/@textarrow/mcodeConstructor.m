function mcodeConstructor(this,code)
%MCODECONSTRUCTOR Customize object code generation
% code is a codegen.codeblock object

%   Copyright 1984-2003 The MathWorks, Inc. 

set(code,'Name','textarrow');
methods(this,'mcodeConstructor',code,'textarrow');



