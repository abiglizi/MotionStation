% LPC  線形予測係数
%
% A = LPC(X,N)は、誤差(err(n) = X(n) - Xp(n))の二乗を最小化する N 次の前
% 向き線形予測子係数 A = [ 1 A(2) ... A(N+1) ]を出力します。Xはベクトル
% でも行列でも構いません。
%
%   Xp(n) = -A(2)*X(n-1) - A(3)*X(n-2) - ... - A(N+1)*X(n-N)
%
% Xが、列単位に種々の異なる信号を含んだ行列の場合、LPCは各列のモデル推定
% 値をAの各行に出力します。N は、多項式 A(z) の次数です。
%
% N を設定しないと、LPC は、デフォルトとして、N = length(X)-1 を使用しま
% す。
%
% [A,E] = LPC(X,N)は、予測誤差の分散(べき)を出力します。
%
% LPCは、Levinson-Durbin回帰を使って、最小二乗式から生じる正規方程式を
% 解きます。この線形予測係数の計算は、自己相関法として参照されます。
%
% 参考：   LEVINSON, ARYULE, PRONY, STMCB.



%   Copyright 1988-2002 The MathWorks, Inc.
