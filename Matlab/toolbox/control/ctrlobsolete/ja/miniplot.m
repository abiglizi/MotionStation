% MINIPLOT   複数の小さなプロットの重ね書き
% 
% [H,AX,BigAx] = MINIPLOT(ROWS,COLS,X1,Y1, ...) は、軸を ROWS 行 COLS 列
% の行列に分け、その中にデータをプロットします。たとえば、つぎのコマンド
% を試してください。
% 
%    miniplot(4,3,(1:10)',rand(10,12))
%
% H は、作成するラインを示すハンドル番号の行列です。H の最初の列は、x1 
% と y1 で作成するラインのハンドル番号で、二番目の列は、x2 と y2 で作成
% するラインのハンドル番号です。
%
% AX は、列の順でのサブ軸のベクトルです。
%
% BigAx は、サブ軸を形作る大きな(可視状態でない)軸に対するハンドル番号です。
%
% 注意：
% ------
% Xi と Yi は、* 列 * ベクトルで、期待した通りの結果を生じます。
%
% 機能が完了すると、BigAx は、CurrentAxes になります。この場合、MINIPLOT
% をコールすることができ、ラベル、タイトルコマンドを読み込み、"正しい位
% 置"に表示します。
%
% スピードに関して、軸に対してたった2つのラインのみが作成される可能性が
% あります。
%
% figureの NextPlot プロパティは、ホールド状態が解除されている場合、
% replace となります。これは、他のプロットコマンドに関して、予想通りの
% 結果になります。
%
% 参考 : SUBAXES


%       Author(s): A. Potvin, 11-1-94
%   Copyright 1986-2002 The MathWorks, Inc. 
%   $Revision: 1.6.4.1 $  $Date: 2003/06/26 16:08:12 $
