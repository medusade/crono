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
///   File: Main_main.cpp
///
/// Author: $author$
///   Date: 9/23/2016
///////////////////////////////////////////////////////////////////////
#include "crono/console/Main_main.hpp"
#include "crono/mt/os/Mutex.hpp"
#include "crono/mt/Logger.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char** env) {
    int err = 0;
    ::crono::mt::os::Mutex locked;
    ::crono::mt::Logger logger(locked);

    CRONO_SET_DEFAULT_LOGGER(&logger);

    CRONO_LOGGER_INIT();

    CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_DEFAULT);

    ::crono::console::Main::TheMain(argc, argv, env);

    CRONO_LOGGER_FINI();
    return err;
}
