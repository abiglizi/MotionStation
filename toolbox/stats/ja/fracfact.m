% FRACFACT   2レベルの一部実施計画を作成
%
% X = FRACFACT(GEN) は、作成器 GEN で定義された一部実施計画を行います。
% GEN は、スペースで区切られた"語"を集めたものです。作成器を表す文字列が、
% アルファベットの K 個の文字を使って、P 個の語(項目)から構成している
% 場合、X は、N=2^K 行 と P 列になります。
%
% [A, CONF] = FRACFACT(GEN) は、設計に対して、区別できないパターンを
% 含んだ文字のセル配列 CONF も出力します。
%
% たとえば、
%
%   x = fracfact('a b c abc')
%
% は、4つの変数に対して、8通りの2レベルの一部実施計画を行います。ここで、
% 最初の3つの列は、最初の3つの変数に対する8実行、2レベルの完全実施計画
% になります。そして、4番目の列は、最初の3つの列の3種類の相互関係を
% 取り違えたものです。


%   Tom Lane, 3-19-99
%   Copyright 1993-2002 The MathWorks, Inc. 
%   $Revision: 1.6 $  $Date: 2003/02/12 17:09:15 $
