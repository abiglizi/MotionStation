function printdmfile(handle,filename,options)
%PRINTDMFILE creates an M-Mat file pair out of a figure
%   PRINTDMFILE(HANDLE,FILENAME) creates an M-Mat file pair
%   named FILENAME from the handle graphics object HANDLE
%
%   PRINTDMFILE(FIGFILENAME,MFILENAME)

%   PRINTDMFILE(...,OPTIONSSTRUCT)
%   a structure with fields containing options
%   options are:
%     addHeaderComment      - (1 or 0), whether to include default
%                           comment at top of file. Default is 1
%     appendToFile          - (1 or 0), If file already exist, append
%                           or overwrite. Default is 0 to overwrite.
%     absorbGUIDEOptions    - (1 or 0), If figure is generated by GUIDE,
%                           write its options in MAT (0) or M (1) file.
%                           Default is 0.
%     excludedPropertyList  - (cell array), property list that will not
%                           be generated in the output m file for given
%                           type.
%     renameCallbacks       - (1 or 0), whether to update callbacks of
%                           figure and its children to use FILENAME. 
%                           Default is 0.
%     functionPrefix        - (string), contents need to be written in the
%                           m file before the m code for the figure. 
%     functionSuffix        - (string), contents need to be written in the
%                           m file after the m code for the figure. 
%     limitForMatFile       - int. Controls whether a numeric value is in m 
%                           file ot in MAT file.
%     showMessageforMATFile - (1 or 0), whether to show a message if the
%                           resulting m file needs some generated MAT files.

%   Copyright 1984-2004 The MathWorks, Inc.
%   $Revision: 1.12.4.6 $  $Date: 2004/04/10 23:28:59 $ 


% Check for valid number of inputs
error(nargchk(2,3,nargin))
if nargin==2
    options = [];
end

try
    % Try to read fig file (if it is one)
    hS = Local_IsFigFile(handle);

    [M_filename,Mat_filename] = Local_GenFilenames(filename);

    if isempty(hS)
       % Check for valid handle
       Local_CheckInputs(handle);

       % Create handle structure for handle
       hS = Local_CreateHandleStructure(handle);
    end

    % make adjustment to the options struct
    options = Local_AdjustOptions(hS, handle, filename, options);
catch
    error(lasterr)
end


% In this revision we'll just write out regular objects wihout acconting for
% any annotation layer stuff


% Create a struct to store necessary data
[graphicsStructure] = Local_CreateGraphicsStructure;


% Check for object type and proceed with generating
% code for the entire graphics structure
% gS is a structure defined in Local_createGraphicsStructure
gS = Local_GenerateCode(graphicsStructure,hS,0, options);

% If there is contextmenu(s), need to generate code to attach the
% contextmenu to the right objects. 
gS = Local_AttachContextmenu(gS, options);    

% Save the Mat data
savedMat = 0;
mat = gS.matdata;


% The data values are saved to an associated MAT-file
if ~isempty(mat)
   save(Mat_filename,'mat');
   savedMat = 1;

   if isfield(options, 'showMessageForMATFile') & options.showMessageForMATFile ==1 
       message = sprintf('MAT file %s is generated for \n M-file %s. \n Please keep them together to run the M-file.', Mat_filename, M_filename); 
       warning(message); 
   end 
end


% Write the code to the file specified
Local_WriteFile(gS.code,M_filename,Mat_filename,savedMat,options);


% ---------- Begin Local_IsFigFile            ---------- %
function out = Local_IsFigFile(name)
if isstr(name)
  try
    out = load('-mat',name);
    varNames = fieldnames(out);
    index = strmatch('hgS', varNames);
    if length(index) == 1
      out = out.(varNames{1});
    else
      out = [];
    end
  catch
    out = [];
  end
else
  out = [];
end


% ---------- Begin Local_CheckInputs            ---------- %
function Local_CheckInputs(handle);
% Local_CheckInputs checks for if a valid handle was provided


% Confirm that 'handle' is a valid handle
if ~ishandle(handle)
    error('First argument must be a valid handle')
end


% Check if 'handle' refers to a figure
if ~strcmp(get(handle,'type'),'figure')
    error('First argument must be a valid figure handle')
end
% ---------- End Local_CheckInputs              ---------- %


% ---------- Begin Local_GenFilenames            ---------- %
function [M_filename,Mat_filename] = Local_GenFilenames(filename);
% Get the path of the filename specifed
[path, file, ext] = fileparts(filename);


