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
///   File: Main_main.cpp
///
/// Author: $author$
///   Date: 9/7/2017
///////////////////////////////////////////////////////////////////////
#include "crono/console/mt/Main_main.hpp"
#include "xos/mt/os/Mutex.hpp"
#include "xos/mt/Logger.hpp"

namespace crono {
namespace console {
namespace mt {

} // namespace mt 
} // namespace console 
} // namespace crono 

///////////////////////////////////////////////////////////////////////
/// Function: main
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char** env) {
    int err = 1;

    try {
        ::xos::mt::os::logger::Mutex mutex;
        ::xos::console::mt::Main::Locked locked(mutex);
        ::xos::mt::Logger logger(locked);

        XOS_ERR_LOG_DEBUG("xos::console::Main::TheMain(argc, argv, env)...");
        err = xos::console::Main::TheMain(argc, argv, env);
        XOS_ERR_LOG_DEBUG("...err = " << err << " on xos::console::Main::TheMain(argc, argv, env)...");
    } catch (const ::xos::CreateException& e) {
        XOS_ERR_LOG_ERROR("...caught ::xos::CreateException& e = \"" << e.StatusToChars() << "\"")
    }
    return err;
}
