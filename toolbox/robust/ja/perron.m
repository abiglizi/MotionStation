% PERRON   Perron固有値
%
% [MU] = PERRON(A)、または、[MU] = PERRON(A,K)は、SafonovのPerron固有値法
% (IEE Proc., Pt. D, Nov. '82)によって計算される構造化特異値(ssv)の
% スカラ上界MUを計算します。
%
% 入力:
%     A  -- ssvが計算されるp行q列の複素行列。
% オプションの入力:
%     K  -- 不確かさのブロックサイズ。デフォルトは、K=ones(q,2)です。
%           Kは、n行1列またはn行2列行列で、その行はssvが評価される
%           不確かさブロックサイズです。Kは、sum(K) == [q,p]を
%           満足しなければなりません。Kの1番目の列のみが与えられた場合は、
%           不確かさブロックは、K(:,2)=K(:,1)のように正方になります。
% 出力:
%     MU -- Aの構造化特異値の上界。



% Copyright 1988-2002 The MathWorks, Inc. 
