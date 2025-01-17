% TABLEREF
% CheckContinue
% 実行の開始時に起動します。空を出力する場合には、プロパティテーブルを作
% 成します。文字列を出力する場合には、実行を停止し、文字列をエラーメッセ
% ージとして表示します。
%  
%    GetPropList(filter)       - フィルタが変更されるときに呼び出されま
%                                す。フィルタに対するプロパティのリスト
%                                を与えます。
%    GetFilterList             - 起動時に呼び出されます。有効な全てのフ
%                                ィルタのリストを取得します。
%    GetPropCell(property)     - 実行中に呼び出されます。文法解釈されな
%                                いセル構造体と解釈されたプロパティ名を
%                                与えます。
%    GetPresetList             - "apply preset table"ポップアップメニュ
%                                ーに対する全てのプリセットテーブルのリ
%                                ストを取得します。
%    GetPresetTable(tablename) - テーブルに対する新たな属性の配列を出力
%                                します。





% $Revision: 1.1.6.1 $ $Date: 2004/03/21 22:33:45 $
%   Copyright 1997-2002 The MathWorks, Inc.
