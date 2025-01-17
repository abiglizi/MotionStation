% VPA   可変精度の演算
% R = VPA(S) は、D 桁の精度をもつ可変精度浮動小数点演算を使って、S の各
% 要素を数値的に評価します。ここで、D は、DIGITS のカレントの設定値です。
% R は、シンボリック式です。
%
% VPA(S, D) は、DIGITS のカレントの設定の代わりに、D 桁を使って評価しま
% す。D は、整数、または、数値のシンボリック表現です。
%
% 例題 :
%      phi = sym('(1+sqrt(5))/2');      % phiは、"黄金比"です。
%      vpa(phi,75) は、75桁のphiを含む文字列です。
%
%      vpa(sym(pi),1919)は、スクリーン全体にpiを表示します。
%      vpa(sym('exp(pi*sqrt(163))'),36) は、ほとんど整数を表示します。
%
%      vpa(sym(hilb(2)),5) は、つぎの結果を出力します。
% 
%      [    1., .50000]
%      [.50000, .33333]
%
% 参考： DOUBLE, DIGITS.



%   Copyright 1993-2002 The MathWorks, Inc.
