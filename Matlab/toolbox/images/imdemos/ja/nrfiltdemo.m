% NRFILTDEMO   ノイズ除去フィルタリングデモ
%
% このデモは、数種類のノイズに適用される線形、および、非線形フィルタ
% リングを使用してイメージ内のノイズ除去を行います。
%   
% Figure ウィンドウの左側にあるイメージは、劣化していないオリジナルの
% イメージです。多くのイメージから選択するには、オリジナルイメージ下の
% メニューを使用してください。
%
% 中央のイメージは、ノイズの付加されたオリジナルのイメージです。中央の
% イメージの下のメニューを使用して、3つのノイズタイプから選択してくだ
% さい。メニューの下のフィールドを編集して、ノイズのパラメータを設定して
% ください。"Add Noise”を押すと、そのノイズを適用します。
%   
% 右側のイメージは、ノイズ除去フィルタを中央のイメージに適用した結果を
% 表示しています。3番目のイメージ下のメニューを使用して、ノイズ除去
% フィルタのタイプと近傍の大きさを選択してください。"Apply Filter"を
% 押すと、劣化したイメージのフィルタリングを行います。
%
% Flower、Blood、Circuit、Rice、Saturn、Bone Marrow、および Aluminum の
% イメージは、J. C. Russ, The Image Processing Handbook, Third Edition, 
% 1998, CRC Press から無料で提供されています。
%
% 参考：IMNOISE, MEDFILT2, ORDFILT2, WIENER2



%   Copyright 1993-2002 The MathWorks, Inc.  
