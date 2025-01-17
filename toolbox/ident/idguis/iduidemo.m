function iduidemo(arg)
%IDUIDEMO Runs the ident demo.
%   ARG is the number of the frame to be shown.

%   L. Ljung 4-4-94
%   Copyright 1986-2004 The MathWorks, Inc.
%   $Revision: 1.14.2.2 $ $Date: 2004/04/10 23:19:34 $

set(0,'showhiddenhandles','on')
Xsum = findobj(get(0,'children'),'flat','tag','sitb16');
set(0,'showhiddenhandles','off')
number = 1;
if isempty(Xsum)
   number = -1;
   ident;
   set(0,'showhiddenhandles','on') 
   Xsum = findobj(get(0,'children'),'flat','tag','sitb16');
   set(0,'showhiddenhandles','off') 
end

XID = get(Xsum,'Userdata');

if arg==0
   figname=idlaytab('figname',31);
   if ~figflag(figname)
      layout
      butwh=[mStdButtonWidth mStdButtonHeight];
      butw=butwh(1);buth=butwh(2);
      ftb=mFrameToText/2;  % Frame to button
      bb = 4; % between buttons
      etf = mEdgeToFrame;
      EdWH=[4*butw 11*mLineHeight+2*bb];
      FigW = EdWH(1)+2*(etf+ftb);
      fig=figure('Units','Points','NumberTitle','off','Name',figname,'color',...
         get(0,'defaultUIcontrolbackgroundcolor'),'tag','sitb31',...
         'HandleVisibility','callback','Resize','on',...
         'Integerhandle','off','MenuBar','none',...
         'DockControls','off',...
         'vis','off','Defaulttextfontsize',10);
      pos = iduilay1(FigW,3);
      uicontrol(fig,'Units','Points','pos',pos(1,:),'style','frame')%...
      %,'backgroundcolor',  [0.5,0.5,0.5]);
      XID.demo(2)=uicontrol(fig,'Units','Points','pos',pos(2,:),'style','push',...
         'string','Next >>','callback','iduidemo(1);','userdata',1);
      XID.demo(3)=uicontrol(fig,'Units','Points','pos',pos(3,:),'style','push',...
         'string','Prev <<','callback','iduidemo(2);','userdata',1,...
         'enable','off');
      XID.demo(4)=uicontrol(fig,'Units','Points','pos',pos(4,:),'style','push',...
         'string','Close','callback','close(gcf)');
      lev2=pos(1,2)+pos(1,4);
      uicontrol(fig,'Units','Points','pos',[etf lev2+etf [EdWH+[2*ftb 2*bb]]],...
         'style','frame','backgroundcolor',[0.5,0.5,0.5]);
      XID.demo(1)=uicontrol(fig,'Units','Points','pos',[etf+ftb lev2+etf+bb EdWH],...
         'style','text','Backgroundcolor',[1 1 1],'Foregroundcolor',[0,0,0],...
         'max',20,'Horizontalalignment','left','Fontsize',10);
      %           'edit','max',2,'fontsize',13,'Horizontalalignment','left');
      FigWH=[FigW lev2+2*etf+EdWH(2)+2*bb];
      ScreenPos = get(0,'ScreenSize');
      FigPos = [(ScreenPos(3)-FigWH(1)) FigWH(2)/4 FigWH];
      set(fig,'pos',FigPos);
      set(fig,'Units','Pixels');
      new_figpos = get(fig,'pos');
      FigPos = [(ScreenPos(3)-new_figpos(3)) new_figpos(4)/4 new_figpos(3:4)];
      set(fig,'pos',FigPos);
      set(get(fig,'children'),'units','norm')
      try
         if length(XID.layout)>30,
            if XID.layout(31,3)
               eval('set(fig,''pos'',XID.layout(31,1:4))','')
            end,
         end
      catch
      end
      figure(fig)
   
        set(fig,'vis','on')
      drawnow
   end
   arg=1;
   %if isempty(iduiwok(16)),number=-1;else number=1;end
