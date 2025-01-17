% PMUSIC   MUSIC 固有ベクトル法を使って、周波数の推定
% S = PMUSIC(X,P)は、離散時間信号ベクトル X の擬似スペクトルをベクトル S
% に出力します。P は、信号 X の中の複素正弦波の数です。X がデータ行列の
% 場合、各行は別々のセンサーまたは実験からの測定値と解釈されます。ユーザ
% は、ここで使用するデータ行列を、関数 CORRMTX を使って作成できます。
%
% S = PMUSIC(R,P,'corr') は、正定行列 R で与えられた離散時間信号の相関行
% 列の擬似スペクトルを出力します。
%
% P が2要素ベクトルの場合、P(2) は、信号空間とノイズ空間を分離するカット
% オフとして使われます。P(2)と最小の固有値の積より大きい固有値が信号の固
% 有値と考えられます。この場合、信号の部分空間の次元は、ほぼ P(1) になり
% ます。
%
% 実数信号に対して、PMUSIC は、デフォルトでは、半分の擬似スペクトルを出
% 力します。複素数信号に対して、全体の擬似スペクトルを出力します。実数信
% 号に対して、全体の擬似スペクトルを出力したい場合、PMUSIC(X,P,'whole')
% としてください。'whole'や'corr'の文字列は、Pの後の任意の位置に設定する
% ことができます。
%
% S = PMUSIC(X,P,NFFT) は、擬似スペクトルを計算するために使用する FFT の
% 長さを設定します。実数に対して、NFFT が偶数の場合、(NFFT/2+1)で、奇数
% の場合、(NFFT+1)/2 です。複素数では、S は、長さが常に NFFT になります。
% 空の場合、デフォルトは、256 です。
%
% [S,W] = PMUSIC(...) は、擬似スペクトルが計算する正規化された角周波数 W
% を設定するベクトルを出力します。W の単位は、rad/サンプルです。実数信号
% に対して、W は、NFFT が偶数の場合[0,pi]の区間に広がり、NFFT が奇数の場
% 合[0,pi)の範囲になります。複素数信号の場合、W は、常に、[0.2*pi)の区間
% です。
%
% [S,F] = PMUSIC(...,Fs) は、サンプリング周波数を Hz 単位で設定し、Hz 毎
% にパワースペクトル密度を出力します。F は、Hz 単位の周波数ベクトルで、
% ここで設定されている周波数で、擬似スペクトルを計算します。実数信号に対
% して、Fは、NFFT が偶数の場合[0,Fs/2]で、奇数の場合[0,Fs/2)の範囲に広が
% ります。複素数信号に対して、Fは、常に、[0,Fs)の範囲です。Fsを空にする
% と、デフォルトのサンプリング周波数1 Hz を使います。
% 
% [S,F] = PMUSIC(...,NW,NOVERLAP)  は、信号ベクトル X を長さ NW で、オー
% バラップNOVERLAP サンプルの部分に分割します。これらの部分は、行列の行
% として考え、その転置したものとの乗算で、X の NW 行 NW 列の相関行列を作
% 成します。NW がベクトルの場合、データ行列の行は、NW の長さのウインドウ
% を適用します。空または省略されている場合、NW = 2*P と NOVERLAP = NW-1
% を設定します。
%
% [S,W,V,E] = PMUSIC(...) は、行列の列がノイズ部分空間に対応する固有ベク
% トルである行列 V とすべての固有値を含むベクトル E を出力します。このシ
% ンタックスは、正弦波の周波数とパワーを決定するのに有効なものです。
%
% 出力引数を設定しない PMUSIC(...) は、カレントの Figure ウインドウに擬
% 似スペクトルをプロットします。
%
% 例題：
%      randn('state',1); n=0:99;   
%      s=exp(i*pi/2*n)+2*exp(i*pi/4*n)+exp(i*pi/3*n)+randn(1,100);  
%      X=corrmtx(s,12,'mod');   % 修正共分散法を使って、相関行列を推定
%      pmusic(X,3,'whole');     % NFFT は、デフォルト値256を使います。
%
%      n=0:99; figure;
%      s2=sin(pi/3*n)+2*sin(pi/4*n)+randn(1,100);
%      X2=corrmtx(s2,20,'cov'); % 共分散法を使って、相関行列を推定      
%      pmusic(X2,4,'whole');    % 実数正弦波に対して、信号空間の次元の
%                               % 2倍のものを使います
% 
% 参考：   ROOTMUSIC, PEIG, PMTM, PCOV, PMCOV, PBURG, PYULEAR, PWELCH,
%          CORRMTX, PSDPLOT.



%   Copyright 1988-2002 The MathWorks, Inc.
