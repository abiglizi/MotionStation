function sfinit( command )
%SFINIT  Initializes Stateflow module.
%  This is the callback function executed upon the initialization
%  of SF (MEX file). It is also used to load and save defaults.

%
%	E. Mehran Mestchian
%   Copyright 1995-2004 The MathWorks, Inc.
%  $Revision: 1.121.4.17 $  $Date: 2004/04/15 01:00:06 $



if nargin==0
    %%% this is the first thing we do
    sf('lock');
    sfinit('load defaults');
    
    sf('new', 'machine', '.name', '$$Clipboard$$');
	
	% HG based toolbars are resource intensive on Win9x boxes.
	% Saturate the maximum number of Stateflow editors that can
	% be up at once.
	if sf('RunningWin95'),
            sf('MaxNumberOfOpenEditors', 7); 
            sf('SingleChartCacheMode', 1);
        	
        %
        % ONLY use Musical Toolbar when running in R12 or
        % later to avoid a bug in R11 with maximaized windows.
        %	
        if (sf('MatlabVersion') >= 600), 
	  sf('MusicalToolbar', 1); 	% Forces 1 toolbar for all Stateflow Editors.
        else,
          sf('MusicalToolbar', 0);	  
        end;	    
	else,
		sf('MaxNumberOfOpenEditors', 1000);
        sf('SingleChartCacheMode', 0);
        sf('MusicalToolbar', 0);
	end;
    
    return;
end

switch command
case 'factory',
    relax_flags;
    factory_default('factory');
    override;
    restore_flags;
case {'load defaults','load_defaults'},
    relax_flags;
    factory_default('default');
    defaultsFile = fullfile(prefdir,'sfdefaults');
    if(~exist(defaultsFile,'file'))
        defaultsFile = sf('Root','defaults');
    end
    sf('loaddefaults',defaultsFile);
    override;    
    restore_flags;
case {'save_defaults','save defaults'},
    save_defaults;
    restore_flags;
end


function relax_flags
sf('flag'...
    ,'machine:all','write'...
    ,'chart:all','write'...
    ,'state:all','write'...
    ,'junction:all','write'...
    ,'transition:all','write'...
    ,'note:all','write'...
    ,'event:all','write'...
    ,'data:all','write'...
    ,'target:all','write'...
    ,'linkchart:all','write'...
    ,'instance:all','write'...
    ,'style:all','write'...
    );

function restore_flags
sf('flag'...
    ,'machine:all','nosave/hide/readonly'...
    ,'machine','save/show'...
    ,'machine.id','save/show'...
    ,'machine.name','abssave/show/write'...
    ,'machine.document','save/show/write'...
    ,'machine.requirementInfo','save/show/write'...
    ,'machine.rgTag','show/write'...
    ,'machine.tag','save/show/write'...
    ,'machine.description','save/show/write'...
    ,'machine.created','save/show'...
    ,'machine.creator','save/show/write'...
    ,'machine.modified', 'save/show/write'...
    ,'machine.version', 'save/show/write'...
    ,'machine.fullFileName', 'show'...
    ,'machine.simulinkModel','show'...
    ,'machine.searchTool','show/write'...
    ,'machine.symbolWizard','show/write'...
    ,'machine.dirty','write'...
    ,'machine.firstData','save/show'...
    ,'machine.firstEvent','save/show'...
    ,'machine.firstTarget','save/show'...
    ,'machine.checksum:all','show/write'...
    ,'machine.makefileChecksum:all','show/write'...
    ,'machine.debug','save/show/write'...
    ,'machine.debug.gui:all','save/show/write'...
    ,'machine.hideSymbolWizardAlert','show/write'...
    ,'machine.debug.breakOn:all','save/show/write'...
    ,'machine.debug.runTimeCheck:all','save/show/write'...
    ,'machine.debug.animation:all','save/show/write'...
    ,'machine.debug.disableAllBreakpoints','save/show/write'...
    ,'machine.iced','show/write'...
    ,'machine.deleted','show/write'...
    ,'machine.dialog','write'...
    ,'machine.isLibrary','abssave/show/write'...
    ,'machine.sfVersion','abssave/show'...
    ,'machine.sfLinks','show/write'...
    ,'machine.locked','show/save/write'...
    ,'machine.defaultActionLanguage','save/show/write'...
    ,'machine.activeTarget','show/write'...
    ,'machine.activeParentTarget','write'...
    ,'machine.rtwInfo:all','show/write'...
    ,'machine.codeOptimizer:all','show/write'...
    ,'machine.time:all','nosave/show/write'...
    ,'machine.exportedFcnInfo','nosave/show/write'...
    ,'machine.exportedFcnChecksum','nosave/show/write'...
    ,'machine.sfDemoChecksum:all','save'...
    );

