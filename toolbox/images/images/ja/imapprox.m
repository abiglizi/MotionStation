% IMAPPROX   少ないカラーでインデックス付きイメージを近似
%   [Y,NEWMAP] = IMAPPROX(X,MAP,N) は、インデックス付きイメージ X とそ
%   れに関連したカラーマップ MAP をもつカラーを最小変動量子化法を使っ
%   て近似します。IMAPPROX は、カラーマップ NEWMAP をもつインデックス
%   付きイメージ Y を出力します。このカラーマップは、たかだか N 個のカ
%   ラーしかもっていません。
%
%   [Y,NEWMAP] = IMAPPROX(X,MAP,TOL) は、X と MAP の中のカラーを一様量
%   子化法により近似します。NEWMAP は、たかだか(FLOOR(1/TOL)+1)^3 色し
%   か含んでいません。TOL は、0と1.0の間の値です。
%
%   Y = IMAPPROX(X,MAP,NEWMAP) は、MAP の中のカラーに一番マッチするよ
%   うに NEWMAP の中のカラーを求めるために、カラーマッピングを使って、
%   MAP の中のカラーを近似します。
%
%   Y = IMAPPROX(...,DITHER_OPTION) は、デザリングを適用するかどうかを
%   設定します。DITHER_OPTION には、つぎのいずれかの文字列を設定するこ
%   とができます。
%
%       'dither'   必要ならば、空間的な解像度を犠牲にして、カラーの解
%                  像度を高めるためにデザリングを適用(デフォルト)
%
%       'nodither' オリジナルイメージの各カラーを、新しいマップの最も
%                  近いカラーにマッピング。デザリングは適用されませ
%                  ん。
%
% クラスサポート
% -------------
%   入力イメージ X は、uint8、uint16、または、double のいずれのクラス
%   もサポートしています。出力イメージ Y は、NEWMAP の長さが256以下の
%   場合に、クラス uint8 になります。NEWMAP の長さが256より大きい場合
%   には、X はクラス double になります。
%
% 参考 : CMUNIQUE, DITHER, RGB2IND



%   Copyright 1993-2002 The MathWorks, Inc.  
