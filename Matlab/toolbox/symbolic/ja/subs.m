% SUBS   シンボリックな代入
% SUBS(S) は、シンボリック式S内のすべての変数を、呼び出し関数、または、M
% ATLAB のワークスペースから得られる値で置き換えます。
%   
% SUBS(S, NEW) は、S 内のシンボリックな自由変数を NEW で置き換えます。
% SUBS(S, OLD, NEW) は、シンボリック式S内の OLD を NEW で置き換えます。
% OLD は、シンボリック変数、変数名を表わす文字列、コーテーションで囲まれ
% た文字列表現です。NEW は、シンボリック変数または数値的な変数、あるいは
% 式です。
%
% OLD と NEW が同じサイズのセル配列ならば、OLD の各要素は、NEW の対応す
% る要素で置き換えられます。S と OLD がスカラで、NEW が配列、または、セ
% ル配列ならば、スカラを拡張して、配列の結果を生成します。NEW が数値行列
% からなるセル配列ならば、要素ごとの代入が実行されます(すなわち、A と B 
% が数値配列のとき、subs(x*y, {x,y}, {A,B})は、A.*B を出力します)。
%
% SUBS(S, OLD, NEW) により S が変更されなければ、SUBS(S, NEW, OLD) が試
% されます。これは、前バージョンに対する互換性を提供します。これにより、
% 引数の順序を覚える必要はありません。S が変更されなければ、SUBS(S, OLD,
% NEW, 0)は、引数の入れ替えを行いません。
%
% 例題 :
% 単入力:
% ワークスペース内に、a = 980とC1 = 3が存在すると仮定します。
% ステートメント
% 
%     y = dsolve('Dy = -a*y')
% 
% は、つぎの結果を出力します。
% 
%     y = exp(-a*t)*C1
% 
% ステートメント
% 
%     subs(y)
% 
% は、つぎの結果を出力します。
% 
%     ans = 3*exp(-980*t)
%
% 1変数の代入:
% 
%    subs(a+b,a,4)は、4+bを出力します。
%
% 多変数の代入:
% 
%    subs(cos(a)+sin(b),{a,b},{sym('alpha'),2})は、cos(alpha)+sin(2)を出
%    力します。
%   
% スカラ式の場合: 
% 
%    subs(exp(a*t),'a',-magic(2))は、つぎの結果を出力します。
%
%       [   exp(-t), exp(-3*t)]
%       [ exp(-4*t), exp(-2*t)]
%
% 複数のスカラ式の場合:
% 
%    subs(x*y,{x,y},{[0 1;-1 0],[1 -1;-2 1]})は、つぎの結果を出力します。
% 
%       [  0, -1]
%       [  2,  0]
%
% 参考   SUBEXPR



%   Copyright 1993-2002 The MathWorks, Inc. 
