% PSDDEMO   パワースペクトル密度デモ
%
% PSDDEMO は、様々な信号のパワースペクトル密度(PSD)を表示します。この
% デモは、これらの要素が含まれています。
%
% 信号
% -------
% 3つのノイズを含む信号に異なるスペクトル推定を適用します。最初の信号
% は、狭帯域(正弦波)と広帯域(自己回帰過程)の要素の両方を含む信号です。
% SNR は、入力のパワーとARフィルタの出力のパワーの比として定義されます。
% 2番目の信号は、狭帯域の成分のみを含みます。この場合、SNR は、ノイズ
% のパワーと正弦波のパワーの比になります。3番目の信号は、単純な白色性
% ガウスノイズです。
%   
% モンテカルロ・シミュレーション
% ------------------------------
% モンテカルロ・シミュレーションを用いて各推定量の特性を統計的に比較
% します。すべての実行を重ね描きするか、平均したものだけを表示すること
% ができます。
%
% スペクトル推定
% --------------
% パラメトリックおよび部分空間法と同様に、ノンパラメトリックを試して
% 真のPSD(黒い太線)を比較します。データの記録が短いものに対して、高分
% 解能の手法(パラメトリック、および部分空間法)は、古典的なフーリエ変換
% に基づいた手法よりも良い結果を出す傾向にあります。これらの高分解能の
% 手法は、信号のモデルに組み込むために、信号のスペクトル内の情報を優先
% 的に使用します。詳しい情報に関しては、Signal Processing Toolbox の
% User's Guide の3章を見てください。
%
% スペクトルウィンドウ
% --------------------
% 異なるスペクトルウィンドウを選択します。ウィンドウ関数を選択は、様々
% な推定量に対する PSD の質を決定するのに重要です。ウィンドウの主な役割
% は、無限の系列を打ち切った結果のギブス現象の効果を減衰させることです。
% Window Visualization ツールで選択されたウィンドウを視覚化するには、
% View をクリックしてください。
%
% 参考: PERIODOGRAM, PWELCH, PMTM, PYULEAR, PBURG, PCOV, PMCOV, 
%          PMUSIC, PEIG, SPTOOL, WVTOOL.


%   Reference:
%     [1] Kay, S.M. Modern Spectral Estimation. Englewood Cliffs, 
%         NJ: Prentice Hall, 1988

%   Last Modified by GUIDE v2.0 04-Dec-2001 15:00:10
%   Author(s): S.Sand, V.Pellissier
%   Copyright 1988-2002 The MathWorks, Inc.
%   $Revision: 1.1 $  $Date: 2003/04/18 17:42:14 $

