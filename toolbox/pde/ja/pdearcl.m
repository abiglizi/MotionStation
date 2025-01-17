% PDEARCL   パラメータ表現されたものと弧の長さを曲線で補間します。
%
% PP = PDEARCL(P,XY,S,S0,S1) は、円弧の長さで与えたものに対応してパラメ
% ータ化された曲線に対するパラメータ値を出力します。
%
% P は、パラメータ値の単調な行ベクトルで、XY は、曲線上の対応する点を与
% えた二つの行をもつ行列です。
%
% 曲線の最初の点は、円弧長値 S0 と最後の点 S1 で与えられます。
%
% 一方、PP は、S の中に指定した円弧長の値に対応したパラメータ値です。
%
% 円弧長 S, S0, S1 は、円弧長に比例する必要があります。
%
% 参考   PDEGEOM, PDEIGEOM



%       Copyright 1994-2001 The MathWorks, Inc.
