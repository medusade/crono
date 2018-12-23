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
///   File: LoggerOutput.hpp
///
/// Author: $author$
///   Date: 6/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_IO_LOGGEROUTPUT_HPP
#define _CRONO_IO_LOGGEROUTPUT_HPP

#include "crono/io/LoggerEnabled.hpp"

#if !defined(USE_NADIR_BASE)
#include <iostream>

namespace crono {
namespace io {

typedef LoggerEnabled LoggerOutputImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LoggerOutput
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS LoggerOutput: virtual public LoggerOutputImplements {
public:
    typedef LoggerOutputImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Function: public String {
    public:
        typedef String Extends;
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        Function(const char* name): Extends(name) {
        }
        Function(const Function& copy): Extends(copy) {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Location {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        Location
        (const char* functionName, const char* fileName, size_t lineNumber)
        : m_functionName(functionName),
          m_fileName(fileName), m_lineNumber(lineNumber) {
        }
        Location(const Location& copy)
        : m_functionName(copy.m_functionName),
          m_fileName(copy.m_fileName), m_lineNumber(copy.m_lineNumber) {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        inline String FunctionName() const { return m_functionName; }
        inline String FileName() const { return m_fileName; }
        inline String LineNumber() const {
            String s(to_unsigned(m_lineNumber));
            return s;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        String m_functionName;
        String m_fileName;
        size_t m_lineNumber;
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Message: public String {
    public:
        Message& operator << (const Extends& str) { append(str.c_str()); return *this; }
        Message& operator << (const char* chars) { append(chars); return *this; }
        Message& operator << (const wchar_t* chars) { append(chars); return *this; }
        Message& operator << (int i) {
            String s(crono::to_signed(i));
            append(s.c_str());
            return *this;
        }
    };

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Log(const Location& _location) {
        Log(_location.FileName().c_str());
        Log("[");
        Log(_location.LineNumber().c_str());
        Log("]");
        Log(" ");
        Log(_location.FunctionName().c_str());
        Log(": ");
    }
    virtual void Log(const Function& _function) {
        Log(_function.c_str());
        Log(": ");
    }
    virtual void Log(const Message& _message) {
        Log(_message.c_str());
    }
    virtual void Log(const char* chars, size_t length) {
        if ((chars) && (length)) {
            for (char c = *(chars); length; --length, c = *(++chars)) {
                ::std::cerr << c;
            }
        }
    }
    virtual void Log(const char* chars) {
        ::std::cerr << chars;
    }
    virtual void LogLn() {
        ::std::cerr << ::std::endl;
        ::std::cerr.flush();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace io 
} // namespace crono 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if defined(_MSC_VER)
#define __CRONO_LOGGER_FUNCTION__ __FUNCTION__
#else // defined(_MSC_VER)
#endif // defined(_MSC_VER)

#if !defined(__CRONO_LOGGER_FUNCTION__)
#define __CRONO_LOGGER_FUNCTION__ __FUNCTION__
#endif // !defined(__CRONO_LOGGER_FUNCTION__)

#if !defined(CRONO_LOGGER_FUNCTION)
#define CRONO_LOGGER_FUNCTION \
    ::crono::io::LoggerOutput::Function(__CRONO_LOGGER_FUNCTION__)
#endif // !defined(CRONO_LOGGER_LOCATION)

#if !defined(CRONO_LOGGER_LOCATION)
#define CRONO_LOGGER_LOCATION \
    ::crono::io::LoggerOutput::Location(__CRONO_LOGGER_FUNCTION__, __FILE__, __LINE__)
#endif // !defined(CRONO_LOGGER_LOCATION)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_COSTREAM_LOG_PLAIN(ostream_, message_) \
{ ::crono::io::LoggerOutput::Message message; \
  ostream_ << message << message_ << "\n"; }

#define CRONO_COSTREAM_LOG_FUNCTION(ostream_, message_) \
{ ::crono::io::LoggerOutput::Message message; \
  ostream_ << CRONO_LOGGER_FUNCTION << ": " << message << message_ << "\n"; }

#define CRONO_COSTREAM_LOG_LOCATION(ostream_, message_) \
{ ::crono::io::LoggerOutput::Location location = CRONO_LOGGER_LOCATION; \
  ::crono::io::LoggerOutput::Message message; \
  ostream_ <<  location.FileName().chars() << "[" <<  location.LineNumber().chars() << "] " \
  <<  location.FunctionName().chars() << ": " << message << message_ << "\n"; }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_STDSTREAM_LOG_PLAIN(stream_, message_) \
{ ::crono::io::LoggerOutput::Message message; message << message_; \
  fprintf(stream_, "%s\n", message.chars()); }

#define CRONO_STDSTREAM_LOG_FUNCTION(stream_, message_) \
{ ::crono::io::LoggerOutput::Function function = CRONO_LOGGER_FUNCTION; \
  ::crono::io::LoggerOutput::Message message; message << message_; \
  fprintf(stream_, "%s: %s\n", function.chars(), message.chars()); }

#define CRONO_STDSTREAM_LOG_LOCATION(stream_, message_) \
{ ::crono::io::LoggerOutput::Location location = CRONO_LOGGER_LOCATION; \
  ::crono::io::LoggerOutput::Message message; message << message_; \
  fprintf(stream_, "%s[%s] %s: %s\n", location.FileName().chars(), \
  location.LineNumber().chars(), location.FunctionName().chars(), message.chars()); }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_CERR_LOG_PLAIN(message_) CRONO_COSTREAM_LOG_PLAIN(::std::cerr, message_)
#define CRONO_STDERR_LOG_PLAIN(message_) CRONO_STDSTREAM_LOG_PLAIN(stderr, message_)
#define CRONO_CERR_LOG_FUNCTION(message_) CRONO_COSTREAM_LOG_FUNCTION(::std::cerr, message_)
#define CRONO_STDERR_LOG_FUNCTION(message_) CRONO_STDSTREAM_LOG_FUNCTION(stderr, message_)
#define CRONO_CERR_LOG_LOCATION(message_) CRONO_COSTREAM_LOG_LOCATION(::std::cerr, message_)
#define CRONO_STDERR_LOG_LOCATION(message_) CRONO_STDSTREAM_LOG_LOCATION(stderr, message_)

#if defined(CRONO_PLAIN_LOGGING)
#define CRONO_CERR_LOG CRONO_CERR_LOG_PLAIN
#define CRONO_STDERR_LOG CRONO_STDERR_LOG_PLAIN
#else // defined(CRONO_PLAIN_LOGGING)
#if defined(CRONO_FUNCTION_LOGGING)
#define CRONO_CERR_LOG CRONO_CERR_LOG_FUNCTION
#define CRONO_STDERR_LOG CRONO_STDERR_LOG_FUNCTION
#else // defined(CRONO_FUNCTION_LOGGING)
#define CRONO_CERR_LOG CRONO_CERR_LOG_LOCATION
#define CRONO_STDERR_LOG CRONO_STDERR_LOG_LOCATION
#endif // defined(CRONO_FUNCTION_LOGGING)
#endif // defined(CRONO_PLAIN_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

#if defined(TRACE_BUILD)
#define CRONO_CERR_LOG_TRACE(message_) CRONO_CERR_LOG(message_)
#define CRONO_STDERR_LOG_TRACE(message_) CRONO_STDERR_LOG(message_)
#define CRONO_CERR_LOG_PLAIN_TRACE(message_) CRONO_CERR_LOG_PLAIN(message_)
#define CRONO_STDERR_LOG_PLAIN_TRACE(message_) CRONO_STDERR_LOG_PLAIN(message_)
#define CRONO_CERR_LOG_FUNCTION_TRACE(message_) CRONO_CERR_LOG_FUNCTION(message_)
#define CRONO_STDERR_LOG_FUNCTION_TRACE(message_) CRONO_STDERR_LOG_FUNCTION(message_)
#define CRONO_CERR_LOG_LOCATION_TRACE(message_) CRONO_CERR_LOG_LOCATION(message_)
#define CRONO_STDERR_LOG_LOCATION_TRACE(message_) CRONO_STDERR_LOG_LOCATION(message_)
#else // defined(TRACE_BUILD)
#define CRONO_CERR_LOG_TRACE(message_)
#define CRONO_STDERR_LOG_TRACE(message_)
#define CRONO_CERR_LOG_PLAIN_TRACE(message_)
#define CRONO_STDERR_LOG_PLAIN_TRACE(message_)
#define CRONO_CERR_LOG_FUNCTION_TRACE(message_)
#define CRONO_STDERR_LOG_FUNCTION_TRACE(message_)
#define CRONO_CERR_LOG_LOCATION_TRACE(message_)
#define CRONO_STDERR_LOG_LOCATION_TRACE(message_)
#endif // defined(TRACE_BUILD)

#if defined(DEBUG_BUILD)
#define CRONO_CERR_LOG_DEBUG(message_) CRONO_CERR_LOG(message_)
#define CRONO_STDERR_LOG_DEBUG(message_) CRONO_STDERR_LOG(message_)
#define CRONO_CERR_LOG_PLAIN_DEBUG(message_) CRONO_CERR_LOG_PLAIN(message_)
#define CRONO_STDERR_LOG_PLAIN_DEBUG(message_) CRONO_STDERR_LOG_PLAIN(message_)
#define CRONO_CERR_LOG_FUNCTION_DEBUG(message_) CRONO_CERR_LOG_FUNCTION(message_)
#define CRONO_STDERR_LOG_FUNCTION_DEBUG(message_) CRONO_STDERR_LOG_FUNCTION(message_)
#define CRONO_CERR_LOG_LOCATION_DEBUG(message_) CRONO_CERR_LOG_LOCATION(message_)
#define CRONO_STDERR_LOG_LOCATION_DEBUG(message_) CRONO_STDERR_LOG_LOCATION(message_)
#else // defined(DEBUG_BUILD)
#define CRONO_CERR_LOG_DEBUG(message_)
#define CRONO_STDERR_LOG_DEBUG(message_)
#define CRONO_CERR_LOG_FUNCTION_DEBUG(message_)
#define CRONO_STDERR_LOG_FUNCTION_DEBUG(message_)
#define CRONO_CERR_LOG_LOCATION_DEBUG(message_)
#define CRONO_STDERR_LOG_LOCATION_DEBUG(message_)
#endif // defined(DEBUG_BUILD)

#define CRONO_CERR_LOG_ERROR(message_) CRONO_CERR_LOG(message_)
#define CRONO_STDERR_LOG_ERROR(message_) CRONO_STDERR_LOG(message_)
#define CRONO_CERR_LOG_PLAIN_ERROR(message_) CRONO_CERR_LOG_PLAIN(message_)
#define CRONO_STDERR_LOG_PLAIN_ERROR(message_) CRONO_STDERR_LOG_PLAIN(message_)
#define CRONO_CERR_LOG_FUNCTION_ERROR(message_) CRONO_CERR_LOG_FUNCTION(message_)
#define CRONO_STDERR_LOG_FUNCTION_ERROR(message_) CRONO_STDERR_LOG_FUNCTION(message_)
#define CRONO_CERR_LOG_LOCATION_ERROR(message_) CRONO_CERR_LOG_LOCATION(message_)
#define CRONO_STDERR_LOG_LOCATION_ERROR(message_) CRONO_STDERR_LOG_LOCATION(message_)

#if defined(CRONO_CERR_LOGGING)
#define CRONO_ERR_LOG_TRACE(message_) CRONO_CERR_LOG_TRACE(message_)
#define CRONO_ERR_LOG_PLAIN_TRACE(message_) CRONO_CERR_LOG_PLAIN_TRACE(message_)
#define CRONO_ERR_LOG_FUNCTION_TRACE(message_) CRONO_CERR_LOG_FUNCTION_TRACE(message_)
#define CRONO_ERR_LOG_LOCATION_TRACE(message_) CRONO_CERR_LOG_LOCATION_TRACE(message_)

#define CRONO_ERR_LOG_DEBUG(message_) CRONO_CERR_LOG_DEBUG(message_)
#define CRONO_ERR_LOG_PLAIN_DEBUG(message_) CRONO_CERR_LOG_PLAIN_DEBUG(message_)
#define CRONO_ERR_LOG_FUNCTION_DEBUG(message_) CRONO_CERR_LOG_FUNCTION_DEBUG(message_)
#define CRONO_ERR_LOG_LOCATION_DEBUG(message_) CRONO_CERR_LOG_LOCATION_DEBUG(message_)

#define CRONO_ERR_LOG_ERROR(message_) CRONO_CERR_LOG_ERROR(message_)
#define CRONO_ERR_LOG_PLAIN_ERROR(message_) CRONO_CERR_LOG_PLAIN_ERROR(message_)
#define CRONO_ERR_LOG_FUNCTION_ERROR(message_) CRONO_CERR_LOG_FUNCTION_ERROR(message_)
#define CRONO_ERR_LOG_LOCATION_ERROR(message_) CRONO_CERR_LOG_LOCATION_ERROR(message_)
#else // defined(CRONO_CERR_LOGGING)
#define CRONO_ERR_LOG_TRACE(message_) CRONO_STDERR_LOG_TRACE(message_)
#define CRONO_ERR_LOG_PLAIN_TRACE(message_) CRONO_STDERR_LOG_PLAIN_TRACE(message_)
#define CRONO_ERR_LOG_FUNCTION_TRACE(message_) CRONO_STDERR_LOG_FUNCTION_TRACE(message_)
#define CRONO_ERR_LOG_LOCATION_TRACE(message_) CRONO_STDERR_LOG_LOCATION_TRACE(message_)

#define CRONO_ERR_LOG_DEBUG(message_) CRONO_STDERR_LOG_DEBUG(message_)
#define CRONO_ERR_LOG_PLAIN_DEBUG(message_) CRONO_STDERR_LOG_PLAIN_DEBUG(message_)
#define CRONO_ERR_LOG_FUNCTION_DEBUG(message_) CRONO_STDERR_LOG_FUNCTION_DEBUG(message_)
#define CRONO_ERR_LOG_LOCATION_DEBUG(message_) CRONO_STDERR_LOG_LOCATION_DEBUG(message_)

#define CRONO_ERR_LOG_ERROR(message_) CRONO_STDERR_LOG_ERROR(message_)
#define CRONO_ERR_LOG_PLAIN_ERROR(message_) CRONO_STDERR_LOG_PLAIN_ERROR(message_)
#define CRONO_ERR_LOG_FUNCTION_ERROR(message_) CRONO_STDERR_LOG_FUNCTION_ERROR(message_)
#define CRONO_ERR_LOG_LOCATION_ERROR(message_) CRONO_STDERR_LOG_LOCATION_ERROR(message_)
#endif // defined(CRONO_CERR_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(ERR_LOG_TRACE)
#define ERR_LOG_TRACE(message_) CRONO_ERR_LOG_TRACE(message_)
#endif // !defined(ERR_LOG_TRACE)

#if !defined(ERR_LOG_DEBUG)
#define ERR_LOG_DEBUG(message_) CRONO_ERR_LOG_DEBUG(message_)
#endif // !defined(ERR_LOG_DEBUG)

#if !defined(ERR_LOG_ERROR)
#define ERR_LOG_ERROR(message_) CRONO_ERR_LOG_ERROR(message_)
#endif // !defined(ERR_LOG_ERROR)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#else // !defined(USE_NADIR_BASE)
#endif // !defined(USE_NADIR_BASE)

#endif // _CRONO_IO_LOGGEROUTPUT_HPP
