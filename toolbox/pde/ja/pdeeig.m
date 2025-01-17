% PDEEIG   固有値 PDE 問題を解きます。
%
% [V,L] = PDEEIG(B,P,E,T,C,A,D,R) は、P, E, T で記述されるメッシュ上で、
% B によって与えられた境界条件をもつ PDE 固有値問題 -div(c grad(u))+a u 
% = l du の FEM 形式に合わせて解を作ります。 
%
% R は、実数軸上の範囲を示す2要素ベクトルです(下限は、-Inf にすることが
% できます)。アルゴリズムは、設定した範囲内の全ての固有値を求め、L に出
% 力します。
%
% V は、固有ベクトル行列です。スカラの場合、V の各列は、P に基づいて対応
% する節点での解の値の固有ベクトルです。NP 節点をもつ N 次元のシステムの
% 場合、V の最初のNP 行は v の最初の成分を表示し、続く V の NP 行は v の
% 第2の成分を、というように表示します。このようにして、v の成分は、節点
% の行数の N ブロックとして、ブロック V に設定されます。
%
% B は、PDE 問題の境界条件を表示します。詳細は、PDEBOUND を参照してくだ
% さい。
%
% PDE 問題の形状は、メッシュデータ P, E, T によって与えられます。詳細は、
% INITMESH を参照してください。
%
% PDE 問題の係数 C, A, D は、多種多様な方法で与えることができます。詳細
% は、ASSEMPDE を参照してください。
%
% [V,L] = PDEEIG(K,B,M,R) は、一般化行列固有値問題 K*UI = l B'*M*B*UI, U
% = B*UI に合わせて解を求めます。
% 



%       Copyright 1994-2001 The MathWorks, Inc.
