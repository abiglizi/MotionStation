% PDENONLIN   非線型PDE問題を解きます。
% [U,RES] = PDENONLIN(B,P,E,T,C,A,F) は、P, E, T で表わされるメッシュ上
% で、関数名 B で与えられる境界条件をもつ非線形 PDE 問題 -div(c*grad(u))
% +a*u = f を解きます。ここで、Armijo-Golestein ライン探索法を伴う減衰付
% きニュートン反復を使います。
%
% 解 u は、MATLAB 列ベクトルとして表現されます。詳細は、ASSEMPDE を参照
% してください。RES は、ニュートンステップ残差の2-ノルムです。
%
% PDE 問題の形状は、三角形データ P, E, T によって与えられます。詳細は、
% INITMESH または PDEGEOM を参照してください。
%
% B は、PDE 問題の境界条件を表わします。B は、Boundary Condition 行列ま
% たは Boundary M-ファイルのファイル名のどちらでも可能です。詳細は、PD-
% EBOUND を参照してください。
%
% オプション引数 TOL と U0 は、それぞれ、相対許容誤差パラメータと解の初
% 期値を指定します。
%
% PDE 問題の係数 C, A, F は、多種多様な方法で与えられます。PDENONLIN に
% おいては、係数は U に依存します。係数は、時間 T には依存できません。詳
% 細は、ASSEMPDE を参照してください。
%
% 細かい調整を行うパラメータを、パラメータ名と値の組合わせの形式でソルバ
% に設定することができます。完全ヤコビアンの計算、"lumped" 近似または固
% 定点の反復を選択したり、解の初期推定を与えることができます。反復回数の
% 最大値は、検索ベクトルの最小の減衰値、終了時の残差のサイズとノルムを制
% 御できます。これらの調整は、つぎのプロパティと値の組合わせのうちの1つ
% または複数を設定することによって行われます。
%
%     プロパティ  値/{デフォルト}              詳細
%     --------------------------------------------------------------
%     Jacobian   'lumped'|'full'|{'fixed'}    ヤコビアンの近似法
%     U0          文字列|数値{0}              初期推定値の設定
%     Tol         数値{1e-4}                  残差の許容値
%     MaxIter     数値{25}                    反復回数の最大値
%     MinStep     数値{1/2^16}                減衰の最小値
%     Report      'on'|{'off'}                収束情報の表示
%     Norm        数値|{Inf}|'energy'         残差ノルム
%
% 参考  : ASSEMPDE, PDEBOUND
%
% 診断: ニュートン反復法が収束しなければ、エラーメッセージ 'Too many 
%       iterations'、または、'Stepsize too small' が表示されます。
% 



%       Copyright 1994-2001 The MathWorks, Inc.
