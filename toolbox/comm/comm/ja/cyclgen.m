% CYCLGEN 巡回符号のパリティチェック行列、生成行列を生成
%
% H = CYCLGEN(N, P) は、コードワードの長さ N と生成多項式 P に対するパリ
% ティチェック行列を作成します。ベクトル P は、昇ベキの順に生成多項式の
% バイナリ係数を与えます。P が多項式 X^N-1 の係数である場合、多項式 P は、
% 巡回符号のみを生成することが可能です。この符号化のメッセージの長さは
% K = N - M です。このとき、M は P の次数です。パリティチェック行列は
% M行N列の行列です。
% 
% H = CYCLGEN(N, P, OPT) は、OPT で指定した指示に基づいて、パリティチェック
% 行列を作成します。
% OPT = 'nonsys' の場合、この関数は非組織巡回パリティチェック行列を作成
% します。
% OPT = 'system' の場合、この関数は組織巡回パリティチェック行列を作成
% します。このオプションはデフォルトです。
% 
% [H, G] = CYCLGEN(...) は、生成行列 G とパリティチェック行列Hを作成
% します。生成行列は、K = N - M の K 行 N 列の行列です。
% 
% [H, G, K] = CYCLGEN(...) は、メッセージの長さ K を出力します。
% 
% 参考： ENCODE, DECODE, BCHPOLY, CYCLPOLY.


%   Copyright 1996-2002 The MathWorks, Inc.
%   $Revision: 1.6.4.1 $
