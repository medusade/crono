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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 6/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_BASE_NADIR_BASE_HPP
#define _CRONO_BASE_NADIR_BASE_HPP

#include "nadir/base/string.hpp"
#include "nadir/base/base.hpp"

namespace crono {

typedef ::nadir::pointer_t pointer_t;
typedef ::nadir::unsigned_t unsigned_t;
typedef ::nadir::signed_t signed_t;

typedef ::nadir::implement_base ImplementBase;
typedef ::nadir::base Base;

typedef ::nadir::char_string String;
typedef ::nadir::tchar_string TString;
typedef ::nadir::wchar_string WString;

} // namespace crono

#endif // _CRONO_BASE_NADIR_BASE_HPP 
