% PACK   ワークスペースメモリの整理
% 
% PACKは、メモリガーベージコレクションを行います。MATLABセッションは、メ
% モリを断片的に使うため、大きな変数が格納されません。PACKは、すべての変
% 数をディスク上に保存し、一度、メモリを消去し、その後、変数をリロードし
% ます。
%
% メモリの不足が頻繁に起こる場合は、システムに固有のつぎのような解決法を
% 行ってください。
% 
% Windows   : コントロールパネルを使って仮想メモリを増量してください。
% Unix      : スワップ領域を増やすように、システム管理者に相談してくださ
%             い。
%
% このコマンドを実行できるためには、"書き込み"権を設定しているディレクト
% リに移動してください。つぎのステートメントは、ワークスペースメモリの
% 整理を行う1つの例を示したものです。
%
%           cwd = pwd;
%           cd(tempdir);
%           pack
%           cd(cwd)
%
% 参考：MEMORY.



%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.10.4.1 $  $Date: 2004/04/28 01:53:26 $
%   Built-in function.
