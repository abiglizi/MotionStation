function prefspanel
%PREFSPANEL Registers a Filter Design Toolbox preferences control panel.
%   PREFSPANEL registers a Preferences Control panel with the MATLAB IDE.

%   Author: P. Costa
%   Copyright 1998-2003 The MathWorks, Inc.
%   $Revision: 1.2.2.4 $  $Date: 2003/08/29 04:41:00 $


% Register Object-based context menus items in the Workspace Browser.

%   Methods of MatlabObjectMenuRegistry are unsupported.  Calls to these
%   methods will become errors in future releases.

% Define ANALOGINPUT Context menu
com.mathworks.mlwidgets.workspace.MatlabCustomClassRegistry.registerClassCallbacks(...
    {'analoginput'},...
    'Explore',...
    {'Display Summary', ...
	'Call Property Editor',...
	'-',...
	'Display Hardware Info', ...
   	'Show DAQ Events', ...
	'-', ...
	'DAQ Help'},...
    {'disp($1)', ...
	'daqpropedit($1);', ...
	'',...
	'daqhwinfo($1); disp(ans)',...
 	'showdaqevents($1)', ...
	'-',...
	'daqhelp($1)'});

% Define ANALOGOUTPUT Context menu - same as analoginputs
com.mathworks.mlwidgets.workspace.MatlabCustomClassRegistry.registerSimilarClassCallbacks(...
    {'analogoutput'}, 'analoginput');

% Define DIGITALIO Context menu
com.mathworks.mlwidgets.workspace.MatlabCustomClassRegistry.registerClassCallbacks(...
    {'digitalio'},...
    'Explore',...
    {'Display Summary', ...
	'Call Property Editor',...
	'-',...
	'Display Hardware Info', ...
	'-', ...
	'DAQ Help'},...
    {'disp($1)', ...
	'daqpropedit($1);', ...
	'',...
	'daqhwinfo($1); disp(ans)',...
	'-',...
	'daqhelp($1)'});

% Define DAQDEVICE Context menu
com.mathworks.mlwidgets.workspace.MatlabCustomClassRegistry.registerClassCallbacks(...
    {'daqdevice'},...
    'Explore',...
    {'Display Summary', ...
	'Call Property Editor',...
	'-',...
	'DAQ Help'},...
    {'display($1)', ...
	'daqpropedit;', ...
	'',...
	'daqhelp($1)'});

% Define AICHANNEL Context menu
com.mathworks.mlwidgets.workspace.MatlabCustomClassRegistry.registerClassCallbacks(...
    {'aichannel'},...
    'Explore',...
    {'Display Summary', ...
	'Call Property Editor',...
	'-', ...
	'DAQ Help'},...
    {'disp($1)', ...
	'if (length($1)>1), daqpropedit; else, daqpropedit($1); end;', ...
	'',...
	'daqhelp($1)'});

% Define AOCHANNEL and DIOLINE Context menus - same as aichannel
com.mathworks.mlwidgets.workspace.MatlabCustomClassRegistry.registerSimilarClassCallbacks(...
    {'aochannel', 'dioline'}, 'aichannel');

% [EOF]
