///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: logger_level.hpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_IO_LOGGER_LEVEL_HPP
#define _CRONO_NADIR_IO_LOGGER_LEVEL_HPP

#include "crono/nadir/base/base.hpp"

namespace crono {
namespace io {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef unsigned logger_level;
typedef logger_level logger_message_level;
enum {
    logger_level_none  = 0,

    logger_level_fatal = 1,
    logger_level_error = (logger_level_fatal << 1),
    logger_level_warn  = (logger_level_error << 1),
    logger_level_info  = (logger_level_warn << 1),
    logger_level_debug = (logger_level_info << 1),
    logger_level_trace = (logger_level_debug << 1),

    next_logger_level  = (logger_level_trace << 1),
    all_logger_level   = (next_logger_level - 1),
    logger_level_all = all_logger_level,

    logger_message_level_none  = 0,

    logger_message_level_fatal = (next_logger_level),
    logger_message_level_error = (logger_message_level_fatal << 1),
    logger_message_level_warn  = (logger_message_level_error << 1),
    logger_message_level_info  = (logger_message_level_warn << 1),
    logger_message_level_debug = (logger_message_level_info << 1),
    logger_message_level_trace = (logger_message_level_debug << 1),

    all_logger_message_level   = (all_logger_level << next_logger_level),
    logger_message_level_all = all_logger_message_level,
};
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
typedef logger_level logger_levels;
typedef logger_levels logger_message_levels;
enum {
    logger_levels_none  = 0,

    logger_levels_fatal = 1,
    logger_levels_error = (((logger_levels_fatal + 1) << 1) - 1),
    logger_levels_warn  = (((logger_levels_error + 1) << 1) - 1),
    logger_levels_info  = (((logger_levels_warn + 1) << 1) - 1),
    logger_levels_debug = (((logger_levels_info + 1) << 1) - 1),
    logger_levels_trace = (((logger_levels_debug + 1) << 1) - 1),

    all_logger_levels   = (logger_levels_trace),
    logger_levels_all = all_logger_levels,

    logger_message_levels_none  = 0,

    logger_message_levels_fatal = (((logger_levels_fatal) << logger_level_trace)),
    logger_message_levels_error = (((logger_levels_error) << logger_level_trace)),
    logger_message_levels_warn  = (((logger_levels_warn) << logger_level_trace)),
    logger_message_levels_info  = (((logger_levels_info) << logger_level_trace)),
    logger_message_levels_debug = (((logger_levels_debug) << logger_level_trace)),
    logger_message_levels_trace = (((logger_levels_trace) << logger_level_trace)),

    all_logger_message_levels   = (logger_message_levels_trace),
    logger_message_levels_all = all_logger_message_levels
};

} // namespace io
} // namespace crono 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_LOGGING_LEVELS ::crono::io::logger_levels
#define CRONO_LOGGING_LEVELS_ALL ::crono::io::logger_levels_all
#define CRONO_LOGGING_LEVELS_NONE ::crono::io::logger_levels_none
#define CRONO_LOGGING_LEVELS_FATAL ::crono::io::logger_levels_fatal
#define CRONO_LOGGING_LEVELS_ERROR ::crono::io::logger_levels_error
#define CRONO_LOGGING_LEVELS_WARN ::crono::io::logger_levels_warn
#define CRONO_LOGGING_LEVELS_INFO ::crono::io::logger_levels_info
#define CRONO_LOGGING_LEVELS_DEBUG ::crono::io::logger_levels_debug
#define CRONO_LOGGING_LEVELS_TRACE ::crono::io::logger_levels_trace

#define CRONO_LOGGING_MESSAGE_LEVELS ::crono::io::logger_message_levels
#define CRONO_LOGGING_MESSAGE_LEVELS_ALL ::crono::io::logger_message_levels_all
#define CRONO_LOGGING_MESSAGE_LEVELS_NONE ::crono::io::logger_message_levels_none
#define CRONO_LOGGING_MESSAGE_LEVELS_FATAL ::crono::io::logger_message_levels_fatal
#define CRONO_LOGGING_MESSAGE_LEVELS_ERROR ::crono::io::logger_message_levels_error
#define CRONO_LOGGING_MESSAGE_LEVELS_WARN ::crono::io::logger_message_levels_warn
#define CRONO_LOGGING_MESSAGE_LEVELS_INFO ::crono::io::logger_message_levels_info
#define CRONO_LOGGING_MESSAGE_LEVELS_DEBUG ::crono::io::logger_message_levels_debug
#define CRONO_LOGGING_MESSAGE_LEVELS_TRACE ::crono::io::logger_message_levels_trace

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(CRONO_LOGGING_LEVELS_DEFAULT)
#if defined(TRACE_BUILD)
#define CRONO_LOGGING_LEVELS_DEFAULT CRONO_LOGGING_LEVELS_TRACE
#else // defined(TRACE_BUILD)
#if defined(DEBUG_BUILD)
#define CRONO_LOGGING_LEVELS_DEFAULT CRONO_LOGGING_LEVELS_DEBUG
#else // defined(DEBUG_BUILD)
#define CRONO_LOGGING_LEVELS_DEFAULT CRONO_LOGGING_LEVELS_ERROR
#endif // defined(DEBUG_BUILD)
#endif // defined(TRACE_BUILD)
#endif // !defined(CRONO_LOGGING_LEVELS_DEFAULT)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _CRONO_NADIR_IO_LOGGER_LEVEL_HPP
