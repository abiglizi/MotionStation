function [xsol, fval, basicVarIdx, nonbasicVarIdx, exitflag, niters] = ...
    simplexpiecewise(n_orig,c,A,b,lb,ub,basicVarIdx,nonbasicVarIdx,x0,maxiter,tol,verbosity)
%SIMPLEXPIECEWISE The simplex method for a piecewise LP problem.
%   Input model: 
%              max c'*x  % Note that here c is a piecewise linear function of x
%              s.t. A*x = b,  
%              lb <= x <= ub.
%
%   Output: xsol ... optimal solution if exitflag == 1, otherwise current
%           fval ... optimal value if exitflag ==1, otherwise current value
%           exitflag ... the status of the solution 
%                     = -2; unbounded
%                     = -1; infeasible
%                     = 0; the maxiter exceeded 
%                     = 1; converged, optimal                    

%   Copyright 1990-2004 The MathWorks, Inc.
%   $Revision: 1.4.4.4 $  $Date: 2004/02/01 22:09:40 $

% Note: MAXIMIZE the objective, consistent with the setup of the auxiliary problem 
% in the function SIMPLEXPHASEONE
  
if (nargin < 12 ) 
    verbosity = 0;
    if (nargin < 9) 
        error('optim:simplexpiecewise:NotEnoughInputs', ...
              'At least 9 input arguments are required.');
    end
end

[m, n] = size(A);

if n > 0 
    if isempty(lb) 
        lb = repmat(-inf, n,1);
    end
    if isempty(ub)
        ub = repmat(inf, n,1);
    end
else
    error('optim:simplexpiecewise:EmptyA', ...
          'The constraint matrix A must be nonempty.');
end

% Set up a feasible basis solution.
% Data: basicVarIdx, nonbasicVarIdx; B, N and c_B, c_N; ub_B, lb_B; and ub_N, lb_N.
if ( nnz(basicVarIdx) > 0 )
    B = A(:, basicVarIdx);
    N = A(:, nonbasicVarIdx);
    x_B = x0(basicVarIdx);
    x_N = x0(nonbasicVarIdx);
    c_B = c(basicVarIdx);
    c_N = c(nonbasicVarIdx);
    
    ubtmp = ub;
    ubtmp(x0 > ub) = Inf; 
    lbtmp = lb;
    lbtmp(x0 < lb) = -Inf; 
    
    ub_B = ubtmp(basicVarIdx);
    ub_N = ubtmp(nonbasicVarIdx);
    lb_B = lbtmp(basicVarIdx);
    lb_N = lbtmp(nonbasicVarIdx);
    
    if verbosity >= 5
        checkin2 = any(x0(basicVarIdx) < lb_B) + any(x0(basicVarIdx) > ub_B) + any(x0(nonbasicVarIdx) < lb_N) + any(x0(nonbasicVarIdx) > ub_N);
        if (checkin2)
            error('optim:simplexpiecewise:BndryCondViolated', ...
                  'Wrong setup: boundary conditions are violated.');
        end
    end
else
    error('optim:simplexpiecewise:NoFirstFeasBasis', ...
          'No first feasible basis is available.');
end % if ( nnz(basicVarIdx) > 0 )

xsol = [x_B; x_N];
fval = [c_B; c_N]'*[x_B; x_N];

% Display the starting iteration
niters = 0;
if verbosity >= 2
    disp( sprintf('\nPhase 1: Compute initial basic feasible point.') );
    disp('      Iter            Infeasibility');
    disp( sprintf('%8d             %12.6g', niters, full(-fval)) );
    if verbosity >= 5
        disp('    [basicVarIdx      c_B       x_B      lb_B      ub_B] = ');
        disp(full([basicVarIdx      c_B       x_B      lb_B      ub_B]) );
        disp('    [nonbasicVarIdx      c_N       x_N      lb_N      ub_N] = ');
        disp(full([nonbasicVarIdx      c_N       x_N      lb_N      ub_N]) );
        disp( sprintf('\n*********************************') );
    end
end

%---------- Optimality conditions and update if necessary -----------------------

% Default tolerance initialization
tol2 = tol*tol;
% Setup constants for exitflag
Unset = Inf;
Converged  = 1;
ExcdMaxiter = 0;
Infeasible = -1; % Will be remapped to -2 in linprog.m
Unbounded  = -2; % Will be remapped to -3 in linprog.m
Degenerate = -3;

% Initialization for the while loop
exitflag = Unset;
sameBasis = false;