sf('flag'...
    ,'chart:all','nosave/hide/readonly'...
    ,'chart','save/show'...
    ,'chart.id','save/show'...
    ,'chart.name','abssave/show/write'...
    ,'chart.document','save/show/write'...
    ,'chart.requirementInfo','save/show/write'...
    ,'chart.rgTag','show/write'...
    ,'chart.tag','save/show/write'...
    ,'chart.description','save/show/write'...
    ,'chart.windowPosition:all','save3/write'...
    ,'chart.stateFontS.fontName','save/show/write'... 
    ,'chart.stateFontS.fontWeight','save/show/write'... 
    ,'chart.stateFontS.fontAngle','save/show/write'... 
    ,'chart.stateFontS.defaultFontSize','save3/show/write'... 
    ,'chart.transitionFontS.fontName','save/show/write'... 
    ,'chart.transitionFontS.fontWeight','save/show/write'... 
    ,'chart.transitionFontS.fontAngle','save/show/write'... 
    ,'chart.transitionFontS.defaultFontSize','save3/show/write'... 
    ,'chart.viewLimits:all','save3/show/write'...
    ,'chart.zoomFactor','save3/show/write'...
    ,'chart.subviewS.zoomFactor', 'save3/show' ...
    ,'chart.subviewS.x1', 'save3/show' ...
    ,'chart.subviewS.y1', 'save3/show' ...
    ,'chart.stateColor:all','save/show/write'...
    ,'chart.stateLabelColor:all','save/show/write'...
    ,'chart.transitionColor:all','save/show/write'...
    ,'chart.transitionLabelColor:all','save/show/write'...
    ,'chart.junctionColor:all','save/show/write'...
    ,'chart.selectionColor:all','save/show/write'...
    ,'chart.highlightColor:all','save/show/write'...
    ,'chart.highlightHistoryOn','save/show/write'...
    ,'chart.errorColor:all','save/show/write'...
    ,'chart.chartColor:all','save/show/write'...
    ,'chart.colorsChanging','write'...
    ,'chart.fontsChanging','write'...
    ,'chart.screen:all','abssave/show/write'...
    ,'chart.treeNode:all','save'...
    ,'chart.firstTransition','save/show'...
    ,'chart.firstJunction','save/show'...
    ,'chart.firstEvent','save/show'...
    ,'chart.firstData','save/show'...
    ,'chart.decomposition','abssave/show/write'...
    ,'chart.machine','save/show'...
    ,'chart.visible','save/show/write'...
    ,'chart.updateMethod','save/show/write'...
    ,'chart.sampleTime','save/show/write'...
    ,'chart.checksum:all','show/write'...
    ,'chart.dirty','write'...
    ,'chart.dialog','write'...
    ,'chart.debug:all','save/show/write'...
    ,'chart.activeInstance','show/write'...
    ,'chart.fullPathOfActiveInstance','show/write'...      
    ,'chart.number','show/write'...
    ,'chart.iced','show/write'...
    ,'chart.locked','save/show/write'...
    ,'chart.chartFileNumber','save/show'...
    ,'chart.rtwInfo:all','show/write'...
    ,'chart.disableImplicitCasting','save/show/write'...
    ,'chart.simulationMode','show/write'...
    ,'chart.toolbarVisible','save/show/write'...
    ,'chart.toolbarMode','save/show/write'...
    ,'chart.executeAtInitialization','save/show/write'...
    ,'chart.unique:all','show/write'...
    ,'chart.exportChartFunctions','save/show/write'...
    ,'chart.noCodegenForCustomTargets','save/show/write'...
    ,'chart.actionLanguage','save/show/write'...
    ,'chart.unresolved:all','show/write'...
    ,'chart.viewObj', 'save/show' ...
    ,'chart.showQuantumTransitions', 'write' ...
    ,'chart.type','save/show/write'...
    ,'chart.eml.name','save/show/write'...
    ,'chart.encryption.enabled','save/show'...
    ,'chart.encryption.password','save/show'...
    ,'chart.altStyle','write'...
    );

