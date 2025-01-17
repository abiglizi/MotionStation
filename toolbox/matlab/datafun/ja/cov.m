% COV   共分散行列
% 
% COV(X)は、Xがベクトルのとき、ベクトルの要素の分散を出力します。各行が
% 観測値で、各列が変数である行列に対して、COV(X)は共分散行列です。DIAG
% (COV(X))は、各列の分散を表わす要素からなるベクトルで、
% SQRT(DIAG(COV(X)))は、標準偏差を表わす要素からなるベクトルです。
% COV(X,Y)は、XとYが同じ長さのベクトルのとき、COV([X(:) Y(:)])と
% 等価です。
% 
% COV(X)、または、COV(X,Y)は、Nが観測数のとき、(N-1)によって正規化
% します。これにより、観測値が正規分布の場合、COV(X)は、共分散行列
% のバイアスのかかっていない推定になります。
% 
% COV(X,1)、または、COV(X,Y,1)は、Nにより正規化を行い、それらの平均
% の観測に関する2次モーメント行列を出力します。COV(X,Y,0)はCOV(X,Y)
% と等価で、COV(X,0)はCOV(X)と等価です。
%
% 平均は、結果を計算する前に、各列から除かれます。
%
% 参考：CORRCOEF, STD, MEAN.


%   J. Little 5-5-86
%   Revised 6-9-88 LS 3-10-94 BJ
%   Copyright 1984-2003 The MathWorks, Inc. 
