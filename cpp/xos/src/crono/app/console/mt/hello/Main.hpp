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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 8/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_APP_CONSOLE_MT_HELLO_MAIN_HPP
#define _CRONO_APP_CONSOLE_MT_HELLO_MAIN_HPP

#include "crono/app/console/mt/hello/MainOpt.hpp"
#include "crono/console/mt/getopt/Main.hpp"
#include "fila/app/console/mt/hello/Main.hpp"

namespace crono {
namespace app {
namespace console {
namespace mt {
namespace hello {

typedef crono::console::mt::getopt::MainImplements MainImplements;
typedef nadir::app::console::hello::MainT
<MainOpt, MainImplements, crono::console::mt::getopt::Main> MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TOptImplements = MainOpt,
 class TImplements = MainImplements, class TExtends = MainExtends>

class _EXPORT_CLASS MainT
: virtual public TOptImplements, virtual public TImplements, public TExtends {
public:
    typedef TOptImplements OptImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Implements::char_t char_t;
    typedef typename Implements::endchar_t endchar_t;
    static const endchar_t endchar = Implements::endchar;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: MainT
    ///////////////////////////////////////////////////////////////////////
    MainT() {
    }
    virtual ~MainT() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    /// Function: RunHello
    ///////////////////////////////////////////////////////////////////////
    virtual int RunHello(int argc, char_t**argv, char_t** env) {
        int err = 0;
        err = Extends::RunHello(argc, argv, env);
        return err;
    }
};
typedef MainT<> Main;

} // namespace hello
} // namespace mt 
} // namespace console 
} // namespace app 
} // namespace crono 

#endif // _CRONO_APP_CONSOLE_MT_HELLO_MAIN_HPP 
