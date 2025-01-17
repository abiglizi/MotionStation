function out=getinfo(c)
%GETINFO returns a structure containing information about the component
%   I=GETINFO(CSF_SUMM_TABLE)
%
%   I.Name - component informal name
%   I.Type - component general category 2-letter code
%   I.Desc - short description of the component
%   I.ValidChildren - shows whether or not component can have children
%          ValidChildren={logical(0)} for no children
%          ValidChildren={logical(1)} if children are allowed
%   I.att - component attributes
%   I.attx - information about component attributes
%   I.ref - reference structure
%   I.x - temporary attribute page handle structure


%   Copyright 1997-2004 The MathWorks, Inc.
%   $Revision: 1.1.6.2 $  $Date: 2004/04/15 00:18:39 $

persistent RPTGEN_GETINFO_STRUCTURE
if isempty(RPTGEN_GETINFO_STRUCTURE)
   out=getprotocomp(c);
   
   out.Name = xlate('Object Summary Table');
   out.Type = 'SF';
   out.Desc = xlate('Shows properties of several Stateflow objects in one table.');
   
   [out.att,out.attx]=get_summ_attribute(c.rpt_summ_table);
   
   out.att.ObjectType='Chart';
  
   
   RPTGEN_GETINFO_STRUCTURE=out;
   
else
   out=RPTGEN_GETINFO_STRUCTURE;
end
