%   [X,L,G,RR] = dares(A,B,Q,R,S,E)
% 
% 既知のA,B,Q,R,S,Eに対して、離散時間代数Riccati方程式
%                                      -1 
%    E'XE = A'XA - (A'XB + S)(B'XB + R)  (A'XB + S)' + Q
%  
% または、等価な（Rが正則な場合）
%                                -1             -1    
%    E'XE = F'XF - F'XB(B'XB + R)  B'XF + Q - SR  S'  
%                       -1
%    (ここで、F = A - BR  S')
% 
% を計算し、唯一で対称な安定化解である n 行 n 列の行列Xを求めます。付加
% 的なオプション出力として、閉ループ固有値L(n次ベクトル)と、つぎの式を満
% 足する m 行 n 列の行列ゲインG、相対残差行列のフロベニウスノルムRRを出
% 力します。
%                 -1
%    G = -(B'XB + R)  (B'XA + S'),
%
% 仮定: Eは正則で、Q=Q'、R=R'、関連するシンプレティックペンシルが単位円
%       上に固有値をもたないことが仮定されます。
% 
% 上記の仮定を補償するための十分条件は、可安定かつ可検出、
% 
%    [Q S;S' R] >= 0
%　　
% です。
%
% SとEが指定されない場合、デフォルトでS = 0とE = Iに設定されます。このバ
% ージョンでは、発見的自動スケーリングが実行されますが、インタラクティブ
% ではありません。スケーリングではBが0でないことが仮定され、B = 0の場合
% リアプノフソルバが利用されます。

% Copyright 1995-2001 The MathWorks, Inc. 
