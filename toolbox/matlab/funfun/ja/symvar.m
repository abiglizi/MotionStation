% SYMVAR   数式の内部のシンボリック変数の決定.
%
% SYMVAR(S) は、'i','j','pi'、'inf'、'nan'、'eps'、および、一般的
% に使われる関数以外の識別子を文字列 から検索します。変数は、文字列の
% セル配列として出力されます。そのような変数が存在しない場合は、空セル
% 配列 {} が出力されます。 
%
% 注意: 'f(1)' のような数式では、SYMVAR は、シンボリックな変数内のイン
% デックスとしてではなく、関数コールとしてシンボル 'f' を解釈します。
%
% 例題
%      symvar('cos(pi*x - beta1)') returns {'beta1';'x'}
%
% 参考 ： FINDSTR.


%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.10.4.1 $ $Date: 2004/04/28 01:52:44 $
