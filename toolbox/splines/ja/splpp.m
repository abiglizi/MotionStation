% SPLPP   局所的なB-係数から左のテイラー(Taylor)係数へ
%
% [V,B] = SPLPP(TX,A)
%
% は、[ ,k]:=size(A) のとき、(節点列 TX(.,1:2k-2) に対する)区間 
% [TX(.,k-1) .. TX(.,k)] に関連するB-スプライン係数 A(.,:) から、
% (節点列 [TX(.,1:k-1),0,...,0] に対する)区間 [TX(.,k-1) .. 0] に
% 関連するB-スプライン係数 B(.,1:k) を得るために、節点の挿入を使用
% します。
%
% TX(.,k-1) < 0 <= TX(.,k) と仮定します。
%
% このことから、与えられた節点と係数によって記述されるスプライン s に
% 対して、V(j) := D^{k-j}s(0-)/(k-j)!  , j=1,...,k を計算します。
%
% 参考 : SPRPP, SP2PP.


%   Copyright 1987-2003 C. de Boor and The MathWorks, Inc. 
