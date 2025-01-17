function pj = render( pj, h )
%RENDER Method to draw a model or Figure on current page of a print job.
%   Figure or model is drawn in the output format specified by the device
%   option to PRINT. The Figure or model may be modified as required for
%   printing.
%
%   Ex:
%      pj = RENDER( pj, h ); %draw Figure/model h on output of PrintJob pj
%
%   See also PRINT, PREPARE.

%   Copyright 1984-2003 The MathWorks, Inc.
%   $Revision: 1.12.4.4 $  $Date: 2004/04/10 23:29:11 $

error( nargchk(2,2,nargin) )

%When support multiple objects per page, h should be a scalar
if isempty(h) | ~ishandle( h )
    error( 'Need a handle to a Figure or model.' )
end

if ~pj.Active
   error('PrintJob is not active')
end

%Call the output driver and render Figure/model to device, file, or clipboard.
%We report error in PrintJob flag, caller will error out (allows it to recover gracefully).
try
    pj.Error = 0;  %So caller knows there was an error

	if feature('NewPrintAPI')
        pj.Return = hardcopy( pj, 'render', h );
        
    else
        
        %If writing out to PS for later conversion via GS to an image format,
        %true for either Simulink TIFF previews or for saving in pgm type formats,
        %must move the objects to the lower-left of the page so we can crop the image.
        if pj.GhostImage
            %Save all the current values of the 'paper' properties
            %Then move each object(s) PaperPosition to lower left
            %using points; saved a translation for every object on
            %the current page earlier.
            pp = cell(size(h));
            for i = 1:length(h)
                pp{i} = getpp(h(i));
                setset( h(i), 'paperunits', 'points' )
                if ~strcmp(pj.GhostDriver, 'pdfwrite')
                  % Change the paperposition if the output format is not
                  % PDF, since PDF is a format that supports margins
                  setset( h(i), 'paperposition', getget(h(i), ...
                  'paperposition')-[pj.GhostTranslation 0 0] )

                end
                
            end
        end
        
        %Create TIFF preview file
        tiffName = '';
        if pj.PostScriptPreview == pj.TiffPreview
            %Write out TIFF temp file for concatenating with EPS file later.
            eventualName = pj.FileName;
            pj.FileName = [tempname '.eps'];
            
            try
                tiffName = LocalWriteTiff( pj, h );
                wasErr = 0;
            catch
                wasErr = 1;
            end
            
            %Restore paper properites if using GS to create TIFF
            if pj.GhostImage
                for i = 1:length(h)
                    setpp( h(i), pp{i} )
                end
            end
            
            if wasErr
                error( lasterr );
            end
            
            %Using GS only to create TIFF for SL, don't want to call it again later.
            pj.GhostDriver = '';
        end
        
        %Make argument cell array for calling HARDCOPY
        inputargs = LocalPrintJob2Arguments( pj, h );
            
        if pj.DebugMode
            fprintf('Printing handle: %d\n', inputargs{1})
            fprintf('Passing input args to hardcopy: ')
            fprintf('''%s'' ', inputargs{2:end})
            fprintf('\n')
        end
            
        %Create the output file
        try
            pj.Return = hardcopy( inputargs{:} );
            wasErr = 0;
        catch
            wasErr = 1;
        end
            
        %Restore paper properites now if using GS to create image output.
        if pj.GhostImage & (pj.PostScriptPreview ~= pj.TiffPreview)
            for i = 1:length(h)
                setpp( h(i), pp{i} )
            end
        end
        
        %If we had a problem with creating the EPS file, clean up
        %before erroring out.
        if wasErr
            if ~pj.DebugMode
                if exist(pj.FileName), delete(pj.FileName); end
                if exist(pj.GhostName), delete(pj.GhostName); end
                if exist(tiffName), delete(tiffName); end
            end
            error( lasterr )
        end
        
        if (pj.PostScriptPreview == pj.TiffPreview) & ~isempty( tiffName )
            catpreview( pj, pj.FileName, tiffName, eventualName );
            pj.FileName = eventualName; %just in case
        end
        
    end %old API
        
    %Some output formats are generated by first creating ZBuffer via hardcopy
    %then using IMWRITE to ouput image. The default extension of the specified
    %format is passed to IMWRITE in case user gave FileName a different ext.
    if strcmp( pj.DriverClass, 'IM') 
        dims = size(pj.Return);
        if length(dims) ~=3 | dims(3) ~= 3
            error('Bad data returned by HARDCOPY. Not calling IMWRITE.')
        else
            imwriteArgs = LocalCreateImwriteArgs( pj );

            if pj.DebugMode
                fprintf('Passing input args to IMWRITE: ')
                fprintf('''%s'' ', imwriteArgs{:})
                fprintf('\n')
            end
            
            if strcmp('landscape', getget(h,'paperorientation') )
                pj.Return = cat( 3, rot90(pj.Return(:,:,1),1), rot90(pj.Return(:,:,2),1), rot90(pj.Return(:,:,3),1) );
            elseif strcmp('rotated', getget(h,'paperorientation') )
                pj.Return = cat( 3, rot90(pj.Return(:,:,1),-1), rot90(pj.Return(:,:,2),-1), rot90(pj.Return(:,:,3),-1) );
            end
            imwrite( pj.Return, pj.FileName, pj.DriverExt, imwriteArgs{:} );
            pj.Return = 0;
        end
        
    end
catch
    pj.Error = 1;
end



%------------------------------------------------------------------------------------

function tiffName = LocalWriteTiff( pj, h )
%LOCALWRITETIFF Creates a TIFF file for output object h
%   For Figure use IMWRITE to create TIFF from zbuffer
%   For Simulink models and for multiple objects create a 
%    PS file and uses GhostScript to create a TIFF file.

tiffName = [ tempname '.tif' ];
try
    if isfigure(h)
        imageDriver = LocalGetImageDriver(h, pj.Renderer);
        z = hardcopy( h, imageDriver, '-r150' );
        dims = size( z );
        if length(dims) ~=3 | dims(3) ~= 3
            error('Bad data returned by HARDCOPY. Not calling IMWRITE.')
        end
        if strcmp('landscape', get(h,'paperorientation') )
            z = cat( 3, rot90(z(:,:,1),1), rot90(z(:,:,2),1), rot90(z(:,:,3),1) );
        elseif strcmp('rotated', getget(h,'paperorientation') )
            z = cat( 3, rot90(z(:,:,1),-1), rot90(z(:,:,2),-1), rot90(z(:,:,3),-1) );
        end
        imwrite( z, tiffName, 'tiff', 'Compression', 'packbits',...
                 'Description', 'HG Figure Preview',...
                 'Resolution',[150 150]) 
    else
	  %If creating preview using GS, need to save 72dpi PS to temporary place
	  hardcopy( h, pj.FileName, [ '-d' pj.Driver], '-r72');
        
	  %We now have a temporary 72dpi EPS file, convert that to TIFF. 
      pj.GhostName = tiffName;
      res = get(0,'screenpixelsperinch');
      pj.GhostExtent = (res/72).*pj.GhostExtent;
      pj = ghostscript( pj );
	end	  
catch
    error( sprintf( ['Could not create TIFF preview, error was:\n' lasterr ] ) )
end


%------------------------------------------------------------------------------------

function imwriteArgs = LocalCreateImwriteArgs( pj )
%LOCALCREATEIMWRITEARGS Create a cell-array of input arguments for IMWRITE

imwriteArgs = {};

%We will have extra arguments for when we call IMWRITE.
if strcmp(pj.DriverClass, 'IM' )
    if strncmp( pj.Driver, 'tiff', 4 )
        imwriteArgs{end+1} = 'Compression';
        if strcmp( pj.Driver, 'tiffnocompression')
            imwriteArgs{end+1} = 'none';
        else
            imwriteArgs{end+1} = 'packbits';
        end
        
        imwriteArgs{end+1} = 'Description';
        imwriteArgs{end+1} = 'MATLAB Handle Graphics';
        
        imwriteArgs{end+1} = 'Resolution';
        if pj.DPI == -1
            imwriteArgs{end+1} = 150;
        elseif pj.DPI == 0
            imwriteArgs{end+1} = get(0,'screenpixelsperinch');
        else
            imwriteArgs{end+1} = pj.DPI;
        end
        
    elseif strncmp( pj.Driver, 'jpeg', 4 )
        %Already checked that it is in acceptable format.
        imwriteArgs{end+1} = 'Quality';
        imwriteArgs{end+1} = sscanf(pj.Driver,'jpeg%d');    
        if isempty( imwriteArgs{end} )
            %Default quality level
            imwriteArgs{end} = 75;
        end
        
    elseif strcmp( pj.Driver, 'png' )
        
        %Date will look like "20 May 1998 18:41:36"
        c = clock;
        imwriteArgs{end+1} = 'CreationTime';
        imwriteArgs{end+1} = [ strrep(date,'-',' ') sprintf(' %02d:%02d:%02d', fix(c(4:6))) ];
         
        imwriteArgs{end+1} = 'ResolutionUnit';
        imwriteArgs{end+1} = 'meter';
        
        if pj.DPI == -1
            dpi = 150;
        elseif pj.DPI == 0
            dpi = get(0,'screenpixelsperinch');
        else
            dpi = pj.DPI;
        end
        dpi = fix(dpi * 100.0 / 2.54 + 0.5);

        imwriteArgs{end+1} = 'XResolution';
        imwriteArgs{end+1} = dpi;
        
        imwriteArgs{end+1} = 'YResolution';
        imwriteArgs{end+1} = dpi;
        
        imwriteArgs{end+1} = 'Software';
        imwriteArgs{end+1} = 'MATLAB, The Mathworks, Inc.';
    end
end



%------------------------------------------------------------------------------------

function inputargs = LocalPrintJob2Arguments( pj, h );
%LOCALPRINTJOB2ARGUMENTS Make Cell-array of input arguments for old hardcopy from PrintJob.

inputargs{1} = h;
inputargs{2} = pj.FileName;

%If asking internal driver to create a zbuffer image to call
%IMWRITE with, set driver argument accordingly.
if strcmp( pj.DriverClass, 'IM')
  inputargs{3} = LocalGetImageDriver(h, pj.Renderer);
else
  inputargs{3} = [ '-d' pj.Driver];
end

if pj.DPI ~= -1
    inputargs{end+1} = ['-r' num2str(pj.DPI)];
end
if ~pj.PostScriptTightBBox
	inputargs{end+1} = '-loose';
end
if pj.PostScriptCMYK
	inputargs{end+1} = '-cmyk';
end
if pj.PostScriptAppend
	inputargs{end+1} = '-append';
end
if ~pj.PostScriptLatin1
	inputargs{end+1} = '-adobecset';
end
if pj.Verbose == 1
	inputargs{end+1} = '-v';
end

if strcmp(computer, 'PCWIN') & strncmp(pj.Driver, 'win', 3)
    if isfigure(h) & isempty(getprinttemplate(h)) 
        if ~pj.DriverColorSet 
            inputargs{end+1} = '-wcolor';
        end
    end
end

% add _P option to hardcopy for Windows only
if strcmp(computer, 'PCWIN')
    if strcmp( pj.PrinterName, '' )==0 % if printer is not empty send it on windows
        inputargs{end+1} = [ '-P' pj.PrinterName ];
    end    
end

function imageDriver = LocalGetImageDriver(h, renderer)
if isempty(renderer)
  renderer = get(h, 'Renderer');
end
if strcmp( renderer, 'painters' )
  renderer = 'zbuffer';
end
imageDriver = ['-d' renderer];
