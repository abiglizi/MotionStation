% SOS2TF は、2次構造を伝達関数型へ変換します。
%
% [B,A] = SOS2TF(SOS,G) は、ゲイン G と2次構造システム SOS を与えて、離
% 散時間線形システムの分子係数 B と分母係数 A を出力します。
%
% SOS は、つぎのように構成される L 行6列の行列で、SOS の各行には2次構造
% の係数が含まれます。
%
%     SOS = [ b01 b11 b21  1 a11 a21 
%             b02 b12 b22  1 a12 a22
%             ...
%             b0L b1L b2L  1 a1L a2L ]
%
% システムの伝達関数は2次構造の伝達関数とゲイン G の積になります。Gが設
% 定されていない場合、デフォルトで1が使われます。SOS 行列の各行は、以下
% の2次構造形式の離散伝達関数を表しています。
%
%     b0k +  b1k z^-1 +  b2k  z^-2
%     ----------------------------
%     1 +  a1k z^-1 +  a2k  z^-2
%
% ここで、k は行インデックスです。
%
% 参考：   ZP2SOS, SOS2ZP, SOS2SS, SS2SOS



%   Copyright 1988-2002 The MathWorks, Inc.
