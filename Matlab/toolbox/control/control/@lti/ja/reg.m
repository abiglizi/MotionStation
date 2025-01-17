% REG   状態フィードバックと推定器ゲインによるレギュレータの設計
%
% RSYS = REG(SYS,K,L) は、状態空間システム SYS に対するオブザーバに基づく
% レギュレータ RSYS を作成します。このとき、SYS のすべての入力は、制御
% 入力で、すべての出力は観測されていると仮定します。行列 K と L は、状態
% フィードバックゲインとオブザーバゲインを指定しています。
%           .
%    SYS:   x = Ax + Bu ,   y = Cx + Du 
%
% に対して、結果のレギュレータは、
%     .
%    x_e = [A-BK-LC+LDK] x_e + Ly
%      u = -K x_e  
%
% となります。このレギュレータは、正のフィードバックを用いて、プラントに
% 接続されなければいけません。REG は、離散時間システムでも同様に働きます。
%
% RSYS = REG(SYS,K,L,SENSORS,KNOWN,CONTROLS) は、より一般的なレギュレータ
% 問題を扱います。ここで、
%  * プラント入力は、制御入力 u 、既知入力 Ud 、確率的入力 ｗ から構成
%    します。
%  * プラント出力のサブセット y のみが測定されます。
%  
% I/O のサブセット y, Ud, u は、インデックスベクトル SENSORS, KNOWN, 
% CONTROLS で指定します。結果のレギュレータ RSYS は、指令値 u を生成する
% ための入力として、[Ud;y] を利用します。 
%
% ゲイン K と L を求めるために極配置の手法( PLACE 参照)を用いることが
% でき、または、LQR/DLQR と KALMAN で求めた LQ ゲインと Kalman ゲインを
% 利用できます。
%
% 参考 : PLACE, LQR, DLQR, LQGREG, ESTIM, KALMAN, SS.


%   Clay M. Thompson 6-29-90
%   Revised: P. Gahinet  7-26-96
%   Copyright 1986-2002 The MathWorks, Inc. 
