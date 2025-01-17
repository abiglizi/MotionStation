% TRF   モデルの周波数関数
%
%   G = trf(TH) または、
%   [G, NSP] = trf(TH)
%
% TH : THETA行 列で定義されたモデル(THETA参照)
% 
% G は、伝達関数推定で、NSP は(指定された場合)、モデルTHに対する雑音スペ
% クトルです。これらの行列は、TH の共分散行列から求められた推定標準偏差
% を含む標準的な周波数関数フォーマットです(FREQFUNC 参照)。TH が時系列の
% 場合、G はそのスペクトルです。
%
% モデルTHが複数入力をもつ場合、G は、G = trf(TH, [j1 j2 ... jk])で選択
% された入力番号 j1 j2 ... jk の伝達関数です(デフォルトは、すべての入力
% です)。0から pi/T の区間で128点の等間隔周波数で計算されます。ここで、
% T は TH で指定されたサンプリング周波数です。任意の周波数 w[rad/s](たと
% えば、LOGSPACE で生成された行ベクトル)で計算するためには、G = trf(TH, 
% ku, w)と実行します。伝達関数は、BODEPLOT で表示できます。BODEPLOT(trf
% (TH))と実行します。
%
% モデル TH が複数出力をもつ場合、G は、G = trf(TH, ku, w, ky)で選択され
% た出力 ky(行ベクトル)の伝達関数です(デフォルトは、すべての出力です)。
%
% 参考:    TH2FF

%   Copyright 1986-2001 The MathWorks, Inc.
