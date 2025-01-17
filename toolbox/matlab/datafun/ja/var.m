% VAR    分散 
% 
% ベクトルに対して、Y = VAR(X)は、Xの分散を出力します。
% 行列に対して、Y は、Xの各列の分散を含む行ベクトルです。
% N 次元配列に対して、VARは、X の最初に1でない次元で操作します。
%
% VARは、Nが列の長さのとき、Yを N-1で正規化します。これは、X が正規分布す
% るサンプルの場合、分散の最も良いバイアスのかかっていない推定です。
%
% Y = VAR(X,1)は、Nで正規化し、その平均に関するサンプルの2次モーメントを出
% 力します。
%
% Y = VAR(X,W) は、重みベクトルWを使って分散を計算します。Wの要素数は、W = 1
% の場合を除いて、Xの行数と等しくなければなりません。W = 1 の場合は、1を
% 要素とするベクトルに対するショートカットとして扱われるからです。
%
% Wの要素は正でなければなりません。VARは、W内の各要素を、すべての要素の
% 和で除算することによりWを正規化します。
%
% 分散は、標準偏差(STD)の二乗です。 
%
% 例題: X = [4 -2 1
%            9  5 7]
%   の場合、var(X,0,1) は [12.5 24.5 18.0] であり、 var(X,0,2) は [9.0  です。
%                                                                  4.0]
%
% 参考 MEAN, STD, COV, CORRCOEF.

% VAR は、分散の一般の定義を両方とも定義します。  
% X がベクトルの場合、
%
%      VAR(X) = SUM(RESID.*CONJ(RESID)) / (N-1)
%      VAR(X,1) = SUM(RESID.*CONJ(RESID)) / N
%
% ここで、RESID = X - MEAN(X) であり、 N は LENGTH(X) です。
%
% ベクトル X に対する重み付きの分散は、つぎのように定義されます。
%
%      VAR(X,W) = SUM(W.*RESID.*CONJ(RESID)) / SUM(W)
%
% ここで、RESID は、重み付きの平均を使用して計算されます。

%   Copyright 1984-2003 The MathWorks, Inc.
