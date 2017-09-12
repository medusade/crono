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
///   File: message.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_MESSAGE_HPP
#define _XOS_LOGGER_MESSAGE_HPP

#include "xos/logger/location.hpp"

namespace xos {
namespace logger {

typedef string_implements message_implements;
typedef string message_extends;
///////////////////////////////////////////////////////////////////////
///  class: message
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS message
: virtual public message_implements, public message_extends {
public:
    typedef message_implements implements;
    typedef message_extends extends;
    ///////////////////////////////////////////////////////////////////////
    /// constructor: message
    ///////////////////////////////////////////////////////////////////////
    message() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    message& operator << (const extends& str) { append(str.c_str()); return *this; }
    message& operator << (const char* chars) { append(chars); return *this; }
    message& operator << (int i) {
        string::from_signed from(i);
        string s(from);
        append(s);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace logger
} // namespace xos 

#endif // _XOS_LOGGER_MESSAGE_HPP 
