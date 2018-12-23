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
///   File: logger_stdio.hpp
///
/// Author: $author$
///   Date: 5/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_IO_LOGGER_STDIO_HPP
#define _CRONO_NADIR_IO_LOGGER_STDIO_HPP

#include "crono/nadir/io/logger_message.hpp"
#include <iostream>

namespace crono {
namespace io {

} // namespace io 
} // namespace crono 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if defined(TRACE_BUILD)
#define CRONO_CERR_LOG_TRACE(message_) CRONO_CERR_LOG(message_)
#define CRONO_STDERR_LOG_TRACE(message_) CRONO_STDERR_LOG(message_)
#else // defined(TRACE_BUILD)
#define CRONO_CERR_LOG_TRACE(message_)
#define CRONO_STDERR_LOG_TRACE(message_)
#endif // defined(TRACE_BUILD)

#if defined(DEBUG_BUILD)
#define CRONO_CERR_LOG_DEBUG(message_) CRONO_CERR_LOG(message_)
#define CRONO_STDERR_LOG_DEBUG(message_) CRONO_STDERR_LOG(message_)
#else // defined(DEBUG_BUILD)
#define CRONO_CERR_LOG_DEBUG(message_)
#define CRONO_STDERR_LOG_DEBUG(message_)
#endif // defined(DEBUG_BUILD)

#define CRONO_CERR_LOG_ERROR(message_) CRONO_CERR_LOG(message_)
#define CRONO_STDERR_LOG_ERROR(message_) CRONO_STDERR_LOG(message_)

#define CRONO_CERR_LOG(message_) CRONO_COSTREAM_LOG(::std::cerr, message_)
#define CRONO_STDERR_LOG(message_) CRONO_STDSTREAM_LOG(stderr, message_)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(CRONO_LOCATION_LOGGING) && !defined(CRONO_FUNCTION_LOGGING) && !defined(CRONO_MESSAGE_LOGGING)
#define CRONO_LOCATION_LOGGING
#endif // !defined(CRONO_LOCATION_LOGGING) && !defined(CRONO_FUNCTION_LOGGING) && !defined(CRONO_MESSAGE_LOGGING)

#if defined(CRONO_LOCATION_LOGGING)
#define CRONO_COSTREAM_LOG(ostream_, message_) \
    CRONO_COSTREAM_LOG_LOCATION(ostream_, message_)

#define CRONO_STDSTREAM_LOG(stream_, message_) \
    CRONO_STDSTREAM_LOG_LOCATION(stream_, message_)
#else // defined(CRONO_LOCATION_LOGGING)
#if defined(CRONO_FUNCTION_LOGGING)
#define CRONO_COSTREAM_LOG(ostream_, message_) \
    CRONO_COSTREAM_LOG_FUNCTION(ostream_, message_)

#define CRONO_STDSTREAM_LOG(stream_, message_) \
    CRONO_STDSTREAM_LOG_FUNCTION(stream_, message_)
#else // defined(CRONO_FUNCTION_LOGGING)
#define CRONO_COSTREAM_LOG(ostream_, message_) \
    CRONO_COSTREAM_LOG_MESSAGE(ostream_, message_)

#define CRONO_STDSTREAM_LOG(stream_, message_) \
    CRONO_STDSTREAM_LOG_MESSAGE(stream_, message_)
#endif // defined(CRONO_FUNCTION_LOGGING)
#endif // defined(CRONO_LOCATION_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_CERR_LOG_MESSAGE(message_) CRONO_COSTREAM_LOG_MESSAGE(::std::cerr, message_)
#define CRONO_COSTREAM_LOG_MESSAGE(ostream_, message_) \
{ ::crono::io::logger_message message; \
  ostream_ << message << message_ << "\n"; }

#define CRONO_STDERR_LOG_MESSAGE(message_) CRONO_STDSTREAM_LOG_MESSAGE(stderr, message_)
#define CRONO_STDSTREAM_LOG_MESSAGE(stream_, message_) \
{ ::crono::io::logger_message message; message << message_; \
  fprintf(stream_, "%s\n", message.chars()); }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_CERR_LOG_FUNCTION(message_) CRONO_COSTREAM_LOG_FUNCTION(::std::cerr, message_)
#define CRONO_COSTREAM_LOG_FUNCTION(ostream_, message_) \
{ ::crono::io::logger_function function = CRONO_LOGGER_FUNCTION; \
  ::crono::io::logger_message message; \
  ostream_ << function << message << ": " << message_ << "\n"; }

#define CRONO_STDERR_LOG_FUNCTION(message_) CRONO_STDSTREAM_LOG_FUNCTION(stderr, message_)
#define CRONO_STDSTREAM_LOG_FUNCTION(stream_, message_) \
{ ::crono::io::logger_function function = CRONO_LOGGER_FUNCTION; \
  ::crono::io::logger_message message; message << message_; \
  fprintf(stream_, "%s: %s\n", function.chars(), message.chars()); }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_CERR_LOG_LOCATION(message_) CRONO_COSTREAM_LOG_LOCATION(::std::cerr, message_)
#define CRONO_COSTREAM_LOG_LOCATION(ostream_, message_) \
{ ::crono::io::logger_location location = CRONO_LOGGER_LOCATION; \
  ::crono::io::logger_message message; \
  ostream_ << location << message << ": " << message_ << "\n"; }

#define CRONO_STDERR_LOG_LOCATION(message_) CRONO_STDSTREAM_LOG_LOCATION(stderr, message_)
#define CRONO_STDSTREAM_LOG_LOCATION(stream_, message_) \
{ ::crono::io::logger_location location = CRONO_LOGGER_LOCATION; \
  ::crono::io::logger_message message; message << message_; \
  fprintf(stream_, "%s: %s\n", location.chars(), message.chars()); }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _CRONO_NADIR_IO_LOGGER_STDIO_HPP
