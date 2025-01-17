% FNPLT   関数のプロット
%
% FNPLT(F) は、F にある関数を基本区間でプロットします。
%
% FNPLT(F,SYMBOL,INTERV,LINEWIDTH,JUMPS) は、指定した INTERV = [a,b] 
% (デフォルトは基本区間）における関数 F を、指定した SYMBOL（デフォルトは 
% '-')と LINEWIDTH (デフォルトは1)を用いてプロットします。さらに、JUMPS が
% 'j' ではじまる文字列である場合のみ、飛びを実際の飛びとして示すために、
% NaN を使用してプロットします。
%
% 4つのオプション引数を、任意の順序で並べることができます。INTERV は、
% [1 2] の大きさで、SYMBOL と JUMPS は文字列で、LINEWIDTH はスカラです。
% 空のオプション引数は、いずれも無視されます。
%
% F にある関数が2要素のベクトル値の場合、平面曲線がプロットされます。
% F にある関数が、d>2 であるd要素のベクトル値の場合、F の最初の3成分に
% よって与えられる空間曲線がプロットされます。
%
% 関数が多変数の場合、付加的な変数については基本区間の中間点を使って、
% 2変数関数としてプロットされます。
%
% POINTS = FNPLT(F,...) は、プロットはしませんが、2次元の点または3次元の
% 点の列 F(T) を出力します。
%
% [POINTS, T] = FNPLT(F,...) は、ベクトル値 F に対して、対応するパラメータ
% 値のベクトル T も出力します。
%
% 例題:
%      x=linspace(0,2*pi,21); f = spapi(4,x,sin(x));
%      fnplt(f,'r',3,[1 3])
%
% は、赤色で線の幅を3として、区間 [1 .. 3] での f にある関数のグラフを
% プロットします。


%   Copyright 1987-2003 C. de Boor and The MathWorks, Inc.
