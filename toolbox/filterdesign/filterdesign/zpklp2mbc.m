function [z2, p2, k2, allpassnum, allpassden] = zpklp2mbc(z, p, k, wo, wt)
%ZPKLP2MBC Zero-pole-gain lowpass to complex M-band frequency transformation.
%   [Z2,P2,K2,AllpassNum, AllpassDen] = ZPKLP2MBC(Z,P,K,Wo,Wt) returns
%   zeros, Z2, poles, P2, and gain factor, K2, of the transformed lowpass
%   digital filter as well as the numerator, ALLPASSNUM, and the denominator,
%   ALLPASSDEN, of the allpass mapping filter. The prototype lowpass filter is
%   given with zeros, Z, poles, P, and gain factor, K.
%
%   Inputs:
%     Z          - Zeros of the prototype lowpass filter
%     P          - Poles of the prototype lowpass filter
%     K          - Gain factor of the prototype lowpass filter
%     Wo         - Frequency value to be transformed from the prototype filter.
%                  The frequency should be normalized to be between 0 and 1,
%                  with 1 corresponding to half the sample rate.
%     Wt         - Desired frequency location in the transformed target filter.
%                  The frequency should be normalized to be between -1 and 1,
%                  with 1 corresponding to half the sample rate.
%   Outputs:
%     Z2         - Zeros of the target filter
%     P2         - Poles of the target filter
%     K2         - Gain factor of the target filter
%     AllpassNum - Numerator of the mapping filter
%     AllpassDen - Denominator of the mapping filter
%
%   Example:
%        [b, a]     = ellip(3,0.1,30,0.409);      % IIR halfband filter
%        z          = roots(b);
%        p          = roots(a);
%        k          = b(1);
%        [z1,p1,k1] = zpklp2mbc(z, p, k, 0.5, [2 4 6 8]/10);
%        fvtool(b, a, k1*poly(z1), poly(p1), k2*poly(z2), poly(p2));
%
%   See also ZPKFTRANSF.

%   References:
%     [1] Krukowski A. and I. Kale, "High-order complex frequency transformations",
%         Internal report No. 27/2001, Applied DSP and VLSI Research Group,
%         University of Westminster.

%   Author(s): Dr. Artur Krukowski, University of Westminster, London, UK.
%   Copyright 1999-2002 The MathWorks, Inc.
%   $Revision: 1.2 $  $Date: 2002/04/14 15:43:47 $

% --------------------------------------------------------------------

% Check for number of input arguments
error(nargchk(5, 5, nargin));

% Calculate mapping filter
[allpassnum, allpassden] = allpasslp2mbc(wo, wt);

% Perform the transformation
[z2, p2, k2]             = zpkftransf(z, p, k, allpassnum, allpassden);
