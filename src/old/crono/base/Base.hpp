///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 9/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_BASE_BASE_HPP
#define _CRONO_BASE_BASE_HPP

#if !defined(USE_PATRONA_BASE)
#include "crono/base/nadir/Base.hpp"
#else //  !defined(USE_PATRONA_BASE)
#endif // !defined(USE_PATRONA_BASE)

#if defined(_MSC_VER)
#if !defined(DEBUG_BUILD) && !defined(RELEASE_BUILD)
#if defined(_DEBUG)
#define DEBUG_BUILD
#else // defined(_DEBUG)
#define RELEASE_BUILD
#endif // defined(_DEBUG)
#endif // !defined(DEBUG_BUILD) && !defined(RELEASE_BUILD)
#endif // defined(_MSC_VER)

#if !defined(CRONO_CONFIG)
#if defined(DEBUG_BUILD)
#define CRONO_CONFIG Debug
#else // defined(DEBUG_BUILD)
#define CRONO_CONFIG Release
#endif // defined(DEBUG_BUILD)
#endif // !defined(CRONO_CONFIG)

namespace crono {

inline const pointer_t& to_pointer(const pointer_t& v) { return v; }
inline const unsigned_t& to_unsigned(const unsigned_t& v) { return v; }
inline const signed_t& to_signed(const signed_t& v) { return v; }
inline const byte_t& to_byte(const byte_t& v) { return v; }
inline const wchar_t& to_wchar(const wchar_t& v) { return v; }
inline const tchar_t& to_tchar(const tchar_t& v) { return v; }
inline const char& to_char(const char& v) { return v; }
inline const bool& to_bool(const bool& v) { return v; }

} // namespace crono

#endif // _CRONO_BASE_BASE_HPP 
