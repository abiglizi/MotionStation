## Copyright (C) 2006-2012 David Bateman
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
## @deftypefn {Function File} {} mex [options] file @dots{}
## Compile source code written in C, C++, or Fortran, to a MEX file.
## This is equivalent to @code{mkoctfile --mex [options] file}.
## @seealso{mkoctfile}
## @end deftypefn

function mex (varargin)
  args = {"--mex", varargin{:}};
  mkoctfile (args{:});
endfunction
