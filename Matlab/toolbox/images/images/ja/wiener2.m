% WIENER2   2次元適応ノイズ除去フィルタリング
%   WIENER2 は、一定のパワーをもつ加算的なノイズで劣化している強度イ
%   メージにローパスフィルタを適用します。WIENER2 は、各ピクセルの局所
%   的な近傍から推定される統計量を基にピクセル単位に作用する適応 
%   Wiener 法を使います。
%
%   J = WIENER2(I,[M N],NOISE) は、局所的なイメージの平均と標準偏差を
%   計算するため、M 行 N 列のサイズの近傍を使って、ピクセルに作用する
%   適応 Wiener フィルタでイメージ I をフィルタリングします。[M N] を
%   省略すると、M と N は、デフォルトの3を使います。加算的なノイズ(ガ
%   ウス白色ノイズ)のエネルギーは、NOISE で設定します。
%
%   [J,NOISE] = WIENER2(I,[M N]) は、フィルタリングの前に加算的なノイ
%   ズのエネルギーを推定します。WIENER2 は、この推定値を NOISE に出力
%   します。
%
% クラスサポート
% -------------
%   入力イメージ I は、uint8、uint16、または、double のいずれのクラス
%   もサポートしています。出力イメージ J は、I と同じクラスです。
%
% 例題
% ----
%       I = imread('saturn.tif');
%       J = imnoise(I,'gaussian',0,0.005);
%       K = wiener2(J,[5 5]);
%       imshow(J), figure, imshow(K)
%
%   参考：FILTER2, MEDFILT2



%   Copyright 1993-2002 The MathWorks, Inc.  
