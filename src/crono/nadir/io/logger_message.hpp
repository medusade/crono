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
///   File: logger_message.hpp
///
/// Author: $author$
///   Date: 5/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_IO_LOGGER_MESSAGE_HPP
#define _CRONO_NADIR_IO_LOGGER_MESSAGE_HPP

#include "crono/nadir/io/logger_location.hpp"

namespace crono {
namespace io {

typedef char_string::Implements logger_messaget_implements;
typedef char_string logger_messaget_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger_messaget
///////////////////////////////////////////////////////////////////////
template
<class TImplements = logger_messaget_implements,
 class TExtends = logger_messaget_extends>

class _EXPORT_CLASS logger_messaget
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger_messaget& operator << (const char_string& str) { this->append(str); return *this; }
    logger_messaget& operator << (const char* chars) { this->append(chars); return *this; }
    logger_messaget& operator << (int n) { this->append_signed(n); return *this; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef logger_messaget<> logger_message;

} // namespace io 
} // namespace crono 

#endif // _CRONO_NADIR_IO_LOGGER_MESSAGE_HPP 