% Construct the M and MAT filenames
M_filename = fullfile(path, [file '.m']);
Mat_filename = fullfile(path, [file '.mat']);


% ---------- End Local_GenFilenames            ---------- %





% ---------- Begin Local_CreateHandleStructure  ---------- %
function [hS] = Local_CreateHandleStructure(handle)
% Local_CreateHandleStructure creates and returns a handle structure


hS = handle2struct(handle);
% ---------- End Local_CreateHandleStructure    ---------- %


% ---------- Begin Local_AdjustOptions  ---------- %
function options = Local_AdjustOptions(hStruct,handle, filename, choices);

options = choices;
hS =hStruct;

if length(hS) == 1 & ishandle(hS.handle)
    options.sourceFile = get(hS.handle, 'FileName');
else
    options.sourceFile = handle;
end
options.destinationFile = filename;    
% ---------- End Local_AdjustOptions    ---------- %


% ---------- Begin Local_CreateGraphicsStructure ---------- %
function gS = Local_CreateGraphicsStructure
% LOCAL_CREATEGRAPHICSSTRUCTURE creates a structure to hold all the necessary data


gS.oldhandlelist = [];
gS.newhandlelist = [];
gS.matdata = [];
gS.contextmenu = [];
gS.objnumber = 1;
gS.varnumber = 1;
gS.code = [];



% ---------- End Local_CreateGraphicsStructure ---------- %




% ---------- Begin Local_GenerateCode          ---------- %
function gS = Local_GenerateCode(gS,hS,Parent, options);
% Local_GenerateCode creates the commands necessary to replicate the figure

% Since the object number is incremented after the object is created the objects
% number is actually one less than the current value
Parent = gS.objnumber - 1;

for i = 1:length(hS);
    % First check to see if this object is of a supported type
    isSupported = Local_CheckSupportedType(hS(i).type);

    if ~isSupported
        continue
    end

    % Create the object
    gS = Local_CreateObject(gS,hS(i),hS(i).type,Parent, options);

    % Check for Axes objects and make put in necessary hooks to
    % get labels and title hooked up
    if strcmp(hS(i).type,'axes') & ~isempty(hS(i).children)
        gS = Local_CreateAxesChildren(gS,hS(i), Parent, options);

    elseif ~isempty(hS(i).children);
        gS = Local_GenerateCode(gS,hS(i).children,Parent, options);
    end
end

% ---------- End Local_GenerateCode              ---------- %



% ---------- Begin Local_CheckSupportedType ---------- %
function SUP = Local_CheckSupportedType(Type)


% Assume that the object type is supported
SUP = 1;


if strncmpi('graph',Type,5)
    if isempty(gcbo)
        disp([Type,' objects are not supported...'])
        disp('Skipping...')
    else
        warndlg({[Type ,' objects are not supported...'],'Skipping'});
    end
    SUP = 0;
end


% ---------- Begin Local_CheckSupportedType ---------- %



% ---------- Begin Local_AttachContextmenu       ---------- %
function gS = Local_AttachContextmenu(gS,options)

CodeStr = {};

if ~isempty(gS.contextmenu)
    hname = 'handles';
    for i=1:length(gS.contextmenu)
        menudata = gS.contextmenu{i};
        if ~isempty(menudata.special)
            indice = find(ismember(gS.oldhandlelist,menudata.special));
            if ~isempty(indice)
               str = ' ';
               for k=1:length(indice)
                   str = [str, 'h', num2str(indice(k)),' '];
               end
               CodeStr{length(CodeStr)+1} = sprintf('\n%s = [%s];',hname,str);
               CodeStr{length(CodeStr)+1} = sprintf('set(%s, ''uicontextmenu'', h%i);',hname,menudata.objnumber);
            end
        end
    end
end

if ~isempty(CodeStr)
    gS.code{length(gS.code)+1} = CodeStr;
end

% ---------- End Local_AttachContextmenu         ---------- %


% ---------- Begin Local_CreateObject       ---------- %
function gS = Local_CreateObject(gS,hS,Type,Parent, options)

% Assuming that the object type name is the same as the
% constructor method...

isuicm = 0;

% Place holder for code
CodeStr = {};


VarNumber = gS.varnumber;


ObjNumber = gS.objnumber;

