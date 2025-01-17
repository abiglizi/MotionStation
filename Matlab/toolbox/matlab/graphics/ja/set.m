% SET   オブジェクトのプロパティの設定
% 
% SET(H,'PropertyName',PropertyValue) は、ハンドル番号が H のグラフィックス
% オブジェクトの指定したプロパティの値を設定します。H は、ハンドル番号を
% 要素とするベクトルで、この場合 SET は、すべてのオブジェクトのプロパティ
% 値を設定します。
%
% SET(H,a) は、a がフィールド名がオブジェクトのプロパティ名である構造体の
% とき、各フィールド名で識別されるプロパティを、構造体に含まれる値を使っ
% て設定します。
%
% SET(H,pn,pv) は、H で指定されたすべてのオブジェクトに対して、文字列から
% なるセル配列 pn で指定されたプロパティを、セル配列pv内の対応する値に
% 設定します。セル配列 pn は1行N列でなければなりませんが、セル配列 pv は、
% Mがlength(H) のとき、M行N列でも構いません。このため、各オブジェクトが pn
% に含まれるプロパティ名のリストに対して異なる値を使って更新されます。
% 
% SET(H,'PropertyName1',PropertyValue1,'PropertyName2',PropertyValue2,...)
% は、1つの文で複数のプロパティ値を設定します。SET の同じ呼び出しで、プロ
% パティと値の文字列の組、構造体、プロパティと値のセル配列の組を使うことが
% できます。
%
%   A = SET(H、'PropertyName') 
%   SET(H,'PropertyName')
% 
% は、ハンドル番号が H のオブジェクトの指定したプロパティに対して取り得る
% 値を出力または表示します。出力される配列は、可能な値の文字列からなる
% セル配列、またはプロパティが可能な文字列の値の有限な組をもたない場合
% は、空のセル配列です。
% 
%   A = SET(H) 
% 
% SET(H)は、ハンドル番号が H のオブジェクトのすべてのプロパティ名と、それ
% らの取りうる値を出力または表示します。出力値は、フィールド名が H のプロ
% パティ名、その値が取りうるプロパティ値からなるセル配列または空のセル配
% 列である構造体です。
%
% オブジェクトのプロパティのデフォルト値は、文字列 'Default'、オブジェク
% トタイプ、プロパティ名をつなげて作られる ProprtyName を設定することで、
% オブジェクトの上位のものに対して設定されます。たとえば、カレントの
% figureウィンドウのtextオブジェクトのデフォルトの色を赤に設定する場合は
%
%    set(gcf,'DefaultTextColor','red')
% 
% デフォルト値は、オブジェクトの下位やオブジェクト自身に対しては設定でき
% ません。たとえば、'DefaultAxesColor' の値は、axesやaxesの子に対しては設
% 定できませんが、figureやルートに対しては設定できます。
%
% PropertyValues に対して、つぎの3つの文字列は特別な意味があります。
% 
%   'default' - デフォルト値を使用(最近接の親)
%   'factory' - 作成時に定義された値を使用
%   'remove'  - デフォルト値を消去
% 
% 参考：GET, RESET, DELETE, GCF, GCA, FIGURE, AXES.



%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.9.4.1 $  $Date: 2004/04/28 01:56:12 $
%   Built-in function.
