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
///   Date: 8/14/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_MT_HELLO_MAIN_HPP
#define _XOS_APP_CONSOLE_MT_HELLO_MAIN_HPP

#include "xos/app/console/mt/hello/MainOpt.hpp"
#include "crono/app/console/mt/hello/Main.hpp"
#include "xos/mt/os/Mutex.hpp"

namespace xos {
namespace app {
namespace console {
namespace mt {
namespace hello {

typedef crono::app::console::mt::hello::MainImplements MainImplements;
typedef crono::app::console::mt::hello::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main
: virtual public MainOpt, virtual public MainImplements, public MainExtends {
public:
    typedef MainOpt OptImplements;
    typedef MainImplements Implements;
    typedef MainExtends Extends;
    typedef typename Implements::char_t char_t;
    typedef typename Implements::endchar_t endchar_t;
    static const endchar_t endchar = Implements::endchar;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: Main
    ///////////////////////////////////////////////////////////////////////
    Main() {
    }
    virtual ~Main() {
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
    virtual int AfterRun(int argc, char_t**argv, char_t** env) {
        int err = 0;
        xos::mt::os::Mutex mutex;
        return err;
    }
};

} // namespace hello
} // namespace mt 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_MT_HELLO_MAIN_HPP 
