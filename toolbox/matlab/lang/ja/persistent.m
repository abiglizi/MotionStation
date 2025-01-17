% PERSISTENT   固定変数の定義
% 
% PERSISTENT X Y Z は、X、Y、Z が呼び出しとそのつぎの呼び出しとの間で
% それらの値を保持するように、X、Y、Z を固定変数として定義します。固定
% 変数は、グローバル変数と似ています。これは、MATLAB が、2つの変数に
% 対するパーマネントストレージを作成するからです。固定変数は、それを宣
% 言した関数でのみ既知で、この点がグローバル変数と異なります。これによ
% り、他の関数や、MATLAB コマンドラインからこれらを変更することを固定変
% 数は避けることができます。
%
% 固定変数は、M-ファイルがメモリから消去されるか、M-ファイルが変更され
% るときに消去されます。MATLABを終了するまでM-ファイルをメモリ内に
% 置いておくためには、MLOCK を使ってください。
%
% 最初にPERSISTENTステートメントを実行したときに固定変数が存在しない場
% 合は、変数は空行列で初期化されます。
%
% カレントのワークスペースに同じ名前の変数が存在する場合は、固定変数を
% 宣言すると、エラーになります。
%
% 参考：GLOBAL, CLEAR, MLOCK, MUNLOCK, MISLOCKED.


%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.9.4.1 $  $Date: 2004/04/28 01:59:25 $
%   Built-in function.
