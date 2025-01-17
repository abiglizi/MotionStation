% MOVIE2AVI(MOV,FILENAME)  MATLABムービーからAVIムービーを作成します
% 
% MOVIE2AVI(MOV,FILENAME) は、MATLABムービー MOV からAVIムービーを
% 作成します。
%
% MOVIE2AVI(MOV,FILENAME,PARAM,VALUE,PARAM,VALUE...) は、指定したパ
% ラメータ設定を使って、MATLABムービー MOV からAVIムービーを作成します。
%
% 使用可能なパラメータ：
%
%   FPS         - AVI ムービーに設定する単位時間あたりのフレーム数。デフ
%                 ォルトは、15 fpsです。
%
%   COMPRESSION - 使用する圧縮法を示す文字列。UNIXでは、この値は
% 		  'None' です。Windows用に使用可能なパラメータは、'Indeo3', 
%                 'Indeo5', 'Cinepak', 'MSVC', 'None' のいずれかです。カ
%                 スタマイズした圧縮法を使用するには、codecドキュメンテーシ
%                 ョンで指定する4つのキャラクタコードを設定します。指定
%                 したカスタマイズ圧縮方法が見つからない場合は、エラーが
%                 生じます。デフォルトは、Windowsでは 'Indeo3'、UNIXでは 
%                 'None' です。
%
%   QUALITY      - 0から100の間の数字。このパラメータは、非圧縮ムービー
%                  には影響しません。数字が大きいほど、画質が良い(圧縮
%                  によるイメージの劣化が少ない)ことを意味しますが、結果
%                  のファイルサイズは大きくなります。デフォルトは、75です。
%                 
%   KEYFRAME     - テンポラリの圧縮方法をサポートするための単位時間
%                  あたりのキーフレーム数です。デフォルトは、毎秒2キーフ
%                  レームです。
%
%   COLORMAP     - インデックス付きAVIムービーに対して、使用するカラー
%                  マップを定義する M 行 3 列の行列。M は、256(Indeo圧
%                  縮法を使用する場合は236)より大きく設定してはいけま
%                  せん。デフォルトのカラーマップはありません。 
%
%   VIDEONAME    - ビデオストリームに対する記述的な名前。このパラメータ
%                  は、64キャラクタ長より短い必要があります。デフォルト
%                  の名前は、filename です。
%
% 参考：AVIFILE, AVIREAD, AVIINFO, MOVIE.

%   Copyright 1984-2004 The MathWorks, Inc.