sf('flag'...
    ,'state:all','nosave/hide/readonly'...
    ,'state','save/show'...
    ,'state.id','save/show'...
    ,'state.name','nosave/show/write'...
    ,'state.document','save/show/write'...
    ,'state.requirementInfo','save/show/write'...
    ,'state.rgTag','show/write'...
    ,'state.tag','save/show/write'...
    ,'state.description','save/show/write'...
    ,'state.labelString','abssave/show/write'...
    ,'state.position:all','save4/show/write'...
    ,'state.fontSize','save3/show/write'...
    ,'state.chart','save/show'...
    ,'state.treeNode:all','save'...
    ,'state.superState:all','save'...
    ,'state.firstTransition','save/show'...
    ,'state.firstJunction','save/show'...
    ,'state.visible','save'...
    ,'state.isGrouped','save'...
    ,'state.subgrouped','save/show'...
    ,'state.type','abssave/show/write'...
    ,'state.isNoteBox','save'...
    ,'state.noteBox:all','save/show/write'...
    ,'state.decomposition','abssave/show/write'...
    ,'state.arrowSize','save3/show/write'...
    ,'state.isVisited','write'...
    ,'state.entryAction','write'...
    ,'state.activityAction','write'...
    ,'state.exitAction','write'...
    ,'state.dialog','write'...
    ,'state.altStyle','write'...
    ,'state.firstData','save/show'...
    ,'state.firstEvent','save/show'...
    ,'state.checksum:all','show/write'...
    ,'state.debug:all','save/show/write'...
    ,'state.isTestPoint','save/show/write'...
    ,'state.number','show/write'...
    ,'state.translation','save/show/write'...
    ,'state.coverageInfo:all','show/write'...
    ,'state.outputData','save/show'...
    ,'state.subviewS.zoomFactor', 'save3/show'...
    ,'state.subviewS.pos:all', 'save3/show'...
    ,'state.subviewS.x1', 'save3/show' ...
    ,'state.subviewS.y1', 'save3/show' ...
    ,'state.subviewS.fontSize', 'save3/show'...
    ,'state.subviewer', 'save/show'...
    ,'state.entryEventEnumeration', 'write'...
    ,'state.exitEventEnumeration', 'write'...
    ,'state.entryEventEnumString', 'write'...
    ,'state.exitEventEnumString', 'write'...
    ,'state.activeChildEnumString', 'write'...
    ,'state.functionInlineOption','save/show/write'...
    ,'state.unique:all','write'...
    ,'state.eml.isEML','save/show/write'...
    ,'state.eml.script','save/show/write'...
    ,'state.eml.editorLayout','save/show/write'...
    ,'state.eml.breakpoints','save/show/write'...
    ,'state.eml.inferBkpts','save/show/write'...
    ,'state.truthTable.isTruthTable','save/show/write'...
    ,'state.truthTable.predicateArray','save/show/write'...
    ,'state.truthTable.actionArray','save/show/write'...
    ,'state.truthTable.checksum:all','save/show/write'...
    ,'state.truthTable.diagnostic.underSpecification','save/show/write'...
    ,'state.truthTable.diagnostic.overSpecification','save/show/write'...
    ,'state.truthTable.editorLayout','save/show/write'...
    ,'state.truthTable.hPredicateArray','show/write'...
    ,'state.autogen.isAutoCreated','save/show/write'...
    ,'state.autogen.source','save/show/write'...
    ,'state.autogen.mapping','save/show/write'...
    );

sf('flag'...
    ,'junction:all','nosave/hide/readonly'...
    ,'junction','save/show'...
    ,'junction.id','save/show'...
    ,'junction.document','save/show/write'...
    ,'junction.labelString','save/show/write'...      
    ,'junction.rgTag','show/write'...
    ,'junction.tag','save/show/write'...
    ,'junction.description','save/show/write'...
    ,'junction.position:all','save4/show/write'...
    ,'junction.visible','save'...
    ,'junction.isGrouped','save'...
    ,'junction.chart','save/show'...
    ,'junction.linkNode:all','save'...
    ,'junction.type','abssave/show/write'...
    ,'junction.arrowSize','save3/show/write'...
    ,'junction.isVisited','write'...
    ,'junction.inAdefaultPath','write'...
    ,'junction.dialog','write'...
    ,'junction.checksum:all','show/write'...
    ,'junction.number','show/write'...
    ,'junction.subviewer', 'save/show'...
    ,'junction.quantum:all', 'save/show'...
    ,'junction.autogen.isAutoCreated','save/show/write'...
    ,'junction.autogen.source','save/show/write'...
    ,'junction.autogen.mapping','save/show/write'...
    );

