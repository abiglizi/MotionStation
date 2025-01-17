function notsaved = savepath(outputfile)
%SAVEPATH Save the current MATLAB path in the pathdef.m file.
%   SAVEPATH saves the current MATLABPATH in the pathdef.m
%   which was read on startup.
%
%   SAVEPATH outputFile saves the current MATLABPATH in the
%   specified file.
%
%   SAVEPATH returns:
%     0 if the file was saved successfully
%     1 if the file could not be saved
% 
%   See also PATHDEF, ADDPATH, RMPATH, PATH, PATHTOOL, CREATEDEFAULTPATH.

%   Copyright 1984-2003 The MathWorks, Inc. 
%   $Revision: 1.1.6.3 $ $Date: 2004/01/13 16:42:15 $

% Assume that things are going well until we learn otherwise.
result = 0;

% Unless the user specifies otherwise, we're going to overwrite the
% pathdef.m file that MATLAB currently sees.
if nargin == 0
    outputfile = which('pathdef.m');
end

% This is a token string that we will look for in the template file.
magic_string = 'PLEASE FILL IN ONE DIRECTORY PER LINE';

templatefile = fullfile(matlabroot, 'toolbox', 'local', 'template', 'pathdef.m');

% Try to read the template file.  If we can't, that's OK, we have a
% backup plan.
fid = fopen(templatefile, 'r');

if fid ~= -1
    template = fread(fid,'*char')';
    fclose(fid);
else
    template = ['function p = pathdef', 10, ...
                '%PATHDEF Search path defaults.', 10, ...
                '%   PATHDEF returns a string that can be used as input to MATLABPATH', 10, ...
                '%   in order to set the path.', 10, 10, ...
                '% DO NOT MODIFY THIS FILE.  IT IS AN AUTOGENERATED FILE.', 10, ...
                '% EDITING MAY CAUSE THE FILE TO BECOME UNREADABLE TO', 10, ...
                '% THE PATHTOOL AND THE INSTALLER.', 10, 10, ...
                'p = [...', 10, ...
                '%%% BEGIN ENTRIES %%%', 10, ...
                magic_string, 10, ...
                '%%% END ENTRIES %%%', 10, ...
                '     ...', 10, ...
                '];', 10, 10, ...
                'p = [userpath,p];', 10];
end

% Find the location of the "magic string" in the file.
magic_index = findstr(template, magic_string);

% Take everything that appears *before* the "magic string" line as
% "firstpart," and everything that appears after that line as
% "lastpart."
% We'll sandwich the path particulars between the two ends.
firstpart = template(1:magic_index-1);
lastpart = template(magic_index + 1:end);

lfs_in_firstpart = find(firstpart == 10, 1, 'last');
firstpart = firstpart(1:lfs_in_firstpart);

lfs_in_lastpart = find(lastpart == 10, 1, 'first');
lastpart = lastpart(lfs_in_lastpart+1:end);

% Read the current path.
thepath = matlabpath;

% First, Break the path down into a cell array of strings, one for
% each entry in the path.  We leave the pathsep on the end of each
% string.  The path might not actually *end* with a pathsep, but if
% not, we add one for consistency's sake.
ps = pathsep;
if thepath(end) ~= ps
    thepath = [thepath ps];
end

% Get the exact form of the entries that we want to create in the
% new pathdef file based on the path.  all_path_lines will be a
% cell array of strings.
all_path_lines_matches = regexp(thepath,['(.[^' ps ']*' ps '?)'],'tokens');
all_path_lines = [all_path_lines_matches{:}]';
all_path_lines = matlabrootify(all_path_lines);

% Start constructing the contents of the new file.  We start with
% the firstpart.
cont = firstpart;

% Append the paths separated by newline characters
cont = [cont all_path_lines{:}];

% Conclude with the lastpart.
cont = [cont lastpart];

% We have the completed new text of the file, so we try to write it out.
fid = fopen(outputfile, 'w');
if fid == -1
    % We failed to open the file for writing.  That might be
    % because we don't have write permission for that file.  Let's
    % try to make it read-write.
    
    if isunix
        unix(['chmod 666 ''', outputfile, '''']); 
    elseif ispc && ~strncmpi('\\', pwd, 2)
        dos(['attrib -r "', outputfile, '"']);
    end
    % Last chance.  Can we write to it?  If we fail here, we have
    % no choice but to fail.
    fid = fopen(outputfile, 'w');
    if fid == -1
    	result = 1;
		if nargout == 1
			notsaved = result;
		end
		return;
    end
end

% Write it out.
count = fprintf(fid,'%s', cont);
if count < length(template)
    result = 1;
end
fclose(fid);

if nargout == 1
	notsaved = result;
end

%---------------------------------------------
function dirnames = matlabrootify(dirnamesIn)
% Given a cell array of path entries, this performs two functions: 
% (1) If the path entry under consideration is a subdirectory of
% matlabroot, it encodes that information directly into the string.
% Therefore, even if the location of the MATLAB installation is changed,
% pathdef.m will still point to the appropriate location. 
% (2) Performs additional formatting.

% If we're on PC, we want to do our comparisons in a case-insensitive
% fashion.  Since it also doesn't matter what case the entries are made in,
% we might as well lowercase everything now - no harm done.
if ispc
    mlroot = lower(matlabroot);
    dirnames = lower(dirnamesIn);
else
    mlroot = matlabroot;
    dirnames = dirnamesIn;
end

% Find indices to entries in the MATLAB root
% Calculate indices to remaining entries, and preserve case-sensitivity
mlr_dirs = ~cellfun('isempty',strfind(dirnames,mlroot));
dirnames(~mlr_dirs) = dirnamesIn(~mlr_dirs);

% We'll need to wrap all the entries in strings, so do some quote escaping
dirnames = strrep(dirnames, '''', '''''');

% Replace MATLAB roots with "matlabroot", and wrap entires in quotes
dirnames(mlr_dirs) = strrep(dirnames(mlr_dirs),mlroot,'     matlabroot,''');
dirnames(~mlr_dirs) = strcat('     ''',dirnames(~mlr_dirs));
dirnames = strcat(dirnames, ''', ...', {char(10)});
