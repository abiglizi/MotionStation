%BESTTREE   最適ウェーブレットパケットツリー
%   BESTTREE は、エントロピータイプの基準を考慮した初期ツリーの最適とな
%   るサブツリーを計算します。結果のツリーは、初期のものよりも小さくなり%   ます。
%
%   T = BESTTREE(T) は、最適なエントロピー値に対応する、修正されたツリー%    T を計算します。
%
%   [T,E] = BESTTREE(T) は、最適なツリー T に加え、最適なエントロピー値 %   E を出力します。
%   インデックス j-1 のノードの最適なエントロピーは、E(j) です。
%
%   [T,E,N] = BESTTREE(T) は、最適なツリー T とエントロピー値 E に加え、%   並び替えられたノードのインデックスを含むベクトル N を出力します。
% 
%   参考: BESTLEVT, WENTROPY, WPDEC, WPDEC2


%   Copyright 1995-2002 The MathWorks, Inc.
