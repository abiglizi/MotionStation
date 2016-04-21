function capacitor(varargin)
%CAPACITOR  Draw a capacitor

%   Author(s): A. DiVergilio
%   Copyright 1986-2002 The MathWorks, Inc.
%   $Revision: 1.6 $  $Date: 2002/04/10 06:41:42 $

%---Default properties
p = struct(...
   'Parent',[],...
   'Position',[2 2],...
   'Size',1,...
   'Angle',0,...
   'LineWidth',2,...
   'LineStyle','-',...
   'Color','k',...
   'Tag','',...
   'Clipping','off');
plist = fieldnames(p);

%---Merge user-specified properties
for i=1:2:nargin-1
   Property = pnmatch(varargin{i},plist);
   Value = varargin{i+1};
   p.(Property) = Value;
end
if isempty(p.Parent), p.Parent = gca; end

%---Draw a line
x = p.Size*[0 .44 NaN .44 .44 NaN .61 .56 .55 .56 .61 NaN .55 1];
y = p.Size*[0 0 NaN .2 -.2 NaN .2 .1 0 -.1 -.2 NaN 0 0];
r = sqrt(x(2:end).^2+y(2:end).^2);
a0 = atan(y(2:end)./x(2:end));
line(...
   'Parent',p.Parent,...
   'XData',p.Position(1)+[0 r.*cos(a0+p.Angle*pi/180)],...
   'YData',p.Position(2)+[0 r.*sin(a0+p.Angle*pi/180)],...
   'LineWidth',p.LineWidth,...
   'LineStyle',p.LineStyle,...
   'Color',p.Color,...
   'Tag',p.Tag,...
   'Clipping',p.Clipping);