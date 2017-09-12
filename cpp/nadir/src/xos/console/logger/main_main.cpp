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
///   File: main_main.cpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#include "xos/console/logger/main_main.hpp"
#include "xos/console/locked.hpp"
#include "xos/logger/interface.hpp"

namespace xos {
namespace console {
namespace logger {

} // namespace logger 
} // namespace console 
} // namespace xos 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char** env) {
    int err = 0;

    XOS_ERR_LOG_DEBUG("try {...");
    try {
        ::xos::unlocked unlocked;
        ::xos::console::locked locked(unlocked);
        ::xos::logger::base logger(locked);

        XOS_LOG_DEBUG("::xos::console::main::the_main(argc, argv, env)...");
        err = ::xos::console::main::the_main(argc, argv, env);
        XOS_LOG_DEBUG("...err = " << err << " on ::xos::console::main::the_main(argc, argv, env)");
    } catch(const ::xos::exception& e) {
        XOS_ERR_LOG_ERROR("...catch(const ::xos::exception& e = \"" << e.to_chars() << "\")");
    } // try
    XOS_ERR_LOG_DEBUG("...} // try");
    return err;
}
