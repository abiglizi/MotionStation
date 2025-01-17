% POLY2TH 多項式から"theta行列"を生成
% 
%     TH = POLY2TH(A, B, C, D, F, LAM, T)
%
% TH  : モデルを記述する、標準形式の行列出力
%   
%          A(q) y(t) = [B(q)/F(q)] u(t-nk) + [C(q)/D(q)] e(t)
%  
% フォーマットの詳細は、THETA を参照してください。
% 
% A, B, C, D, F は、多項式です。A, C, D, F の先頭要素は1で、B は離散時間
% モデルに対する遅れを指定するために、先頭要素が0となります。多入力シス
% テムに対して、B, F は行列になり、その行数が入力数と一致します。時系列
% に対しては、B, F は [] と指定します。従って、POLY2TH は TH2POLY の逆操
% 作となります。
%
% LAM は雑音項 e の分散で、T はサンプリング周期です。T を負の値で指定す
% ると、連続時間モデルを意味します。そのとき、多項式は、s の降ベキの順で
% 指定されます。たとえば、A = 1, B = [1 2;0 3], C = 1, D = 1, F = [1 0;
% 0 1], T = -1は、連続時間システム Y = (s+2)/s U1 + 3 U2 を意味します。
%
% 最後の C, D, F, LAM, T が省略されると1とみなされます(B = []ならば、
% F = [])。
%
% 参考:    IDINPUT, IDSIM, TH2POLY

%   Copyright 1986-2001 The MathWorks, Inc.
