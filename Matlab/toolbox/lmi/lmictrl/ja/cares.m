%  [X,L,G,RR] = cares(A,B,Q,R,S,E)
%
% 既知のA,B,Q,R,S,Eに対して、連続時間代数Riccati方程式
%                             -1
%    A'XE + E'XA - (E'XB + S)R  (B'XE + S') + Q = 0
% 
% または、等価な
%                       -1             -1          
%    F'XE + E'XF - E'XBR  B'XE + Q - SR  S' = 0  
%                        -1
%     (ここで、F = A - BR  S'です)
% 
% を計算し、唯一で対称な安定化解である n 行 n 列の行列Xを求めます。
% 付加的なオプション出力として、閉ループ固有値L(n次ベクトル)とつぎの式で
% 定義される m 行 n 列の行列ゲインG、相対残差行列のフロベニウスノルムRR
% を出力します。
% 
%          -1
%    G = -R  (B'XE + S'),
%
% 仮定: Eは正則で、Q=Q'、Rは正則でR=R'、そして、関連するハミルトニアンペ
%       ンシルが虚軸上に固有値を持たないことが仮定されます。
% 
% 上記の仮定が補償されるための十分条件は、可安定、かつ、可検出で、R > 0 
% かつ [Q S;S' R] >= 0 です。
%
% SとEが指定されなかった場合、デフォルト値として、S = 0 と E = I に設定
% されます。このバージョンでは、発見的自動スケーリングを実行しますが、イ
% ンタラクティブではありません。スケーリングでは、B が0でないことが仮定
% され、B = 0の場合、リアプノフソルバが利用されます。

% Copyright 1995-2001 The MathWorks, Inc. 
