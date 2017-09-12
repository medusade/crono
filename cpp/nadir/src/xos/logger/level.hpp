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
///   File: level.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_LEVEL_HPP
#define _XOS_LOGGER_LEVEL_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace logger {

///////////////////////////////////////////////////////////////////////
/// enum: level
///////////////////////////////////////////////////////////////////////
typedef unsigned level;
enum {
    level_none  = 0,

    level_fatal = 1,
    level_error = (level_fatal << 1),
    level_warn  = (level_error << 1),
    level_info  = (level_warn << 1),
    level_debug = (level_info << 1),
    level_trace = (level_debug << 1),

    level_all   = ((level_trace << 1) - 1),

    message_level_none  = 0,

    message_level_fatal = (level_trace << 1),
    message_level_error = (message_level_fatal << 1),
    message_level_warn  = (message_level_error << 1),
    message_level_info  = (message_level_warn << 1),
    message_level_debug = (message_level_info << 1),
    message_level_trace = (message_level_debug << 1),

    message_level_all   = ((level_all << level_trace))
};

///////////////////////////////////////////////////////////////////////
/// enum: levels
///////////////////////////////////////////////////////////////////////
typedef level levels;
enum {
    levels_none  = 0,

    levels_fatal = 1,
    levels_error = (((levels_fatal + 1) << 1) - 1),
    levels_warn  = (((levels_error + 1) << 1) - 1),
    levels_info  = (((levels_warn + 1) << 1) - 1),
    levels_debug = (((levels_info + 1) << 1) - 1),
    levels_trace = (((levels_debug + 1) << 1) - 1),

    levels_all   = levels_trace,

    message_levels_none  = 0,

    message_levels_fatal = (((levels_fatal) << level_trace)),
    message_levels_error = (((levels_error) << level_trace)),
    message_levels_warn  = (((levels_warn) << level_trace)),
    message_levels_info  = (((levels_info) << level_trace)),
    message_levels_debug = (((levels_debug) << level_trace)),
    message_levels_trace = (((levels_trace) << level_trace)),

    message_levels_all   = message_levels_trace
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOGGING_LEVELS ::xos::logger::level
#define XOS_LOGGING_LEVELS_ALL ::xos::logger::levels_all
#define XOS_LOGGING_LEVELS_NONE ::xos::logger::levels_none
#define XOS_LOGGING_LEVELS_FATAL ::xos::logger::levels_fatal
#define XOS_LOGGING_LEVELS_ERROR ::xos::logger::levels_error
#define XOS_LOGGING_LEVELS_WARN ::xos::logger::levels_warn
#define XOS_LOGGING_LEVELS_INFO ::xos::logger::levels_info
#define XOS_LOGGING_LEVELS_DEBUG ::xos::logger::levels_debug
#define XOS_LOGGING_LEVELS_TRACE ::xos::logger::levels_trace

#define XOS_LOGGING_MESSAGE_LEVELS ::xos::logger::message_level
#define XOS_LOGGING_MESSAGE_LEVELS_ALL ::xos::logger::message_levels_all
#define XOS_LOGGING_MESSAGE_LEVELS_NONE ::xos::logger::message_levels_none
#define XOS_LOGGING_MESSAGE_LEVELS_FATAL ::xos::logger::message_levels_fatal
#define XOS_LOGGING_MESSAGE_LEVELS_ERROR ::xos::logger::message_levels_error
#define XOS_LOGGING_MESSAGE_LEVELS_WARN ::xos::logger::message_levels_warn
#define XOS_LOGGING_MESSAGE_LEVELS_INFO ::xos::logger::message_levels_info
#define XOS_LOGGING_MESSAGE_LEVELS_DEBUG ::xos::logger::message_levels_debug
#define XOS_LOGGING_MESSAGE_LEVELS_TRACE ::xos::logger::message_levels_trace

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOGGING_LEVELS_DEFAULT)
#if defined(TRACE_BUILD)
#define XOS_LOGGING_LEVELS_DEFAULT XOS_LOGGING_LEVELS_TRACE
#else // defined(TRACE_BUILD)
#if defined(DEBUG_BUILD)
#define XOS_LOGGING_LEVELS_DEFAULT XOS_LOGGING_LEVELS_DEBUG
#else // defined(DEBUG_BUILD)
#define XOS_LOGGING_LEVELS_DEFAULT XOS_LOGGING_LEVELS_ERROR
#endif // defined(DEBUG_BUILD)
#endif // defined(TRACE_BUILD)
#endif // !defined(XOS_LOGGING_LEVELS_DEFAULT)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

} // namespace logger
} // namespace xos 

#endif // _XOS_LOGGER_LEVEL_HPP 
