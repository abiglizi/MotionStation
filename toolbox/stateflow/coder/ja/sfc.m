% SFC( METHOD, VARARGS )を使って、Stateflow マシンに対してCコードを生成
% します。SFCは、適切なStateflowターゲットハンドルで宣言されるコール元の
% ターゲットに機能します。
%
% SFCは、指定されたマシンに対して、つぎのCファイルセットを生成します。
% 
% 1. マシンヘッダファイル  (.c)
% 2. マシンソースファイル  (.h)
% 3. マシンレジストリファイル	(.c) 
%    (シミュレーションターゲットの場合のみ)
% 4. コンパイラ依存のメイクファイル 
%    (シミュレーション/MEX/スタンドアローンターゲットの場合)
% 
% マシン内の各チャートに対して、
% 5. チャートヘッダファイル (.h)
% 6. チャートソースファイル (.c)
%
% SFC('-sfun')は、生成したコード中にSimulink S-Functionインタフェースコ
% ードを含みます。
% 
% SFC('-bitops')は、Cライクなビット操作を許可します。
%
% SFC('-noflow')は、フロー図のコード生成に対して最適化を行いません。
%
% SFC('-exportcharts')は、チャートの entry 関数名とduring 関数名がチャー
% ト名で装飾されない(拡張されない)コード生成を可能にします。このオプショ
% ンは、ステートマシンをコールするユーザオリジナルの外部ソースを作成する
% 場合に有効です。ここで、チャート名はユニークである必要があり、かつ、英
% 数字以外のキャラクタを含んではいけません。このオプションは、Stateflow 
% Coderのライセンスを持っている場合のみ有効となります。
% 
% SFC('-silent')は、コード生成中のすべてのワーニングメッセージを非表示に
% します。
% 
% SFC('-preservenames')は、あらゆるシンボルに対する名前の拡張なしでコー
% ドを生成します。この場合、すべてのデータ/ステート名はユニーク、かつ、
% 妥当な C 識別子である必要があります。すなわち、スイッチのような名前を
% 利用できません。そうでなければ、コンパイラエラーの原因となるでしょう。
% 
% SFC('-nocomments')は、ステートマシンのインプリメントに関連するコメント
% を含まないコードを生成します。ユーザコメントはコードにも継承されます。
% 
% SFC('-noecho')は、セミコロンで打ち切られていない表現の実行結果のMATLAB
% コマンドウィンドウへの表示を無効にします。
% 
% SFC('-msvc4x')は、mexopts.batファイルで指定されているコンパイラのため
% のメイクファイルを生成すると同時に、Microsoft Visual C++ 4.xのためのメ
% イクファイルを生成します。
% 
% SFC('-watcom')は、Watcom 10.6コンパイラのためのメイクファイルを生成し
% ます。
% 
% SFC('-msvc50')は、Microsoft Visual C++ 5.0のためのメイクファイルを生成
% します。
% 
% SFC('-unix')は、UNIXプラットフォーム上のgmakeのためのメイクファイルを
% 生成します。
%  
% LANGUAGE = SFC('language')、または、SFC(target, 'language')は、ターゲ
% ット言語文字を出力します。
%
% [DEBUG, OPTIONAL, NEEDED] = SFC(target, 'flags')は、3種類のフラグに関
% する情報を出力します。DEBUGフラグは、Stateflowデバッガに対するオプショ
% ンフラグです。OPTIONALフラグは、コード生成と最適化に影響します。NEEDED
% フラグは、定義したターゲットに対して必ず必要となるフラグです。
%
% REVISION = SFC('revision')は、コーダーレビジョンを文字で出力します。

%   Copyright (c) 1995-2001 by The MathWorks, Inc.
