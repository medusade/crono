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
///   File: Os.hpp
///
/// Author: $author$
///   Date: 9/23/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_MT_OS_OS_HPP
#define _CRONO_MT_OS_OS_HPP

#include "crono/base/Base.hpp"

namespace crono {
namespace mt {
namespace microsoft { namespace windows { namespace crt { } } }
namespace apple { namespace osx { } }
namespace posix { }
namespace os {

#if defined(WINDOWS)
// Windows
namespace os = microsoft::windows;
#elif defined(MACOSX)
// MacOSX
namespace os = apple::osx;
#else // defined(WINDOWS)
// Unix
namespace os = posix;
#endif // defined(WINDOWS)

} // namespace os
} // namespace mt 
} // namespace crono 

#endif // _CRONO_MT_OS_OS_HPP 
        

