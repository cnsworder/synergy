/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2012 Bolton Software Ltd.
 * Copyright (C) 2002 Chris Schoeneman
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file COPYING that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "common/common.h"
#include "common/stdstring.h"

#include <stdarg.h>

// use standard C++ string class for our string class
typedef std::string String;

namespace synergy {

//! String utilities
/*!
Provides functions for string manipulation.
*/
namespace string {

//! Format positional arguments
/*!
Format a string using positional arguments.  fmt has literal
characters and conversion specifications introduced by `\%':
- \%\%  -- literal `\%'
- \%{n} -- positional element n, n a positive integer, {} are literal

All arguments in the variable list are const char*.  Positional
elements are indexed from 1.
*/
String format(const char* fmt, ...);

//! Format positional arguments
/*!
Same as format() except takes va_list.
*/
String vformat(const char* fmt, va_list);

//! Print a string using sprintf-style formatting
/*!
Equivalent to sprintf() except the result is returned as a String.
*/
String sprintf(const char* fmt, ...);

//! Find and replace all
/*!
Finds \c find inside \c subject and replaces it with \c replace
*/
void findReplaceAll(String& subject, const String& find, const String& replace);

//! Case-insensitive comparisons
/*!
This class provides case-insensitve comparison functions.
*/
class CaselessCmp {
	public:
	//! Same as less()
	bool			operator()(const String& a, const String& b) const;

	//! Returns true iff \c a is lexicographically less than \c b
	static bool		less(const String& a, const String& b);

	//! Returns true iff \c a is lexicographically equal to \c b
	static bool		equal(const String& a, const String& b);

	//! Returns true iff \c a is lexicographically less than \c b
	static bool		cmpLess(const String::value_type& a,
						const String::value_type& b);

	//! Returns true iff \c a is lexicographically equal to \c b
	static bool		cmpEqual(const String::value_type& a,
						const String::value_type& b);
};

}
}
