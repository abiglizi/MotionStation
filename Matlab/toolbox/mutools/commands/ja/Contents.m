% Mu-Analysis and Synthesis Toolbox
% Version 3.0.8 (R14) 05-May-2004
%
% ?V機能
% Readme  - Mu-analysis and Synthesis Toolboxに関する?d要なリリ?[ス?�報
%           (Readmeをダブルクリックするか?A"whatsnew directoryname"とタ
%           イプしてください?Bたとえば?A"whatsnew mutools/commands"とタ
%           イプすると?Aこのファイルを表示します?B)
%
% 標?�演算/基本関?�
%
% abv       - constant/varying/system?s列を?繧ｩら?�に結?�
% cjt       - varying/system?s列の共役転置
% daug      - constant/varying/system?s列を対角に拡大
% madd      - constant/varying/system?s列の加算
% minv      - constant/varying/system?s列の逆?s列
% mmult     - constant/varying/system?s列の?謗Z
% mscl      - SYSTEMまたはVARYING?s列をスカラ倍
% msub      - constant/varying/system?s列の減算
% sbs       - ?s列を並べる
% sclin     - システムの入力をスケ?[リング
% sclout    - システムの?o力をスケ?[リング
% sel       - ?s/列または?o力/入力を選択
% starp     - Redhefferスタ?[?ﾏ
% transp    - varying/system?s列の転置
%
% ?s列の?�報の表示?Aプ�?ット
%
% drawmag   - 対話型のマウスを使った描画と近似のツ?[ル
% minfo     - ?s列の?�報の?o力
% mprintf   - ?s列の?綜ｮ付き表示
% rifd      - 実?舶�?A虚?舶�?A周波?�?A減?蒲ｦの表示
% see       - varying/system?s列の表示
% seeiv     - varying?s列の独立変?狽ﾌ表示
% seesys    - varying/system?s列の?綜ｮ付きの表示
% vplot     - varying?s列のプ�?ット
% vzoom     - プ�?ットウィンドウでマウスを使って軸を選択
% wsgui     - グラフィカルな�??[クスペ?[ス操?�ツ?[ル
%
% モデリング機能
%
% fitsys    - 周波?秤椏噬f?[タを伝達関?狽ﾅ近似
% nd2sys    - SISO伝達関?狽�SYSTEM?s列に変換
% pck       - ?�態空間デ?[タ(A, B, C, D)からsystem?s列を?�?ｬ
% pss2sys   - [A B;C D]?s列をmu-toolsのsystem?s列に変換
% sys2pss   - SYSTEM?s列から?�態空間?s列[A B; C D]を抽?o
% sysic     - SYSTEM?s列の相互結?�?�?ｬプ�?グラム
% unpck     - SYSTEM?s列から?�態空間デ?[タ(A,B,C,D)を抽?o
% zp2sys    - 伝達関?狽ﾌ極と零点をSYSTEM?s列に変換
%
% System?s列関?�
%
% reordsys  - SYSTEM?s列の?�態の並べ替え
% samhld    - 連続時間システムのサンプルホ?[ルド近似
% spoles    - SYSTEM?s列の極
% statecc   - SYSTEM?s列に?ﾀ標変換を適用
% strans    - SYSTEM?s列の双対角?ﾀ標変換
% sysrand   - ランダムなSYSTEM?s列の?�?ｬ
% szeros    - SYSTEM?s列の伝達零点
% tustin    - Prewarped Tustin変換を使って連続SYSTEM?s列を離散SYSTEM?s列
%             に変換
%
% モデルの低次元化
%
% hankmr    - SYSTEM?s列の?ﾅ適Hankelノルム近似
% sdecomp   - SYSTEM?s列を2つのSYSTEM?s列に分解
% sfrwtbal  - SYSTEM?s列の周波?�?dみ付き平?t化実現
% sfrwtbld  - SYSTEM?s列の安定な周波?�?dみ付き実現
% sncfbal   - SYSTEM?s列の既約分解の平?t化実現
% srelbal   - SYSTEM?s列の確率的平?t化実現
% sresid    - SYSTEM?s列の?�態量を取り?怩ｭ
% strunc    - SYSTEM?s列の?�態の?�?�
% sysbal    - SYSTEM?s列の平?t化実現
%
% システム応答
%
% cos_tr    - 余弦?M?�をVARYING?s列として?ｶ?ｬ
% dtrsp     - ?�形システムの離散時間応答
% frsp      - SYSTEM?s列の周波?秤椏�
% sin_tr    - ?ｳ弦?M?�をVARYING?s列として?ｶ?ｬ
% sdtrsp    - ?�形システムのサンプル値時間応答
% siggen    - ?M?�をVARYING?s列として?ｶ?ｬ
% simgui    - グラフィカルな?�形システムシミュレ?[ションツ?[ル
% step_tr   - ステップ?M?�をVARYING?s列として?ｶ?ｬ
% trsp      - ?�形システムの時間応答
%
% H_2?AH_?�解?ﾍ?Aシンセシス
%
% dhfsyn    - 離散時間H?�?ｧ御?ﾝ計
% dhfnorm   - 安定なSYSTEM?s列の離散時間?�ノルムの計算
% emargin   - ギャップ計量�?バスト安定?ｫ
% gap       - 2つのSYSTEM?s列間のギャップ計量の計算
% h2norm    - 安定で?A厳密にプ�?パなSYSTEM?s列の2ノルムを計算
% h2syn     - H_2?ｧ御?ﾝ計
% hinffi    - H?�全?�報?ｧ御則
% hinfnorm  - 安定でプ�?パなSYSTEM?s列のH?�ノルムを計算
% hinfsyn   - H?�?ｧ御?ﾝ計
% hinfsyne  - H?�?ﾅ?ｬエント�?ピ?[?ｧ御?ﾝ計
% linfnorm  - プ�?パなSYSTEM?s列のL?�ノルムを計算
% ncfsyn    - H?�ル?[プ?ｮ形?ｧ御?ﾝ計
% nugap     - SYSTEM?s列間のnuギャップ計量の計算
% pkvnorm   - VARYING?s列のピ?[ク(独立変?狽ﾉ関する)ノルム
% sdhfsyn   - サンプル値H?�(誘導L_2ノルム)?ｧ御?ﾝ計
% sdhfnorm  - 安定なSYSTEM?s列のサンプル値H?�ノルム(誘導L_2ノルム)
%
% ?\造化特異値(mu)解?ﾍとシンセシス
%
% blknorm   - constant/varying?s列のブ�?ック毎のノルム
% cmmusyn   - Constant?s列のmuシンセシス
% dkit      - 自動化されたD-Kイタレ?[ション
% dkitgui   - グラフィカルなDKイタレ?[ションツ?[ル
% dypert    - 周波?狽ﾌmuデ?[タから有�??ﾛ動を?�?ｬ
% fitmag    - ゲインデ?[タを実有�?伝達関?萩ﾟ似
% fitmaglp  - ゲインデ?[タを実有�?伝達関?萩ﾟ似
% genmu     - 一般化muの?繩Eの計算
% genphase  - ゲインデ?[タの?ﾅ?ｬ位相周波?秤椏嘯�?ｶ?ｬ
% magfit    - ゲインデ?[タを実有�?伝達関?萩ﾟ似
% msf       - DKイタレ?[ション用のDスケ?[ル近似
% msfbatch  - msfのバッチバ?[ジョン
% mu        - constant/varying?s列のmu解?ﾍ
% muftbtch  - バッチ形式のDスケ?[ル近似ル?[チン(?ｫ来はサポ?[トを?sわない
%             ので?Amsfbatchを使ってください)
% musynfit  - 対話的なDスケ?[ル有�?近似(?ｫ来はサポ?[トを?sわないので?A
%             msfを使ってください)
% musynflp  - 対話的なDスケ?[ル有�?近似(?ｫ来はサポ?[トを?sわないので?A
%             msfを使ってください)
% muunwrap  - mu計算からデ?[タを抽?o
% randel    - ランダムな?ﾛ動を?ｶ?ｬ
% sisorat   - 1次全通過内挿
% unwrapd   - muからDスケ?[リング?s列を?�?ｬ
% unwrapp   - muからDelta?ﾛ動を?�?ｬ
% wcperf    - ?ﾅ悪ケ?[スの?ｫ能曲?�と?ﾛ動
%
% VARYING?s列の取り扱い
%
% getiv     - VARYING?s列の独立変?狽ﾌ?o力
% indvcmp   - 2つの?s列の独立変?買f?[タの比較
% massign   - ?s列の要素の割り当て
% scliv     - 独立変?狽ﾌスケ?[リング
% sortiv    - 独立変?狽ﾌ並べ替え
% tackon    - VARYING?s列の結?�
% var2con   - VARYING?s列をCONSTANT?s列に変換
% varyrand  - ランダムなVARYING?s列を?ｶ?ｬ
% vpck      - VARYING?s列の圧?k
% vunpck    - VARYING?s列の分解
% xtract    - VARYING?s列の部分的抽?o
% xtracti   - VARYING?s列の部分的抽?o
%
% Varying?s列に関する標?�MATLABコマンド
%
% vabs      - constant/varying?s列の?竭ﾎ値
% vceil     - constant/varying?s列の要素の?�方向への丸め
% vdet      - constant/varying?s列の?s列式
% vdiag     - constant/varying?s列の対角要素
% veig      - constant/varying?s列の固有値分解
% vexpm     - constant/varying?s列の指?�
% vfft      - VARYING?s列のFFT
% vfloor    - constant/varying?s列の要素の-?�方向への丸め
% vifft     - VARYING?s列の逆FFT
% vinv      - constant/varying?s列の逆?s列
% vimag     - constant/varying?s列の虚?舶�
% vnorm     - varying/constant?s列のノルム
% vpoly     - constant/varying?s列の特?ｫ多?�式
% vpinv     - constant/varying?s列の擬似逆?s列
% vrank     - constant/varying?s列のランク
% vrcond    - constant/varying?s列の?��??�
% vreal     - constant/varying?s列の実?舶�
% vroots    - constant/varying?s列の多?�式の?ｪ
% vschur    - constant/varying?s列のSchur分解
% vspect    - VARYING?s列に対するSignal Processingのスペクトル解?ﾍ
%             コマンド
% vsqrtm    - constant/varying?s列の平方?ｪ
% vsvd      - constant/varying?s列の特異値分解
%
% Varying?s列に関する付加的な機能
%
% vcjt      - constant/varying?s列の共役転置
% vcond     - constant/varying?s列の?��??�
% vconj     - constant/varying?s列の複素共役
% vdcmate   - VARYING?s列の間引き
% vebe      - VARYING?s列の要素単位の演算
% veberec   - 要素単位の逆?�
% veval     - VARYING?s列の一般関?狽ﾌ評価
% vveval    - VARYING?s列の一般関?狽ﾌ評価
% mveval    - VARYING?s列の一般関?狽ﾌ評価
% vfind     - 独立変?狽��?める
% vinterp   - VARYING?s列の内挿
% vldiv     - constant/varying?s列の?ｶ?恷Z
% vrdiv     - constant/varying?s列の右?恷Z
% vrho      - constant/varying?s列のスペクトル半径
% vtp       - constant/varying?s列の転置
% vtrace    - constant/varying?s列の対角の和
%
% ユ?[ティリティとその他の関?�
%
% add_disk  - ナイキストプ�?ットに単位円を追加
% cf2sys    - ?ｳ規化された既約分解から?s列を?�?ｬ
% clyap     - 連続系Lyapunov方程式
% crand     - 一様分布するランダムな複素?s列を?�?ｬ
% crandn    - ?ｳ規分布するランダムな複素?s列を?�?ｬ
% csord     - ?�?�付けられた複素Schur?s列
% mfilter   - Butterworth, Bessel, RCフィルタを?�?ｬ
% negangle  - ?s列要素の角度を0から-2 piの間で計算
% ric_eig   - 固有値分解を使って?ARiccati方程式を解く
% ric_schr  - Schur分解を使って?ARiccati方程式を解く
% unum      - 入力の次元
% xnum      - ?�態の次元
% ynum      - ?o力の次元
%

%   Generated from Contents.m_template revision 1.1.6.1  $Date: 2004/03/10 21:22:23 $
%   Copyright 1991-2004 MUSYN Inc. and The MathWorks, Inc. 
