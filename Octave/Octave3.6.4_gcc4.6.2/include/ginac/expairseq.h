/** @file expairseq.h
 *
 *  Interface to sequences of expression pairs. */

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

#ifndef __GINAC_EXPAIRSEQ_H__
#define __GINAC_EXPAIRSEQ_H__

#include <vector>
#include <list>
#include <memory>
// CINT needs <algorithm> to work properly with <vector> and <list>
#include <algorithm>

#include "expair.h"
#include "indexed.h"

namespace GiNaC {

/** Using hash tables can potentially enhance the asymptotic behaviour of
 *  combining n terms into one large sum (or n terms into one large product)
 *  from O(n*log(n)) to about O(n).  There are, however, several drawbacks.
 *  The constant in front of O(n) is quite large, when copying such an object
 *  one also has to copy the has table, comparison is quite expensive because
 *  there is no ordering any more, it doesn't help at all when combining two
 *  expairseqs because due to the presorted nature the behaviour would be
 *  O(n) anyways, the code is quite messy, etc, etc.  The code is here as
 *  an example for following generations to tinker with. */
#define EXPAIRSEQ_USE_HASHTAB 0

typedef std::vector<expair> epvector;       ///< expair-vector
typedef epvector::iterator epp;             ///< expair-vector pointer
typedef std::list<epp> epplist;             ///< list of expair-vector pointers
typedef std::vector<epplist> epplistvector; ///< vector of epplist

/** Complex conjugate every element of an epvector. Returns zero if this
 *  does not change anything. */
epvector* conjugateepvector(const epvector&);

/** A sequence of class expair.
 *  This is used for time-critical classes like sums and products of terms
 *  since handling a list of coeff and rest is much faster than handling a
 *  list of products or powers, respectively. (Not incidentally, Maple does it
 *  the same way, maybe others too.)  The semantics is (at least) twofold:
 *  one for addition and one for multiplication and several methods have to
 *  be overridden by derived classes to reflect the change in semantics.
 *  However, most functionality turns out to be shared between addition and
 *  multiplication, which is the reason why there is this base class. */
class expairseq : public basic
{
	GINAC_DECLARE_REGISTERED_CLASS(expairseq, basic)

	// other constructors
public:
	expairseq(const ex & lh, const ex & rh);
	expairseq(const exvector & v);
	expairseq(const epvector & v, const ex & oc, bool do_index_renaming = false);
	expairseq(std::auto_ptr<epvector>, const ex & oc, bool do_index_renaming = false);
	
	// functions overriding virtual functions from base classes
public:
	unsigned precedence() const {return 10;}
	bool info(unsigned inf) const;
	size_t nops() const;
	ex op(size_t i) const;
	ex map(map_function & f) const;
	ex eval(int level=0) const;
	ex to_rational(exmap & repl) const;
	ex to_polynomial(exmap & repl) const;
	bool match(const ex & pattern, lst & repl_lst) const;
	ex subs(const exmap & m, unsigned options = 0) const;
	ex conjugate() const;
	bool is_polynomial(const ex & var) const;
protected:
	bool is_equal_same_type(const basic & other) const;
	unsigned return_type() const;
	unsigned calchash() const;
	ex expand(unsigned options=0) const;
	
	// new virtual functions which can be overridden by derived classes
protected:
	virtual ex thisexpairseq(const epvector & v, const ex & oc, bool do_index_renaming = false) const;
	virtual ex thisexpairseq(std::auto_ptr<epvector> vp, const ex & oc, bool do_index_renaming = false) const;
	virtual void printseq(const print_context & c, char delim,
	                      unsigned this_precedence,
	                      unsigned upper_precedence) const;
	virtual void printpair(const print_context & c, const expair & p,
	                       unsigned upper_precedence) const;
	virtual expair split_ex_to_pair(const ex & e) const;
	virtual expair combine_ex_with_coeff_to_pair(const ex & e,
												 const ex & c) const;
	virtual expair combine_pair_with_coeff_to_pair(const expair & p,
												   const ex & c) const;
	virtual ex recombine_pair_to_ex(const expair & p) const;
	virtual bool expair_needs_further_processing(epp it);
	virtual ex default_overall_coeff() const;
	virtual void combine_overall_coeff(const ex & c);
	virtual void combine_overall_coeff(const ex & c1, const ex & c2);
	virtual bool can_make_flat(const expair & p) const;
	
