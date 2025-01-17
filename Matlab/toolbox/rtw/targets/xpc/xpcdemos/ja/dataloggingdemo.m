% DATALOGGINGDEMO 時間、値において等間隔なデータロギングについてのデモ
%
% DATALOGGINGDEMO は、モデルxpcsosc.mdlを取得し、ビルドし、ターゲットPCに
% ダウンロードします。状態をログするオプションは、このデモに対してoffとなりま
% す。
%
% アプリケーションの停止時間は、0.2 秒に設定されます。最初の実行の終わりに、
% 時間と出力ログが回収され、プロットされます。このとき、ロギングは、時間に
% ついて等間隔であり、各サンプルが、ログされます。続いて、ロギングモードは、
% 0.02のステップで、0.02 と 0.2の間で値に等間隔に設定されます。
%
% オプションの引数 PARAM を1に設定する場合、'Gain1/Gain' (ダンピング)
% パラメータ(プロパティ名は、関数GETPARAMIDを使用して回収されます)は、
% 各時刻にランダム値に設定されます。そうでない場合、これは、定数になります。
% しかし、ランダムなゲインの設定では、結果は、ゲインの変更の効果と値等間隔な
% ロギングの組み合わせにより、正しく見えない場合があります。




%   Copyright (c) 1996-2000 The MathWorks, Inc. All Rights Reserved.
