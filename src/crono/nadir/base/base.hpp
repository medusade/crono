///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: base.hpp
///
/// Author: $author$
///   Date: 5/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_BASE_BASE_HPP
#define _CRONO_NADIR_BASE_BASE_HPP

#include "nadir/base/base.hpp"
#include "nadir/base/locked.hpp"
#include "nadir/base/created.hpp"
#include "nadir/base/opened.hpp"
#include "nadir/base/chars.hpp"
#include "nadir/base/array.hpp"
#include "nadir/base/string.hpp"
#include "nadir/base/to_string.hpp"

namespace crono {

typedef nadir::implement_base implement_base;
typedef nadir::base base;

typedef nadir::chars_t chars_t;
typedef nadir::tchars_t tchars_t;
typedef nadir::wchars_t wchars_t;

typedef nadir::char_array char_array;
typedef nadir::tchar_array tchar_array;
typedef nadir::wchar_array wchar_array;

typedef nadir::char_string char_string;
typedef nadir::tchar_string tchar_string;
typedef nadir::wchar_string wchar_string;

typedef nadir::pointer_t pointer_t;
typedef nadir::unsigned_t unsigned_t;
typedef nadir::signed_t signed_t;

inline const pointer_t& to_pointer(const pointer_t& v) { return v; }
inline const unsigned_t& to_unsigned(const unsigned_t& v) { return v; }
inline const signed_t& to_signed(const signed_t& v) { return v; }
inline const wchar_t& to_wchar(const wchar_t& v) { return v; }
inline const tchar_t& to_tchar(const tchar_t& v) { return v; }
inline const char& to_char(const char& v) { return v; }
inline const bool& to_bool(const bool& v) { return v; }

typedef nadir::chars_to_string chars_to_string;
typedef nadir::chars_to_tstring chars_to_tstring;
typedef nadir::chars_to_wstring chars_to_wstring;

typedef nadir::locked locked;
typedef nadir::locker locker;
typedef nadir::lock_status lock_status;
const nadir::lock_status
    unlock_success     = nadir::unlock_success,
    lock_success       = nadir::lock_success,
    lock_failed        = nadir::lock_failed,
    lock_busy          = nadir::lock_busy,
    lock_interrupted   = nadir::lock_interrupted,
    lock_invalid       = nadir::lock_invalid,
    unlock_failed      = nadir::unlock_failed,
    unlock_busy        = nadir::unlock_busy,
    unlock_interrupted = nadir::unlock_interrupted,
    unlock_invalid     = nadir::unlock_invalid;

typedef nadir::creator creator;
typedef nadir::create_exception create_exception;
typedef nadir::create_status create_status;
const nadir::create_status
    destroy_success = nadir::destroy_success,
    create_success = nadir::create_success,
    create_failed = nadir::create_failed,
    destroy_failed = nadir::destroy_failed;

} // namespace crono

#endif // _CRONO_NADIR_BASE_BASE_HPP 
