% BWPACK 　バイナリイメージのパック(圧縮)
% BWP = BWPACK(BW) は、uint8 のバイナリイメージ BW を uint32 の配列 BWP
% にパックします。この uint32 の配意列は、パックされたバイナリイメージと
% して良く知られたものです。バイナリイメージの中の個々の 8-ビットピクセル
% 値は、たった2つの値(1 と 0)しかもつことができないので、BWPACK は、パッ
% クされた出力イメージの中の単一ビットに各ピクセルをマッピングできます。
%
% BWPACK は、列単位で、イメージピクセルを処理し、32 ピクセルのグループを 
% uint32 の値のビットにマッピングします。最初の行の最初のピクセルは、出力
% 配列の最初の uint32 要素の最小の意味をもつビットに対応します。32番目の
% 行の最初のピクセルは、この同じ要素の最も大きい意味のあるビットに対応し
% ます。33番目の行の最初のピクセルは、2番目の出力要素の最小の意味のあるビ
% ットに対応します。同じように、後も対応します。BW が、M 行 N 列の場合、
% BWP は、CEIL(M/32) 行 N 列になります。 
%
% バイナリイメージのパック化は、膨張や縮退のようないくつかのバイナリ形態
% 学的演算を高速にするために使われます。IMDILATE や IMERODE への入力が、
% パックされたバイナリイメージの場合、関数は、特別な関数に使われ、演算を
% 高速にします。 
%
% BWUNPACK は、バイナリイメージのパックを解除するために使います。
%
% クラスサポート
% -------------
% BW は logical か数値で、2次元の実数で、非スパースでなければなりません。
% BWP は uint32 です。
%
% 例題
% -------
% バイナリイメージのパック、膨張、パックの解除を行います。
%
%       bw = imread('text.tif');
%       bwp = bwpack(bw);
%       bwp_dilated = imdilate(bwp,ones(3,3),'ispacked');
%       bw_dilated = bwunpack(bwp_dilated, size(bw,1));
%
% 参考：BWUNPACK, IMDILATE, IMERODE.



%   Copyright 1993-2002 The MathWorks, Inc.
