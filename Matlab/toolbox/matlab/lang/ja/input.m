% INPUT   ユーザ入力の要求
% 
% R = INPUT('How many apples') は、プロンプトをテキスト文字列の中に設定
% でき、キーボードからの入力を待ちます。入力は、カレントのワークスペース
% の変数を使って実行されるMATLAB表現で、結果は R に出力されます。ユーザ
% が何も入力せずにリターンキーを押した場合は、INPUT は空行列を出力します。
%
% R = INPUT('What is your name','s') は、プロンプトとしてテキスト文字列を
% 表示し、キャラクタ文字列の入力を待ちます。タイプされた入力は、評価され
% ません。キャラクタは、単にMATLAB文字列として出力されます。
%
% プロンプトとしてのテキスト文字列には、1つ以上の '\n' を用いることが
% できます。'\n' は、つぎの行の先頭に移動することを意味します。これに
% より、プロンプト文字列を複数行にすることができます。'\' を表示する
% ためには、'\\' を使ってください。
%
% 参考：KEYBOARD.


%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.9.4.1 $  $Date: 2004/04/28 01:59:05 $
%   Built-in function.
