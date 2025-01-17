/* $Revision: 1.2 $ */
/*
	locale.h
	Values appropriate for the formatting of monetary and other
	numeric quantities.
*/
#ifndef _LOCALE_H_
#define _LOCALE_H_

#include "_ansi.h"

#ifndef NULL
#define NULL    0L
#endif

#define LC_ALL	    0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5

struct lconv
{
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
};
char *setlocale(int category, const char *locale);
struct lconv *localeconv(void);
struct _reent;
char *_setlocale_r(struct _reent *, int category, const char *locale);
struct lconv *_localeconv_r(struct _reent *);
#endif /* _LOCALE_H_ */
