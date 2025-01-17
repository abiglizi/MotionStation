function initialize(this,Axes)
%INITIALIZE  Initialization for @BodeStabilityMarginView class

%  Author(s): John Glass
%  Copyright 1986-2004 The MathWorks, Inc.
%  $Revision: 1.1.6.2 $  $Date: 2004/04/11 00:18:43 $
if ~isequal(size(Axes),[1 1 2])
   % Leave all properties empty for MIMO responses
   % RE: Can happen in Viewer with SISO and MIMO models
   return
end
Color = this.AxesGrid.AxesStyle.YColor;

%% Gain Margin Characteristics
this.MagPoints = handle(line(NaN,NaN,5,...
    'Parent',Axes(1),...
    'Visible','off',...
    'Marker','o',...
    'XLimInclude','off',...
    'YLimInclude','off',...
    'MarkerSize',6));

this.MagLines = handle(line([NaN,NaN],[NaN,NaN],[-10,-10],...
    'Parent',Axes(1),...
    'Visible','off',...
    'LineStyle','-',...
    'Selected','off',...
    'HandleVisibility','off',...
    'XLimInclude','off',...
    'YLimInclude','off',...
    'HitTest','off',...
    'Color',Color));

this.MagCrossLines = handle(line([NaN,NaN],[NaN,NaN],[-10,-10],...
    'Parent',Axes(1),...
    'Visible','off',...
    'LineStyle','-.',...
    'Selected','off',...
    'HandleVisibility','off',...
    'XLimInclude','off',...
    'YLimInclude','off',...
    'HitTest','off',...
    'Color',Color));

this.MagTips = handle(NaN);

%% Phase Margin Characteristics
this.PhasePoints = handle(line(NaN,NaN,5,...
    'Parent',Axes(2),...
    'Visible','off',...
    'Marker','o',...
    'XLimInclude','off',...
    'YLimInclude','off',...
    'MarkerSize',6));

this.PhaseLines = handle(line([NaN,NaN],[NaN,NaN],[-10,-10],...
    'Parent',Axes(2),...
    'Visible','off',...
    'LineStyle','-',...
    'Selected','off',...
    'HandleVisibility','off',...
    'XLimInclude','off',...
    'YLimInclude','off',...
    'HitTest','off',...
    'Color',Color));

this.PhaseCrossLines = handle(line([NaN,NaN],[NaN,NaN],[-10,-10],...
    'Parent',Axes(2),...
    'Visible','off',...
    'LineStyle','-.',...
    'Selected','off',...
    'HandleVisibility','off',...
    'XLimInclude','off',...
    'YLimInclude','off',...
    'HitTest','off',...
    'Color',Color));

this.PhaseTips = handle(NaN);



