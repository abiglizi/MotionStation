% DATEVEC   日付の要素
% 
% C = DATEVEC(T) は、日付文字列と日付番号の要素を、[year month date 
% hour mins secs] を列としてもつ日付ベクトルに分割します。T が日付文字列の
% 場合は、DATESTR で定義されるような日付書式 0,1,2,6,13,14,15,16,23 の
% いずれかでなければなりません。書式の中には日付ベクトルを計算するための十分
% な情報を含まないものがある場合があります。そのような場合は、失われた値は、
% 一般的に、時、分、秒についてはデフォルトは0で、月に対してはJanuary、日に
% 対しては1です。年のデフォルトは現在の年です。年を表わす2文字の文字列は、
% 現在の年を中心とした100年の以内の年と解釈されます。
%
% [Y,M,D,H,MI,S] = DATEVEC(T) は、日付ベクトルの要素を個々の変数として
% 出力します。
%
% C = DATEVEC(T,F) は、日付文字列を解釈するために指定した日付書式Fを使って
% 日付文字列Tを日付ベクトルCに変換します。日付書式は、DATESTRヘルプの表2に
% 従って、日付書式シンボルで構成される必要があります。詳細は、上記の
% DATEVEC(T) を参照してください。'Q' を含む書式はdatevecでは利用できません。
%
% [...] = DAVEVEC(T,PIVOTYEAR) は、年を表わす2文字の文字列に対しては、
% 100年の範囲の開始年として指定したピボット年を使います。デフォルトの
% ピボット年は、現在の年のマイナス50年です。
%
%　C = DATEVEC(T,F,P) またはC = DATEVEC(T,P,F) は、ピボット年Pと日付書式F
% を使って、日付文字列Tを日付ベクトルCに変換します。
%
% 例題
%   d = '12/24/1984';
%   t = 725000.00;
%   c = datevec(d) または c = datevec(t)は、c = [1984 12 24 0 0 0] を
%   出力します。
%   [y,m,d,h,mi,s] = datevec(d) は、y = 1984、m = 12、d = 24、h = 0、mi = 0、
%   s = 0を出力します。
%   c = datevec('5/6/03') は、2054年まで c = [2003 5 6 0 0 0] を出力します。  %   c = datevec('5/6/03',1900) は、c = [1903 5 6 0 0 0] を出力します。
%   c = datevec('19.05.2000','dd.mm.yyyy') は、c = [2000 5 19 0 0 0]を出
% 力します。
%
% 参考：DATENUM, DATESTR, CLOCK, DATETICK.


%   Copyright 1984-2002 The MathWorks, Inc. 