while (exitflag == Unset) && (niters < maxiter) && (fval <= -tol) && (~isempty(nonbasicVarIdx))
    % Solve the system yB= c_B', 
    if ~sameBasis
        y = c_B'/B;  
    end
    
    % Choose the entering variable and check the optimality condition
    dualf = c_N - (y * N)';
    
    % k is the chosen (the first one that satisfies the conditions) index of the entering variable
    kcands = find( ( (dualf >= tol) & (tol2 < ub_N - x_N) ) | ( (dualf <= -tol) & (x_N - lb_N > tol2) ) );
    
    if isempty(kcands)  % no entering variable exists, already optimal                                                       
        xsol = [x_B; x_N];
        if niters == 0
            fval = c_B' * x_B + c_N' * x_N;
        end
        exitflag  = Converged;
        
        if verbosity >= 5
            disp('  Simplexpiecewise terminated.');
        end
        break;  % break out of while loop
    end % if isempty(kcands)
    
    % kcands is not empty so continue
    k = min(kcands);  % Choose by the smallest-subscript rule
    if verbosity >= 5
        disp( sprintf('  The entering variable : \t %d.', nonbasicVarIdx(k)) );
    end
    niters = niters + 1;
    
    % Solve the system Bz = N(:,k)
    % where k is the index for the entering variable, 
    % and delta is the value change of entering variable.
    N_k = N(:, k);
    z   = B\N_k;
    
    % Choose the leaving variable and update
    % where lv is the index of the leaving variable.
    lv = 0;
    minUb      = inf;
    bounds     = ub_B;
    ubB        = ub(basicVarIdx);
    lbB        = lb(basicVarIdx);
    zind       = find( abs(z) >= tol ); 
    zneg       = z <= - tol;
    zpos       = z >= tol;
    
    if ( dualf(k) >= tol ) && ( tol2 < ub_N(k) - x_N(k) )
        ub_delta = ub_N(k) - x_N(k);
        
        % find index that gives the tightest upper bound
        if ~isempty(zind) 
            zind1 = zpos & c_B == -1 & lb_B < ubB;
            zind2 = zneg & c_B == 1  & ub_B > lbB;
            bounds(zpos) = lb_B(zpos);
            
            if any(zind1)
                bounds(zind1) =  ubB(zind1);
            end
            
            if any(zind2)
                bounds(zind2) = lbB(zind2);
            end
            
            tB = (x_B(zind) - bounds(zind))./ z(zind);
            [minUb, lv] = min(tB);
            
            % choose lv by the smallest-script rule 
            
            lv = zind(lv);
            if (lv ~= 0)  && (verbosity >= 5)
                disp( sprintf('  The leaving variable : \t %d.', basicVarIdx(lv)) );
            end
        end
        
        if minUb < ub_delta 
            delta = minUb;
            sameBasis = false;
        else 
            delta = ub_delta;
            sameBasis = true;    
        end
        
        % do the update on solution x_N and x_B
        if delta < inf && delta > tol2 
            x_N(k) = x_N(k) + delta;
            x_B    = x_B - delta * z;
        end
    elseif ( dualf(k) <= -tol )  &&  ( x_N(k) - lb_N(k) > tol2 )  
        
        ub_delta =  x_N(k) - lb_N(k);
        
        % Find the index that gives the tightest upper bound
        if ~isempty(zind)   
            zind1 = zpos & c_B == 1 & ub_B > lbB;
            zind2 = zneg & c_B == -1  & lb_B < ubB;
            bounds(zneg) = lb_B(zneg);
            
            if any(zind1)
                bounds(zind1) = lbB(zind1);
            end
            
            if any(zind2)
                bounds(zind2) = ubB(zind2);
            end
            
            tB = (bounds(zind) - x_B(zind))./ z(zind);
            [minUb, lv] = min(tB);
            % Choose by the smallest-script rule
            lv = zind(lv);
            if (lv ~= 0)  && (verbosity >= 5)
                disp( sprintf('  The leaving variable : \t %d.', basicVarIdx(lv)) );
            end
            
        end
        
        if minUb < ub_delta   
            delta = minUb;
            sameBasis = false;
        else  
            delta = ub_delta;
            sameBasis = true;
        end
        
        % Update the solution x_N and x_B
        if delta < inf && delta > tol2
            x_N(k) = x_N(k) - delta;
            x_B = x_B + delta * z;
        end
        
    end % if ( dualf(k) >= tol ) && ( tol2 < ub_N(k) - x_N(k) )
    
    if ( abs(dualf(k)) >= tol )
        if delta == inf
            exitflag = Unbounded;
            % Set the delta to be 1.0e+16 in unbounded case.
            delta = 1.0e+16;
            if dualf(k) >= tol
                x_N(k) = x_N(k) + delta;
                x_B = x_B - delta * z;
            elseif dualf(k) <= -tol
                x_N(k) = x_N(k) - delta;
                x_B = x_B + delta * z;
            end
            xsol = [x_B; x_N];
            [tmp, order] = sort([basicVarIdx; nonbasicVarIdx]);
            xsol = xsol(order);
            % Note niters is updated but the last iteration is not executed
            % completely, so niters needs to be adjusted by -1.
            niters = niters - 1;
            return;     
        elseif  abs(delta) < tol2
            dcount = nnz( x_B == lb_B | x_B == ub_B);
            if verbosity >= 5
                disp( sprintf('******%8d degenerating already', dcount ) );
            end
        elseif  delta == ( ub_N(k) - lb_N(k) )
            sameBasis = true; 
        else % sameBasis = false already
        end
    else % This should never occur
        xsol = [x_B; x_N];  
        error('optim:simplexpiecewise:WrongEnteringVar', ...
              'The choice of the entering variable is wrong.');
    end
    
    % Both the entering variable and the leaving variable exist:
    % update x_B(lv) and x_N(k) 
    % update B, N, basicVarIdx, nonbasicVarIdx and c_B, c_N; ub_B, lb_B; and ub_N, lb_N.
    if ~sameBasis 
        
        N(:,k)   = B(:, lv);
        B(:,lv)   = N_k;
        
        swaptmp  = basicVarIdx(lv);
        basicVarIdx(lv) = nonbasicVarIdx(k);
        nonbasicVarIdx(k) = swaptmp;
        
        swaptmp  = c_B(lv); 
        c_B(lv)   = c_N(k);
        c_N(k)   = swaptmp; 
        
        swaptmp  = ub_B(lv);
        ub_B(lv)  = ub_N(k);
        ub_N(k)  = swaptmp;
        
        swaptmp  = lb_B(lv);
        lb_B(lv)  = lb_N(k);
        lb_N(k)  = swaptmp;
        
        swaptmp  = x_B(lv);
        x_B(lv)   = x_N(k);
        x_N(k)   = swaptmp;
        
    end % if ~sameBasis
    
    % Detect the following two cases to update the objective function and 
    % to restore the original bounds to the corresponding variables.
    % Case 1. The value of some x_i, which was less than its original lower bound, 
    %         rises to its original lower bound.
    %         Update the objective function c_B & c_N and restore the bounds lb_B & lb_N
    rstlbB = (c_B == 1) & (x_B >= lb(basicVarIdx)) &  (x_B <= ub(basicVarIdx));
    if any(rstlbB)
        c_B(rstlbB)  = 0;
        lb_B(rstlbB) = lb(basicVarIdx(rstlbB));
        if verbosity >= 5
            disp( sprintf('  Reset c_B and lb_B with index %d.', basicVarIdx(rstlbB)) );
        end
    end
    rstlbN = (c_N == 1) & (x_N >= lb(nonbasicVarIdx)) & (x_N <= ub(nonbasicVarIdx));
    if  any(rstlbN)
        c_N(rstlbN)  = 0;
        lb_N(rstlbN) = lb(nonbasicVarIdx(rstlbN));
        if verbosity >= 5
            disp( sprintf('  Reset c_N and lb_N with index %d.', nonbasicVarIdx(rstlbN)) );
        end
    end
    
    % Case 2. the value of some x_i, which was greater than its original upper bound, 
    %         drops to its original upper bound.
    %         update the objective function c_B & c_N and restore the
    %         bounds ub_B & ub_N.
    rstubB = (c_B == -1) & (x_B <= ub(basicVarIdx)) & (x_B >= lb(basicVarIdx));
    if any(rstubB) 
        c_B(rstubB)  = 0;
        ub_B(rstubB) = ub(basicVarIdx(rstubB));
        if verbosity >= 5
            disp( sprintf('  Reset c_B and lb_B with index %d.', basicVarIdx(rstubB)) );
        end
    end
    rstubN = (c_N == -1) & (x_N <= ub(nonbasicVarIdx)) & (x_N >= lb(nonbasicVarIdx));
    if any(rstubN)
        c_N(rstubN)  = 0;
        ub_N(rstubN) = ub(nonbasicVarIdx(rstubN));
        if verbosity >= 5 
            disp( sprintf('  Reset c_N and lb_N with index %d.', nonbasicVarIdx(rstubN)) );
        end
    end
    
    xsol = [x_B; x_N];
    if verbosity >= 5
        fcheck = max( abs( A(:, basicVarIdx)*xsol(1:m) + A(:,nonbasicVarIdx)*xsol(m+1: n) - b ) );  
        if fcheck > tol2
            disp( sprintf('Feasibility is broken in SIMPLEXPHASETWO by %e.', fcheck) );       
        end
    end
    
    fval = c_B' * x_B + c_N' * x_N;
    if verbosity >= 2
        disp( sprintf('%8d             %12.6g', niters, full(-fval)) );
        if verbosity >= 5
            disp('    [basicVarIdx    c_B     x_B     lb_B     ub_B     z] = ');
            disp(full([basicVarIdx    c_B     x_B     lb_B     ub_B     z]) );
            disp('    [nonbasicVarIdx    c_N     x_N     lb_N     ub_N     dualf] = ');
            disp(full([nonbasicVarIdx    c_N     x_N     lb_N     ub_N     dualf]) );
            disp( sprintf('\n*********************************') );
        end
    end   
    
end % while (exitflag == Unset) && (niters < maxiter) && (fval <= -tol)

% Phase 1 reached the maximum iteration number, but did not converge yet.
if ((niters == maxiter) && (exitflag == Unset))
    exitflag = ExcdMaxiter;
end
