function margindemo
%MARGINDEMO  Stability margin demo.

%   Author(s): P. Gahinet
%   Copyright 1986-2004 The MathWorks, Inc.
%   $Revision: 1.8.4.2 $  $Date: 2004/04/10 23:13:47 $

% Data structure
sys = tf([.2  .3  1],[1 .2  1 0]);
Gain = 1e-1;
ds = struct(...
	'System',sys,...
	'System_ss',ss(sys),...
	'BodeMag',[],...
	'BodePhase',[],...
	'Step',[],...
	'Controls',[]);
	
% Main figure
Prefs = cstprefs.tbxprefs;
fig = figure(...
    'Units','character', ...
    'Visible','off',...
    'DoubleBuffer','on', ...
    'IntegerHandle','off',...
    'Name',xlate('Gain and Phase Margins Demo'), ...
    'NumberTitle','off', ...
    'DefaultUIControlFontSize',Prefs.UIFontSize,...
    'DefaultAxesFontSize',Prefs.AxesFontSize,...
    'DefaultTextFontSize',Prefs.AxesFontSize,...
    'DockControls', 'off');

figgray = get(fig,'Color');

% Frame 
hBorder = 0.01;
vBorder = 0.01;
axf = axes('Parent',fig,...
	'Units','norm',...
	'Position',[.74 0.08 .25 0.83],...
	'Color',[.7 .7 .7],...
	'Box','on',...
	'Xlim',[0 1],'Ylim',[0 1],...
	'Xcolor',[0 0 0],...
	'Ycolor',[0 0 0],...
	'XTick',[], ...
	'YTick',[]);
ax = axes('Parent',fig,...
	'Units','norm',...
	'Position',[.75 .62 .23 .2],...
	'Color',[.7 .7 .75],'XColor',[.5 .5 .75],'YColor',[.5 .5 .75],...
	'Box','on','XTick',[],'YTick',[]);
DrawLoop(ax);

% Buttons
uicontrol('style','pushbutton',...
    'parent',fig,...
    'units','norm',...
    'position',[1-2*(.12+hBorder) vBorder .12 .06],...
    'callback','margindemo_sls',...
    'string','Details');
uicontrol('style','pushbutton',...
    'parent',fig,...
    'units','norm',...
    'position',[1-(.12+hBorder) vBorder .12 .06],...
    'string','Close',...
    'callback','close(gcbf)');

% Bode mag axis
pw = 0.275;
px = 0.09;
MagPos = [px 0.53 pw 0.38];
hmag = axes('parent',fig,...
    'position',MagPos,...
    'xscale','log',...
    'box','on',...
    'DrawMode','fast', ...
    'XColor',Prefs.AxesForegroundColor,...
    'YColor',Prefs.AxesForegroundColor,...
    'Xtick',[.1 1 10], ...
    'XtickLabel',[], ...
    'xlim',[0.1 10],...
    'ylim',[-60 60]);
set(get(hmag,'Title'),'String','Open Loop G\cdotK',...
    'FontSize',Prefs.TitleFontSize);
set(get(hmag,'Ylabel'),'String','Magnitude (dB)',...
    'FontSize',Prefs.TitleFontSize,'Color',[0 0 0]);
line([0.1 10],[0 0],'Color',Prefs.AxesForegroundColor,...
    'LineStyle',':','Parent',hmag);
    
% Bode phase axis
PhasePos = [px 0.11 pw 0.38];
hphase = axes('parent',fig,...
    'position',PhasePos,...
    'xscale','log',...
    'box','on',...
    'DrawMode','fast', ...
    'XColor',Prefs.AxesForegroundColor,...
    'YColor',Prefs.AxesForegroundColor,...
    'Xtick',[.1 1 10], ...
    'Ytick',[-225,-180,-135,-90,-45],...
    'xlim',[0.1 10],...
    'ylim',[-225 -45]);
set(get(hphase,'Xlabel'),'String','Frequency (rad/sec)',...
    'FontSize',Prefs.TitleFontSize,'Color',[0 0 0]);
set(get(hphase,'Ylabel'),'String','Phase (deg)',...
    'FontSize',Prefs.TitleFontSize,'Color',[0 0 0]);
line([0.1 10],[-180 -180],'Color',Prefs.AxesForegroundColor,...
    'LineStyle',':','Parent',hphase);

