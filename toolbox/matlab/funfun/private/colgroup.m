function gout = colgroup(S)
%COLGROUP Helper function used by NUMJAC for sparse Jacobians.
%   This helper function is used by NUMJAC to reduce the number of function
%   evaluations required to compute all of the columns of a sparse Jacobian
%   matrix.  Given a sparsity pattern matrix S, G = COLGROUP(S) returns a
%   column vector G consisting of a group number assigned to each column of
%   matrix S.  Two columns may be grouped together if they do not overlap,
%   i.e. their dot product is zero.  The number of function evaluations that
%   NUMJAC requires to generate a sparse Jacobian is given by
%   max(colgroup(S)).
%   
%   COLGROUP tries two different packings (first-fit and first-fit after
%   reverse colamd ordering) and returns the one that requires fewer
%   groups. The result may not be optimal.  (Finding the smallest packing is
%   an NP-complete problem equivalent to K-coloring a graph.)
%   
%   See also NUMJAC, ODE15S, ODE23S, ODESET, BRUSSODE, COLAMD.

%   Mark W. Reichelt and Lawrence F. Shampine, 3-28-94
%   Copyright 1984-2003 The MathWorks, Inc.
%   $Revision: 1.13.4.2 $  $Date: 2004/04/16 22:06:36 $

[m,n] = size(S);
[i,j] = find(S);
T = sparse(i,j,1,m,n);
TT = tril(T' * T);

% First-fit packing.
g = zeros(n,1);
groupnum = 0;
J = (1:n)';
while length(J)
  groupnum = groupnum + 1;
  g(J(1)) = groupnum;
  col = full(TT(:,J(1)));
  for k = J'
    if col(k) == 0
      col = col + TT(:,k);
      g(k) = groupnum;
    end
  end
  J = find(g == 0);
end

% Form the reverse column minimum-degree ordering.
p = colamd(T);
p = p(n:-1:1);
T = T(:,p);
TT = tril(T' * T);

% First-fit packing.
g2 = zeros(n,1);
groupnum2 = 0;
J = (1:n)';
while length(J)
  groupnum2 = groupnum2 + 1;
  g2(J(1)) = groupnum2;
  col = full(TT(:,J(1)));
  for k = J'
    if col(k) == 0
      col = col + TT(:,k);
      g2(k) = groupnum2;
    end
  end
  J = find(g2 == 0);
end

% Use whichever packing required fewer groups.
if groupnum <= groupnum2
  gout = g;
else
  q(p) = 1:n;               % invert the permutation
  gout = g2(q);
end
