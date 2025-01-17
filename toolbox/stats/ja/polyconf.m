% POLYCONF   多項式の計算と信頼区間を推定
%
% p が、長さ n+1 のベクトルで、その要素が多項式の係数の場合、
% y = POLYCONF(p,x) は、x での多項式の値を計算します。
% 
%    y = p(1)*x^n + p(2)*x^(n-1) + ... + p(n)*x + p(n+1)
% 
% X が行列またはベクトルの場合、多項式は、X の中のすべての要素に対して
% 多項式の値を計算します。
% 
% [y,delta] = POLYCONF(p,x,S,alpha) は、関数 POLYFUT で作成される
% オプション出力 S を使って、信頼区間 Y +/- DELTA を作成します。POLYFIT 
% へのデータ入力の中に含まれる誤差が、一定の分散をもつ独立な正規分布の
% 場合、Y +/- DELTA は、未来の予測の 100(1-ALPHA)% を含んでいます。
% ALPHA のデフォルト値は0.05で、95% の信頼区間に対応します。


%   5-11-93 B.A. Jones
%   Copyright 1993-2002 The MathWorks, Inc. 
%   $Revision: 1.6 $  $Date: 2003/02/12 17:14:58 $