sf('flag'...
    ,'transition:all','nosave/hide/readonly'...
    ,'transition','save/show'...
    ,'transition.id','save/show'...
    ,'transition.document','save/show/write'...
    ,'transition.requirementInfo','save/show/write'...
    ,'transition.rgTag','show/write'...
    ,'transition.tag','save/show/write'...
    ,'transition.dataLimits:all','save3/show/write'...
    ,'transition.description','save/show/write'...
    ,'transition.labelString','save/show/write'...
    ,'transition.labelPosition:all','save3/show/write'...
    ,'transition.fontSize','save3/show/write'...
    ,'transition.arrowSize','save3/show/write'...
    ,'transition.src.id','save/show'...
    ,'transition.src.intersection:all','save4/write'...
    ,'transition.dst.id','save/show'...
    ,'transition.dst.intersection:all','save4/write'...
    ,'transition.midPoint:all','save4/write'...
    ,'transition.linkNode:all','save'...
    ,'transition.visible','save'...
    ,'transition.isGrouped','save'...
    ,'transition.chart','save/show'...
    ,'transition.isVisited','write'...
    ,'transition.inAdefaultPath','write'...
    ,'transition.coverageInfo:all','show/write'...
    ,'transition.trigger','write'...
    ,'transition.altStyle','write'...
    ,'transition.guard','write'...
    ,'transition.conditionAction','write'...
    ,'transition.transitionAction','write'...
    ,'transition.conditionString','write'...
    ,'transition.entryActionsNeeded','write'...
    ,'transition.exitActionsNeeded','write'...      
    ,'transition.dialog','write'...
    ,'transition.checksum:all','show/write'...
    ,'transition.debug:all','save/show/write'...
    ,'transition.number','show/write'...
    ,'transition.translation','save/show/write'...
    ,'transition.type','save/show'...
    ,'transition.firstSubWire','save/show'...
    ,'transition.subLink:all','save/show'...
    ,'transition.subviewer', 'save'...
	,'transition.drawStyle', 'save/show/write'...
    ,'transition.stampAngle','save4/show'...
    ,'transition.slide.mode','save/show'...
    ,'transition.slide.arcL', 'save4/show'...
    ,'transition.slide.arcClockDir', 'save/show'...
    ,'transition.slide.sticky','save/show'...
    ,'transition.slide.midPointSticky', 'save/show'...
    ,'transition.autogen.isAutoCreated','save/show/write'...
    ,'transition.autogen.source','save/show/write'...
    ,'transition.autogen.mapping','save/show/write'...
    );

sf('flag'...
    ,'note:all','save/show/write'...
    );

sf('flag'...
    ,'event:all','nosave/hide/readonly'...
    ,'event','save/show'...
    ,'event.id','save/show'...
    ,'event.name','abssave/show/write'...
    ,'event.document','save/show/write'...
    ,'event.rgTag','show/write'...
    ,'event.tag','save/show/write'...
    ,'event.description','save/show/write'...
    ,'event.machine','save/show'...
    ,'event.scope','abssave/show/write'...
    ,'event.trigger','abssave/show/write'...
    ,'event.firstData','save/show'...
    ,'event.linkNode:all','save/show'...
    ,'event.dialog','write'...
    ,'event.checksum:all','show/write'...
    ,'event.debug:all','save/show/write'...
    ,'event.number','show/write'...
    ,'event.functionCallIndex','show/write'...
    ,'event.eventEnumeration', 'write'...
    ,'event.eventEnumString', 'write'...
    );



   
