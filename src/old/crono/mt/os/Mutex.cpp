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
///   File: Mutex.cpp
///
/// Author: $author$
///   Date: 9/23/2016
///////////////////////////////////////////////////////////////////////
#include "crono/mt/os/Mutex.hpp"

#if defined(WINDOWS)
// Windows
#include "crono/mt/microsoft/windows/Mutex.cpp"
#elif defined(MACOSX)
// MacOSX
#include "crono/mt/apple/osx/Mutex.cpp"
#else // defined(WINDOWS)
// Unix
#include "crono/mt/posix/Mutex.cpp"
#endif // defined(WINDOWS)

namespace crono {
namespace mt {
namespace os {

} // namespace os 
} // namespace mt 
} // namespace crono 
