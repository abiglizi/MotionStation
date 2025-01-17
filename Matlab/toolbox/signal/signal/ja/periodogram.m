% PERIODOGRAM は、ピリオドグラム法を使って、パワースペクトル密度(PSD)を
% 計算します。
% 
% Pxx = PERIODOGRAM(X) は、ベクトル X で設定される信号の PSD 推定をベク
% トル Pxx に出力します。デフォルトでは、X と同じ長さのBOXCARウインドウ
% が適用されます。PSD 推定は、長さ256か、または、Xの長さより大きい2のベ
% キ乗で求められる長さの大きい方の FFT を計算します。
%
% Pxx は、単位周波数に対するパワーの分布です。実数信号に対して、PERIOD-
% GRAM は、片側 PSD をデフォルトとして出力します。複素数信号の場合、両側
% PSD を出力します。片側 PSD は、入力信号のすべてのパワーを含んでいるこ
% とに注意してください。
%
% Pxx = PERIODOGRAM(X,WINDOW) は、X に適用するウインドウを設定します。
% WINDOW は、X と同じ長さのベクトルです。WINDOW に箱型以外のウインドウを
% 使用したい場合、結果求まるピリオドグラムは変更されます。WINDOW に空行
% 列を設定すると、デフォルトのウインドウが使用されます。
% 
% [Pxx,W] = PERIODOGRAM(X,WINDOW,NFFT) は、PSD を計算するために使用する 
% FFT の点数です。実数に対して、NFFT が偶数の場合、(NFFT/2+1)で、奇数の
% 場合、(NFFT+1)/2 です。複素数では、Pxxは、長さが常に NFFT になります。
% 空の場合、デフォルトは、256 です。
%
% W は、PSD が計算される正規化された周波数を設定するものです。W は、rad
% /サンプル単位です。実数信号に対して、W は、NFFT が偶数の場合[0,pi]の区
% 間に広がり、NFFT が奇数の場合[0,pi)の範囲になります。複素数信号の場合、
% W は、常に、[0.2*pi)の区間です。
%
% [Pxx,F] = PERIODOGRAM(X,WINDOW,NFFT,Fs) は、物理的な周波数(Hz)関数とし
% て計算された PSD を出力します。Fs は、Hz 単位で表したサンプリング周波
% 数で、デフォルトでは1 Hzです。
%
% F は、Hz 単位で表した PSD を計算する周波数を要素とするベクトルです。実
% 数信号に対して、Fは、NFFT が偶数の場合[0,Fs/2]で、奇数の場合[0,Fs/2)の
% 範囲に広がります。複素数信号に対して、Fは、常に、[0,Fs)の範囲です。
%
% [...] = PERIODOGRAM(...,'twosided') は、実数信号 X の両側 PSD を出力し
% ます。この場合、Pxx は、長さ NFFTで、Fs が設定されていない場合、区間 
% [0,2*pi)で計算され、Fs が設定されている場合、区間[0,Fs)になります。一
% 方、文字列'twosided'は、実数信号 X に対する文字列 'onesided'と置き換わ
% ります。これは、デフォルトの挙動と同じになります。文字列 'twosided' ま
% たは 'onesided'は、WINDOW引数の後の任意の位置で設定できます。
%
% 出力引数を設定しない PERIODOGRAM(...) は、カレントの Figure ウインドウ
% に単位周波数に対する PSD をdB単位でプロット表示します。これが、デフォ
% ルトです。
%
% 例題：
%    Fs = 1000;   t = 0:1/Fs:.3;
%    x = cos(2*pi*t*200)+randn(size(t)); % 200Hz のコサイン波にノイズを
%                                        % 加えたもの
%    periodogram(x,[],'twosided',512,Fs);% デフォルトウインドウを使用
% 
% 参考：   PWELCH, PBURG, PCOV, PYULEAR, PMTM, PMUSIC, PMCOV, 
%          PEIG, PSDPLOT.



%   Copyright 1988-2002 The MathWorks, Inc.
