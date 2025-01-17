% NULL   行列のヌル空間
% 
% Z = NULL(A) は、特異値分解から得られる A のヌル空間に対する直交基底
% を出力します。A*Z は無視できる要素をもち、size(Z,2)は A の退化次数で、
% Z'*Z = Iです。
%
% Z = NULL(A,'r') は、行の階段型から得られるヌル空間に対する"有理"基底
% です。A*Z はゼロで、size(Z,2) は A の退化次数に対する推定で、A が整数
% 要素をもつ小さい行列の場合は、R の要素は小さい整数の比になります。
%
% 直交基底は数値的に望ましく、有理基底は教育的(pedagogical)なものが望ま
% しいです。
%
% 例題:
%
%       A =
%
%           1     2     3
%           1     2     3
%           1     2     3
%
%      null(A) = 
%
%         -0.1690   -0.9487
%          0.8452    0.0000
%         -0.5071    0.3162
%
%      null(A,'r') = 
%
%          -2    -3
%           1     0
%           0     1
%
% 参考：SVD, ORTH, RANK, RREF.

%   Copyright 1984-2004 The MathWorks, Inc. 
