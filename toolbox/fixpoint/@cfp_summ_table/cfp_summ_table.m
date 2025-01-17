function c=cfp_summ_table(varargin)
%Summary Table
%   This component inserts a table which lists several
%   Fixed-Point blocks and their properties.
%
%   See also CSL_SUMM_TABLE, RPT_SUMM_TABLE

% Copyright 1994-2002 The MathWorks, Inc.
%   $Revision: 1.7 $  $Date: 2002/04/10 16:56:09 $

r=rpt_summ_table;

r=set_table(r,...
   'fpBlock',...
   'cfp_blk_loop',...
   'propfixpt',...
   {'Name','DataType','MinLim','MaxLim'},...
   'Fixed-Point Block',...
   [],...
   'Block');

c=rptgenutil('EmptyComponentStructure','cfp_summ_table');

c=class(c,c.comp.Class,...
   rptcomponent,...
   rptfpmethods,...
   zslmethods,...
   r);

c=buildcomponent(c,varargin{:});

if ~isempty(varargin)
   c=refresh_loop_comps(c.rpt_summ_table,c);
end
