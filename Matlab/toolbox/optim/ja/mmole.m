% MMOLE   距離問題
% 
% この関数は、 MOLECULE で使用されます。
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 入力：
%     x -  ある部分のカレントでの位置(実ライン上)
%    DM -  スパースな `距離行列'
% 
% 出力：
%   val -  距離関数の値：
%          DM 内での (i,j) に関する [(x(i)-x(j))^2 -dist^2]^2 の和と 
%          (x(1)-1)^2) の項に x(1)を加え、変換によって特異にならない
%          ように、1を加えます。
%  grad -  距離関数の勾配 
%  H    -  距離関数のスパースHessian行列
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Javier Pena, 8-18-95
% Copyright 1990-2003 The MathWorks, Inc.
% $Revision: 1.7 $  $Date: 2003/05/01 13:02:13 $
