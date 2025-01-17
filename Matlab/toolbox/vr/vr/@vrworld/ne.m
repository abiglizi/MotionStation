function x = ne(A, B)
%NE True for nonequal VRWORLD objects.
%   NE(A,B) tests for nonequality of VRWORLD objects.
%   See EQ for detailed description.

%   Copyright 1998-2001 HUMUSOFT s.r.o. and The MathWorks, Inc.
%   $Revision: 1.2 $ $Date: 2002/02/12 09:09:28 $ $Author: batserve $

x = ~eq(A, B);
