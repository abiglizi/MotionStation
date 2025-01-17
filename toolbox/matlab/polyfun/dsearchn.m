function [t,d] = dsearchn(x,tes,xi,outval,coptions,doptions)
%DSEARCHN N-D nearest point search.
%   K = DSEARCHN(X,T,XI) returns the indices K of the closest points in X for
%   each point in XI. X is an m-by-n matrix representing m points in n-D
%   space. XI is a p-by-n matrix, representing p points in n-D space. T is a
%   numt-by-n+1 matrix, a tessellation of the data X generated by DELAUNAYN.
%   The output K is a column vector of length p. 
%
%   K = DSEARCHN(X,T,XI,OUTVAL) returns the indices K of the closest points
%   in X for each point in XI, unless a point is outside the convex hull. 
%   If XI(J,:) is outside the convex hull, then K(J) is assigned OUTVAL, 
%   a scalar double.  Inf is often used for OUTVAL. If OUTVAL is [], 
%   then K is the same as in the case K = DSEARCHN(X,T,XI).
%
%   K = DSEARCHN(X,T,XI,OUTVAL,COPTIONS) specifies COPTIONS, a cell array of
%   strings to be used as options in Qhull via CONVHULLN.
%   If COPTIONS is [], the default CONVHULLN options will be used.
%   If COPTIONS is {''}, no options will be used, not even the default.
% 
%   K = DSEARCHN(X,T,XI,OUTVAL,COPTIONS,DOPTIONS) specifies DOPTIONS, a
%   cell array of strings to be used as options in Qhull via DELAUNAYN.
%   If DOPTIONS is [], the default DELAUNAYN options will be used.
%   If DOPTIONS is {''}, no options will be used, not even the default.
%  
%   K = DSEARCHN(X,XI) performs the search without using a tessellation.
%   With large X and small XI, this approach is faster and uses much
%   less memory. 
%
%   [K,D] = DSEARCHN(X,...) also returns the distances D to the closest
%   points. D is a column vector of length p. 
%
%   See also TSEARCH, DSEARCH, TSEARCHN, QHULL, GRIDDATAN, DELAUNAYN,
%            CONVHULLN.

%   Relies on the MEX file tsrchnmx to do most of the work.

%   Copyright 1984-2003 The MathWorks, Inc.
%   $Revision: 1.7.4.3 $  $Date: 2004/01/16 20:04:54 $

if nargin < 2
  error('MATLAB:dsearchn:NotEnoughInputs','Needs at least 2 inputs.'); 
end
if nargin >= 4
    if ~isempty(outval) && ~isa(outval,'double')
        error('MATLAB:dsearchn:OutvalNotScalarDouble',...
              'OUTVAL must be a scalar double');
    end
    copt = [];
    dopt = [];
    if nargin > 4
        if ~iscellstr(coptions)
            error('MATLAB:dsearchn:CoptionsNotStringCell',...
                  'COPTIONS should be cell array of strings.');           
        end
        copt = coptions;
        if nargin > 5 
            if ~iscellstr(doptions)
                error('MATLAB:dsearchn:DoptionsNotStringCell',...
                      'DOPTIONS should be cell array of strings.');           
            end            
            dopt = doptions;
        end
    end
end

if nargin == 2 % (x,xi) syntax
    if size(x,2) ~= size(tes,2)
        error('MATLAB:dsearchn:XandXIColSizeMismatch',...
              'X and XI should have the same column dimension.');
    end
end

if nargin >= 3
    if size(x,2) ~= size(xi,2)
        error('MATLAB:dsearchn:XandXIColSizeMismatch',...
              'X and XI should have the same column dimension.');
    end
    if size(x,2) ~= size(tes,2)-1
        error('MATLAB:dsearchn:InvalidSizeT',...
              'T does not have the right size to be a tessellation of X.');
    end
end

if nargin == 2 % loop, no triangles, tes is xi in this syntax
    xi = tes;
    t = zeros(size(xi,1),1);
    d = zeros(size(xi,1),1);
    for i = 1:size(xi,1) 
        yi = repmat(xi(i,:),size(x,1),1);
        [d(i),t(i)] = min(sum((x-yi).^2,2));
    end
    if nargout == 2
        d = sqrt(d); 
    end
    return;
end

if nargin < 4 || (nargin == 4 && isempty(outval)) % index, no outval
    [t,d] = tsrchnmx(x',tes,xi',1);
    if nargout == 2
        d = sqrt(d); 
    end
else  % give outval to point outside of the convex hull
    t = zeros(size(xi,1),1);
    d = zeros(size(xi,1),1);
    if isempty(copt)
        c = convhulln(x);
    else
        c = convhulln(x,copt);
    end
    c1 = unique(c);
    x1 = x(c1,:);
    if isempty(dopt)
        tes1 = delaunayn(x1);
    else
        tes1 = delaunayn(x1,dopt);
    end
    t1 = tsrchnmx(x1',tes1,xi',2);
    c2 = isnan(t1);
    xi1 = xi(~c2,:);
    [t2,d2] = tsrchnmx(x1',tes,xi1',1);
    t(c2) = outval;
    t(~c2) = t2;
    if nargout == 2
        d(c2) = outval;
        d(~c2) = sqrt(d2);
    end
end

