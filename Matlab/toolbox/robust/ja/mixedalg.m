% MIXEDALG は、正の実数対角乗数の存在チェックを行ないます。
%
% [MULT,XQO] = MIXEDALG(T,XQI,K) は、つぎのような
%
%           Re ( Tt.M ) > 0                   .....   ($)
%
% 正の実数部をもつ複素対角乗数の存在を探索します。
%
%  入力   : Tt   -- 正方複素行列
%           xqi  -- 単位ノルムのベクトルで、初期推定値
%            K   -- 対角不確かさブロックの中の不確かさのタイプを定義する列
%                   ベクトル
%                -- 1 : セクタ[-1,1]の中で正規化された実数パラメトリック不
%                       確かさを定義します。
%                   2 : 単位円内で正規化した複素パラメトリックな不確かさを
%                       定義します。
% 出力    : mult -- ($) を満足する乗数ベクトル
%                   ($) が満足されない場合、mult はゼロベクトルになります。
%           xqo  -- ($) を満足する単位ノルムの最終ベクトル x 
%

% Copyright 1988-2002 The MathWorks, Inc. 
