% [tau,P,S,N] = popov(sys,delta,flag)
%
% この関数は、ポポフ規範を使って、つぎの相互接続
%                   ___________
%                   |         |
%              +----|  Phi(.) |<---+
%              |    |_________|    |
%           w  |                   | y
%              |    ___________    |
%              +--->|         |----+
%                   |   SYS   |
%             ----->|_________|----->
%
%
% が、DELTAで設定された不確かさクラスの任意の作用素Phiに対して安定かどう
% かを検証します。このクラスは、ノルム、または、セクタ有界の非線形、また
% は、時変不確かさを含みます。
%
% 安定性は、TAU < 0のとき達成され、この場合、POPOVは、Lyapunov行列Pと安
% 定性を検証する乗数SとNを出力します。
%
% 入力:
%  SYS        動的システム(LTISYSを参照)。
%  DELTA      不確かさクラスの記述(UBLOCKを参照)。
%  FLAG       オプション。デフォルトは0です。FLAG=1と設定すると、より強
%             力な計算を実行し、実パラメータの不確かさの保守性を緩和しま
%             す。
%
% 出力:
%  TAU        対応するLMI可解問題の最適最大固有値。ロバスト安定性は、TAU
%             < 0のとき、すなわち、Popov連立LMIが可解のときに保証されま
%             す。
%  P          x'*P*xは、安定性を検証するLyapunov関数の2次部分です。
%  S,N        TAU < 0ならば、SとNは、安定性を検証するPopov"乗数"です。
%
% 参考：    QUADSTAB, PDLSTAB, MUSTAB, UBLOCK, UDIAG, UINFO.



% Copyright 1995-2002 The MathWorks, Inc. 
