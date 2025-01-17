## Copyright (C) 2002 Etienne Grossmann <etienne@egdn.net>
##
## This program is free software; you can redistribute it and/or modify it under
## the terms of the GNU General Public License as published by the Free Software
## Foundation; either version 3 of the License, or (at your option) any later
## version.
##
## This program is distributed in the hope that it will be useful, but WITHOUT
## ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
## FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
## details.
##
## You should have received a copy of the GNU General Public License along with
## this program; if not, see <http://www.gnu.org/licenses/>.

## v = vrml_group (s1, s2 ... ) - Form a group node with children s1,...

function v = vrml_group ( varargin )

if nargin == 0, return end

s = "";

				# beginpre 2.1.38
## if (nargin > 0) 
##   varargin = list(varargin, all_va_args); 
## end
				# endpre 2.1.38
if nargin > 0, s = varargin{1}; end
if nargin > 1
  for i = 2:nargin, s = [s,",\n", varargin{i}]; end
end
## indent s
ni = 4;
s = [blanks(ni), strrep(s,"\n",["\n",blanks(ni)])(:)'];

v = sprintf (["Group {\n",\
              "  children [\n",\
	      "%s",\
              " ]\n",\
	      "}\n"],\
	     s);
endfunction

