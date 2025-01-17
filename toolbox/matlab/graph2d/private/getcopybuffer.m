function [copyBufferFig, copyBufferAx] = getcopybuffer(varargin)
%GETCOPYBUFFER
%   [copyBufferFig, copyBufferAx] = getcopybuffer
%       returns the scribe copy buffer figure and axis,
%       creating them if they do not already exist.
%   [copyBufferFig, copyBufferAx] = getcopybuffer('noforce')
%       does not force the creation of a copy buffer figure if
%       none currently exists.

%   Copyright 1984-2002 The MathWorks, Inc. 
%   $Revision: 1.10 $  $Date: 2002/04/15 04:05:29 $


copyBufferFig = findobj(allchild(0),'flat',...
        'Tag','ScribeCopyBufferFig');
copyBufferAx = findobj(allchild(copyBufferFig),'flat',...
        'Tag','ScribeCopyBufferOverlayAxes');

if nargin==0 & isempty(copyBufferAx)
   copyBufferFig = figure('Tag','ScribeCopyBufferFig',...
           'IntegerHandle','off',...
           'HandleVisibility','off',...
           'NumberTitle','off',...
           'Visible','off',...           
           'Name','Scribe Copy Buffer',...
           'Resize','off');
   copyBufferAx = axes('Tag','ScribeCopyBufferOverlayAxes',...
           'HandleVisibility','off',...
           'Visible','off',...
           'Parent',copyBufferFig);
   fh = scribehandle(figobj(copyBufferFig));
end

