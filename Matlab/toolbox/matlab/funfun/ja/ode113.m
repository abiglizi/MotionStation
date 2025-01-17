% ODE113  可変次数のノンスティッフな微分方程式の解法
%
% [T,Y] = ODE113(ODEFUN,TSPAN,Y0) は、TSPAN = [T0 TFINAL] のとき、
% 初期状態 Y0 で、時刻 T0 から TFINAL まで微分方程式システム y' = f(t,y) 
% を積分します。関数 ODEFUN(T,Y) は、f(t,y) に対応する列ベクトルを出力
% します。解の配列 Y の各行は、列ベクトル T に出力される時間に対応します。
% 時間T0,T1,..., TFINAL(単調増加または単調減少)での解を求めるためには、
% TSPAN = [T0 T1 ... TFINAL] を使ってください。     
%   
% [T,Y] = ODE113(ODEFUN,TSPAN,Y0,OPTIONS) は、デフォルトの積分パラ
% メータを OPTIONS の値で置き換えて、上記のように解きます。OPTIONS
% は、関数 ODESET で作成された引数です。詳細は、関数 ODESETを参照
% してください。一般的に使用されるオプションは、スカラの相対許容誤差
% 'RelTol' (デフォルトでは1e-3)と、絶対 許容誤差ベクトル 'AbsTol' 
% (デフォルトではすべての要素が 1e-6)です。
%   
% [T,Y] = ODE113(ODEFUN,TSPAN,Y0,OPTIONS,P1,P2,...) は、
% ODEFUN(T,Y,FLAG,P1,P2,...) のように、付加パラメータP1,P2 ,... をODE関数、
% およびOPTIONS で指定したすべての関数に渡します。オプションを指定しな
% い場合は、OPTIONS = [] を使ってください。   
%   
% ODE113 は、正則な質量行列 M をもつ問題 M(t,y)*y' = f(t,y) を解きます。
% MASS(T,Y) が質量行列の値を出力する場合は、ODESET を使って関数
% MASS に、'Mass' プロパティを設定します。質量行列が定数の場合、行列は、
% 'Mass' オプションの値として使われ、質量行列が状態変数 Y に依存せず、
% 関数 Mass が1つの入力引数 T と共に呼び出される場合、'MStateDependence'
% を 'none' に設定します。その他の場合、'MStateDependence' に 'weak'
% (デフォルト)または、'strong' を設定します。どちらの場合も、関数 MASS は
% 2つの引数(T,Y) と共に呼び出されます。ODE15S と ODE23T は、特異質量
% 行列をもつ問題を解きます。  
%
% [T,Y,TE,YE,IE] = ODE113(ODEFUN,TSPAN,Y0,OPTIONS...) は、OPTIONS
% の 'Events' プロパティが関数 EVENTS に設定されている場合は上記のよ
% うに解き、イベント関数と呼ばれる (T,Y) の関数がゼロとなる点を求めます。
% 指定する各関数に対して、積分がゼロで終了するかどうか、およびゼロク
% ロッシングの方向は重要です。これらは、EVENTS: 
% [VALUE,ISTERMINAL,DIRECTION] =EVENTS(T,Y) によって出力される3つ
% のベクトルです。I番目のイベント関数に対して、VALUE(I) は、積分がこの
% イベント関数のゼロで終了する場合は関数 ISTERMINAL(I)=1 の値で、
% そうでない場合は0です。すべてのゼロが計算される(デフォルト)場合は、
% DIRECTION(I)=0 で、イベント関数が増加した点のみゼロである場合は +1
% で、イベント関数が減少した点のみゼロである場合は -1 です。出力 TE は、
% イベントが発生する時間の列ベクトルです。YE の行は対応する解で、ベク
% トル IE のインデックスはどのイベントが発生したかを指定します。   
%
% SOL = ODE113(ODEFUN,[T0 TFINAL],Y0...) は、T0 と TFINAL 間の任意
% の点で、解を計算するため、DEVAL で使用可能な構造体を出力します。
% ODE113 で選択されたステップは、行ベクトル SOL.x に出力されます。
% Iに対して、列 SOL.y(:,I) は、SOL.x(I) での解を含んでいます。イベントが
% 検出された場合は、SOL.xe は、イベントが発生した位置を示す点から構成
% される行ベクトルです。SOL.ye の列は、対応する解で、ベクトル SOL.ie の
% インデックスは、イベントが発生したものがどれかを示しています。ターミナ
% ルイベントが検出される場合、SOL.x(end) は、イベントが発生した位置での
% ステップの終わりを含んでいます。イベントの正確な位置は、SOL.xe(end) 
% に報告されます。
%
% 例題
%         [t,y]=ode113(@vdp1,[0 20],[2 0]);   
%         plot(t,y(:,1));
%   
% は、デフォルトの相対誤差 1e-3 とデフォルトの絶対誤差 1e-6 を各成分に
% 使ってシステム y' = vdp1(t,y) を解き、解の最初の要素をプロットします。 
%
% 参考
%   他のODEソルバ: ODE45, ODE23, ODE15S, ODE23S, ODE23T, ODE23TB
%   OPTIONSの取り扱い: ODESET, ODEGET
%   出力関数: ODEPLOT, ODEPHAS2, ODEPHAS3, ODEPRINT
%   解の計算: DEVAL
%   ODE例題: RIGIDODE, BALLODE, ORBITODE
%
% 注意: 
% ODE ソルバの最初の入力引数と ODESET へ渡すいくつかのプロパティの
% 解釈は、このバージョンで変更されています。バージョン 5 のシンタックスは
% 現在、サポートしていますが、新しい機能は、新しいシンタックスでのみ使用
% 可能です。バージョン 5 のヘルプを見るには、つぎのように入力してください。
%  
%         more on, type ode113, more off

