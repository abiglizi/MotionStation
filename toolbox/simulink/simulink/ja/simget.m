% SIMGET   SIM オプション構造体の取得
%
% Struct  =  SIMGET(MODEL) は、与えられたSimulinkモデルに対するカレントの
% SIM コマンドのオプション構造体を出力します。Options構造体は、SIM、および、
% SIMSET コマンドで用いられます。
%
% Value  =  SIMGET(MODEL,property) は、指定されたシミュレーションパラメータ、
% または、ソルバのプロパティ値をモデルから抽出します。
%
% Value = SIMGET(OptionStructure,property) は、指定されたシミュレーションパラ
% メータ、または、ソルバのプロパティ値を OptionStructure から抽出し、構造体に値
% が指定されていない場合は空行列を出力します。プロパティは、関連するパラメー
% タとプロパティ名のリストを含むセル配列とすることができます。セル配列を使用
% すると、出力もセル配列です。
%
% プロパティ名は、一意的に識別するために必要な頭文字を入力するだけで構いません
% 。プロパティ名については、大文字と小文字の区別は無視されます。
%
% Struct  =  SIMGET は、フィールドを [] に設定したフルオプション構造体を出力
% します。
%
% 参考 : SIM, SIMSET.


% Copyright 1990-2002 The MathWorks, Inc.
