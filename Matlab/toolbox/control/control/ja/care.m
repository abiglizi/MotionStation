% CARE   連続時間の代数Riccati方程式を解きます。
%
%
% [X,L,G,RR] = CARE(A,B,Q,R,S,E) は、連続時間代数Riccati方程式のユニークで
% 対称な安定化解xを求めます。 
%                                -1
%       A'XE + E'XA - (E'XB + S)R  (B'XE + S') + Q = 0 
%
% R, S, E は、省略されると、デフォルト値 R = I, S = 0, E = I が設定されます。
% 解 X の他に、CARE  は、ゲイン行列　
%                -1
%           G = R  (B'XE + S')
% と閉ループ固有値のベクトル L　(すなわち、EIG(A-B*G,E)) も出力します。
%
% [X,L,G,REPORT] = CARE(...) は、つぎの値をもつ診断 REPORT を出力します。
%    * Hamiltonian 行列が虚軸に非常に近い固有値をもつ場合、-1
%    * 有限の安定化解 X  が存在しない場合、-2
%    * X が存在し有限の場合、相対残差のフロベニウスノルム。
% この構文は、X が存在しない場合、エラーメッセージを出力しません。
%
% [X1,X2,D,L] = CARE(A,B,Q,...,'factor') は、2つの行列 X1, X2 と、
% X = D*(X2/X1)*D の対角型スケーリング行列 D を出力します。ベクトル L は、
% 閉ループ固有値を含みます。すべての出力は、関連する Hamiltonian 行列が
% 虚軸上に固有値をもつ場合、空です。
%
% [...] = CARE(A,B,Q,...,'nobalance') は、データのオートスケーリング機能を
% 無効にします。
%
% 参考 : DARE.


% Copyright 1986-2002 The MathWorks, Inc.
