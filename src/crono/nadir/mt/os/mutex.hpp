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
///   File: mutex.hpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_MT_OS_MUTEX_HPP
#define _CRONO_NADIR_MT_OS_MUTEX_HPP

#include "crono/nadir/mt/os/os.hpp"

#if defined(WINDOWS)
// Windows
#include "crono/nadir/mt/microsoft/windows/mutex.hpp"
#elif defined(MACOSX)
// MacOSX
#include "crono/nadir/mt/apple/osx/mutex.hpp"
#else // defined(WINDOWS)
// Unix
#include "crono/nadir/mt/posix/mutex.hpp"
#endif // defined(WINDOWS)

namespace crono {
namespace mt {
namespace os {

typedef os::mutex mutex;

} // namespace os 
} // namespace mt 
} // namespace crono 

#endif // _CRONO_NADIR_MT_OS_MUTEX_HPP 
