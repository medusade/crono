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
///   Date: 5/5/2017
///////////////////////////////////////////////////////////////////////
#include "crono/nadir/console/main_main.hpp"
#include "crono/nadir/mt/logger.hpp"
#include "crono/nadir/mt/os/mutex.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char** env) {
    int err = 1;
    ::crono::console::main* main = 0;

    CRONO_CERR_LOG_DEBUG("crono::console::main::get_the_main()...");
    if ((main = crono::console::main::get_the_main())) {
        try {
            ::crono::mt::os::mutex mutex;
            ::crono::mt::logger logger(mutex);

            CRONO_LOGGER_INIT();
            err = (*main)(argc, argv, env);
            CRONO_LOGGER_FINI();
        } catch (const nadir::create_exception& e) {
            CRONO_CERR_LOG_ERROR("...caught nadir::create_exception& e status = " << e.status() << "");
        }
    } else {
        CRONO_CERR_LOG_ERROR("...failed 0 = crono::console::main::get_the_main()");
    }
    return err;
}
