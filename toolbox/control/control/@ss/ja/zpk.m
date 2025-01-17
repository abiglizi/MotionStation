% ZPK   極-零点-ゲイン型モデルへの変換、または作成
%
% 作成:
% SYS = ZPK(Z,P,K) は、零点 Z、極 P、ゲイン K の連続時間極-零点-ゲイン型
% (ZPK)モデル SYS を作成します。出力 SYS はZPKオブジェクトです。
%
% SYS = ZPK(Z,P,K,Ts) は、サンプル時間 Ts の離散時間ZPKモデルを作成し
% ます(サンプル時間を未定義にする場合、Ts = -1に設定してください)。
% S = ZPK('s') は、H(s) = s (ラプラス演算子)を定義します。
% Z = ZPK('z',TS) は、サンプル時間 TS の H(z) = z を定義します。ZPKモデル
% を、つぎのように簡単に表現できます。S または Z を利用して、たとえば、
% 
%     z = zpk('z',0.1);  H = (z+.1)*(z+.2)/(z^2+.6*z+.09)
%
% SYS = ZPK は、空の極-零点-ゲインモデルを作成します。
% SYS = ZPK(D) は、静的ゲイン行列 D を定義します。
%
% 上記のすべての書式で、入力リストは組にして続けることができます。
% 
%    'PropertyName1', PropertyValue1, ...
% 
% これにより、ZPKモデルの様々なプロパティ(詳細は、LTIPROPS を参照)を
% 設定します。既存の LTI モデル REFSYS のすべての LTI プロパティを継承
% して SYS を作成するためには、SYS = ZPK(NUM,DEN,REFSYS) の書式を利用
% します。
% 
% データフォーマット:
% SISOモデルに対して、Z と P は、零点と極のベクトルで(零点がないときは 
% z = [] と設定してください)、K はスカラのゲインです。
%
% NU 入力 NY 出力の MIMO システムに対しては、
% * Z と P は、NY*NU のセル配列で、Z{i,j} と P{i,j} は、入力 j から出力 i 
%   までの伝達関数の零点と極を表します。
% * K は、各 I/O チャンネルに対するゲインの2次元行列です。
% たとえば、
% 
%    H = ZPK( {[];[2 3]} , {1;[0 -1]} , [-5;1] )
% 
% は、つぎの1入力2出力の極-零点-ゲインモデルを定義します。
% 
%    [    -5 /(s-1)      ]
%    [ (s-2)(s-3)/s(s+1) ] 
%
% 極-零点-ゲインモデルの配列:
% 上記の Z, P に対してNDセル配列を、 K に対してND配列を利用すること
% で、ZPKモデルの配列を作成することができます。たとえば、Z, P, K がサイズ
% [NY NU 5] の3次元配列とすると、
% 
%    SYS = ZPK(Z,P,K) 
% 
% は、ZPKモデルの5行1列の配列を作成します。
% 
%    SYS(:,:,m) = ZPK(Z(:,:,m),P(:,:,m),K(:,:,m)),   m = 1:5.
% 
% これらの個々のモデルは、NU 入力 NY 出力になります。
%
% NU 入力 NY 出力をもつZPKモデルに、0行列をあらかじめ割り当てるには、
% つぎの書式を用いてください。
% 
%    SYS = ZPK(ZEROS([NY NU k1 k2...])) .
%
% 変換:
% SYS = ZPK(SYS) は、任意のLTIモデル SYS をZPK表現に変換します。結果は、
% ZPKオブジェクトになります。  
%
% SYS = ZPK(SYS,'inv') は、状態空間からZPKモデルへの変換に高速なアルゴ
% リズムを用いますが、高次のシステムに対しては、精度が失われます。
%
% 参考 : LTIMODELS, SET, GET, ZPKDATA, SUBSREF, SUBSASGN, 
%        LTIPROPS, TF, SS.


%       Author(s): A. Potvin, 3-1-94, P. Gahinet, 4-5-96
%       Copyright 1986-2002 The MathWorks, Inc. 
