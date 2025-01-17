% STACK   LTIモデルをLTI配列へ組み込み
%
% SYS = STACK(ARRAYDIM,SYS1,SYS2,...) は、配列の次元 ARRAYDIM に従って、
% LTIモデル SYS1,SYS2,... を組み込んで、LTIモデルの配列 SYS を作成しま
% す。すべてのモデルは入出力数が等しくなければいけません。また、I/O次元
% は、配列次元としてカウントされません。
%
% たとえば、SYS1 と SYS2 が同じI/O次元である2つのLTIモデルの場合、
% 
%  * STACK(1,SYS1,SYS2) は、2*1 LTI 配列を作成します。
%  * STACK(2,SYS1,SYS2) は、1*2 LTI 配列を作成します。
%  * STACK(3,SYS1,SYS2) は、1*1*2 LTI 配列を作成します。
%
% 配列の次元 ARRAYDIM に応じて、LTI配列 SYS1,SYS2,... を連鎖させるため
% に STACK を利用することもできます。
%
% 参考 : HORZCAT, VERTCAT, APPEND, LTIMODELS.


%   Author(s): P. Gahinet, 1-98
%   Copyright 1986-2002 The MathWorks, Inc. 
