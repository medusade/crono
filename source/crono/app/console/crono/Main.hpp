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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_APP_CONSOLE_CRONO_MAIN_HPP
#define _CRONO_APP_CONSOLE_CRONO_MAIN_HPP

#include "crono/console/lib/crono/version/Main.hpp"

namespace crono {
namespace app {
namespace console {
namespace crono {

typedef ::crono::console::lib::crono::version::Main::Implements MainImplements;
typedef ::crono::console::lib::crono::version::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;
    typedef Main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main(): m_run(0) {
    }
    virtual ~Main() {
    }
private:
    Main(const Main& copy) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*m_run)(int argc, char_t**argv, char_t** env);
    virtual int Run(int argc, char_t**argv, char_t** env) {
        int err = 0;
        if ((m_run)) {
            LOG_DEBUG("(this->*m_run)(argc, argv, env)...");
            err = (this->*m_run)(argc, argv, env);
            LOG_DEBUG("..." << err << " = (this->*m_run)(argc, argv, env)...");
        } else {
            LOG_DEBUG("Extends::Run(argc, argv, env)...");
            err = Extends::Run(argc, argv, env);
            LOG_DEBUG("..." << err << " = Extends::Run(argc, argv, env)");
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS Main

} /// namespace crono
} /// namespace console
} /// namespace app
} /// namespace crono

#endif ///ndef _CRONO_APP_CONSOLE_CRONO_MAIN_HPP
