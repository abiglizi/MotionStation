% UPWLEV2　 2次元のウェーブレット分解の単一レベルの再構成
%
% [NC,NS,CA] = UPWLEV2(C,S,'wname') は、ウェーブレット分解構造 [C,S] の単一レベ
% ルの再構成を計算し、新しいウェーブレット分解構造 [NC,NS] を与え、最終的に、A-
% ppoximation 係数行列 CA を抽出します。
%
% [C,S] は、レベル n = size(S,1)-2 での分解で、[NC,NS] は、レベル n-1 での同じ分
% 解成分で、CA は、レベル n での Approximation 行列です。
%
% 'wname' は、ウェーブレット名を含む文字列です。C は、オリジナルのウェーブレット
% 分解ベクトルで、S は、関連した長さの数を要素とする行列です(ストレージに関する
% 詳細な情報については、WAVEDEC2を参照してください)。
%
% ウェーブレット名の代わりに、フィルタを設定することもできます。
% [NC,NS,CA] = UPWLEV2(C,S,Lo_R,Hi_R) に対して、Lo_R は、再構成ローパスフィルタ
% で、Hi_R は、再構成ハイパスフィルタです。
%
% 参考： IDWT2, UPCOEF2, WAVEDEC2.



%   Copyright 1995-2002 The MathWorks, Inc.