sf('flag'...
    ,'data:all','nosave/hide/readonly'...
    ,'data','save/show'...
    ,'data.id','save/show'...
    ,'data.name','abssave/show/write'...
    ,'data.document','save/show/write'...
    ,'data.rgTag','show/write'...
    ,'data.tag','save/show/write'...
    ,'data.description','save/show/write'...
    ,'data.scope','abssave/show/write'...
    ,'data.dataType','abssave/show/write'...
    ,'data.fixpt.bias','abssave/show/write'...
    ,'data.fixpt.slope','abssave/show/write'...
    ,'data.fixpt.exponent','abssave/show/write'...
    ,'data.fixpt.baseType','abssave/show/write'...
    ,'data.fixpt.lock','abssave/show/write'...
    ,'data.isComplex','save/show/write'...
    ,'data.dlgFixptMode','abssave/show/write'...
    ,'data.units','save/show/write'...
    ,'data.props.initialValue','save/show/write'...
    ,'data.props.range.minimum','save/show/write'...
    ,'data.props.range.maximum','save/show/write'...
    ,'data.props.array.size','save/show/write'...
    ,'data.props.array.firstIndex','save/show/write'...
    ,'data.props.initialValue','save/show/write'...
    ,'data.machine','save/show'...
    ,'data.linkNode:all','save/show'...
    ,'data.dialog','write'...
    ,'data.checksum:all','show/write'...
    ,'data.number','show/write'...
    ,'data.parsedInfo:all','show/write'...
    ,'data.debug:all','save/show/write'...
    ,'data.isTestPoint','save/show/write'...
    ,'data.outputState','save/show'...
    ,'data.initFromWorkspace','save/show/write'...
    ,'data.paramIndexForInitFromWorkspace','save/show/write'...
    ,'data.saveToWorkspace','save/show/write'...
    ,'data.unique:all','show/write'...
    ,'data.changeEventEnumeration', 'write'...
    ,'data.changeEventEnumString', 'write'...
    ,'data.autogen.isAutoCreated','save/show/write'...
    ,'data.autogen.source','save/show/write'...
    ,'data.autogen.mapping','save/show/write'...
    );

sf('flag'...
    ,'target:all','nosave/hide/readonly'...
    ,'target','save/show'...
    ,'target.id','save/show'...
    ,'target.name','save/show/write'...
    ,'target.description','save/show/write'...
    ,'target.document','save/show/write'...
    ,'target.rgTag','show/write'...
    ,'target.tag','save/show/write'...
    ,'target.showLog','show/write'...
    ,'target.deleteLog','show/write'...
    ,'target.logfile','show/write'...
    ,'target.reservedNames','save/show/write'...
    ,'target.customInitializer','save/show/write'...
    ,'target.customTerminator','save/show/write'...
    ,'target.customCode','save/show/write'...
    ,'target.userSources','save/show/write'...
    ,'target.userIncludeDirs','save/show/write'...
    ,'target.userLibraries','save/show/write'...
    ,'target.userMakefiles','save/show/write'...
    ,'target.codeFlags','save/show/write'...
    ,'target.compilerFlags','save/show/write'...
    ,'target.makeCommand','save/show/write'...
    ,'target.targetFunction','save/show/write'...
    ,'target.mexFileName','save/show/write'...
    ,'target.codegenDirectory','save/show/write'...
    ,'target.machine','save/show'...
    ,'target.linkNode:all','save/show'...
    ,'target.checksumOld:all','save/show/write'...
    ,'target.checksumNew:all','show/write'...
    ,'target.checksumSelf:all','show/write'...
    ,'target.transTable','save/show/write'...
    ,'target.dialog','show/write'...
    ,'target.applyToAllLibs','save/show/write'...
    ,'target.time:all','nosave/show/write'...
    ,'target.makeInfo','nosave/show/write'...
    );

sf('flag'...
    ,'instance:all','nosave/hide/readonly'...
    ,'instance','save/show'...
    ,'instance.id','save/show'...
    ,'instance.name','save/show/write'...
    ,'instance.machine','save/show'...
    ,'instance.chart','save/show'...
    ,'instance.saveFlag','show/write'...
    ,'instance.rgTag','show/write'...
    ,'instance.tag','save/show/write'...
    );
sf('flag'...
    ,'instance:all','nosave/hide/readonly'...
    ,'instance','save/show'...
    ,'instance.id','save/show'...
    ,'instance.name','save/show/write'...
    ,'instance.machine','save/show'...
    ,'instance.chart','save/show'...
    ,'instance.saveFlag','show/write'...
    ,'instance.rgTag','show/write'...
    ,'instance.tag','save/show/write'...
    );
sf('flag'...
    ,'portal:all','nosave');

sf('flag'...
    ,'linkchart:all','nosave');

sf('flag'...
    ,'wormhole:all','nosave'...
    ,'wormhole.adjustedEscapeVelocity','save/write');

