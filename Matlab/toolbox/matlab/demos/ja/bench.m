% BENCH   MATLAB ベンチマーク
%
% BENCH は、6種類のMATLABの実行時間を測定し、数種のコンピュータの実行
% 速度と比較します。6種類の作業はつぎのものです。
%   
%    LU       LAPACK, n = 1000.       浮動小数点、通常のメモリアクセス
%    FFT      Fast Fourier変換.       浮動小数点、通常でないメモリアクセス
%    ODE      Ordinary diff. eqn.     データ構造体とM-ファイル
%    Sparse   スパースシステムの解法. 整数と浮動小数点数の混在
%    2-D      plot(fft(eye)).         2次元のライン描画
%    3-D      MathWorksロゴ           3次元のOpenGLグラフィックスアニメー
%                                     ション
%
% 最後に表示されるバーチャートは、時間に反比例する量として速度を示してい
% ます。長いバーは速いマシンで、短いバーが遅いマシンを示します。
%
% BENCH は、6種類の作業を1回実行します。
% BENCH(N) は、6種類の作業を N 回実行します。
% BENCH(0) は、他のコンピュータと比較した時間のみを出力します。
% T = BENCH(N) は、実行時間を要素とするN行6列の配列を出力します。
%
% 他のコンピュータに対する比較データは、つぎのテキストファイルに保存されて
% います。
%
%      .../toolbox/matlab/demos/bench.dat
%
% このファイルのアップデートされたバージョンは、MATLAB Centralから入手
% 可能です。
%
%      http://www.mathworks.com/matlabcentral/fileexchange/loadFile.do?
%           objectId=1836&objectType=file#
%
% 単一マシン上での繰り返し実行の観測速度は、5%または10%の変動が生じま
% す。ユーザ自身のものでは、異なる場合があります。
%
% このベンチマークは、種々のマシン間での特定のバージョンのパフォーマンス
% を比較することを意図しています。MATLABの種々のバージョン間での比較は
% 意図していません。内容や問題のサイズは、バージョン毎に異なっています。
%
% LU と FFT については、大きな行列と長いベクトルを使っています。従って、
% 物理的なメモリが64MBよりも少ないマシンや、最適化されたBasic Linear 
% Algebra Subprograms をもたないマシンでは、パフォーマンスが低下する
% 場合があります。
%
% 2次元や3次元のものは、OpenGLをサポートしているハードウェアまたはソフト
% ウェアを含むグラフィックスのパフォーマンスを測定します。コマンド
%      opengl info
% は、特定のマシン上で利用可能なOpenGLサポートを記述しています。


%   Copyright 1984-2002 The MathWorks, Inc.
