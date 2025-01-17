% STD   標準偏差
% 
% Xがベクトルの場合、Y = STD(X) は標準偏差を計算します。Xが行列の場合、
% STD(X)は各列の標準偏差を含む行ベクトルを出力します。XがN次元配列の場合、
% STD(X)は最初に1でない次元の要素の標準偏差を出力します。
%
% STD(X)は、Nが長さのとき(N-1)を使って、正規化します。これにより、Xが正
% 規分布からのサンプルの場合、STD(X).^2は分散のバイアスのかかっていない
% 推定になります。 
%
% Y = STD(X,1) は、Nを使って正規化され、その平均についてのサンプルの
% 2次モーメントの平方根を出力します。STD(X,0)は、STD(X)と同じです。
%
% Y = STD(X,FLAG,DIM) は、Xの次元DIMで標準偏差を計算します。FLAG = 0のとき，
% STDは(N-1)を使って正規化し、そうでなければNを使って正規化します。
%
% 例題: X = [4 -2 1
%           9  5 7]
% 
% の場合、std(X,0,1)は、[ 3.5355 4.9497 4.2426]で、std(X,0,2)は[3.0  です。
%                                                               2.0]
% 参考：COV, MEAN, VAR, MEDIAN, CORRCOEF.


%   Copyright 1984-2003 The MathWorks, Inc.

