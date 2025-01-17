% HISTFIT   正規確率密度を重ね合わせたヒストグラム
%
% HISTFIT(DATA,NBINS) は、ヒストグラムの NBINS 個のバーを使って、ベクトル 
% DATA のデータのヒストグラムをプロットします。引数を設定しないで使用
% すると、NBINS は、DATA 内の要素数の平方根を計算した値を使います。
% 
% H = HISTFIT(DATA,NBINS) は、プロットされるラインのハンドル番号を要素
% とするベクトルを出力します。H(1) は、ヒストグラムのハンドル番号で、
% H(2) は、密度曲線のハンドル番号です。


%   B.A. Jones 2-14-95
%   Copyright 1993-2002 The MathWorks, Inc. 
%   $Revision: 1.6 $  $Date: 2003/02/12 17:07:40 $
