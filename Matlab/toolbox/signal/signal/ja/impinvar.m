% IMPINVAR アナログからディジタルフィルタへの変換のインパルス不変応答法
%
% [BZ,AZ] = IMPINVAR(B,A,Fs)は、設定したサンプリング周波数Fs(Hz)で、係数
% B(分子)と係数A(分母)をもつアナログフィルタのインパルス応答と等しいイン
% パルス応答をもつディジタルフィルタの係数BZとAZを出力します。係数B,Aは、
% 1/Fsでスケーリングされています。
%
% Fsを設定しないと、デフォルト値 1Hz を使用します。
%
% [BZ,AZ] = IMPINVAR(B,A,Fs,TOL)は、重複している極をグループ化する際の許
% 容誤差TOLを指定することができます。デフォルト値は、0.001つまり 0.1%で
% 設定されています。
%
% 注意:
% 重複している極の場合は、根を多項式に変換する関数ROOTSによって制限を受
% けます。
%
% 参考：   BILINEAR.



%   Copyright 1988-2002 The MathWorks, Inc.
