% PLUS   2つのLTIモデルの加算
%
% SYS = PLUS(SYS1,SYS2) は、SYS = SYS1 + SYS2 を実行します。LTIモデルの
% 加算は、並列結合と等価です。
%
% SYS1 と SYS2 が、それぞれ LTI モデルの配列のとき、それらの加算は、
% 同じ次数の1つのLTI配列 SYS になります。ここで、k 番目のモデルは、SYS1
% と SYS2 のk番目のモデルを加算したものです。
% 
%   SYS(:,:,k) = SYS1(:,:,k) + SYS2(:,:,k)
%
% 参考 : PARALLEL, MINUS, UPLUS, LTIMODELS.


%   Author(s): A. Potvin, 3-1-94,  P. Gahinet, 4-1-96
%   Copyright 1986-2002 The MathWorks, Inc. 
