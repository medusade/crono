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
///   File: Message.hpp
///
/// Author: $author$
///   Date: 8/8/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_MESSAGE_HPP
#define _XOS_LOGGER_MESSAGE_HPP

#include "xos/logger/Location.hpp"

namespace xos {
namespace logger {

typedef StringImplements MessageImplements;
typedef String MessageExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Message
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Message
: virtual public MessageImplements, public MessageExtends {
public:
    typedef MessageImplements Implements;
    typedef MessageExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: Message
    ///////////////////////////////////////////////////////////////////////
    Message() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Message& operator << (const Extends& str) { append(str.c_str()); return *this; }
    Message& operator << (const char* chars) { append(chars); return *this; }
    Message& operator << (int i) {
        String::from_signed from(i);
        String s(from);
        append(s);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace logger 
} // namespace xos 

#endif // _XOS_LOGGER_MESSAGE_HPP 
