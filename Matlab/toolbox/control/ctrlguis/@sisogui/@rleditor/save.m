function SavedData = save(Editor)
%SAVE   Creates backup of Root Locus Editor settings.
%
%   See also SISOTOOL.

%   Author(s): P. Gahinet
%   Copyright 1986-2002 The MathWorks, Inc. 
%   $Revision: 1.9 $  $Date: 2002/04/10 04:57:56 $

Axes = Editor.Axes;
PlotAxes = getaxes(Axes);
SavedData = struct(...
    'Constraints',saveconstr(Editor),...
    'Grid',Axes.Grid,...
    'Title',Axes.Title,...
    'TitleStyle',struct(Axes.TitleStyle),...
    'Visible',Editor.Visible,...
    'Xlabel',{Axes.Xlabel},...
    'XlabelStyle',struct(Axes.XlabelStyle),...
    'Xlim',{get(PlotAxes,'Xlim')},...
    'XlimMode',{Axes.XlimMode},...
    'Ylabel',{Axes.Ylabel},...
    'YlabelStyle',struct(Axes.YlabelStyle),...
    'Ylim',{get(PlotAxes,'Ylim')},...
    'YlimMode',{Axes.YlimMode},...
    'LimitStack',Editor.Axes.LimitStack,...
    'AxisEqual',Editor.AxisEqual,...
    'GridOptions',Editor.GridOptions);