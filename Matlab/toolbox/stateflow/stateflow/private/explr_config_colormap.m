function explr_config_colormap(axesH)
%EXPLR_CONFIG_COLORMAP(AXES)  Configures the colormap and color holders for
%         the Stateflow Explorer given the overlay axes handle.
%
%   Copyright 1995-2002 The MathWorks, Inc.
%   $Revision: 1.6.2.1 $  $Date: 2004/04/15 00:57:38 $

 cm = [
    0.0209    0.0203    0.0183
    0.1922         0         0
    0.1778    0.1712    0.1582
    0.2902    0.2784         0
    0.2716    0.2667    0.2461
    0.4451         0         0
    0.3882    0.1882         0
    0.7098    0.1882         0
    0.2588    0.4902    0.2588
    0.3438    0.3359    0.3111
    0.4069    0.3990    0.3755
    0.5176    0.5098         0
    0.5044    0.5010    0.4848
    0.5773    0.5733    0.5529
    0.8078    0.3961    0.0961
    1.0000    0.3961    0.2902
    1.0000    0.6039    0.3882
    1.0000    0.9608         0
    1.0000    0.9608    0.2902
    0.4824    0.6353    0.4824
    0.6333    0.6480    0.6118
    0.7627    0.7529    0.7402
    0.8745    0.8392    0.7725
    1.0000    0.7078    0.6118
    0.8078    0.8118    0.8078
    0.9386    0.8523    0.8039
    0.9186    0.8843    0.8618
    0.9784    0.9402    0.8441
    1.0000    0.9686    0.8882
    1.0000    1.0000    1.0000 
	0.502	  0.502		0.502
	0.0       0.0       0.0
    1.0       0.9608    0.8842
	0.725	  0.725		0.725
	0.9		  0.9		0.9
	0.0		  0.0	    0.5
	0.0		  0.0		1.0
	0.0		  1.0		0.0
	1.0		  0.9608	0.8842
	0.25	  0.25		0.25
];

figH = get(axesH, 'parent');
set(figH, 'colormap', cm, 'sharecolors', 'on');

% add color holders to explr figure
for i=1:length(cm), line('color', cm(i,:), 'vis','off','parent', axesH, 'tag', 'COLOR_HOLDER');end;


