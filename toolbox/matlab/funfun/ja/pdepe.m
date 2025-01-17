% PDEPE   1次元の放物型-楕円型PDEにおける初期-境界値問題を解きます。
%
% SOL = PDEPE(M,PDEFUN,ICFUN,BCFUN,XMESH,TSPAN) は、1つの空間
% を表現する変数 x と時間 t による放物型と楕円型のPDEの小さなシステム
% の初期-境界値問題を中程度の精度で解きます。つぎの形式の npde 個の
% 方程式によるシステムを満たす npde 個の未知の解の要素があります。   
%
%   c(x,t,u,Du/Dx) * Du/Dt = x^(-m) * D(x^m * f(x,t,u,Du/Dx))/Dx + s(x,t,u,Du/Dx)
% 
% ここで、f(x,t,u,Du/Dx) は流束で、s(x,t,u,Du/Dx) は入力項です。m は、
% 0, 1, 2 で、それぞれ対称性をもつ平面、円筒名、球面に対応します。
% 時間に関する偏微分係数のカップリングは、対角行列 c(x,t,u,Du/Dx) との
% 積に制限されます。c の対角要素は等しく、ゼロまたは正です。ゼロに等し
% い要素は楕円型方程式に対応し、そうでなければ、放物型方程式に対応
% します。少なくとも1つの放物型方程式は存在しなければなりません。
% 放物型方程式に対応する c の成分は、与えられたxの孤立した値でゼロに
% でき、それらはメッシュ XMESH に含まれ、特に間隔の最後でいつもゼロに
% できます。PDEは、t0 <= t <= tf かつ a <= x <= b で成り立ちます。区間
% [a,b] は、有限でなければなりません。m > 0 の場合は、0 <= a が必要条
% 件です。解の要素は、初期時間 t = t0 で既知で、初期条件です。解の
% 要素は、つぎの式のすべての t において、x=a と x=b で境界条件を満たし
% ます。
% 
%       p(x,t,u) + q(x,t) * f(x,t,u,Du/Dx) = 0 
%
% q(x,t) は、対角行列です。q の対角要素は、すべてゼロになるか、すべて
% ゼロでないかのどちらかです。境界条件は Du/Dx より、むしろ流束の項
% で表現されることに注意してください。また、2つの係数で表現され、p のみが
% u に依存することが可能です。      
%
% 入力引数 M は、問題の対称性を定義します。
%
% [C,F,S] = PDEFUN(X,T,U,DUDX) は、微分方程式を定義している精度(品質)
% を計算する関数です。入力引数は、スカラ X と T 、およびベクトル U と DUDX 
% で、解と x に関する偏微分係数を近似するものです。PDEFUN は、列ベクトル
% C (行列 c(x,t,u,Dx/Du) の対角要素を含んでいます), F, S (流量とソースの
% 項をそれぞれ表わします)です。
%
% U = ICFUN(X) は、初期条件を計算する関数です。スカラ引数 X と共に呼び
% 出されるときは、ICFUN は、列ベクトル U に X での解の要素の初期値を
% 計算し、出力します。  
%
% [PL,QL,PR,QR] = BCFUN(XL,UL,XR,UR,T) は、時間 T での境界条件の要素
% を計算する関数です。PL と QL は、p に対応した列ベクトルと、q の対角要
% 素で、左境界で計算されます。同様に、PR と QR は、右境界で計算されます。
% m > 0 かつ a = 0 の場合、x = 0 の近傍の解の境界部は、a = 0 で流量 f が
% ゼロになる必要があります。PDEPE は、この境界条件を自動的に設定します。
%
% PDEPE は、入力配列 XMESH として与えられたメッシュ上の解の値を出力
% します。XMESH の要素は、NX >= 3 に対して、
%       a = XMESH(1) < XMESH(2) < ... < XMESH(NX) = b 
% を満たさなければなりません。問題が流束 f は接続点で連続であることが
% 要求される問題で、メッシュ点が各接続点に配置されている場合は、構成
% 要素の接続点のための c または s での不連続は認められます。空間にお
% ける離散化によるODEは、入力配列 TSPAN で指定された時間で近似解を
% 求めるために積分されます。TSPAN の要素は、NT >= 3 に対して、
%       t0 = TSPAN(1) < TSPAN(2) < ... < TSPAN(NT) = tf 
% を満たす必要があります。配列 XMESH と TSPAN は、PDEDEにおいて、
% 同じ役割はもっていません。時間積分は、時間ステップと定式化を共にダイ
% ナミックに選択するODEソルバにより行われます。コストは、TSPAN の長さ
% にわずかながら影響を受けます。解への2次の近似が、XMESH の中に設
% 定したメッシュ上で行われます。一般的に、解が急激に変化する部分で、
% 密な間隔での点を使うことがベストです。PDEPE は、このように自動的には、
% X におけるメッシュを選択することはできません。ユーザ自身で、適切に設定
% したメッシュを選択する必要があります。離散化は、m > 0 のとき、x = 0 で
% の座標特異点を考慮します。このために、x = 0 の近傍で、密なメッシュを
% 使用する必要はありません。コストは、XMESH の長さに強く影響を受けます。   
%  
% 解は、多次元配列SOLとして出力されます。UI = SOL(:,:,i) は、i = 1:npde に
% 対する解のベクトル u の i 番目の要素の近似解です。UI(j,k) = SOL(j,k,i)の
% 要素は、(t,x) = (TSPAN(j),XMESH(k)) で UI に近似されます。 
%
% SOL = PDEPE(M,PDEFUN,ICFUN,BCFUN,XMESH,TSPAN,OPTIONS) は、
% デフォルトの積分パラメータを OPTIONS の中で設定した値と置き換えて、
% 上述のように解きます。OPTIONS は、関数 ODESET で作成された引数です。
% ODE ソルバ自身の中のいくつかのオプション、RelTol, AbsTol, NormControl, 
% InitialStep, MaxStepが、PDEPE で利用できます。詳細は、ODESET を参照
% してください。    
%
% SOL = PDEPE(M,PDEFUN,ICFUN,BCFUN,XMESH,TSPAN,OPTIONS,P1,P2...) 
% は、付加パラメータ P1, P2,... を関数 PDEFUN, ICFUN, BCFUN に渡します。
% オプションが設定されない場合は、OPTIONS = [] を利用します。   
%
% UI = SOL(j,:,i) が時間 TSPAN(j)とメッシュ点 XMESH での解の要素 i を近似
% するとき、PDEVAL は点 XOUT の配列での近似値と偏微係数Dui/Dxを計
% 算し、それらを UOUT と DUOUTDX に出力します。
%      [UOUT,DUOUTDX] = PDEVAL(M,XMESH,UI,XOUT)
% 偏微係数Dui/Dxは、流束からではなく、むしろここで計算されることに注意
% してください。流束は連続ですが、構成物の接続点では偏微係数は不連続に
% なる場合があるからです。 
%  
% 例題
%         x = linspace(0,1,20);
%         t = [0 0.5 1 1.5 2];
%         sol = pdepe(0,@pdex1pde,@pdex1ic,@pdex1bc,x,t);         
%
% は、関数 pdex1ic と pdex1bc でそれぞれ与えられる初期条件と境界条件を使
% って、関数 deex1pde で定義された問題を解きます。解は、区間 [0,1]の中の
% 20の等間隔に分割された空間メッシュ上で得られ、時間 t = [0  0.5  1  1.5  2] 
% で出力されます。解を求めるための良い方法は、サーフェスとしてプロットし、
% Rotate 3Dを利用することである場合があります。最初の未知の u1 は、sol から
% 求められ、以下を使ってプロットされます。
%
%         u1 = sol(:,:,1);
%         surf(x,t,u1);
%
% PDEX1 は、サブ関数を使ってこの問題がどのようにコード化されるかを示し
% ています。より詳細な例題は、PDEX2, PDEX3, PDEX4, PDEX5 を参照してくだ
% さい。例題は、それぞれ別個に見ることができますが、PDEDEの利用に関する
% ミニチュートリアルを形成しているので、順番に見てください。 
%
% 参考 ： PDEVAL, ODE15S, ODESET, ODEGET, @.


%   Lawrence F. Shampine and Jacek Kierzenka
%   Copyright 1984-2003 The MathWorks, Inc. 