function factory_default( reference )
% MACHINE FACTORY DEFAULTS
sf('set','default'...
    ,'machine.creator','Unknown'...
    ,'machine.version','none'...
    ,'machine.debug.runTimeCheck',[1 1 1 1]...
    );

fontName = get(0,[reference,'TextFontName']);
fontWeight = get(0,[reference,'TextFontWeight']);
fontAngle = get(0,[reference,'TextFontAngle']);
fontSize = get(0,[reference,'TextFontSize'])+2;

% CHART FACTORY DEFAULTS
sf('set','default'...
    ,'chart.name','Chart'...
    ,'chart.stateFontS.fontName',fontName...
    ,'chart.stateFontS.fontWeight',fontWeight...
    ,'chart.stateFontS.fontAngle',fontAngle...
    ,'chart.stateFontS.defaultFontSize',fontSize...
    ,'chart.transitionFontS.fontName',fontName...
    ,'chart.transitionFontS.fontWeight',fontWeight...
    ,'chart.transitionFontS.fontAngle',fontAngle...
    ,'chart.transitionFontS.defaultFontSize',fontSize...
    ,'chart.stateColor',[0 1 1]...
    ,'chart.stateLabelColor',[1 1 1]...
    ,'chart.transitionColor',[1 1 0]...
    ,'chart.transitionLabelColor',[1 1 0]...
    ,'chart.lowlightColor',[0.75 0.75 0.75]...
    ,'chart.junctionColor',[1 0 1]...
    ,'chart.selectionColor',[0 1 0]...
    ,'chart.errorColor',[1 0 0]...
    ,'chart.highlightColor',[1 0 0]...
    ,'chart.toolbarVisible',1 ...
    ,'chart.chartColor',[0 0 0]...
    ,'chart.showQuantumTransitions', 1 ...
    );

% STATE FACTORY DEFAULTS
sf('set','default'...
    ,'state.fontSize',fontSize ... 
	,'state.arrowSize',fontSize ...
);

% JUNCTIONS FACTORY DEFAULTS
sf('set','default'...
    ,'junction.arrowSize',fontSize ...
);

% TRANSITION FACTORY DEFAULTS
sf('set','default'...
    ,'transition.fontSize',fontSize ...
,'transition.arrowSize',fontSize ...
);

% TARGET FACTORY DEFAULTS
sf('set','default'...
    ,'target.name','untitled'...
    ,'target.customCode',''...
    ,'target.userSources',''...
    ,'target.userIncludeDirs',''...
    ,'target.userLibraries',''...
    ,'target.userMakefiles',''...
    ,'target.codeFlags',''...
    ,'target.compilerFlags',''...
    ,'target.makeCommand',''...
    ,'target.targetFunction',''...
    );

function override

% MACHINE OVERRIDE DEFAULTS

defaultPos = get(0,'defaultfigureposition');

% CHART OVERRIDE DEFAULTS
sf('set','default'...
    ,'chart.windowPosition',defaultPos...
    ,'chart.zoomFactor',1.0 ...
    ,'chart.subviewS.zoomFactor', 1.0 ...
    );

% STATE OVERRIDE DEFAULTS
sf('set','default'...
    ,'state.labelString','?'...
    ,'state.position',[0 0 60 40]...
    ,'state.lineStyle','-'...
    ,'state.visible',1 ...
    ,'state.isGrouped',0 ...
    ,'state.subviewS.zoomFactor', sf('get','default','chart.zoomFactor')...
    ,'state.subviewS.fontSize', sf('get','default','chart.stateFontS.defaultFontSize')...
    ,'state.subviewS.pos', [0 0 60 40] ...
    ,'state.subviewS.zoomFactor', 1.0 ...
    );

% JUNCTIONS FACTORY DEFAULTS
sf('set','default'...
    ,'junction.position',[10,10,10]...
    ,'junction.visible',1 ...
    ,'junction.isGrouped',0 ...
    );

% TRANSITION FACTORY DEFAULTS
sf('set','default'...
    ,'transition.labelString','?'...
    ,'transition.lineStyle','-'...
    ,'transition.visible',1 ...
    ,'transition.isGrouped',0 ...
    );

% DATA FACTORY DEFAULTS
sf('set','default'...
    ,'data.props.range.maximum','inf'...
    ,'data.props.range.minimum','-inf'...
    ,'data.props.initialValue','0' ...
    ,'data.props.array.size','' ...
    ,'data.props.array.firstIndex','0' ...
    );