	// non-virtual functions in this class
protected:
	void do_print(const print_context & c, unsigned level) const;
	void do_print_tree(const print_tree & c, unsigned level) const;
	void construct_from_2_ex_via_exvector(const ex & lh, const ex & rh);
	void construct_from_2_ex(const ex & lh, const ex & rh);
	void construct_from_2_expairseq(const expairseq & s1,
	                                const expairseq & s2);
	void construct_from_expairseq_ex(const expairseq & s,
	                                 const ex & e);
	void construct_from_exvector(const exvector & v);
	void construct_from_epvector(const epvector & v, bool do_index_renaming = false);
	void make_flat(const exvector & v);
	void make_flat(const epvector & v, bool do_index_renaming = false);
	void canonicalize();
	void combine_same_terms_sorted_seq();
#if EXPAIRSEQ_USE_HASHTAB
	void combine_same_terms();
	unsigned calc_hashtabsize(unsigned sz) const;
	unsigned calc_hashindex(const ex & e) const;
	void shrink_hashtab();
	void remove_hashtab_entry(epvector::const_iterator element);
	void move_hashtab_entry(epvector::const_iterator oldpos,
	                        epvector::iterator newpos);
	void sorted_insert(epplist & eppl, epvector::const_iterator elem);
	void build_hashtab_and_combine(epvector::iterator & first_numeric,
	                               epvector::iterator & last_non_zero,
	                               vector<bool> & touched,
	                               unsigned & number_of_zeroes);
	void drop_coeff_0_terms(epvector::iterator & first_numeric,
	                        epvector::iterator & last_non_zero,
	                        vector<bool> & touched,
	                        unsigned & number_of_zeroes);
	bool has_coeff_0() const;
	void add_numerics_to_hashtab(epvector::iterator first_numeric,
	                             epvector::const_iterator last_non_zero);
#endif // EXPAIRSEQ_USE_HASHTAB
	bool is_canonical() const;
	std::auto_ptr<epvector> expandchildren(unsigned options) const;
	std::auto_ptr<epvector> evalchildren(int level) const;
	std::auto_ptr<epvector> subschildren(const exmap & m, unsigned options = 0) const;
	
// member variables
	
protected:
	epvector seq;
	ex overall_coeff;
#if EXPAIRSEQ_USE_HASHTAB
	epplistvector hashtab;
	unsigned hashtabsize;
	unsigned hashmask;
	static unsigned maxhashtabsize;
	static unsigned minhashtabsize;
	static unsigned hashtabfactor;
#endif // EXPAIRSEQ_USE_HASHTAB
};

/** Class to handle the renaming of dummy indices. It holds a vector of
 *  indices that are being used in the expression so-far. If the same
 *  index occurs again as a dummy index in a factor, it is to be renamed.
 *  Unless dummy index renaming was swichted of, of course ;-) . */
class make_flat_inserter
{
	public:
		make_flat_inserter(const epvector &epv, bool b): do_renaming(b)
		{
			if (!do_renaming)
				return;
			for (epvector::const_iterator i=epv.begin(); i!=epv.end(); ++i)
				if(are_ex_trivially_equal(i->coeff, 1))
					combine_indices(i->rest.get_free_indices());
		}
		make_flat_inserter(const exvector &v, bool b): do_renaming(b)
		{
			if (!do_renaming)
				return;
			for (exvector::const_iterator i=v.begin(); i!=v.end(); ++i)
				combine_indices(i->get_free_indices());
		}
		ex handle_factor(const ex &x, const ex &coeff)
		{
			if (!do_renaming)
				return x;
			exvector dummies_of_factor;
			if (is_a<numeric>(coeff) && coeff.is_equal(GiNaC::numeric(1)))
				dummies_of_factor = get_all_dummy_indices_safely(x);
			else if (is_a<numeric>(coeff) && coeff.is_equal(GiNaC::numeric(2)))
				dummies_of_factor = x.get_free_indices();
			else
				return x;
			if (dummies_of_factor.size() == 0)
				return x;
			sort(dummies_of_factor.begin(), dummies_of_factor.end(), ex_is_less());
			ex new_factor = rename_dummy_indices_uniquely(used_indices,
				dummies_of_factor, x);
			combine_indices(dummies_of_factor);
			return new_factor;
		}
	private:
		void combine_indices(const exvector &dummies_of_factor)
		{
			exvector new_dummy_indices;
			set_union(used_indices.begin(), used_indices.end(),
				dummies_of_factor.begin(), dummies_of_factor.end(),
				std::back_insert_iterator<exvector>(new_dummy_indices), ex_is_less());
			used_indices.swap(new_dummy_indices);
		}
		bool do_renaming;
		exvector used_indices;
};

} // namespace GiNaC

#endif // ndef __GINAC_EXPAIRSEQ_H__
