///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Base.hpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_BASE_BASE_HPP
#define _CRONO_BASE_BASE_HPP

#include "patrona/base/Base.hpp"

namespace crono {

typedef ::patrona::pointer_t pointer_t;
typedef ::patrona::unsigned_t unsigned_t;
typedef ::patrona::signed_t signed_t;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef ::patrona::implement_base implement_base;
typedef ::patrona::base base;

typedef ::patrona::char_string char_string;
typedef ::patrona::tchar_string tchar_string;
typedef ::patrona::wchar_string wchar_string;

typedef ::patrona::ImplementBase ImplementBase;
typedef ::patrona::Base Base;

typedef ::patrona::String String;
typedef ::patrona::TString TString;
typedef ::patrona::WString WString;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef ::patrona::bool_to_string bool_to_string;
typedef ::patrona::bool_to_tstring bool_to_tstring;
typedef ::patrona::bool_to_wstring bool_to_wstring;

typedef ::patrona::chars_to_string chars_to_string;
typedef ::patrona::chars_to_tstring chars_to_tstring;
typedef ::patrona::chars_to_wstring chars_to_wstring;

typedef ::patrona::int_to_string int_to_string;
typedef ::patrona::int_to_tstring int_to_tstring;
typedef ::patrona::int_to_wstring int_to_wstring;

typedef ::patrona::signed_to_string signed_to_string;
typedef ::patrona::signed_to_tstring signed_to_tstring;
typedef ::patrona::signed_to_wstring signed_to_wstring;

typedef ::patrona::unsigned_to_string unsigned_to_string;
typedef ::patrona::unsigned_to_tstring unsigned_to_tstring;
typedef ::patrona::unsigned_to_wstring unsigned_to_wstring;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline const pointer_t& to_pointer(const pointer_t& v) { return v; }
inline const unsigned_t& to_unsigned(const unsigned_t& v) { return v; }
inline const signed_t& to_signed(const signed_t& v) { return v; }
inline const byte_t& to_byte(const byte_t& v) { return v; }
inline const wchar_t& to_wchar(const wchar_t& v) { return v; }
inline const tchar_t& to_tchar(const tchar_t& v) { return v; }
inline const char& to_char(const char& v) { return v; }
inline const bool& to_bool(const bool& v) { return v; }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
inline seconds_t mseconds_seconds
(mseconds_t mseconds) { return nadir::mseconds_seconds(mseconds); }

inline mseconds_t mseconds_mseconds
(mseconds_t mseconds) { return nadir::mseconds_mseconds(mseconds); }

inline useconds_t mseconds_useconds
(mseconds_t mseconds) { return nadir::mseconds_useconds(mseconds); }

inline nseconds_t mseconds_nseconds
(mseconds_t mseconds) { return nadir::mseconds_nseconds(mseconds); }

} // namespace crono

#endif // _CRONO_BASE_BASE_HPP 