% If 'renameCallbacks' and 'exludedPropertyList' are not fields in the
% options, hS.properties is returned.
Props = Local_ReturnObjectProperties(hS, options);

% If there is AppData or CreateFcn is set, calling our local_CreateFcn
% so that AppData is set first and code in CreateFcn can access it.
if ~isempty(fieldnames(Props.ApplicationData))
    createfcn = '';
    if isfield(Props, 'CreateFcn')
        createfcn = Props.CreateFcn;
    end
    Props.CreateFcn = createfcn;
end

% whether we have a real corresponding object at the same time. This is the
% case that we are calling printdmfile with a handle instead of a FIG
% file name
ObjectExist = 0;
if ishandle(hS.handle)
    ObjectExist = 1;
end

% write code for populating AppData
thisappdata = Props.ApplicationData;
if ~isempty(fieldnames(thisappdata))
    realappdata=[];
    if ObjectExist
        try 
           realappdata = getappdata(hS.handle);
        catch
        end
    end
    [CodeStr,VarNumber,gS] = Local_SetAppData(CodeStr,thisappdata,realappdata,VarNumber,ObjNumber,gS, options);
end

% If the TYPE hasn't already been specified then use the one the handle
% structure provides
if ~exist('Type','var') | isempty(Type)
    Type = hS.type;
end
% title and labels have special constructors and need to be treated separately
if any(strcmp(Type,{'title','xlabel','ylabel','zlabel'}))
   % Constructor requires an enpty string input argument
    CodeStr{length(CodeStr)+1} = sprintf('\nh%i = get(h%i,''%s'');\n',ObjNumber,Parent,Type);
    CodeStr{length(CodeStr)+1} = sprintf('set(h%i,...',ObjNumber);
else
    CodeStr{length(CodeStr)+1} = sprintf('\nh%i = %s(...',ObjNumber,Local_Type2CreationCommand(Type));
end
  
