function wavetool
%WAVETOOL Warning function. 
%   The reason for this is that Strang-Nguyen's book 
%   explicitly refers to wavetool in the appendix.

%   M. Misiti, Y. Misiti, G. Oppenheim, J.M. Poggi 12-Mar-96.
%   Last Revision: 01-May-1998.
%   Copyright 1995-2002 The MathWorks, Inc.
%   $Revision: 1.11 $


msg = [ ...
        '===================================================' ; ...
        '|                  WARNING  !!                    |' ; ...
        '|=================================================|' ; ...
        '| The name of this function has been changed.     |' ; ...
        '| To launch the main wavelet GUI use: wavemenu.m  |' ; ...
        '==================================================='   ...
        ];
clc;
disp(msg);
