% FREAD   バイナリデータをファイルから読み込みます
% 
% [A, COUNT] = FREAD(FID,SIZE,PRECISION) は、指定したファイルからバイナリ
% データを読み込み、行列 A に書き出します。オプションの出力引数 COUNT 
% には、正常に読み込まれた要素数が出力されます。
%
% FID は、FOPEN で得られる整数のファイル識別子です。
% 
% size 引数は、オプションです。指定されなければ、ファイルの終端まで読み込
% み、ファイルのポインタはファイルの末尾になります(詳細は FEOF を参照)。
% 指定する場合の有効な値をつぎに示します。
%
%     N      列ベクトルにN要素を読み込みます
%     inf    ファイルの最後まで読み込みます
%     [M,N]  M行N列の行列を満たす要素を列順に読み込みます。Nはinfを指定
%            できますが、Mはできません。
%   
% 引数 PRECISION は、読み込むデータのフォーマットを指定する文字列です。
% 'int' または 'float' のようなデータタイプ識別子にバイト単位で大きさを指定
% する整数を後に続けたものを含みます。つぎの文字列で、MATLAB版または
% C、Fortran版を利用することができます。指定しない場合は、デフォルトは
% 'uchar' です。 
%   
%     MATLAB  CまたはFortran     解釈
%
%     'uchar'   'unsigned char'  符号なしキャラクタ、8ビット
%     'schar'   'signed char'    符号付きキャラクタ、8ビット
%     'int8'    'integer*1'      整数、8ビット
%     'int16'   'integer*2'      整数、16ビット
%     'int32'   'integer*4'      整数、32ビット
%     'int64'   'integer*8'      整数、64ビット
%     'uint8'   'integer*1'      符号なし整数、8ビット
%     'uint16'  'integer*2'      符号なし整数、16ビット
%     'uint32'  'integer*4'      符号なし整数、32ビット
%     'uint64'  'integer*8'      符号なし整数、64ビット
%     'single'  'real*4'         浮動小数点、32ビット
%     'float32' 'real*4'         浮動小数点数、32ビット
%     'double'  'real*8'         浮動小数点、64ビット
%     'float64' 'real*8'         浮動小数点数、64ビット
%
% たとえば、
%
%       type fread.m
%
% は、FREAD ヘルプを含むM-ファイルを表示します。つぎのコマンドをシミュ
% レーションするには、つぎのように入力してください。
%
%       fid = fopen('fread.m','r');
%       F = fread(fid);
%       s = char(F')
%
% コマンド FOPEN は、読み込み用にMATLABパス上の名前'fread.m'をもつ
% M-ファイルをオープンします。コマンド FREAD は、デフォルト SIZE として inf
% をもち、デフォルトの PRECISION として 'uchar' を仮定しています。ファイル
% 全体を読み込んで、符号なしキャラクタをクラス 'double' (倍精度浮動小数点)
% の列ベクトルに変換します。読み取り可能なテキストとして結果を表示する
% ため、'double' の列ベクトルは行ベクトルに転置され、関数 CHAR を使ってク
% ラス 'char' に変換されます。
%
% つぎのプラットフォーム固有の書式はサポートされていますが、すべてのプ
% ラットフォーム上で同じサイズであることは保証されていません。
% 
%     MATLAB    CまたはFortran   解釈
%     'char'    'char*1'         キャラクタ、8ビット(符号付きまたは符号なし)
%     'short'   'short'          整数、16ビット
%     'int'     'int'            整数、32ビット
%     'long'    'long'           整数、32または64ビット
%     'ushort'  'unsigned short' 符号なし整数、16ビット
%     'uint'    'unsigned int'   符号なし整数、32ビット
%     'ulong'   'unsigned long'  符号なし整数、32ビットまたは64ビット
%     'float'   'float'          浮動小数点数、32ビット
%
% つぎの書式は、バイトではなく、ビットの入力ストリームに写像します。
%
%     'bitN'                     符号付き整数、Nビット (1< = N< = 64)
%     'ubitN'                    符号なし整数、Nビット (1< = N< = 64)
%
% 入力ストリームがバイトで、FREAD がある要素に対して必要なバイト数を
% 読んでいる途中でファイルの終端(FEOFを参照)に達した場合は、部分的な結果
% は無視されます。しかし、入力ストリームがビットの場合は、部分的な結果は
% 最後の値として出力されます。ファイルの終端に達する前にエラーが生じた
% 場合は、その点までに読み込まれた要素のみが利用されます。
%
% デフォルトでは、数値は、クラス'double'の配列に出力されます。double 以外の
% クラスに格納された数値を出力するためには、ユーザのソースフォーマットを
% まず指定して PRECISION 引数を作成し、その後に '=>' を続けて、最終的な
% ユーザ指定フォーマットを指定します。指定のためにMATLABクラスタイプの
% 正確な名前を使う必要はありません(詳細は CLASS を参照)。名前は、最も
% 適切な MATLAB クラスタイプの名前に変換されます。ソーズフォーマットと相
% 手のフォーマットが同じ場合は、つぎの省略した記法が使われます。
%
%       *source
%
% は、つぎのことを意味します。
%
%       source=>source
%
%  たとえば、
%
%       uint8=>uint8               これは、符号なしの8ビット整数で読み込み、
%                                  符号なし8ビット整数配列で保存します。  
%
%       *uint8                     上の省略形です。
%
%       bit4=>int8                 バイト単位で圧縮された符号付き4ビット
%                                  整数を読み込み、符号付き8ビット整数配列
%                                  に保存します(各4ビット整数は、1つの
%                                  8ビット整数になります)。
%
%       double=>real*4             倍精度で読み込み、32ビットの浮動小数点
%                                  配列として変換し、保存します。
%
% [A, COUNT] = FREAD(FID,SIZE,PRECISION,SKIP) は、各 PRECISION 値が
% 読み込まれた後でスキップするバイト数を指定する引数 SKIP を含んでいます。
% PRECISION が、ビットソースフォーマット、たとえば、'bitN' や 'ubitN' を
% 指定する場合は、SKIP 引数はスキップするバイト数と解釈します。
%
% SKIP が使われる場合、文字列 PRECISION は、引数 PRECISION のソース
% フォーマットの前に、'N*'の型の正の整数の繰り返しファクタを含んでいます。
% たとえば、'40*uchar' のようにです。PRECISION に対する 40*uchar は
% '40*uchar=>double' と等価ですが、'40*uchar=>uchar' とは異なります。SKIP
% 引数が指定された場合、FREAD は最大で値の繰り返しファクタ(デフォルトは1)
% を読み込み、SKIP 引数により指定された数だけ入力をスキップします。そして
% つぎのブロックを読み込み、入力をスキップし、SIZE で指定した個数が読み込
% まれるまで続けます。SKIP 引数が指定されていない場合は、繰り返しファクタ
% は無視されます。スキップ付きの繰り返しは、固定長のレコードから非連続の
% フィールド内のデータを抽出するのに有効です。
%
% たとえば、
%
%       s = fread(fid,120,'40*uchar=>uchar',8);
%
% は、8キャラクタずつ分離された40ブロックの中の120キャラクタを読み込み
% ます。s のクラスタイプは、'uint8' であることに注意してください。
% これは、送り手のフォーマット 'uchar' に対応する適切なクラスです。40は
% 120の約数なので、最後のブロックの読み込みは、フルブロックになります。
% フルブロックとは、最終のスキップが、コマンドが終了する前に実行される
% ものです。最後のブロック読み込みがフルブロックでない場合は、FREAD は
% スキップ付きで終了しません。
%
% Big EndianファイルやLittle Endianファイルの読み込み方については、
% FOPEN を参照してください。
%
% 参考：FWRITE, FSEEK, FSCANF, FGETL, FGETS, LOAD, FOPEN, FEOF.



%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.9.4.1 $  $Date: 2004/04/28 01:58:10 $
%   Built-in function.
