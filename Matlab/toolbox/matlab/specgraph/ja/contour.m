% CONTOUR   コンタープロット
% 
% CONTOUR(Z) は、行列Zのコンタープロットを描画します。Z の値は、平面から
% の高さとして扱われます。コンタープロットは、値 V に対する Z 個のレベル
% の曲線です。値 V に選択されます。CONTOUR(X,Y,Z) では、X と Y は、
% サーフェスの (x,y) 座標を、SURF のように指定します。
% 
% CONTOUR(Z,N) と CONTOUR(X,Y,Z,N) は、N 個のコンターラインを、自動的に
% 値を変更しながら描画します。
% 
% CONTOUR(Z,V) と CONTOUR(X,Y,Z,V) は、ベクトル V で指定した値にコン
% ターラインをもつ、LENGTH(V) レベルのコンターラインを描画します。レベル 
% v の単一のコンターを計算するためには、CONTOUR(Z,[v v]) または
% CONTOUR(X,Y,Z,[v v]) を使用してください。 [C,H] = CONTOUR(...) は、
% CONTOURC で記述したように、コンター行列 C と、contourグループオブジェクト
% のハンドル番号からなる列ベクトル H をライン毎に出力します。これらは共に、
% CLABEL に対する入力として使うことができます。
%
% 下位互換性
% CONTOUR('v6',...) は、MATLAB 6.5およびそれ以前のバージョンとの互換性
% のため、contourグループオブジェクトの代わりにpatchオブジェクトを作成
% します。
%  
% コンターは、通常カレントのカラーマップに基づいてカラーリングされ、PATCH
% オブジェクトとして描画されます。指定したカラーとラインタイプをもつコン
% ターを描画するためには、シンタックスCONTOUR(...,'LINESPEC') を使って、
% この挙動を変更できます。
%
% 上記のCONTOURへの入力は、コンターオブジェクトのプロパティを指定するため
% にプロパティと値の組を続けることができます。
%
% このコマンドは、R. Pawlowiczが記述したコードを使用し、パラメトリックな
% サーフェスとインラインコンターラベルを扱います。
%
% 例題:
%      [c,h] = contour(peaks); clabel(c,h), colorbar
%
% 参考：CONTOUR3, CONTOURF, CLABEL, COLORBAR.


%   Copyright 1984-2002 The MathWorks, Inc. 
