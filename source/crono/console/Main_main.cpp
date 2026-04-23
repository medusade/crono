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
///   File: Main_main.cpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#include "crono/console/Main_main.hpp"
#include "crono/mt/os/Mutex.hpp"
#include "crono/mt/Logger.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main(int argc, char** argv, char** env) {
    int err = 1;

    ERR_LOG_DEBUG("try {...");
    try {
        ::crono::mt::os::Mutex locked;
        ::crono::mt::Logger logger(locked);
    
        ERR_LOG_DEBUG("CRONO_SET_DEFAULT_LOGGER(&logger)...");
        CRONO_SET_DEFAULT_LOGGER(&logger);
    
        ERR_LOG_DEBUG("CRONO_LOGGER_INIT()...");
        CRONO_LOGGER_INIT();
    
        ERR_LOG_DEBUG("CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_DEFAULT = " << CRONO_LOGGING_LEVELS_DEFAULT << ")...");
        CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_DEFAULT);
    
        ERR_LOG_DEBUG("::crono::console::Main::TheMain(argc, argv, env)...");
        err = ::crono::console::Main::TheMain(argc, argv, env);
        ERR_LOG_DEBUG("..." << err << " = ::crono::console::Main::TheMain(argc, argv, env)");
    
        ERR_LOG_DEBUG("CRONO_LOGGER_FINI()...");
        CRONO_LOGGER_FINI();
    
        ERR_LOG_DEBUG("...} try");
    } catch (...) {
        ERR_LOG_ERROR("...catch (...)");
    }
    return err;
}