% 注意:
% この部分は、ODE113 の v5 シンタックスを記述します。
%
% [T,Y] = ODE113('F',TSPAN,Y0) では、TSPAN = [T0 TFINAL] の場合、初期条件を
% Y0 として微分方程式系 y' = F(t,y) を、時刻 T0 から TFINAL まで積分します。
% 'F' は、ODE ファイルの名前を含む文字列です。関数 F(T,Y) は、列ベクトルを
% 返さなければなりません。解の配列 Y の各行は、列ベクトル T に出力される時間に
% 相当します。指定時刻 T0, T1, ..., TFINAL (すべて増加、または、すべて減少)
% で解を得るためには、TSPAN = [T0 T1 ... TFINAL] を使用してください。
%   
% [T,Y] = ODE113('F',TSPAN,Y0,OPTIONS) は、ODESET 関数で作成された
% 引数、OPTIONS の値で置き換えられたデフォルトの積分パラメータを使用
% して上記のように解きます。 詳細は、ODESET を参照してください。
% 通常使用されるオプションは、スカラーの相対許容誤差 'RelTol' ( デフォルトは、
% 1e-3 ) と 絶対許容誤差のベクトル 'AbsTol' (デフォルトは、すべての要素
% が 1e-6 ) です。
%   
% [T,Y] = ODE113('F',TSPAN,Y0,OPTIONS,P1,P2,...) は、付加的なパラメータ
% P1,P2,... を ODE ファイルに F(T,Y,FLAG,P1,P2,...) として渡します
% ( ODEFILE を参照 )。オプションが設定されていない場合、プレイスホルダとして 
% OPTIONS = [] を使用してください。
%   
% ODE ファイルで TSPAN, Y0 および OPTIONS を指定できます (ODEFILE を参照)。
% TSPAN または Y0 が空の場合、ODE113 は、ODE113 引数リストで与えられない値
% を得るために、ODE ファイル [TSPAN,Y0,OPTIONS] = F([],[],'init') をコール
% します。コールリストの最後の空の引数は、たとえば、ODE113('F') のように
% 省略することができます。
%   
% ODE113 は、非特異質量行列 M をもつ問題 M(t,y)*y' = F(t,y) を
% 解くことができます。F(T,Y,'mass') が定数、時間依存、または、
% time- と state-依存する質量行列をそれぞれ出力するように、ODE ファイルが
% コードされている場合、'M', 'M(t)', または 'M(t,y)' に質量を設定するためには、
% ODESET を使用してください。質量のデフォルト値は、'none' です。 
% FEM1ODE, FEM2ODE, または BATONODE を参照してください。ODE15S と ODE23T は、
% 特異質量行列をもつ問題を解くことができます。
%   
% [T,Y,TE,YE,IE] = ODE113('F',TSPAN,Y0,OPTIONS) では、OPTIONS の Events
% プロパティを'on' に設定して、ODE ファイルに定義されるイベント関数の
% ゼロクロッシングを置いていますが、上記のように解きます。ODE ファイルは、
% F(T,Y,'events') が適当な情報を出力するようにコードされる必要があります。
% 詳細は、ODEFILE を参照してください。出力 TE は、イベントが起こる時間の
% 列ベクトルであり、YE の行が対応する解です。ベクトル IE のインデックスは、
% どのイベントが起こるかを指定します。
%   
% 参考 ODEFILE

% ODE113 は、fully variable ステップサイズです。 1-12 次の Adams-Bashforth-
% Moulton family の修正差分商でPECE を実行します。natural "free" interpolants 
% が使用されます。局所的な補外が行われます。

%   詳細が The MATLAB ODE Suite にあります。L. F. Shampine and
%   M. W. Reichelt, SIAM Journal on Scientific Computing, 18-1, 1997.

%   Mark W. Reichelt and Lawrence F. Shampine, 6-13-94
%   Copyright 1984-2003 The MathWorks, Inc. 

