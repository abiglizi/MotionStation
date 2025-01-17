% GPLOTMATRIX   共通変数でグループ化された散布図プロット行列
%
% GPLOTMATRIX(X,Y,G) は、G でグループ化されたY の列に対する X の列の
% 散布図プロット行列を作成します。X が P 行 M 列で、Y が P 行 N 列の場合、
% GPLOTMATRIX は、軸の N 行 M 列の行列を作成します。G は、各行列内の
% 各点に対するマーカやカラーを設定します。Y を省略するか、[] で設定する
% 場合、関数は、X と X との関係をグラフ化します。G は、各行列内の各点に
% 割り当てられたマーカーとカラーで定義されるグループ化変数で、ベクトル、
% または文字列の行列、文字列のセル配列です。また、G は、グループ化変数の
% それぞれユニークな結合によって X 内の値をグループ化するために、
% ({G1 G2 G3} のように) グループ化変数のセル配列としても構いません。
% 
% GPLOTMATRIX(X,Y,G,CLR,MRK,SIZ) は、使用するカラー、マーカ、大きさを
% 指定します。CLR は、カラーの仕様を設定する文字列、MRK は、マーカの
% 仕様を設定する文字列です。より詳細な情報を得るには、"help plot"と入力
% してください。たとえば、MRX = 'o+x'は、最初のグループを円マークで、
% 2番目のグループをプラスマークで、3番目をxマークで、表示します。SIZ は、
% プロットで使用するマーカの大きさを指定します。デフォルトでは、カラーは
% 'bgrcmyk'、マーカは'.'、マーカの大きさは、figureウィンドウの大きさと
% プロット数に依存します。
% 
% GPLOTMATRIX(X,Y,G,CLR,MRK,SIZ,DOLEG) は、凡例を作成するか否かをコント
% ロールします。DOLEG は、'on'(デフォルト)または、'off' のいずれかを
% 設定します。
% 
% GPLOTMATRIX(X,Y,G,CLR,MRK,SIZ,DOLEG,DISPOPT) は、X と Y の関係のプロット
% 図の中で、対角部の塗りつぶし法をコントロールします。DISPOPT を 'none' 
% とすると空白のままになり、'hist'(デフォルト)とするとヒストグラムを
% プロットし、'variable' の場合は変数名を記述します。
% 
% GPLOTMATRIX(X,Y,G,CLR,MRK,SIZ,DOLEG,DISPOPT,XNAM,YNAM) は、X と Y 変数
% の名前を XNAM と YNAM を使って、設定します。それぞれは、適切な次元の
% キャラクタ配列である必要があります。
% 
% [H,AX,BigAx] = GPLOTMATRIX(...) は、作成したオブジェクトのハンドル番号
% からなる配列を H に出力し、個々のサブ軸のハンドル番号は AX に、サブ軸
% から作成する大きな(非可視)軸のハンドル番号は BigAx に出力します。
% BigAx は、CurrentAxes となり、それらに続く TITLE, XLABEL, YLABEL の
% いずれかは、軸の行列に関して中央に位置します。


%   Tom Lane, 5-4-1999
%   Copyright 1993-2002 The MathWorks, Inc. 
%   $Revision: 1.6 $  $Date: 2003/02/12 17:12:16 $
