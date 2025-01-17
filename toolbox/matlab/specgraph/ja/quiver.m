% QUIVER   Quiverプロット
% 
% QUIVER(X,Y,U,V) は、点(x,y)で成分(u,v)をもつ矢印として、速度ベクトルを
% プロットします。行列 X,Y,U,V は、すべて同じサイズで、対応する位置と速度
% 成分を含まなければなりません(X とY は、一定のグリッドを指定するベクトル
% でも構いません)。QUIVER は、グリッドに適合するように、自動的に矢印を
% スケーリングします。
%
% QUIVER(U,V) は、xy平面上の等間隔の点で、速度ベクトルをプロットします。
%
% QUIVER(U,V,S) または QUIVER(X,Y,U,V,S) は、グリッド内に適合するように、
% 自動的に矢印をスケーリングし、その後それらをS倍に拡大します。自動
% スケーリングを行わずに矢印をプロットするためには、S = 0 を使ってください。
%
% QUIVER(...,LINESPEC) は、速度ベクトルに対して、指定されたラインスタイル
% を使用します。矢印の先端の代わりに、LINESPECのマーカが描画されます。
% マーカを設定しないようにするには、'.' を使用してください、使用可能な
% 他の値については、PLOT を参照してください。
%
% QUIVER(...,'filled') は、指定したマーカを塗りつぶします。
%
% QUIVER(AX,...) は、GCAの代わりにAXにプロットします。
%
% H = QUIVER(...) は、quiverグループオブジェクトのハンドル番号からなる
% ベクトルを出力します。
%
% 下位互換性
% QUIVER('v6',...) は、MATLAB 6.5およびそれ以前のバージョンとの互換性
% のため、quiverグループオブジェクトの代わりにlineオブジェクトを作成し
% ます。
%  
% 例題:
% 
%      [x,y] = meshgrid(-2:.2:2,-1:.15:1);
%      z = x .* exp(-x.^2 - y.^2); [px,py] = gradient(z,.2,.15);
%      contour(x,y,z), hold on
%      quiver(x,y,px,py), hold off, axis image
%
% 参考：FEATHER, QUIVER3, PLOT.


%   Clay M. Thompson 3-3-94
%   Copyright 1984-2002 The MathWorks, Inc. 
