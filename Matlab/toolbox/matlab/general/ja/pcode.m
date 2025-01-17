% PCODE   文法解釈された擬似コードファイル(P-ファイル)の作成
% 
% PCODE FUN は、M-ファイル FUN.M を文法解釈してP-ファイル FUN.P を作
% 成し、カレントディレクトリに保存します(privateとメソッドディレクトリが存在し
% ない場合は、UDDを含むプライベートとオブジェクトメソッドに対してそれらを
% 作成します)。オリジナルのM-ファイルは、MATLABサーチパス上のどこに
% あっても構いません。
% 
% PCODE FUN1 FUN2 ... は、リストした関数に対するP-ファイルを作成します。
% 
% PCODE *.m は、カレントディレクトリ内のすべてのM-ファイルに対してP-ファ
% イルを作成します。
%
% PCODE FILE.LST は、拡張子LST (list-file)をもつファイルFILEをオープンし、
% 上記の有効なファイル引数として各行を読み込みます。LST ファイルは、入れ子
% 形式にはできません。
%   
% PCODE ... -INPLACE  は、M-ファイルと同じディレクトリにP-ファイルを作成
% します。ファイルが作成できない場合は、エラーが発生します。
%
% PCODE DIR/*.m は、ディレクトリ DIR 内のすべてのM-ファイルに対してP-ファ
% イルを作成します。
%
% PCODE DIR は、PCODE DIR/*.m と等価です。
% 
% ファイルとディレクトリパスは、相対パスでかまいません。'..' および'.' を含むパスは、
% それらが存在する場合は、MATLABパス上で一致しなくても、機能することがあり
% ます。
%
% 注意: 生成されたP-コードは、対応するM-ファイルがMATLABパス上にあるかどう
% かによって、1つの例外を除いて影響を受けません。関数がMATファイルからロード
% されるように場合のように隠されている場合は、生成されたP-コードは、プライベート
% ディレクトリのようなメソッド以外のパスの関数に対してセンシティブである場合が
% あります。


%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.13.4.1 $  $Date: 2004/04/28 01:53:28 $
