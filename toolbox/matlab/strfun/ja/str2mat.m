% STR2MAT   ブランクを挿入したキャラクタ行列を文字列から作成
% 
% S = STR2MAT(T1,T2,T3,..) は、テキスト文字列 T1,T2,T3,...を行として含む
% 行列 S を作成します。有効な行列を作成するために、文字列にブランクを
% 自動的に付け加えます。各テキストパラメータTiは、それ自身が文字列行列
% でも構いません。これにより、任意の大きさの文字列行列を作成できます。
% 空の文字列は、意味をもちます。
%
% STR2MAT は、空の文字列はブランク行を出力する点が、STRVCAT と異なります。
% STRVCAT では、空文字列は無視されます。
%
% STR2MAT は、古いものです。代わりに、CHAR 関数を使ってください。
%
% 参考：CHAR, STRVCAT.


%   Clay M. Thompson  3-20-91, 5-16-95
%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.8.4.1 $  $Date: 2004/04/28 02:07:05 $
