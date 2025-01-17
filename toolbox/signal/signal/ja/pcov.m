% PCOV   共分散法を使って、パワースペクトル密度(PSD)を計算
% Pxx = PCOV(X,ORDER) は、離散時間信号ベクトル X の PSD をベクトル Pxx 
% に出力します。Pxx は、単位周波数に対するパワーの分布です。周波数は、
% rad/sec単位で表示します。ORDER は、 PSD を計算するために使用する自己回
% 帰(AR)モデルの次数です。PCOV は、デフォルトのFFTの長さ256を使って、Pxx
% の長さを決定します。
%
% デフォルトでは、PCOV は、実信号に対して、片側 PSD を、複素数に対して、
% 両側 PSDを計算出力します。片側 PSD は、入力信号のすべてのパワーを含ん
% でいることに注意してください。
%
% Pxx = PCOV(X,ORDER,NFFT) は、 PSD 推定を計算するために FFT の長さを設
% 定します。実数に対して、NFFT が偶数の場合、(NFFT/2+1)で、奇数の場合、
% (NFFT+1)/2 です。複素数では、Pxxは、長さが常に NFFT になります。空の場
% 合、デフォルトは、256 です。
%
% [Pxx,W] = PCOV(...) は、PSD を計算する正規化された角周波数からなるベク
% トル W を出力します。W の単位は、rad/secです。実数信号に対して、W は、
% NFFT が偶数の場合[0,pi]の区間に広がり、NFFT が奇数の場合[0,pi)の範囲に
% なります。複素数信号の場合、W は、常に、[0.2*pi)の区間です。
%
% [Pxx,F] = PCOV(...,Fs) は、サンプリング周波数を Hz 単位で設定し、Hz 毎
% にパワースペクトル密度を出力します。F は、Hz 単位の周波数ベクトルで、
% ここで設定されている周波数で、PSD を計算します。実数信号に対して、Fは、
% NFFT が偶数の場合[0,Fs/2]で、奇数の場合[0,Fs/2)の範囲に広がります。複
% 素数信号に対して、Fは、常に、[0,Fs)の範囲です。Fsを空にすると、デフォ
% ルトのサンプリング周波数1 Hz を使います。
%
% [Pxx,W] = PCOV(...,'twosided') は、区間[0,2*pi)で、PSD を出力します。
% また、[Pxx,F] = PCOV(...,Fs,'twosided') は、区間[0,Fs)で、PSD を計算し
% ます。'onesided'(片側)は、オプションとして設定できますが、実数の X に
% 対してのみ使用できるものです。文字列 'twosided' または 'onesided' は、
% 入力引数 ORDER の後の任意の位置に設定することができます。
%
% 出力引数を設定しない PCOV(...) は、カレントの Figure ウインドウに単位
% 周波数に付き、dB 単位での PSD をプロットします。
%
% 例題：
%      randn('state',1);
%      x = randn(100,1);
%      y = filter(1,[1 1/2 1/3 1/4 1/5],x);
%      pcov(y,4,[],1000);             デフォルトの NFFT 数 256 を使用
%
% 参考：   PMCOV, PYULEAR, PBURG, PMTM, PMUSIC, PEIG, PWELCH, 
%          PERIODODGRAM, ARCOV, PRONY, PSDPLOT.



%   Copyright 1988-2002 The MathWorks, Inc.
