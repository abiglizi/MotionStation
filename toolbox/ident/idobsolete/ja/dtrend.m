% DTREND データセットからのトレンドの除去
% 
%   ZD = DTREND(Z) または、ZD = DTREND(Z,O,BREAKPOINTS)
%
%   Z  : 列ベクトルとしてまとめられた、トレンドを除去するデータセット。
%   ZD : トレンド除去後のデータ。
%
%   O = 0の場合、各列からサンプル平均を除去します。(デフォルト)
%   O = 1の場合、線形トレンドを除去します。連続的な区分的線形トレンドが
%       各々のデータ暦に適合され、除去されます。行ベクトル BREAKPOINTS 
%       に、線形トレンドの区分のためのブレークポイントが設定されます。デ
%       フォルト値ではブレークポイントを設定しません。従って、ある一つの
%       直線データが各々のデータ暦から除去されます。
%
% この関数は古い関数で、将来バージョンでは対応しません。代わりに、DETR-
% END を利用してください。
%
%   参考:    DETREND, IDFILT.

%   Copyright 1986-2001 The MathWorks, Inc.
