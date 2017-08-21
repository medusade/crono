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
///   File: Logger.hpp
///
/// Author: $author$
///   Date: 8/14/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_LOGGER_HPP
#define _XOS_MT_LOGGER_HPP

#include "xos/logger/Interface.hpp"

namespace xos {
namespace mt {

typedef logger::BaseImplements LoggerImplements;
typedef logger::Base LoggerExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Logger
: virtual public LoggerImplements, public LoggerExtends {
public:
    typedef LoggerImplements Implements;
    typedef LoggerExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: Logger
    ///////////////////////////////////////////////////////////////////////
    Logger(xos::Locked& locked, logger::Level level): Extends(locked, level) {
    }
    Logger(xos::Locked& locked): Extends(locked) {
    }
    Logger(logger::Level level): Extends(level) {
    }
    Logger(const Logger& copy): Extends(copy) {
    }
    Logger() {
    }
    virtual ~Logger() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_LOGGER_HPP 