else
   number=get(XID.demo(1+arg),'userdata');
end

if number==-1
   
   text=str2mat('  The Graphical User Interface for the System Identification',...
      '   Toolbox (ident) is now being created. It is normally invoked',...
      '   by typing ident in the MATLAB command window.',...
      '');%,...
      %'   Be patient, it may take a while to finish.');
   set(XID.demo(1),'string',text)
   set(XID.demo(2),'userdata',1);
   set(XID.demo(3),'userdata',1,'enable','off');drawnow
   ident
elseif number==1
   set(XID.demo(3),'enable','off');
   text=str2mat(...
      '  To follow the demo, please select menu items and click on buttons',...
      '  as prompted. You are of course free to explore other options during',...
      '  the demo, but the text assumes that you carry out all instructions.',...
      '',...
      '  Note that you can resize this figure (and most other ident figures)', ...
      '  if necessary.  Try to resize now if you wish.', ...
      '',...
      '  1) First type load dryer2 at the MATLAB command',...
      '     line.  This loads the data variables u2 and y2 into the workspace.', ...
      '     This data is from an actual hairdryer.  The input (u2) is the heating',...
      '     power and the output (y2) is the temperature of the outflow air.');
   
   set(XID.demo(2),'userdata',2);   set(XID.demo(3),'userdata',1);
elseif number==2
   set(XID.demo(3),'enable','on');
   text=str2mat(...
      '  2) In the ident window, press the popup menu Data and select',...
      '     Import. This will open a dialog box.', ...
      '',...
      '  3) Go to the dialog box and enter u2 into the editable text box beside',...
      '     Input: and y2 into the editable text box beside Output:.',...
      '',...
      '  4) Enter a Sampling interval: of 0.08.',...
      '',...
      '  5) Enter any variable name you wish in the box marked',...
      '     Data name:. For example: dry.');
   set(XID.demo(2),'userdata',3);   set(XID.demo(3),'userdata',1);
elseif number==3
   text=str2mat(...
      '  6) By pressing the button ''More'', you get access',...
      '     to more book-keeping options. You may, e.g., enter',...
      '     any text you wish in the box marked Notes.',...
      '     For example, %This is my first attempt at using ident.',...
      '',...
      '  7) Now press the Import button and the data will be represented', ...
      '     as an icon in the ident figure.  To close the Import Data dialog,', ...
      '     press the dialog''s Close button.');
   text=str2mat(text,...
      '',...
      '     Notice that the data also fills the Working Data and the',...
      '     Validation Data icons. More about that later.') ;
   set(XID.demo(2),'userdata',4);   set(XID.demo(3),'userdata',2);
   
elseif number==4
   
   text=str2mat(...
      '   8) Click on the Time Plot checkbox beneath Data Views to open',...
      '      a plot figure.',...
      '   9) Examine the plot.  The plot figure has a number of options accessible', ...
      '      via the menu bar which you may wish to explore now.',...
      '  10) Note for example that Zoom under the Style menu is active.',...
      '      You can draw rectangles in the plot with the left mousebutton down.',...
      '      When you release the button, the area within the rectangle expands');
   text=str2mat(text,...
      '      to fill the axes. Double-click to return to the original plot limits.',...
      '      Click the left/right (alt-click) mouse button to zoom in/out.  Type',...
      '      help zoom at the MATLAB command line for more information.');
   set(XID.demo(2),'userdata',5);   set(XID.demo(3),'userdata',3);
elseif number==5
   text=str2mat(...
      ' 11) To remove the constant levels in the data sequences, return to', ...
      '     the ident window and select Remove means from the Preprocess', ...
      '     popup menu. Notice that a new data set will be inserted into the', ...
      '     Data board.',...
      '',...
      ' 12) The new data set has also automatically been plotted in the',...
      '     Time plot figure. You may have to choose Autorange under the',...
      '     Options menu to see the new plots. To unplot a data set, just',...
      '     click on its icon to deselect it. We shall work further with',...
      '     this new data set (with a ''d'' appended to its name), so drag',...
      '     and drop it onto the Working Data icon',...
      '     at the center of the ident figure.');
   set(XID.demo(2),'userdata',6);   set(XID.demo(3),'userdata',4);
