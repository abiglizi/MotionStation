% AUGTF   W1,W2,W3 (伝達関数型)の2ポートプラントへの拡大
%
% [TSS_] = AUGTF(SS_G,W1,W2,W3)または[A,B1,B2,C1,C2,D11,D12,D21,D22] = 
% AUGTF(AG,BG,CG,DG,W1,W2,W3)は、H2/Hinf制御設計において、拡大された状態
% 空間型を作成します。ここで、
%         ss_g = mksys(ag,bg,cg,dg); (オリジナルのプラントの状態空間型)
%
%         w1   = "e"に対する対角化した重み行列 
%              = [N11;D11;N22;D22;....]
%
%         w2   = "u"に対する対角化した重み行列
%              = [N11;D11;N22;D22;....]
%
%         w3   = "y"に対する対角化した重み行列、周波数無限大では多項式行
%                列です(すなわち、w3(s) = sysw3 + w3poly(s))
%              = [N11;D11;N22;D22;....]
%
% 結果の状態空間型sysw1, sysw2, W3(s) = sysw3 + w3poly(s)は、最終的な状
% 態空間型を計算するために、AUGSS.Mに渡されます。
%
% 重み関数を未定義にする場合、単に空行列[]として入力してください。



% Copyright 1988-2002 The MathWorks, Inc. 
