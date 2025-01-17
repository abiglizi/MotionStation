% TRI2GRID   三角形メッシュから長方形グリッドに補間します。
%
% UXY = TRI2GRID(P,T,U,X,Y) は、P と T によって定義された三角形メッシュ
% 上での値をもつ関数 U から、ベクトル X と Y によって定義されたグリッド
% 上での関数値 UXY を計算します。値は、グリッド点を含む三角形の中で線形
% 補間を使って計算されます。ベクトル X と Y は、増加していなければなりま
% せん。
%
% [UXY,TN,A2,A3] = TRI2GRID(P,T,U,X,Y) は、各グリッド点を含む三角形のイ
% ンデックス TN と補間係数 A2 と A3 を表示します。
%
% 1つ前の TRI2GRID で計算された TN, A2, A3 を使う UXY = TRI2GRID(P,...
% T,U,TN,A2,A3)は、1つ前と同じグリッドを使って補間します。これは、数個の
% 関数値が同じグリッドを使って補間されれば、より高速になります。
%
% 三角形メッシュの外側のグリッド点に対しては、UXY, TN, A2, A3 に NaN が
% 表示されます。
%
% 参考   INITMESH, REFINEMESH, ASSEMPDE



%       Copyright 1994-2001 The MathWorks, Inc.
