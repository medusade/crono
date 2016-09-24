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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 9/22/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_APP_CONSOLE_HELLO_MAIN_HPP
#define _CRONO_APP_CONSOLE_HELLO_MAIN_HPP

#include "crono/console/Main.hpp"
#include "crono/io/Logger.hpp"

namespace crono {
namespace app {
namespace console {
namespace hello {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: public crono::console::Main {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t **argv, char_t **env) {
        CRONO_LOG_DEBUG("OutLn(\"Hello\")...");
        OutLn("Hello");
        return 0;
    }
};

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace crono 

#endif // _CRONO_APP_CONSOLE_HELLO_MAIN_HPP 