elseif number==6
   text=str2mat(...
      ' 13) Now double-click on a data set icon. (On slower machines, use the',...
      '     right mousebutton if you have a three/two button mouse. With one',...
      '     button use the usual alt selection key sequence e.g. ctrl-click.)',...
      '     A new dialog box will open containing information about the data.',...
      '',...
      '      At this point the name of the data can be changed. The color of',...
      '      its icon can also be changed. Try this, or just close the',...
      '      dialog by pressing its Close button.');
   set(XID.demo(2),'userdata',7);   set(XID.demo(3),'userdata',5);
elseif number==7
   text=str2mat(...
      '  14) Now select the Select range... option from the Preprocess', ...
      '     popup menu in the ident figure. A new figure will open.',...
      '',...
      '  15) You can use the editable text fields to select a subset of the data.', ...
      '      Or, draw a rectangle (with the mouse button down) to select a portion',...
      '      of the data to be used for estimation purposes. For example, choose',...
      '      the interval from 1 to 50 seconds.  Note that if you make a mistake,',...
      '      you can erase the rectangle and restart by pressing the Revert button.',...
      '',...
      '  16) Press Insert in the dialog box, and the selected data range',...
      '      is added as a new data set to the Data  board.');
   set(XID.demo(2),'userdata',8);   set(XID.demo(3),'userdata',6);
elseif number==8
   text=str2mat(...
      '   17) Repeat once more to select a portion of the data set to be',...
      '       used for validation purposes. For example, select the interval',...
      '       from 50 seconds to the end. Insert this data set. Close the',...
      '       dialog by pressing its Close button.',...
      ' ',...
      '       Make sure that you now have the two data sets dryde and drydv',...
      '       on the data board.');
   set(XID.demo(2),'userdata',9);   set(XID.demo(3),'userdata',7);
elseif number==9
   text=str2mat(...
      '  18) In the Data board of the ident figure, select a data set to',...
      '      work with for estimation by dragging it to the Working Data',...
      '      icon. The data set to be used for validation purposes should be',...
      '      dragged and dropped onto the Validation Data icon.',...
      '',...
      '  19) Use the third set (dryde) for estimation purposes and the fourth',...
      '      data set (drydv) for validation purposes. Drag them to the icons',...
      '      as described in step 18.');
   set(XID.demo(2),'userdata',10);   set(XID.demo(3),'userdata',8);
elseif number==10
   text=str2mat(...
      '  20) To estimate the step response (or impulse response) of the',...
      '      system, select Correlation model... from the Estimate popup menu',...
      '      in the ident figure. Note this adds a model to the Model board.',...
      '      Close the dialog.',...
      '',...
      '  21) To view the result, click on the Transient Response',...
      '      checkbox beneath Model Views in the ident figure.',...
      '',...
      '  22) Examine the various menu items in the plot that appears.');
   set(XID.demo(2),'userdata',11);   set(XID.demo(3),'userdata',9);
elseif number==11
   text=str2mat(...
      '  23) To estimate the frequency response of the system, select',...
      '      Spectral model... from the Estimate popup menu in the', ...
      '      ident figure.  Press Estimate in the dialog box that opens.',...
      '      Note that this adds a model to the Model board. Close the dialog.',...
      '  24)  To view the result, click on the Frequency Response ',...
      '       checkbox beneath Model Views in the ident figure.',...
      '',...
      '  25)  Examine the various menu items in the plot that appears. Apart',...
      '       from Style and Options, these are the same as in the other plots.');
   set(XID.demo(2),'userdata',12);   set(XID.demo(3),'userdata',10);
