% LINMOD   連立常微分方程式(ODE)から線形モデルを取得
% diff.
% equations (ODEs).
%
%  [A,B,C,D] = LINMOD('SYS') は、状態変数と入力がデフォルトに設定されたとき、
% ブロック線図'SYS'に記述された連立常微分方程式の状態空間線形モデルを取得し
%
%  [A,B,C,D] = LINMOD('SYS',X,U) は、状態ベクトルXと入力Uを指定することがで
% きます。線形モデルは、その平衡点で取得されます。
%
%  [A,B,C,D] = LINMOD('SYS',X,U,PARA) は、パラメータのベクトルを設定すること
% ができます。PARA(1) は、線形モデルを取得するための摂動レベルを設定します
% ('v5'オプションを利用しない限りR12 では廃止される関数です。下記参照)。時間
% 関数であるシステムに対して、PARA(2) は線形モデルが得られる時間tの値を使っ
% て設定されます(デフォルトt=0)。PARA(3)=1 と設定すると、入力から出力へのパス
% をもたないブロックに関連する余分な状態を削除します。
%
%  [A,B,C,D]=DLINMOD('SYS',TS,X,U,'v5') は、MATLAB 5.x で用意されている摂動
% をベースにしたアルゴリズムを使用します。カレントアルゴリズムは、大部分のブロッ
% クに対して、正確な線形化を行いますが、より精度の高いものが要求されます。新し
% いアルゴリズムは、Transport Delay や Quantizerブロックのような、より問題を
% 含むブロックに対して、特別な取り扱いができます。より詳細な情報や取り扱いに
% ついては、これらのブロックのマスクダイアログを参照してください。
%
%  [A,B,C,D]=LINMOD('SYS',X,U,'v5',PARA,XPERT,UPERT)は、MATLAB 5.xの摂動モデ
% ルアルゴリズムを使用します。 XPERTとUPERが与えられない場合は、PARA(1)は、摂
% 動レベルを以下のように設定します: XPERT= PARA(1)3*PARA(1)*ABS(X)
% UPERT= PARA(1)3*PARA(1)*ABS(U) デフォルトの摂動レベルは、PARA(1)=1e-5です。
%  ベクトルXPERTとUPERTが与えられる場合は、システムの状態と入力に対する摂動
%
% 参考 : LINMODV5, LINMOD2, DLINMOD, TRIM


% Copyright 1990-2002 The MathWorks, Inc.
