% AUREAD   NeXT/SUN (".au")音声ファイルの読み込み
% 
% Y = AUREAD(AUFILE)は、文字列AUFILEで指定される音声ファイルをロードし、
% 結果のサンプルデータをyに出力します。拡張子を設定していない場合、".au"
% が付きます。振幅値は、[-1,+1]の範囲で表わされます。つぎの形式のマルチ
% チャンネルデータをサポートします。8-ビット mu-則、8、16、32ビット線形、浮動
% 小数点数
%
% [Y,Fs,BITS] = AUREAD(AUFILE)は、ヘルツ単位のサンプリングレート(Fs)とフ
% ァイル内のデータを符号化するために使うサンプルに対するビット数(BITS)を
% 出力します。
%
% [...]  = AUREAD(AUFILE,N)は、ファイルの中の各チャンネルから、最初のNサ
% ンプルのみを出力します。
% 
% [...] = AUREAD(AUFILE,[N1 N2])は、ファイルの中の各チャンネルからN1から
% N2までのサンプルのみを取り出します。
% 
% SIZ  = AUREAD(AUFILE,'size')は、実際のオーディオデータの代わりに、ファ
% イルに含まれるオーディオデータの大きさを出力します。結果は、ベクトル 
% SIZ = [samples channels]になります。
%
% 参考：AUWRITE, WAVREAD.

% Copyright 1984-2004 The MathWorks, Inc. 
