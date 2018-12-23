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
///   Date: 6/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_IO_NADIR_LOGGER_HPP
#define _CRONO_IO_NADIR_LOGGER_HPP

#include "nadir/io/logger.hpp"

#define CRONO_CERR_LOG_ERROR STDERR_LOG_ERROR
#define CRONO_CERR_LOG_DEBUG STDERR_LOG_DEBUG
#define CRONO_CERR_LOG_TRACE STDERR_LOG_TRACE

#define CRONO_STDERR_LOG_ERROR STDERR_LOG_ERROR
#define CRONO_STDERR_LOG_DEBUG STDERR_LOG_DEBUG
#define CRONO_STDERR_LOG_TRACE STDERR_LOG_TRACE

#define CRONO_LOG_FATAL LOG_FATAL
#define CRONO_LOG_ERROR LOG_ERROR
#define CRONO_LOG_WARN  LOG_WARN
#define CRONO_LOG_INFO  LOG_INFO
#define CRONO_LOG_DEBUG LOG_DEBUG
#define CRONO_LOG_TRACE LOG_TRACE

#define CRONO_LOG_FUNCTION_FATAL LOG_FATAL
#define CRONO_LOG_FUNCTION_ERROR LOG_ERROR
#define CRONO_LOG_FUNCTION_WARN  LOG_WARN
#define CRONO_LOG_FUNCTION_INFO  LOG_INFO
#define CRONO_LOG_FUNCTION_DEBUG LOG_DEBUG
#define CRONO_LOG_FUNCTION_TRACE LOG_TRACE

#define CRONO_LOG_LOCATION_FATAL LOG_FATAL
#define CRONO_LOG_LOCATION_ERROR LOG_ERROR
#define CRONO_LOG_LOCATION_WARN  LOG_WARN
#define CRONO_LOG_LOCATION_INFO  LOG_INFO
#define CRONO_LOG_LOCATION_DEBUG LOG_DEBUG
#define CRONO_LOG_LOCATION_TRACE LOG_TRACE

#define CRONO_LOG_MESSAGE_FATAL LOG_MESSAGE_FATAL
#define CRONO_LOG_MESSAGE_ERROR LOG_MESSAGE_ERROR
#define CRONO_LOG_MESSAGE_WARN  LOG_MESSAGE_WARN
#define CRONO_LOG_MESSAGE_INFO  LOG_MESSAGE_INFO
#define CRONO_LOG_MESSAGE_DEBUG LOG_MESSAGE_DEBUG
#define CRONO_LOG_MESSAGE_TRACE LOG_MESSAGE_TRACE

#define CRONO_LOGGING_LEVELS_ALL LOGGING_LEVELS_ALL
#define CRONO_LOGGING_LEVELS_NONE LOGGING_LEVELS_NONE
#define CRONO_LOGGING_LEVELS_FATAL LOGGING_LEVELS_FATAL
#define CRONO_LOGGING_LEVELS_ERROR LOGGING_LEVELS_ERROR
#define CRONO_LOGGING_LEVELS_WARN  LOGGING_LEVELS_WARN
#define CRONO_LOGGING_LEVELS_INFO  LOGGING_LEVELS_INFO
#define CRONO_LOGGING_LEVELS_DEBUG LOGGING_LEVELS_DEBUG
#define CRONO_LOGGING_LEVELS_TRACE LOGGING_LEVELS_TRACE

#define CRONO_LOGGING_MESSAGE_LEVELS_ALL LOGGING_MESSAGE_LEVELS_ALL
#define CRONO_LOGGING_MESSAGE_LEVELS_NONE LOGGING_MESSAGE_LEVELS_NONE
#define CRONO_LOGGING_MESSAGE_LEVELS_FATAL LOGGING_MESSAGE_LEVELS_FATAL
#define CRONO_LOGGING_MESSAGE_LEVELS_ERROR LOGGING_MESSAGE_LEVELS_ERROR
#define CRONO_LOGGING_MESSAGE_LEVELS_WARN  LOGGING_MESSAGE_LEVELS_WARN
#define CRONO_LOGGING_MESSAGE_LEVELS_INFO  LOGGING_MESSAGE_LEVELS_INFO
#define CRONO_LOGGING_MESSAGE_LEVELS_DEBUG LOGGING_MESSAGE_LEVELS_DEBUG
#define CRONO_LOGGING_MESSAGE_LEVELS_TRACE LOGGING_MESSAGE_LEVELS_TRACE

#define CRONO_LOGGING_LEVELS_DEFAULT LOGGING_LEVELS_DEFAULT
#define CRONO_SET_DEFAULT_LOGGER SET_THE_LOGGER
#define CRONO_SET_LOGGING_LEVEL SET_LOGGING_LEVEL
#define CRONO_LOGGER_INIT LOGGER_INIT
#define CRONO_LOGGER_FINI LOGGER_FINI

namespace crono {
namespace io {

typedef nadir::io::logger Logger;
typedef nadir::io::logger_instance LoggerExtendExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LoggerExtend
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS LoggerExtend: public LoggerExtendExtends {
public:
    typedef LoggerExtendExtends Extends;
    typedef Extends::level Level;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LoggerExtend() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace io 
} // namespace crono 

#endif // _CRONO_IO_NADIR_LOGGER_HPP 
