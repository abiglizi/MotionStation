/** @file fderivative.h
 *
 *  Interface to abstract derivatives of functions. */

/*
 *  GiNaC Copyright (C) 1999-2008 Johannes Gutenberg University Mainz, Germany
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __GINAC_FDERIVATIVE_H__
#define __GINAC_FDERIVATIVE_H__

#include <set>

#include "function.h"

namespace GiNaC {


typedef std::multiset<unsigned> paramset;

/** This class represents the (abstract) derivative of a symbolic function.
 *  It is used to represent the derivatives of functions that do not have
 *  a derivative or series expansion procedure defined. */
class fderivative : public function
{
	GINAC_DECLARE_REGISTERED_CLASS(fderivative, function)

	// other constructors
public:
	/** Construct derivative with respect to one parameter.
	 *
	 *  @param ser Serial number of function
	 *  @param param Number of parameter with respect to which to take the derivative
	 *  @param args Arguments of derivative function */
	fderivative(unsigned ser, unsigned param, const exvector & args);

	/** Construct derivative with respect to multiple parameters.
	 *
	 *  @param ser Serial number of function
	 *  @param params Set of numbers of parameters with respect to which to take the derivative
	 *  @param args Arguments of derivative function */
	fderivative(unsigned ser, const paramset & params, const exvector & args);

	// internal constructors
	fderivative(unsigned ser, const paramset & params, std::auto_ptr<exvector> vp);

	// functions overriding virtual functions from base classes
public:
	void print(const print_context & c, unsigned level = 0) const;
	ex eval(int level = 0) const;
	ex evalf(int level = 0) const;
	ex series(const relational & r, int order, unsigned options = 0) const;
	ex thiscontainer(const exvector & v) const;
	ex thiscontainer(std::auto_ptr<exvector> vp) const;
protected:
	ex derivative(const symbol & s) const;
	bool is_equal_same_type(const basic & other) const;
	bool match_same_type(const basic & other) const;

	// non-virtual functions in this class
protected:
	void do_print(const print_context & c, unsigned level) const;
	void do_print_csrc(const print_csrc & c, unsigned level) const;
	void do_print_tree(const print_tree & c, unsigned level) const;

	// member variables
protected:
	paramset parameter_set; /**< Set of parameter numbers with respect to which to take the derivative */
};

} // namespace GiNaC

#endif // ndef __GINAC_DERIVATIVE_H__