elseif number==12
   text=str2mat(...
      '  26) Now, let us compute parametric models. Select Parametric models...', ...
      '      from the Estimate popup menu.', ...
      '',...
      '      A new dialog will open. The idea is to enter model structure',...
      '      information into the Parametric Models dialog and then generate a', ...
      '      model by pressing the Estimate button.',...
      '',...
      '      To help you with the model structures, the Order Editor',...
      '      provides more information on the different types of supported structures.');
   set(XID.demo(2),'userdata',13);   set(XID.demo(3),'userdata',11);
elseif number==13
   text=str2mat(...
      ' 27) As a default, a fourth order ARX type difference equation model has',...
      '     been selected. Press Estimate, and the model will be computed',...
      '     and inserted into the Model board as an icon. Note that the',...
      '     corresponding curves will be added in the open Model Views.',...
      ' 28) Open the Order Editor by pressing the button Order Editor',...
      '     in the Parametric Models dialog.',...
      '     Select the orders na=2, nb=2,  and nk=3, by using the',...
      '     popup menus in the model structure editor dialog. This indicates',...
      '     a second order model with a deadtime of 3 samples (i.e. 0.24 sec).');
   text=str2mat(text,...
      ' 29) Press Estimate to compute another model.');
   set(XID.demo(2),'userdata',14);   set(XID.demo(3),'userdata',12);
elseif number==14
   text=str2mat(...
      ' 30) Let us now look at the transient response. It contains',...
      '     three curves. These are color coded along with',...
      '     the corresponding model icons in the Model board.',...
      '',...
      ' 31) Clicking on the model icons in the ident figure the associated',...
      '     curves are added or removed from the open views.',...
      '',...
      ' 32) Using the middle mouse button (alt selection or ctrl-click),',...
      '     you can click on a line in a Model View and the corresponding',...
      '     Model name will be displayed.'); 
   set(XID.demo(2),'userdata',15);   set(XID.demo(3),'userdata',13);
elseif number==15
   text=str2mat(...
      ' 33) Choose menu item Show 99% confidence intervals under the main menu',...
      '     Options in the Transient Response plot.',...
      '     Curves corresponding to confidence intervals will now be',...
      '     added to the plot. Picking the same menu item again disables',...
      '     the confidence curves.');
   set(XID.demo(2),'userdata',16);   set(XID.demo(3),'userdata',14);
elseif number==16
   text=str2mat(...
      ' 34) There are several other views by which the models can be evaluated',...
      '     These are listed under Model Views. It is better',...
      '     to open and close the view figures by clicking on the checkboxes,',...
      '     rather than to iconify the figures.',...
      '',...
      ' 35) Pick the Model Output view. This shows a comparison between',...
      '     the models'' simulated outputs and the measured output, when applied',...
      '     to the validation data set. The (color coded) numbers at the side of',...
      '     the plot show how much (in %) of the output variation was reproduces',...
      '     by the model.'); 
   set(XID.demo(2),'userdata',17);   set(XID.demo(3),'userdata',15);
elseif number==17
   set(XID.demo(2),'enable','on');
   text=str2mat(...
      ' 36) The parametric model dialog allows a wide range of different',...
      '     model structures. Use the popup menu in the Parametric Models dialog',...
      '     to select State Space: (n). Here it is sufficient to',...
      '     select the order n of the state-space model, and then press Estimate.',...
      '',...
      ' 37) If you don''t know what a good order is, you can enter a range of',...
      '     orders, e.g. 1:10. Then pressing Estimate opens a dialog',...
      '     within which different orders can be estimated by just clicking',...
      '     accordingly along the x-axis and then inserting the chosen models.');
   set(XID.demo(2),'userdata',18);   set(XID.demo(3),'userdata',16);
elseif number==18
   text=str2mat(...
      '   This is the last page of the demo.',...
      '',...
      '   There are many other features to be explored. As you need to use more',...
      '   of the functionality, simply open the appropriate dialog box and press', ...
      '   the help button for more information.  Good luck!');
   set(XID.demo(2),'userdata',19,'enable','off');
   set(XID.demo(3),'userdata',17);
elseif number==19
   close(gcf)
end
if number<19,set(XID.demo(1),'string',text);end
set(Xsum,'UserData',XID);
