% LICENSE   ライセンス番号
% 
% LICENSE は、このMATLABに対するライセンス番号を出力します。
%
% ライセンス番号は、常に文字列として出力されます。
%
% この関数は、数の出力は保証されません。デモのライセンスに対しては 'demo'、
% スチューデントライセンスに対しては 'student'、ライセンス番号が確定
% されない場合は、'unknown' が出力されるかもしれません。
%
% LICENSE('inuse') は、現在のMATLABセッションで使われているライセンスの
% リストを表示します。
%     
% STRUCT = LICENSE('inuse') は、現在のMATLABセッションで使われている
% ライセンスのリストと、そのライセンスを使用しているユーザ名を含むリスト
% を構造体で出力します。
%
% MATLAB Runtime Serverが使用されているとき、'inuse' オプションは、何も
% 表示されないか、空の構造体を出力します。
%
% LICENSE('test', FEATURE) は、プロダクト FEATURE に対するライセンスが
% 存在する場合、テストします。LICENSE は、ライセンスが存在する場合は1、
% ライセンスが存在しない場合は0を出力します。
%
% FEATURE 文字列は、ライセンスファイル内のプロダクトを識別するために
% 使用される正確な feature 名でなければなりません。
% 例えば、'Identification_Toolbox' は、System Identification Toolbox に
% 対する feature 名です。FEATURE 文字列は、27を超えてはいけません。また
% 大文字小文字を区別します。
%
% 注意: ライセンスに対してのみテストすることは、ライセンスが存在するかを
% 確認することになります。ライセンスが使われているかは確認されません。
% ライセンスが期限切れか、またはシステム管理者がオプションファイル内の
% 使用しているプロダクトからあなたを除いた場合、LICENSE は、ライセンスが
% 存在すれば、ライセンスはまだ1を返します。
% 
% LICENSE('test', FEATURE, TOGGLE) は、TOGGLE の値によって、プロダクト 
% FEATURE のテストを有効にする(enable)、または有効にしません(disable)。
% TOGGLE が 'enable' に設定された場合、LICENSE は、プロダクトのライセンス
% が存在する場合は1を、プロダクトのライセンスが存在しない場合は0を出力
% します。
% TOGGLE が 'disable' に設定された場合、LICENSE は、この feature のテスト
% に対して常に0(ライセンスが存在しない)を出力します。
%   
% 注意: 特定のプロダクトに対するテストを有効にしないということは、LICENSE 
% コマンドを用いて実行されたテストだけでなく、ライセンスの存在に対して
% 他のすべてのテストに影響します。


%   Copyright (c) 1984-2002 The MathWorks, Inc.
