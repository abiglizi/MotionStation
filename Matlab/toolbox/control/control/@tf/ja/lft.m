% LFT   LTIシステムの Redheffer スター積を作成
%
% SYS = LFT(SYS1,SYS2,NU,NY) は、2つのLTIモデル SYS1 と SYS2 のスター積
% SYS を計算します。スター積、または、線形分数変換(LFT)は、つぎの SYS1 
% と SYS2 のフィードバック結合に対応します。
%		
%                     +-------+
%         w1 -------->|       |-------> z1
%                     |  SYS1 |
%               +---->|       |-----+
%               |     +-------+     |
%             u |                   | y
%               |     +-------+     |
%               +-----|       |<----+
%                     |  SYS2 |
%        z2 <---------|       |-------- w2
%                     +-------+
%
% フィードバックループは、SYS2 の最初のNU個の出力を SYS1 の最後のNU個
% の入力(信号 u)と結合し、SYS1 の最後のNY個の出力と SYS2 の最初の NY個
% の入力(信号 y)を結合します。結果の LTI モデル SYS は、入力ベクトル 
% [w1;w2] を出力ベクトル [z1;z2] にマッピングします。
%
% SYS = LFT(SYS1,SYS2) は、つぎのシステムを出力します。
%  * SYS2 が SYS1 よりも少ない入力数や出力数の場合、SYS1 と SYS2 の下側
%    の LFT。上の図では、w2,z2を削除します。
%  * SYS1 が SYS2 よりも少ない入力数や出力数の場合、SYS1 と SYS2 の上側
%    の LFT。上の図では、w1,z1を削除します。
%
% SYS1 と SYS2 が、LTIモデルの配列の場合、LFTは、つぎに示すように、同じ
% 次元のLTI配列 SYS を出力します。
% 
%   SYS(:,:,k) = LFT(SYS1(:,:,k),SYS2(:,:,k),NU,NY) .
%
% 参考 : FEEDBACK, CONNECT, LTIMODELS.


%   Author(s): P. Gahinet, 5-10-95.
%   Copyright 1986-2002 The MathWorks, Inc. 
