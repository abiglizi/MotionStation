% IMCLEARBORDER  イメージ境界と連結している構造の明るさを抑える
% IM2 = IMCLEARBORDER(IM) は、イメージ境界に連結しているものを、周りのも
% のより明るい構造を低減します。IM は、強度イメージ、または、バイナリイメ
% ージのどちらかです。出力イメージ IM2 は、強度、または、バイナリイメージ
% です。デフォルトの連結は、2次元の場合8、3次元の場合26、高次元の場合、
% CONNDEF(NDIMS(BW),'maximal') です。
%
% 強度イメージの場合、IMCLEARBORDER は、境界構造表示を低減することに加
% え、全体的な強度レベルを低くする傾向があります。
%
% IM2 = IMCLEARBORDER(IM,CONN) は、希望する連結度を指定します。CONN は、
% つぎのスカラ値を設定します。
%
%       4     2次元4連結近傍
%       8     2次元8連結近傍
%       6     3次元6連結近傍
%       18    3次元18連結近傍
%       26    3次元26連結近傍
%
% 連結度は、CONN に対して、0と1を要素とする3 x 3 x 3 x ... x 3 の行列を
% 使って、任意の次元に対して、より一般的に定義できます。値1は、CONN の中
% 心要素に関連して近傍の位置を設定します。CONN は、中心要素に対して、対
% 称である必要があります。
%
% 注意
% ----
% 入力イメージのエッジ上のピクセルは、デフォルトでない連結を設定した場合、
% "境界"上のピクセルとは考えません。たとえば、CONN = [0 0 0; 1 1 1; 0 0 0]
% の場合、最初と最後の行の要素は、その連結の定義に従って、イメージの外の
% 領域と結合していないので、境界ピクセルとは考えません。
%
% クラスサポート
% -------------
% IM は、任意の次元の数値または logical で、非スパースで実数でなければ
% なりません。IM2 は、IM と同じクラスになります。
%
% 例題
% --------
% つぎの例題は、強度イメージの境界を如何にクリアにするかを示しています。
%
%       I = imread('rice.tif');
%       I2 = imclearborder(I);
%       figure, imshow(I)
%       figure, imshow(I2)
%
% つぎの例題は、バイナリイメージの境界を如何にクリアにするかを示しています。
%
%       BW = im2bw(imread('rice.tif'));
%       BW2 = imclearborder(BW);
%       figure, imshow(BW)
%       figure, imshow(BW2)
%
% 参考： IMRECONSTRUCT.



%   Copyright 1993-2002 The MathWorks, Inc.
