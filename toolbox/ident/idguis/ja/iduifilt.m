% IDUIFILT は、ident 用のデータに適用するプリフィルタ操作の取り扱い
% 
%   FLAG:
%   open         ダイアログボックスのオープン
%   spectra      スペクトルの計算とプロット
%                FILTER は、値 'filt' をもっている場合、フィルタリングさ
%                れたデータに対して処理されたことを意味し、他の場合は、
%                処理をしていないことを意味します。
%   down,move,up 周波数レンジを設定するボックスを描画
%   filter       選択したフィルタをデータに適用し、結果を XIDfilt(1,1) 
%                の userdata としてセーブします。
%   revert       一回のプッシュにより、アウトラインボックスを取り除き、
%                つぎのプッシュで、フィルタリングされたデータをクリアし
%                ます。
%   insert       フィルタリングデータを data summary board に挿入します。
%   mark         XIDfilt(3,1) の中の情報をベースにアウトラインボックスに
%                マークを入れます。
%   done         ダイアログボックスをクローズ

%   Copyright 1986-2001 The MathWorks, Inc.
