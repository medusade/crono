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
///   File: Function.hpp
///
/// Author: $author$
///   Date: 8/8/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_FUNCTION_HPP
#define _XOS_LOGGER_FUNCTION_HPP

#include "xos/logger/Level.hpp"
#include "xos/base/String.hpp"

namespace xos {
namespace logger {

typedef StringImplements FunctionImplements;
typedef String FunctionExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Function
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Function
: virtual public FunctionImplements, public FunctionExtends {
public:
    typedef FunctionImplements Implements;
    typedef FunctionExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: Function
    ///////////////////////////////////////////////////////////////////////
    Function(const String& name): Extends(name) {
    }
    Function(const char* name): Extends(name) {
    }
    Function(const Function& copy): Extends(copy) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace logger 
} // namespace xos 

#endif // _XOS_LOGGER_FUNCTION_HPP 
