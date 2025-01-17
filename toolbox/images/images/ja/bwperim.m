% BWPERIM バイナリイメージの中の境界線を検出
% BW2 = BWPERIM(BW1) は、入力イメージ BW1 の中のオブジェクトの境界線のピ
% クセルのみを含むバイナリイメージを戻します。ピクセルは、非ゼロならば境
% 界線で、少なくとも一つゼロの値をもつピクセルと接続しています。デフォル
% トの連結度は2次元の場合4、3次元の場合6で、高次の場合、CONNDEF(NDIMS
% (BW),'minimal') になります。
%
% BW2 = BWPERIM(BW1,CONN) は、希望する連結度を指定します。CONN は、つぎの
% スカラ値を設定します。
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
% クラスサポート
% -------------
% BW1 は、logical または、数値配列で、非スパースでなければなりません。
% BW2 は、logical です。
%
% 例題
%   -------
%       BW1 = imread('circbw.tif');
%       BW2 = bwperim(BW1,8);
%       imshow(BW1)
%       figure, imshow(BW2)
%
% 参考：BWAREA, BWEULER, BWFILL, CONNDEF.



%   Copyright 1993-2002 The MathWorks, Inc.  
