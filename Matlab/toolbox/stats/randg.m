%RANDG Gamma random numbers (unit scale).
%   Note: To generate gamma random numbers with specified shape and
%   scale parameters, you should call GAMRND.
%
%   R = RANDG returns a scalar random value chosen from a gamma
%   distribution with unit scale and shape.
%
%   R = RANDG(A) returns a matrix of random values chosen from gamma
%   distributions with unit scale.  R is the same size as A, and RANDG
%   generates each element of R using a shape parameter equal to the
%   corresponding element of A.
%
%   R = RANDG(A,M) returns an M-by-M matrix of random values chosen from
%   gamma distributions with shape parameters A.  A is either an M-by-M
%   matrix or a scalar.  If A is a scalar, RANDG uses that single shape
%   parameter value to generate all elements of R.
%
%   R = RANDG(A,M,N,...) or R = RANDG(A,[M,N,...]) returns an M-by-N-by-...
%   array of random values chosen from gamma distributions with shape
%   parameters A.  A is either an M-by-N-by-... array or a scalar.
%
%   RANDG produces pseudo-random numbers using the MATLAB functions RAND
%   and RANDN.  The sequence of numbers generated is determined by the
%   states of both generators.  Since MATLAB resets their states at
%   start-up, the sequence of numbers generated by RANDG will be the same
%   in each session unless those states are changed.
%
%   To create reproducible output from RANDG, set the states of both RAND
%   and RANDN to a fixed pair of values before calling RANDG.  For example,
%
%      rand('state',j); randn('state',s); r = randg(1,[10,1]);
%
%   always generates the same 10 values.  You can also use the MATLAB 4
%   generators by calling RAND and RANDN with the argument 'seed'.
%
%   Calling RANDG changes the current states of RAND and RANDN, and
%   therefore alters the outputs of subsequent calls to those functions.
%
%   See also GAMRND, RAND, RANDN.

%   References:
%
%      [1] Marsaglia, G. and Tsang, W.W. (2000) "A Simple Method for Generating
%          Gamma Variables", ACM Trans. Math. Soft. 26(3):363-372.

%   Copyright 1984-2004 The MathWorks, Inc.
%   $Revision: 1.1.6.2 $  $Date: 2004/01/24 09:36:44 $
%
%   Mex file.
