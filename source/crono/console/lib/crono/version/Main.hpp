///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   Date: 2/24/2019
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_CONSOLE_LIB_CRONO_VERSION_MAIN_HPP
#define _CRONO_CONSOLE_LIB_CRONO_VERSION_MAIN_HPP

#include "patrona/console/lib/version/Main.hpp"
#include "crono/lib/crono/Version.hpp"
#include "crono/console/getopt/Main.hpp"

namespace crono {
namespace console {
namespace lib {
namespace crono {
namespace version {

typedef ::crono::lib::crono::Version MainTVersion;
typedef ::patrona::console::lib::version::MainT
<MainTVersion, 
 ::crono::console::getopt::Main::Implements, 
 ::crono::console::getopt::Main> MainTExtends;
typedef MainTExtends::Implements MainTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainTImplements, class TExtends = MainTExtends>
class _EXPORT_CLASS MainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT() {
    }
    virtual ~MainT() {
    }
private:
    MainT(const MainT& copy) {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS MainT
typedef MainT<> Main;

} /// namespace version
} /// namespace crono
} /// namespace lib
} /// namespace console
} /// namespace crono

#endif /// _CRONO_CONSOLE_LIB_CRONO_VERSION_MAIN_HPP 
