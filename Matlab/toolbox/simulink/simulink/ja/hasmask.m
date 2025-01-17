% HASMASK   マスクの存在の確認
%
% VALUE = HASMASK(SYS) は、ブロックがマスクされていなければ0を出力し、ブロッ
% クがグラフィカルなマスクをもつ場合は1を、ブロックが関数的なマスクをもつ場
% 合は2を出力します。グラフィカルなマスクは、マスク内にワークスペースが存在しな
% いことを意味します。これは、通常ブロックまたはシステムがアイコンのみをもつ
% ことを示します。関数的なマスクは、マスクに別のワークスペースが存在することを
% 意味します。これは、通常、マスクがダブルクリックされたときにダイアログが表示
% されることを示します。
%
% SYS は、ブロックの絶対パス名、ブロックのハンドル、絶対パス名のセル配列、ハン
% ドルのベクトルのいずれかです。
%
% 参考 : GET_PARAM, HASMASKDLG, HASMASKICON, LOOKUNDERMASK.


% Copyright 1990-2002 The MathWorks, Inc.
