## Copyright (C) 2007-2012 Thomas Treichl
##
## This file is part of Octave.
##
## Octave is free software; you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or (at
## your option) any later version.
##
## Octave is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with Octave; see the file COPYING.  If not, see
## <http://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {Function File} {} ismac ()
## Return true if Octave is running on a Mac OS X system and false otherwise.
## @seealso{isunix, ispc}
## @end deftypefn

function retval = ismac ()

  if (nargin == 0)
    retval = octave_config_info ("mac");
  else
    print_usage ();
  endif

endfunction

%!error ismac (1);
%!assert (islogical (ismac ()));
