% EIG   シンボリック行列の固有値と固有ベクトル
% 出力引数を1つ設定したLAMBDA = EIG(A)は、シンボリック正方行列Aの固有値
% を含むシンボリックなベクトルを出力します。
%
% 出力引数を2つ設定した[V,D] = EIG(A)は、各列が固有ベクトルからなる行列V
% と、固有値を含む対角行列Dを出力します。結果のVがAと同じサイズならば、A
% は、A*V = V*Dを満たす線形独立な固有ベクトルの完全集合をもちます。
%
% 出力引数を3つ設定した[V,D,P]は、長さが線形独立な固有ベクトルの総数のイ
% ンデックスベクトルPも出力します。A*V = V*D(P,P)を満たします。Aがn行n列
% の場合、Vはn行m列になります。このとき、nは代数的重複度の和で、mは幾何
% 的重複度の和です。
%
% LAMBDA = EIG(VPA(A))と[V,D] = EIG(VPA(A))は、可変精度の演算を使って、
% 数値的に固有値と固有ベクトルを計算します。Aが固有ベクトルの完全集合を
% もたないならば、V の各列は線形独立ではありません。
%
% 例題 :
% 
%      [v,lambda] = eig([a,b,c; b,c,a; c,a,b])
%
%      R = sym(gallery('rosser'));
%      eig(R)
%      [v,lambda] = eig(R)
%      eig(vpa(R))
%      [v,lambda] = eig(vpa(R))
%
% A = sym(gallery(5))は、固有ベクトルの完全集合をもちません。
% [v,lambda,p] = eig(A)は、固有ベクトルを1つだけ出力します。
%
% 参考   POLY, JORDAN, SVD, VPA.



%   Copyright 1993-2002 The MathWorks, Inc.
