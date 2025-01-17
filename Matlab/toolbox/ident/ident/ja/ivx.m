% IVX は、ARX モデルの補助変数推定を計算します。
%
%   MODEL = IVX(Z,NN,X)
%
%   MODEL : つぎのように表される ARX モデル
% 
%               A(q) y(t) = B(q) u(t-nk) + v(t)
%         
%           に対して、関連した構造情報と共に、IV 推定を出力します。MODEL
%           の正確な構造については、HELP IDPOLY を参照してください。
%
%   Z     : IDDATA オブジェクトとして表した出力 - 入力データ。HELP IDD-
%           ATA を参照。
%
%   NN    : NN=[na nb nk] は、上のモデルに関連した次数と遅れです。
%   X     : 補助変数のベクトルで、y ベクトル(すなわち、Z.y)と同じサイズ
%           のものです。また、Z が複数の実験結果を含んでいる場合、X は実
%           験と同じ信号をもつセル配列になります。
%
% 補助変数の上手で、自動的な選択については、IV4 を参照してください。
% 多出力バージョンは、IDARX/IVX です。
%
% TH = ivx(Z,NN,X,maxsize) は、アルゴリズムにより形成されるmaxsize 要素
% より大きい行列を含みません。

%   Copyright 1986-2001 The MathWorks, Inc.
