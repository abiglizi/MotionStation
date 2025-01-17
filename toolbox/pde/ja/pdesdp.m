% PDESDP   サブドメイン集合における節点のインデックスを表示します。
% [I,C] = PDESDP(P,E,T,SDL) では、メッシュデータ P, E, T とサブドメイン
% 番号 SDL のリストを与えると、関数はそれらのサブドメインに属する全ての
% 節点を出力します。節点は、数個のサブドメインに属することができます。
% SDL のドメインに属している節点は、2つの互いに共通元をもたない集合に分
% 割されます。I は、SDL にリストされたサブドメインに属する全ての節点のイ
% ンデックスを含みます。C は、他のサブドメインに属している節点のインデッ
% クスをリストします。
%
% C = PDESDP(P,E,T,SDL) は、SDL の中で2つ以上のサブドメインに属する節点
% のインデックスを出力します。
%
% SDL が与えられなければ、全てのサブドメインのリストが SDL に与えられま
% す。



%       Copyright 1994-2001 The MathWorks, Inc.