% Closed loop step
StepPos = [px+pw+0.08 0.53 pw 0.38];
hstep = axes('parent',fig,...
    'position',StepPos,...
    'box','on',...
    'DrawMode','fast', ...
    'XColor',Prefs.AxesForegroundColor,...
    'YColor',Prefs.AxesForegroundColor,...
    'xlim',[0 20],...
    'ylim',[0 1.5]);
set(get(hstep,'Title'),'String','Closed-Loop Step Response',...
    'FontSize',Prefs.TitleFontSize);
set(get(hstep,'Xlabel'),'String','Time (sec)',...
    'FontSize',Prefs.TitleFontSize,'Color',[0 0 0]);
set(get(hstep,'Ylabel'),'String','Amplitude',...
    'FontSize',Prefs.TitleFontSize,'Color',[0 0 0]);
line(get(hstep,'xlim'),[1 1],'Color',Prefs.AxesForegroundColor,...
    'LineStyle',':','Parent',hstep);

% Text
dy = 0.08;
x0 = pw+0.16;
y0 = 0.13;
ds.Controls.GM = uicontrol('style','text',...
    'parent',fig,...
    'units','norm',...
    'string','Gain Margin:',...
    'horiz','left',...
    'backgroundcolor',figgray,...
    'position',[x0 y0+2*dy .3 .05]);
ds.Controls.PM = uicontrol('style','text',...
    'parent',fig,...
    'units','norm',...
    'string','Phase Margin:',...
    'horiz','left',...
    'backgroundcolor',figgray,...
    'position',[x0 y0+dy .3 .05]);
ds.Controls.Stable = uicontrol('style','text',...
    'parent',fig,...
    'units','norm',...
    'string','Closed-loop Stable?',...
    'horiz','left',...
    'backgroundcolor',figgray,...
    'position',[x0 y0 .3 .05]);

% Gain slider
BDF = {@LocalSlider 'init'};
BUF = {@LocalSlider 'finish'};
BMF = {@LocalSlider 'update'};
rtslider('Position',[0.765 y0+.08 .97-.765 .05],'Range',[.05 100],'Scale','log',...
    'FontSize',8+isunix,'Parent',fig,'Value',Gain,'ButtonDownFcn',BDF,'Callback',BMF,'ButtonUpFcn',BUF);
text('Parent',axf,'String','Loop Gain K:',...
    'Units','norm','Position',[0.04 0.25],...
    'FontSize',10,'FontWeight','normal',...
    'Hor','left','Ver','bottom');

% Mag plot
ds.BodeMag.Plot = line(NaN,NaN,...
	'parent',hmag,...
    'linewidth',2,...
	'color',[0 0.7 0]);
ds.BodeMag.Dot = line(NaN,NaN,...
	'parent',hmag,...
	'MarkerEdgeColor',[1 0 1],...
	'MarkerFaceColor',[1 0 1], ...
	'Marker','o','MarkerSize',6);
ds.BodeMag.vLine = line(NaN,NaN,...
	'parent',hmag,...
	'color',[1 0 1]);

% Phase plot
ds.BodePhase.Plot = line(NaN,NaN,...
	'parent',hphase,...
    'linewidth',2,...
	'color',[0 0.7 0]);
ds.BodePhase.Dot = line(NaN,NaN,...
	'parent',hphase,...
	'MarkerEdgeColor',[1 0 1],...
	'MarkerFaceColor',[1 0 1], ...
	'Marker','o','MarkerSize',6);
ds.BodePhase.vLine = line(NaN,NaN,...
	'parent',hphase,...
	'color',[1 0 1]);

% Step plot
ds.Step.Plot = line(NaN,NaN,...
	'parent',hstep,...
    'linewidth',2,...
	'color','r');

% Initialize plots
[m,p,w] = bode(ds.System,{1e-3 1e3});
t = 0:.01:20;
set([ds.BodeMag.Plot,ds.BodePhase.Plot],'Xdata',w);
set(ds.Step.Plot,'Xdata',t);
set(ds.BodePhase.Plot,'Ydata',p(:))
LocalUpdate(ds,Gain);

% Make figure visible
set(fig,'Visible','on','UserData',ds,'HandleVisibility','callback');


%--------------------- Local functions ------------------------------


