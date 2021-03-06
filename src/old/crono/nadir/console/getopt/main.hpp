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
///   File: main.hpp
///
/// Author: $author$
///   Date: 5/5/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_CONSOLE_GETOPT_MAIN_HPP
#define _CRONO_NADIR_CONSOLE_GETOPT_MAIN_HPP

#include "crono/nadir/console/main.hpp"
#include "nadir/console/getopt/main.hpp"

namespace crono {
namespace console {
namespace getopt {

typedef console::maint_implements maint_implements;
typedef nadir::console::getopt::main_baset
<maint_implements, console::main> maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = maint_implements, class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef maint<> main;

} // namespace getopt 
} // namespace console 
} // namespace crono 

#endif // _CRONO_NADIR_CONSOLE_GETOPT_MAIN_HPP 
