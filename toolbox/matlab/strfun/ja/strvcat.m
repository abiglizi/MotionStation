% STRVCAT   文字列の垂直方向の結合
% 
% S = STRVCAT(T1,T2,T3,..) は、テキスト文字列 T1,T2,T3,...を行として含む
% 行列 S を作成します。有効な行列を作成するために、文字列にブランクを
% 自動的に付け加えます。各々のテキストパラメータ Ti は、それ自身が文字列
% 行列でも構いません。これを使って任意の大きさの文字列行列を作成できます。
% 入力中の空の文字列は、無視されます。
%
% S = STRVCAT(C) は、C の各要素を STRVCAT への入力として渡します。ここで、
% C は文字のセル配列です。入力の中の空の文字列は、無視されます。
%
% STRVCAT('Hello','Yes') は、自動的に空白を付け加えることを除けば、
% ['Hello';'Yes  '] と同じです。
%
% 参考：CELLSTR, CHAR.


%   Clay M. Thompson  3-20-91
%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.8.4.1 $  $Date: 2004/04/28 02:07:18 $