function LocalSlider(hSrc,Value,event)
% Manages the slider dynamic update

persistent gain
ds = get(gcbf,'UserData');

switch event
case 'init'
    set([ds.BodeMag.Plot,ds.BodeMag.Dot,ds.BodeMag.vLine,...
        ds.BodePhase.Dot,ds.BodePhase.vLine,...
        ds.Step.Plot],'erasemode','xor');
case 'update'
    gain = Value;
    LocalUpdate(ds,gain)
case 'finish'
    set([ds.BodeMag.Plot,ds.BodeMag.Dot,ds.BodeMag.vLine,...
        ds.BodePhase.Dot,ds.BodePhase.vLine,...
        ds.Step.Plot],'erasemode','normal');
	LocalUpdate(ds,gain)
end

%%%%%%%%%%%%

function LocalUpdate(ds,Gain)
% Dynamic plot update

% Reponse data
w = get(ds.BodeMag.Plot,'Xdata');
t = get(ds.Step.Plot,'Xdata');
[mag,phase] = bode(ds.System*Gain,w);
mag = mag(:); phase = phase(:);
y = step(feedback(ds.System_ss*Gain,1),t);

% Update plots
set(ds.BodeMag.Plot,'Ydata',20*log10(mag))
set(ds.Step.Plot,'Ydata',y)

% Update margin display
[Gm,Pm,Wcg,Wcp] = imargin(mag,phase,w);
Gm = 20*log10(Gm);
% Determine the phase line associated with the phase margin (-180 modulo 360)
if isfinite(Pm) & (Wcp>=w(1) & Wcp<=w(end))
   Yp = 180 * round((interp1(w,phase,Wcp)-Pm)/180);
else
   Yp = NaN;
end

set(ds.BodeMag.Dot,'Xdata',Wcg,'Ydata',-Gm)
set(ds.BodeMag.vLine,'Xdata',[Wcg Wcg],'Ydata',[-Gm 0])   % vertical line
set(ds.BodePhase.Dot,'Xdata',Wcp,'Ydata',Yp+Pm)
set(ds.BodePhase.vLine,'Xdata',[Wcp Wcp],'Ydata',[Yp Yp+Pm])

% Update text
set(ds.Controls.GM,'String',sprintf('Gain Margin:  %.2g dB',Gm))
set(ds.Controls.PM,'String',sprintf('Phase Margin:  %.2g deg',Pm))
if Gain>.2764 & Gain<12.075
	set(ds.Controls.Stable,'String','Closed-loop Stable?  No')
else
	set(ds.Controls.Stable,'String','Closed-loop Stable?  Yes')
end


function DrawLoop(ax)
% Draws feedback loop with plant data
gray = [0.7 .7 .7];
set(ax,'xlim',[0 19],'ylim',[0 12])
y0 = 8;  x0 = 4;
wire('x',x0+[-3 -1],'y',y0+[0 0],'parent',ax,'arrow',0.7);
sumblock('position',[x0-0.5 y0],'label',{'-240'},'radius',.5,...
    'LabelRadius',1.5,'facecolor',gray,'fontsize',12);
wire('x',x0+[0 2],'y',y0+[0 0],'parent',ax,'arrow',0.7);
sysblock('position',[x0+2 y0-1.5 3 3],'name','K',...
    'fontweight','bold','facecolor',[.8 1 1],'fontsize',10);
wire('x',x0+[5 7],'y',y0+[0 0],'parent',ax,'arrow',0.7);
sysblock('position',[x0+7 y0-1.5 3 3],'name','G',...
    'fontweight','bold','facecolor',[1 1 .9],'fontsize',10);
wire('x',x0+[10 14],'y',y0+[0 0],'parent',ax,'arrow',0.7);
wire('x',x0+[12 12 -0.5 -0.5],'y',y0+[0 -6 -6 -0.5],'parent',ax,'arrow',0.7);
text('Parent',ax,'String','Feedback Loop:',...
    'Units','norm','Position',[0 1.05],...
    'FontSize',10,'FontWeight','normal',...
    'Hor','left','Ver','bottom');
equation('Parent',ax,'Name','G(s)',...
    'Num','0.2 s^2 + 0.3 s + 1','Den','s^3 + 0.2 s^2 + s',...
    'Anchor','center','Position',[9.5 -4.5],'FontSize',8+isunix);
