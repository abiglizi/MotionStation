/** @file wildcard.h
 *
 *  Interface to GiNaC's wildcard objects. */

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

#ifndef __GINAC_WILDCARD_H__
#define __GINAC_WILDCARD_H__

#include "ex.h"

namespace GiNaC {


/** This class acts as a wildcard for subs(), match(), has() and find(). An
 *  integer label is used to identify different wildcards. */
class wildcard : public basic
{
	GINAC_DECLARE_REGISTERED_CLASS(wildcard, basic)

	// other constructors
public:
	/** Construct wildcard with specified label. */
	wildcard(unsigned label);

	// functions overriding virtual functions from base classes
public:
	bool match(const ex & pattern, lst & repl_lst) const;

protected:
	unsigned calchash() const;

	// non-virtual functions in this class
public:
	unsigned get_label() const {return label;}

protected:
	void do_print(const print_context & c, unsigned level) const;
	void do_print_tree(const print_tree & c, unsigned level) const;
	void do_print_python_repr(const print_python_repr & c, unsigned level) const;

	// member variables
private:
	unsigned label; /**< Label used to distinguish different wildcards */
};


// utility functions

/** Create a wildcard object with the specified label. */
inline ex wild(unsigned label = 0)
{
	return wildcard(label);
}

/** Check whether x has a wildcard anywhere as a subexpression. */
bool haswild(const ex & x);

} // namespace GiNaC

#endif // ndef __GINAC_WILDCARD_H__
