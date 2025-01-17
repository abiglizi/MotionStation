% EZPOLAR 極座標の簡単なプロット
% EZPOLAR(f) は、デフォルトの領域 0 < theta < 2*piに、極曲線 rho = f(the
% ta)をプロットします。
%
% EZPOLAR(f, [a,b])は、a < theta < b に対して、f をプロットします。
%
% 例題
%       syms t
%       ezpolar(1 + cos(t))
%       ezpolar(cos(2*t))
%       ezpolar(sin(tan(t)))
%       ezpolar(sin(3*t))
%       ezpolar(cos(5*t))
%       ezpolar(sin(2*t)*cos(3*t),[0,pi])
%       ezpolar(1 + 2*sin(t/2))
%       ezpolar(1 - 2*sin(3*t))
%       ezpolar(sin(t)/t, [-6*pi,6*pi])
%
%       r = 100/(100+(t-1/2*pi)^8)*(2-sin(7*t)-1/2*cos(30*t));
%       ezpolar(r,[-pi/2,3*pi/2])
%
% 参考： EZPLOT3, EZPLOT, EZSURF, PLOT, PLOT3, POLAR



%   Copyright 1993-2002 The MathWorks, Inc.