if ~strcmp(Type, 'figure')
   CodeStr{length(CodeStr)+1} = sprintf('''Parent'',h%i,...',Parent);
end

% jet is first because it is the default
knownColormaps = {'jet', 'hsv', 'hot', 'gray', 'bone', 'copper', 'pink', 'white', 'flag', 'lines', 'colorcube',  'prism', 'cool', 'autumn', 'spring', 'winter', 'summer'};

% Get a list of property names
Names = fieldnames(Props);
Callbacks = guidemfile('getCallbackProperties', hS);
appdataOK = 0;
for i = 1:length(Names)
    % For the moment all the properties go to variables
    PropName = Names{i};
    value = Props.(PropName);
    realValue = [];
    if ObjectExist && isempty(find(ismember(Callbacks,PropName)))
        try 
           realValue = get(hS.handle, PropName);
        catch
        end
    end
    
    % special case for defaults - if the property is the default value
    % use a get statement instead of a literal
    defaultName = ['default', Type, PropName];
    defaultValue = [];
    try, defaultValue = get(0,defaultName); end
    if ~isempty(defaultValue) & isequal(defaultValue, value)
       CodeStr{length(CodeStr)+1} = sprintf('''%s'',get(0,''%s''),...',PropName, defaultName);
       continue;
    end

    % Application Data is set in local_CreateFcn
    if strcmp(PropName,'ApplicationData')
       continue;
    end

    usemat = 0; 
    % search to see whether there is a matching colormap
    if isnumeric(value) & strcmp(Type, 'figure') & strcmp(PropName, 'Colormap') 
       % special case for colormap on figures - it is likely one of the defaults, try each and 
       % store code for that instead of the actual values 
       found = 0; 
       for j = 1:length(knownColormaps) 
           if isequal(value, feval(knownColormaps{j}, length(value))) 
               % this is our colormap 
               CodeStr{length(CodeStr) +1} = ... 
                   sprintf('''%s'',%s(%d),...',PropName,knownColormaps{j},length(value)); 
               found = 1; 
               break; 
           end 
       end 
       if (found) 
           % no need to do the next bit 
           continue;
       end 
    end 

    if isnumeric(value) & length(value) > Local_LimitForGenerateMat(options); 
       usemat =1; 
    else 
       try 
           if strcmpi(PropName,'CreateFcn')
               appdata='''''';
               if ~isempty(fieldnames(Props.ApplicationData))
                   appdata=Local_GetAppDataName;
               end
               CodeStr{length(CodeStr)+1} = sprintf('''%s'', {@local_CreateFcn, %s, %s} ,...',PropName, Local_Data2MCode(value, realValue), appdata); 
               appdataOK=1;
           else
               CodeStr{length(CodeStr)+1} = sprintf('''%s'',%s,...',PropName,Local_Data2MCode(value, realValue));                
           end
       catch 
           usemat = 1; 
       end 
    end 

    if (usemat) 
       CodeStr{length(CodeStr)+1} = sprintf('''%s'',mat{%i},...',PropName,VarNumber); 
       gS.matdata{VarNumber} = value; 
       VarNumber = VarNumber + 1; 
    end            
end

% Since there are no more items to set we take out the ,... and replace with ')
CodeStr{length(CodeStr)} = strrep(CodeStr{length(CodeStr)},',...',');');

% if application data is not empty and could not set by local_CreateFcn
% set it directly
if ~isempty(fieldnames(Props.ApplicationData))&& ~appdataOK
    CodeStr{length(CodeStr)+1} = sprintf('\nlocal_CreateFcn(h%i, [], '''', %s);',ObjNumber, Local_GetAppDataName); 
end

gS.oldhandlelist = [gS.oldhandlelist hS.handle];

% store contextmenu info
if strcmpi('uicontextmenu',Type)
    gS.contextmenu{length(gS.contextmenu)+1} = struct('objnumber',ObjNumber,'special',hS.special);
end

% Set the updated variable number
gS.varnumber = VarNumber;
gS.code{length(gS.code)+1} = CodeStr;
gS.objnumber = gS.objnumber+ 1;



% ---------- End Local_CreateObject         ---------- %


% ---------- Begin Local_CreateAxesChildren ---------- %
function gS = Local_CreateAxesChildren(gS,hS,Parent, options)


Parent = gS.objnumber-1;


Spec = hS.special;
Objects = {'title','xlabel','ylabel','zlabel'};


% Parent = gS.objnumber - 1;


for i = 1:length(Spec)
    if Spec(i) ~= 0;
        gS = Local_CreateObject(gS,hS.children(Spec(i)),Objects{i},Parent, options);
    end
end


hS.children(Spec(Spec > 0)) = [];


if ~isempty(hS.children)
    for i = 1:length(hS.children)
        gS = Local_CreateObject(gS,hS.children(i),[],Parent, options);
    end
end




% ---------- End Local_CreateAxesChildren   ---------- %


% ---------- Begin Local_Type2CreationCommand         ---------- %
function command = Local_Type2CreationCommand(Type)
command = Type;

if strcmpi(command, 'uitools.uibuttongroup')
    command = 'uibuttongroup';
end


% ---------- Begin Local_SetAppData         ---------- %
function appdataname = Local_GetAppDataName
    
appdataname = 'appdata';

% ---------- Begin Local_SetAppData         ---------- %
function [CodeStr,VarNumber,gS] = Local_SetAppData(CodeStr,AppData,RealAppData, VarNumber,ObjNumber,gS, options)
    
NL = sprintf('\n');

if ~isempty(AppData)    
    CodeStr{length(CodeStr)+1} = [NL, Local_GetAppDataName,' = [];'];
    
    FldNms = fieldnames(AppData);    

    for i = 1:length(FldNms)
        Name  = FldNms{i};

        % Ignore application data for scribe and cameratoolbar
        if strncmp(Name,'Scribe',6) | strcmp(Name,'ctb200jaz')
            continue
        end
        Value = AppData.(Name);
        RealValue = [];
        if ~isempty(RealAppData)
            RealValue = RealAppData.(Name);
        end
        usemat = 1; 
        if ( isfield(options,'absorbGUIDEOptions') & options.('absorbGUIDEOptions') ==1) 
            % Add code directly in CodeStr for GUIDE options, not use mat file 
            try 
                Object = sprintf('h%i', ObjNumber); 
                CodeStr{length(CodeStr)+1} = Local_PrintAppData(Object, Name, Value, RealValue); 
                usemat = 0; 
            catch 
            end 
        end 
        if usemat 
            CodeStr{length(CodeStr)+1} = sprintf('%s.%s = mat{%i};',Local_GetAppDataName, Name, VarNumber); 
            gS.matdata{VarNumber} = Value; 
            VarNumber = VarNumber + 1; 
        end 
    end
end


% ---------- End Local_SetAppData           ---------- %


% ---------- Begin Local_PrintAppData          ---------- %

function s= Local_PrintAppData(Object, Name, Value, RealValue)

s=''; 
if ~isempty(Object) 
    s=sprintf('%s.%s = %s;', Local_GetAppDataName, Name, Local_Data2MCode(Value, RealValue));         
end     
% ---------- End Local_PrintAppData           ---------- %

function str = Local_Data2MCode(structValue, realValue) 

value = structValue;
if ~isempty(realValue)
    value = realValue;
end

if isempty(value) 
    if ischar(value) 
        str=''''''; 
    else 
        str = '[]'; 
    end 
elseif isnumeric(value)
    if value~=0 & ishandle(value) 
        str = '[]'; 
    else
        str = mat2str(value); 
    end
elseif ishandle(value) 
    str = '[]'; 
elseif strcmpi(class(value),'handle')
    str = '[]'; 
elseif ischar(value) 
    str = Local_Char2MCode(structValue, realValue); 
elseif iscell(value) 
    str = Local_Cell2MCode(structValue, realValue); 
elseif isstruct(value) 
    str = Local_Struct2MCode(structValue, realValue); 
else 
    error('Data type is not supported for generating M-Code.'); 
end 


function str = Local_Char2MCode(structValue, realValue) 

value = structValue;
if ~isempty(realValue)
    value = realValue;
end

str = '';

dim =size(value); 
if (length(dim)>2) 
    error('Cannot generate M-Code for a char array with more than two dimensions.'); 
end 

for i= 1:dim(1) 
    row = strrep(value(i,:),'''','''''');
    if findstr(row, char(10))
        row = ['' strrep(row, char(10),''', 10, ''') '']
    end
    str = [str  ['''' row ''''] ];
    if i~=dim(1) 
        str = [str, ';']; 
    end 
end 

if dim(1)>1 
    str = ['[' str ']']; 
end

function str = Local_Cell2MCode(structValue, realValue) 

str = '{ '; 
dim =size(structValue); 
if (length(dim)>2) 
    error('Cannot generate M-Code for a cell array with more than two dimensions.'); 
end 

for i= 1:dim(1) 
    for j= 1:dim(2) 
        first = structValue{i,j};
        second = [];
        if ~isempty(realValue)
            second = realValue{i, j};
        end
        str = [str ' ' Local_Data2MCode(first, second)]; 
    end 
    if i~=dim(1) 
        str = [str, ';']; 
    end 
end 

str = [str ' }']; 


function str= Local_Struct2MCode(structValue, realValue)
indent = '    ';
if (isstruct(structValue)) 
    str = 'struct('; 
    names = fieldnames(structValue); 
    for i=1:length(names) 
        first = structValue.(char(names(i))); 
        second=[];
        if ~isempty(realValue)
            second = realValue.(char(names(i))); 
        end
        code = Local_Data2MCode(first, second); 
        if iscell(first) 
            code = ['{ ' code ' }']; 
        end 
        str = sprintf('%s...\n%s''%s'', %s', str, indent, char(names(i)), code); 
        if (i ~= length(names)) 
            str =[str ', ']; 
        end 
    end 
    str=[str, ')']; 
end 



% ---------- Begin Local_WriteFile          ---------- %
function Local_WriteFile(Code,M,MAT,savedMat,options)

if isfield(options,'addHeaderComment')
   addBoiler = options.('addHeaderComment');
else
   addBoiler = 1;
end

if isfield(options,'appendToFile')
   appendFile = options.('appendToFile');
else
   appendFile = 0;
end

if isfield(options,'functionPrefix')
   signature = options.('functionPrefix');
else
   signature = [];
end

if isfield(options,'functionSuffix')
   suffix = options.('functionSuffix');
else
   suffix = [];
end
suffix = [suffix, Local_GetLocalCreateFcn];

if appendFile
    fid = fopen(M,'at');
else
    fid = fopen(M,'wt');
end


if fid < 1
    error('error writing file')
end


[Mp, Mf] = fileparts(M);

if (isempty(signature))
    fprintf(fid,'function h1 = %s()\n',Mf);
else
    fprintf(fid,'%s',signature);
end

if addBoiler
% Add boiler plate header
fprintf(fid,['%% This is the machine-generated representation of a Handle Graphics object\n',...
        '%% and its children.  Note that handle values may change when these objects\n',...
        '%% are re-created. This may cause problems with any callbacks written to\n',...
        '%% depend on the value of the handle at the time the object was saved.\n',...
        '%% This problem is solved by saving the output as a FIG-file.\n',...
        '%% \n',...
        '%% To reopen this object, just type the name of the M-file at the MATLAB\n',...
        '%% prompt. The M-file and its associated MAT-file must be on your path.\n',...
        '%% \n',...
        '%% NOTE: certain newer features in MATLAB may not have been saved in this\n',...
        '%% M-file due to limitations of this format, which has been superseded by\n',...
        '%% FIG-files.  Figures which have been annotated using the plot editor tools\n',...
        '%% are incompatible with the M-file/MAT-file format, and should be saved as\n',...
        '%% FIG-files.\n\n\n']);
end


[MATp, MATf, MATe] = fileparts(MAT);
if savedMat
   fprintf(fid,'load %s\n\n',[MATf MATe]);
end


for i = 1:length(Code)
    ObjCode = Code{i};
    for j = 1:length(ObjCode)
        fprintf(fid,'%s\n',ObjCode{j});
    end
end


if ~isempty(suffix)
    fprintf(fid, '\n%s', suffix);
end

fclose(fid);
clear(M); % Make sure any previous incarnations are flushed

% ---------- Begin Local_GetLocalCreateFcn    ---------- %
function creator = Local_GetLocalCreateFcn

NL = sprintf('\n');
creator =[...
    NL, NL, ...
    '% --- Set application data first then calling the CreateFcn. ', NL, ...
    'function local_CreateFcn(hObject, eventdata, createfcn, appdata)',NL,NL, ...
    'if ~isempty(appdata)',NL,...
    '   names = fieldnames(appdata);',NL,...
    '   for i=1:length(names)',NL,...
    '       name = char(names(i));',NL,...
    '       setappdata(hObject, name, getfield(appdata,name));',NL,...
    '   end',NL,...
    'end',NL,NL,...
    'if ~isempty(createfcn)',NL,...
    '   eval(createfcn);',NL,...
    'end',NL];


% ---------- Begin Local_ReturnObjectProperties      ---------- %
% This function makes the file dependes on guidemfile.m
function props = Local_ReturnObjectProperties(hS,options)

props = hS.properties;

% rename callbacks is needed
if isfield(options,'renameCallbacks') & options.('renameCallbacks')
    [path, file, ext] = fileparts(options.sourceFile);
    [p, mfile, e] = fileparts(options.destinationFile);
    oldLen = length(file);

    callbacks = guidemfile('getCallbackProperties', hS);
    
    if ~isempty(callbacks)
        names = fieldnames(props);
        for i=1:length(names)
            value = props.(char(names(i)));
            
            % code below is copied from guidemfile: renameCallbacks
            % TODO: merge with that code
            if (ismember(names(i), callbacks) & ...
                    strncmp(value, file, oldLen) & ...
                    (...
                    length(value) == oldLen |...
                    value(oldLen+1) == ' '   |...
                    value(oldLen+1) == '('    ...
                    ))
                newVal = [mfile, value((oldLen + 1):end)];
                props.(char(names(i))) = newVal;
            end        
        end
    end
end

% remove all instance proeprties, if any
propnames = fieldnames(props);
for i=1:length(propnames)
    if strncmp(propnames(i), 'i_', 2);
        props= rmfield(props, propnames(i));
    end
end

% remove properties that are in the exludedPropertyList, if any
if (isfield(options,'excludedPropertyList'))
    list = options.('excludedPropertyList');
    for k=1:length(list)
        if (strcmpi(list{k}.type,hS.type))
            properties = list{k}.properties;
            if ~isempty(properties)
                for i=1:length(properties)
                    if isfield(props, properties(i))
                        props= rmfield(props, properties(i));
                    end
                end
            end            
        end
    end
end

% create the figure invisible if is asked
if strcmpi(hS.type,'figure')
    if isfield(options, 'createFigureInvisible') && options.createFigureInvisible ==1
        props.Visible = 'off';
    end
end

% ---------- End Local_ReturnObjectProperties         ---------- %


% ---------- Begin Local_LimitForGenerateMat          ---------- %
function limit = Local_LimitForGenerateMat(options);

limit =5;

if ~isempty(options) & isfield(options,'limitForMatFile')
    limit = options.('limitForMatFile');
end

% ---------- Begin Local_LimitForGenerateMat          ---------- %
