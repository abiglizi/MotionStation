% SPAP2   スプライン最小二乗近似
%
% SPAP2(KNOTS,K,X,Y) は、節点列 KNOTS をもつ K次のスプラインによって、
% データ X, Y への f の最小二乗近似のB-型を出力します。
% データサイト X(j) でのスプライン近似は、j=1:length(X) としたときの
% データ値 Y(:,j) を与えます。
% データ値は、スカラ、ベクトル、行列、またはN次元配列です。
% 同じサイトのデータ点は、それらの平均によって置き換えられます。
%
% f は、
%
% (*)                Y = f(X)
%
% に対して、二乗平均の意味で(すなわち、下式を最小化する)節点列 KNOTS を
% もつK次のスプラインです。
%
% (**)   sum_j W(j) |Y(:,j) - f(X(j))|^2 ,
%
% ここで、W = ones(size(X)) です。オプション引数、すなわち、(**)を最小化
% するK次の節点 KNOTS をもったスプライン f を出力する 
% SPAP2(KNOTS,K,X,Y,W) を使って他の重みを指定することもできます。
% デフォルトの W = ones(size(X)) よりもよい選択として、複合台形則の重み 
% dx = diff(X(:)) となる W = ([dx;0]+[0;dx]).'/2 が適切です(X は、厳密に
% 増加するものと仮定します)。
%
% データサイトがSchoenberg-Whitney条件
%
% (***)   KNOTS(j) < X(j) < KNOTS(j+K) ,
%                             j=1:length(X)=length(KNOTS)-K ,
%
% を満たす(多重度 K の節点において等間隔である)とき、f は、(***)の次数を
% 厳密に満たすユニークなスプラインです。X のいくらかの部分列に対して
% (***)を満たさない場合、スプラインは出力されません。
%
% 与えられたデータサイトに対して、そのような節点列を与えるのは難しいかも
% しれないため、正の整数として KNOTS を指定することが可能です。その場合、
% 可能であれば、X のある部分列に対して (***) を満たす節点列が与えられ、
% KNOTS 多項式区分から構成されるスプラインを出力します。
%
% Y が行列、またはより一般的に、[d1,...,ds,n] のN次元配列の場合、
% Y(:,...,:,j) は、X(j) で近似された値で、結果のスプラインは、[d1,...,ds]
% 個の値に対応します。この場合、誤差基準 (**) 内の式 |Y(:,j) - f(X(j))|^2 
% は、Y(:,j)-f(X(j)) のすべての要素 d1*...*ds の二乗和を意味します。
%
% グリッド化されたデータを近似することも可能です。
%
% SPAP2( {KNOTS1,...,KNOTSm}, [K1,...,Km], {X1,...,Xm}, Y ) は、組み合わ
% せ次数 Ki で、i=1,...,m について、i番目の変数の節点列 KNOTSi をもつ
% m変数テンソル積スプラインを出力します。これに対しては、すべての 
% i := (i1,...,im) で(場合によっては重み付き)二乗平均の意味で
%
% Y(:,...,:,i1,...,im) = f(X1(i1),...,Xm(im))  
%
% が成り立ちます。
% ベクトル値の、更にはN次元の値のデータへの近似の可能性に注目します。
% 1変数の場合と異なり、フィットされるデータがスカラ値ならば、入力配列 
% Y はm次元にすることができます。このとき、(重み付き)二乗平均の意味で、
% つぎのようになります。
%
% すべての i := (i1,...,im) で
% Y(i1,...,im) = f(X1(i1),...,Xm(im)),  
%
% 例題 1:
%
%      spap2(augknt(x([1 end]),2),2,x,y);
%
% は、データ x,y の最小二乗直線近似を与え、すべてのサイト x(j) が区間 
% [x(1) .. x(end)] 内にあると仮定します。一方、
% 
%      spap2(1,2,x,y);
%
% は、条件なしでこれを実行します。そして、条件がある場合、
%
%      w = ones(size(x)); w([1 end]) = 100;
%      spap2(1,2,x,y,w);
%
% は、そのフィッティングがなるべく最初と最後のデータ点で近くなるように
% 近似します。
%
% 例題 2: ステートメント
%
%      x = -2:.2:2; y=-1:.25:1; [xx, yy] = ndgrid(x,y); 
%      z = exp(-(xx.^2+yy.^2)); 
%      sp = spap2({augknt([-2:2],3),2},[3 4],{x,y},z);
%      fnplt(sp)
% 
% は、2変数関数に近似を行った図を作成します。
% ここで NDGRID の代わりに MESHGRID を使用すると、エラーになります。
%
% 参考 : SPAPI, SPAPS.


%   Copyright 1987-2003 C. de Boor and The MathWorks, Inc.
