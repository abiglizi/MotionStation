% GAMRND   ガンマ分布のランダム行列
%
% R = GAMRND(A,B) は、形状パラメータ A と スケールパラメータ B をもつ
% ガンマ分布から抽出された乱数の行列を出力します。R の大きさは、A と B が
% 共に行列の場合、それらに共通する大きさになります。どちらかのパラメータが
% スカラの場合、R の大きさは、もう一方のパラメータと同じ大きさになります。
% また、R = GAMRND(A,B,M,N) は、M行N列の行列を出力します。
% 
% 他の参考文献では、単一のパラメータをもつガンマ分布が報告されていますが、
% これは、GAMRND では、B = 1 に対応します。
%
% 参考 : GAMCDF, GAMFIT, GAMINV, GAMLIKE, GAMPDF, GAMSTAT.


%   Copyright 1993-2003 The MathWorks, Inc. 
%   $Revision: 1.6 $  $Date: 2003/02/12 17:11:46 $
