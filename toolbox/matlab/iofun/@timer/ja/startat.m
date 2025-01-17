% STARTAT   指定された時間にタイマーを稼動
%
% STARTAT(OBJ,TIME) は、シリアルな日付番号 TIME で指定された時間に、
% timer オブジェクト OBJ で表されるタイマーの実行を開始します。OBJ は、
% timer オブジェクトの配列である場合、STARTAT はすべてのタイマーを
% 指定された時間稼動します。TIMER 関数は、timer オブジェクトを作成する
% ために使われます。
%
% START は、timer オブジェクト OBJ の Running プロパティを 'On' に設定し、
% TimerFcn コールバックを初期化し、StartFcn コールバックを実行します。
%
% シリアルな日付番号 TIME は、1-Jan-0000 から経過した日の数を示します
% (開始は1です)。シリアルな日付番号についての追加情報は、DATENUM を参照
% してください。
% 
% STARTAT(OBJ,S) は、日付の文字列 S で指定された時間にタイマーを開始
% します。日付の文字列は、DATESTR 関数で定義された 0,1,2,6,13,14,15,16,23 
% の日付の書式を使用しなければなりません。年を表す2文字の日付の文字列は、
% 現在の年を中心とした100年の範囲内と解釈されます。
%
% STARTAT(OBJ,S,PIVOTYEAR) は、年を表す2文字の場合に、100年の範囲を開始年
% として、指定したピボット年を使います。デフォルトのピボット年は、現在の
% 年のマイナス50年です。
% 
% STARTAT(OBJ,Y,M,D) と STARTAT(OBJ, [Y,M,D]) は、指定された年(Y)、
% 月(M)、日(D) にタイマーを稼動します。Y,M,Dは、同じサイズの配列(または
% スカラ)でなければなりません。
% 
% STARTAT(OBJ,Y,M,D,H,MI,S) と STARTAT(OBJ,[Y,M,D,H,MI,S]) は、指定された
% 年(Y)、月(M)、日(D)、時間(H)、分(MI)、秒(S) にタイマーを稼動します。
% Y,M,D,H,MI,S は、同じサイズの配列(またはスカラ)でなければなりません。
% 各配列の通常の範囲の外側の値は、自動的に次の単位に移行されます(例えば、
% 12よりも大きい月の値は、年に移行されます)。1よりも小さい月の値は、1に
% 設定され、それ以外の単位はすべてまとめられ、有効な負の値をもちます。
%
% 以下の条件の一つが適用された場合、タイマーを停止します。:
%  - 実行された TimerFcn コールバックの数が、TasksToExecute プロパティ
%    で指定された数に等しくなった場合
%  - STOP(OBJ) コマンドが発行された場合
%  - TimerFcn コールバックの実行中にエラーが発生した場合
%
% 例題:
%        t1=timer('TimerFcn','disp(''it is 10 o''''clock'')');
%        startat(t1,'10:00:00');
%
%        t2=timer('TimerFcn','disp(''It has been an hour now.'')');
%        startat(t2,now+1/24);
%
% 参考 : TIMER, TIMER/START, TIMER/STOP, DATENUM, DATESTR, NOW.


%    RDD 11-20-2001
%    Copyright 2001-2002 The MathWorks, Inc. 
%    $Revision: 1.1.4.1 $  $Date: 2004/04/28 01:57:47 $

