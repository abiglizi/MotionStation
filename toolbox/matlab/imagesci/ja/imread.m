% IMREAD   グラフィックスファイルからイメージを読み込みます
% 
% A = IMREAD(FILENAME,FMT)は、FILENAME 内のイメージを A に読み込みます。
% ファイルがグレイスケール強度イメージを含む場合は、A は2次元配列です。
% ファイルがトゥルーカラー(RGB)イメージを含む場合は、A は3次元(M×N×3)
% 配列です。FILENAME はグラフィックスファイル名を指定する文字列で、FMT は
% ファイルの書式を指定する文字列です。ファイルは、カレントのディレクトリ、
% またはMATLABパス上のディレクトリになければなりません。IMREAD がファイル名
% FILENAME を見つけられない場合は、FILENAME.FMT を探します。
%
% FMT の取り得る値は、IMFORMATS コマンドによってアクセスされるファイル
% 形式の登録で得られます
%
% [X,MAP] = IMREAD(FILENAME,FMT) は、FILENAME のインデックス付きイメージ
% を X に読み込み、対応するカラーマップを MAP に読み込みます。イメージ
% ファイル内のカラーマップの値は、読み込まれたときに、範囲 [0,1] に再
% スケーリングされます。
%
% [...] = IMREAD(FILENAME) は、その内容からファイルの書式を推測します。
%
% [...] = IMREAD(URL,...) は、インターネット URL からイメージを読み込
% みます。URL は、プロトコルのタイプ (例えば "http://") を含まなければ
% なりません。
%
% データタイプ
% ------------
% IMREAD によりサポートされているイメージファイルフォーマットのほとん
% どでピクセルは、カラー平面について、8またはそれ以下のビット数でストア
% されます。ファイルがピクセルに対して1ビットのみ含まれる場合、出力の
% クラス(A または X) は、logical になります。カラー平面について、8 
% またはそれ以下のビット数以外のファイルを読み込む場合、出力のクラスは、
% uint8 です。IMREADは、BMP, TIFFやPNGファイルからピクセルあたり
% 16ビットのデータを読むことをサポートしています。16ビットTIFFおよび
% PNG イメージファイルに対しては、出力(AまたはX)のクラスは uint16 で、
% 16ビット BMPイメージファイルに対しては、出力のクラスは unit8 です。
% 
% TIFF 固有のシンタックス
% -----------------------
% [...] = IMREAD(...,IDX) は、複数のイメージをもつTIFFファイルから、
% 1つのイメージを読み込みます。IDX は、ファイル内のイメージの順番を
% 指定する整数値です。 たとえば、IDX が3の場合、IMREAD はファイルの
% 3番目のイメージを読み込みます。この引数を省略すると、IMREAD は
% ファイルの1番目のイメージを読み込みます。
% 
% PNG固有のシンタックス
% -----------------------
% [...] = IMREAD(...,'BackgroundColor',BG) は、BG 内に指定したカラーに
% 対して、入力イメージ内のピクセルを対応付けします。BG が 'none' の
% 場合は、対応付けは存在しません。'none' 以外では、入力イメージが
% インデックス付きイメージの場合は、BG は[1,P]の範囲の整数になり、
% ここでPはカラーマップ長です。入力イメージがグレースケールの場合は、
% BG は[0,1]の範囲の整数です。また、入力イメージがRGBの場合は、BG は
% 範囲が[0,1]の値からなる3成分のベクトルになります。文字列 
% 'BackgroundColor' は省略される可能性があります。
% 
% 下に示すような ALPHA 出力引数が使われる場合は、ユーザが設定できない
% 'none' が、BG のデフォルトになります。そうでない場合は、PNGファイル
% かバックグランドカラーチャンクを含んでいる場合は、カラーは BG に
% 対するデフォルト値として使用されます。ALPHA が使用されず、ファイルが
% バックグラウンドカラーチャンクを含んでいない場合は、BG に対する
% デフォルト値は、インデックス付きイメージで1、グレースケールイメージ
% で0、RGBイメージで[0,0,0]になります。
% 
% [A,MAP,ALPHA] = IMREAD(...) は、存在するならば、ALPHA チャンネルを出力
% し、そうでない場合は ALPHA は [] です。ファイルがグレースケールまた
% はトゥルーカライメージを含む場合は、MAP は空になります。
%
% HDF固有のシンタックス
% -----------------------
% [...] = IMREAD(...,REF) は、複数のイメージをもつHDFファイルから、
% 1つのイメージを読み込みます。REF は、イメージを識別するために使う
% 参照番号を指定する整数値です。たとえば、REF が12の場合は、IMREAD は
% 参照番号が12のイメージを読み込みます(HDFファイルでは、参照番号は
% ファイル内のイメージの順序と対応させる必要はありません。参照番号を
% イメージの順番に一致させるためには、IMFINFO を使うことができます)。
% この引数を省略すると、IMREAD は、ファイルの1番目のイメージを読み込み
% ます。
%
% ICO- と CUR-固有のシンタックス
% ------------------------------
% [...] = IMREAD(...,IDX) は、マルチイメージアイコンまたはカーソル
% ファイルのどちらかから1つのイメージの中を読みます。IDX は、ファイルの
% 中に表れるイメージの順番を指定する整数値です。たとえば、IDX が3の
% 場合は、IMREAD はファイル内の3番目のイメージを読み込みます。この引数
% を省略すると、IMREAD はファイルの中の最初のイメージを読み込みます。
%
% [A,MAP,ALPHA] = IMREAD(...) は、リソース用の AND マスクを出力します。
% これは、透明度の情報を決定するために使われるものです。カーソル
% ファイルに対して、このマスクは使用可能なデータのみを含んでいます。
%
% GIF固有のシンタックス
%   ---------------------
% [...] = IMREAD(...,IDX) は、マルチフレーム (アニメーション化された) 
% GIFファイルから1つまたは複数のフレームを読み込みます。IDX は、整数の
% スカラまたは整数値からなるベクトルでなければなりません。たとえば、
% IDX が3の場合は、IMREAD はファイル内の3番目のイメージを読み込みます。
% IDX は1:5の場合は、最初の5個のフレームのみが出力されます。
%
% [...] = IMREAD(...,'Frames',IDX) は、IDX が'all' であること以外は
% 上記のシンタックスと同じです。この場合は、すべてのフレームが読み
% 込まれ、ファイル内に現われる順に出力されます。
%
% 注意: GIFファイルの作成方法により、すべてのフレームは、特定の
% フレームが要求されるときに読み込まなければなりません。その結果、
% 同じGIFファイルからの複数フレームの読み込み時には、ループ内で IMREAD
% を呼び出すよりも、フレームのベクトルあるいはIDXに対して 'all' を指定
% するほうがはるかに高速です。 
%
% サポートしているファイルタイプ
% ------------------------------
% JPEG  任意のベースラインのJPEGイメージ。一般的に使われる拡張付きの
%       JPEGイメージ
% 
% TIFF  1ビット、8ビット、24ビットの圧縮されていないイメージを含む任意
%       のベースラインのTIFFイメージ。packbit圧縮の1ビット、8ビット、
%       24ビットイメージ。CCITT圧縮の1ビットイメージ。また、16ビット
%       グレースケールイメージ、16ビットインデックス付きイメージ、
%       48ビットRGBイメージ。
% 
% GIF   1ビット、8ビットの圧縮されていないイメージ。
%
% BMP   1ビット、4ビット、8ビット、24ビット、32ビットの圧縮されていない
%       イメージ。4ビットと8ビットの実行長エンコード(RLE)イメージ。
% 
% PNG   1ビット、2ビット、4ビット、8ビット、16ビットのグレースケール
%       イメージ、8ビット、16ビットのインデックス付きイメージ、
%       24ビット、48ビットのRGBイメージを含む任意のRNGイメージ
%
% HDF   関連するカラーマップをもつ、あるいはもたない8ビットのラスター
%       イメージデータセット。24ビットラスターイメージデータセット。
%
% PCX   1ビット、8ビット、24ビットのイメージ。
%
% XWD   1ビットと8ビットのZpixmaps。XYBitmaps。1ビットのXYPixmaps。
% 
% ICO   1-ビット、4-ビット、8-ビットの圧縮をしていないイメージ
%
% CUR   1-ビット、4-ビット、8-ビットの圧縮していないイメージ
%
% RAS   1ビットビットマップ、8ビットインデックス付き、24ビットトゥルー
%       カラー、alpha指定32ビットトゥルーカラーを含む任意のRASイメージ
%
% PBM   任意の1ビットPBMイメージ。 Raw (binary)またはASCII (plain)
%       エンコード
%
% PGM   任意の標準PGMイメージ。任意のカラー深さのASCII (plain) 
%       エンコード。gray値あたり最大16ビットのRaw (binary)エンコード
%
% PPM   任意の標準PPMイメージ。任意のカラー深さのASCII (plain)
%       エンコード。カラーコンポーネントあたり最大16ビットの
%       Raw (binary)エンコード。

% 参考：IMFINFO, IMWRITE, IMFORMATS, FREAD, IMAGE, DOUBLE, UINT8.


%   Steven L. Eddins, June 1996
%   Copyright 1984-2002 The MathWorks, Inc.
%   $Revision: 1.1.6.2 $  $Date: 2004/04/28 01:57:07 $

