% NLS3: snls デモ
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% この例題は、F(x) = 0 の型の構造化された非線形方程式問題の解き方を示す
% ものです。ここで、 F = G(y) で、y は、スパース SPD システム Ay = G(x) 
% を解くことにより、得られます(この例題で、G は、三重対角のJacobian 行列
% です)。
%
% 注意：
% Jacobian行列の要素が計算されますが、明示的にJacobianは、定式化され
% ません。
%
% 最初の実行で、特別な関数 mtxmpy と pcmtx を用意しています。
%
% 2番目の実行で、ニュートンステップが、問題の構造的なものを利用して計算
% され、'拡大'システムを解きます。
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%   Copyright 1990-2003 The MathWorks, Inc.
%   $Revision: 1.7 $  $Date: 2003/05/01 12:59:54 $
