% RATS   有理数近似
% 
% RATS(X,LEN) は、RAT を使用して、X の要素の有理数近似を表示します。
% 各要素の文字列の長さは、LEN です。デフォルトは、LEN = 13 で、78文字分
% のスペース に6要素を表示することができます。割り当てられたスペースに
% 出力できずXの他の要素と比較して無視できない要素には、アスタリスクが
% 使われます。
%
% MATLABのFORMAT RATの内部で、デフォルトの LEN を使った、同じアルゴリズム
% が使用されます。
%
% 参考：FORMAT, RAT.


%   Cleve Moler, 10-28-90, 2-15-94.
%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.9.4.1 $  $Date: 2004/04/28 02:04:29 $

