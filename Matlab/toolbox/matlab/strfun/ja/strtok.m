% STRTOK   文字列内のトークンの検出
% 
% STRTOK(S) は、文字列 S 内の空白で区切られた最初のトークンを出力します。
% 先頭の空白は無視します。S が文字列からなるセル配列の場合は、出力はトーク
% ンからなるセル配列です。
%
% STRTOK(S,D) は、D の中のキャラクタで区切られた、最初のトークンを出力
% します。
%
% [T,R] = STRTOK(...) は、オリジナルの文字列の残りも出力します。
% S 内でトークンが見つからない場合、R は空文字列になり、T は S と等しく
% なります。
% 
% 参考：ISSPACE, STRREAD.


%   Copyright 1984-2002 The MathWorks, Inc. 
