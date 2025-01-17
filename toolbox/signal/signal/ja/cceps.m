% CCEPS 複素セプストラム解析
%
% CCEPS(X)は、(実数と仮定される)デ−タ列Xの複素セプストラムを出力しま
% す。入力は、線形位相項を加えて、+/- πラジアンで位相の不連続性が全く
% ないように変更されます。すなわち、必要であれば、入力はπラジアンで
% ゼロ位相をもつように、(ゼロが付加された後)いくつかのサンプルをシフト
% します。
% 
% [XHAT,ND] = CCEPS(X)は、複素セプストラムを求める前に、Xに付加する
% (巡回)遅れのサンプル数NDを出力します。 
%
% [XHAT,ND,XHAT1] = CCEPS(X)は、改良した根算出のアルゴリズムを使って、
% 複素セプストラムをXHAT1に出力します 。この方法は、単位円上に零点を
% もたない短いデータ列に対して有効です。これらの信号に対して、XHAT1は、
% XHATの検証としても使うことができます。
%
% CCEPS(X,N)は、Xが長さNになるようにゼロを付加して、Xについて長さNの
% 複素セプストラムを出力します。 
%
% 参考：   ICCEPS, RCEPS, HILBERT, FFT.



%   Copyright 1988-2002 The MathWorks, Inc.
