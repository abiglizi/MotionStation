## Copyright (C) 2008 simone pernice
## 
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

## __invertSingleInt__ return 1 / the given interval (which must not take the 0)

## Author: simone pernice
## Created: 2008-08-18

function ret = __invertSingleInt__ (int)
  if (int(1) <= 0 && int(2) >= 0)
    error ("It is not possible to invert an interval containing 0");
  endif
  ret = 1 ./ int;
  ret = __checkInt__ (ret);
endfunction