function save_defaults

% CHART SAVE DEFAULTS FLAGS
sf('flag','chart:all','nosave'...
    ,'chart','save'...
    ,'chart.name','save'...
    ,'chart.stateFontS.fontName','save'...
    ,'chart.stateFontS.fontWeight','save'...
    ,'chart.stateFontS.fontAngle','save'...
    ,'chart.stateFontS.defaultFontSize','save'...
    ,'chart.transitionFontS.fontName','save'...
    ,'chart.transitionFontS.fontWeight','save'...
    ,'chart.transitionFontS.fontAngle','save'...
    ,'chart.transitionFontS.defaultFontSize','save'...
    ,'chart.stateColor:all','save'...
    ,'chart.stateLabelColor:all','save'...
    ,'chart.transitionColor:all','save'...
    ,'chart.transitionLabelColor:all','save'...
    ,'chart.junctionColor:all','save'...
    ,'chart.selectionColor:all','save'...
    ,'chart.errorColor:all','save'...
    ,'chart.highlightColor:all','save'...
    ,'chart.chartColor:all','save'...
    );

% STATE SAVE DEFAULTS FLAGS
sf('flag','state:all','nosave'...
    ,'state','save'...
    ,'state.fontSize','save3'...
    ,'state.arrowSize','save3'...
    );

% JUNCTION SAVE DEFAULTS FLAGS
sf('flag','junction:all','nosave' ...
    ,'junction','save' ...
    ,'junction.arrowSize','save3' ...
    );

% TRANSITION SAVE DEFAULTS FLAGS
sf('flag','transition:all','nosave'...
    ,'transition','save'...
    ,'transition.fontSize','save3'...
    ,'transition.arrowSize','save3'...
    );

% EVENT SAVE DEFAULTS FLAGS
sf('flag','event:all','nosave'...
    ,'event','save'...
    ,'event.name','save'...
    );

% DATA SAVE DEFAULTS FLAGS
sf('flag','data:all','nosave'...
    ,'data','save'...
    ,'data.name','save'...
    );

% MACHINE SAVE DEFAULTS FLAGS
sf('flag','machine:all','nosave'...
    ,'machine','save'...
    ,'machine.creator','save'...
    ,'machine.version', 'save'...
    ,'machine.debug.animation.enabled','save'...
    ,'machine.debug.gui.view:all','save'...
    ,'machine.hideSymbolWizardAlert','save'...
    ,'machine.debug.runTimeCheck:all','save'...
    ,'machine.sfVersion','save'...
    );

% TARGET SAVE DEFAULTS FLAGS
sf('flag','target:all','nosave'...
    ,'target','save'...
    ,'target.name','show/save'...
    ,'target.customCode','show/save/write'...
    ,'target.userSources','save/show/write'...
    ,'target.userIncludeDirs','save/show/write'...
    ,'target.reservedNames','save/show/write'...
    ,'target.userLibraries','save/show/write'...
    ,'target.userMakefiles','save/show/write'...
    ,'target.codeFlags','show/save/write'...
    ,'target.compilerFlags','show/save/write'...
    ,'target.targetFunction','show/save/write'...
    );

% INSTANCE SAVE DEFAULTS FLAGS
sf('flag','instance:all','nosave');

% NOTE SAVE DEFAULTS FLAGS
sf('flag','note:all','nosave');

% LINKCHART SAVE DEFAULTS FLAGS
sf('flag','linkchart:all','nosave'...
    ,'linkchart','save'...
    ,'linkchart.name','show/save/write'...
    ,'linkchart.handle','show/write'...
    );

% Save defaults absolutely! And without changing the dictionary name.
defaultsFile = fullfile(prefdir(1),'sfdefaults');
tmpDefaultsFile = [defaultsFile,'.err'];
try,
    sf('save',tmpDefaultsFile,'w',sf('get','default','.id'),'',1);
    status = copyfile(tmpDefaultsFile,defaultsFile,'writable');
    if status==1,
        sf_delete_file(tmpDefaultsFile);
    else
        error('failed to copy the new defaults file.');
    end
catch,
    disp(lasterr);
    disp(sprintf('Error saving Stateflow defaults in %s.\nPrevious default file is restored',defaultsFile));
end
