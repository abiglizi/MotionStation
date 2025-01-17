%INT8 符号付き8ビット整数への変換
% I = INT8(X) は、配列 X の要素を符号付き8ビット整数に変換します。
% X は、DOUBLE のような任意の数値オブジェクトになることができます。
% INT8 の値は、-128 から 127 まで、または、INTMIN('int8') から INTMAX('int8')
% までの範囲をとります。この範囲外の値は、オーバーフローに飽和、すなわち、
% この範囲外の場合、-128 または 127　に割り当てられます。X が、すでに符号付き
% 8ビット整数配列である場合、INT8  は影響を与えません。DOUBLE および SINGLE 
% の値は変換の際、最も近い INT8 の値への丸めが行われます。
%
% INT8 に対し、他の INT8 配列との演算に定義される算術演算があります。 
% たとえば、+, -, .*, ./, .\ および .^ です。
% 少なくとも1つのオペランドがスカラーの場合、*, /, \ および ^ も定義されます。
% INT8 配列は、また、定数を含む、スカラーの DOUBLE 変数との演算も行います。
% 演算の結果は、INT8 です。INT8 配列は、演算でオーバーフローに飽和します。
%
% ユーザのパス上のディレクトリ内の@int8ディレクトリに適切な名称のメソッド
% を用意することで、(任意のオブジェクトに対してと同様に) INT8 に対する
% ユーザ自身の手法を定義したり、オーバーロードすることができます。
% オーバロードできるメソッド名については、HELP DATATYPES をタイプして
% ください。
%
% つぎの方法は、大きい INT8 配列を初期化するのに特に効率的です。
%
%      I = zeros(1000,1000,'int8')
%
% これは、1000x1000 要素の INT8 配列を作成し、その要素はすべてゼロです。
% 同様の方法で、ONES や EYE を使用することもできます。
%
% 例題:
%      X = 17 * ones(5,6,'int8')
%
% 参考 DOUBLE, SINGLE, DATATYPES, ISINTEGER, UINT8, UINT16, UINT32,
%      UINT64, INT16, INT32, INT64, INTMIN, INTMAX, EYE, ONES, ZEROS.

%   Copyright 1984-2002 The MathWorks, Inc. 
