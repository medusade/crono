///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   Date: 9/22/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_IO_LOGGER_HPP
#define _CRONO_IO_LOGGER_HPP

#include "crono/base/Locked.hpp"
#include <iostream>

namespace crono {
namespace io {

///////////////////////////////////////////////////////////////////////
///  Class: Logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Logger: virtual public Locked {
public:
    typedef Locked Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    typedef unsigned Level;
    enum {
        LevelNone  = 0,

        LevelFatal = 1,
        LevelError = (LevelFatal << 1),
        LevelWarn  = (LevelError << 1),
        LevelInfo  = (LevelWarn << 1),
        LevelDebug = (LevelInfo << 1),
        LevelTrace = (LevelDebug << 1),

        LevelAll   = ((LevelTrace << 1) - 1)
    };
    enum {
        LevelsNone  = 0,

        LevelsFatal = 1,
        LevelsError = (((LevelsFatal + 1) << 1) - 1),
        LevelsWarn  = (((LevelsError + 1) << 1) - 1),
        LevelsInfo  = (((LevelsWarn + 1) << 1) - 1),
        LevelsDebug = (((LevelsInfo + 1) << 1) - 1),
        LevelsTrace = (((LevelsDebug + 1) << 1) - 1),

        LevelsAll   = LevelsTrace
    };

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
            String s(to_signed(i));
            append(s.c_str());
            return *this;
        }
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() { return true; }
    virtual bool Unlock() { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init() { return true; }
    virtual bool Fini() { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Log
    (const Level& _level, const Location& _location, const Message& _message) {
        Locker lock(*this);
        if ((this->IsEnabledFor(_level))) {
            Log(_location);
            Log(_message.c_str());
            LogLn();
        }
    }
    virtual void Log
    (const Level& _level, const Function& _function, const Message& _message) {
        Locker lock(*this);
        if ((this->IsEnabledFor(_level))) {
            Log(_function);
            Log(_message.c_str());
            LogLn();
        }
    }
    virtual void Log
    (const Level& _level, const Message& _message) {
        Locker lock(*this);
        if ((this->IsEnabledFor(_level))) {
            Log(_message.c_str());
            LogLn();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void EnableFor(const Level& _level) {}
    virtual Level EnabledFor() const { return LevelNone; }
    virtual bool IsEnabledFor(const Level& _level) const { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static Logger* GetDefault() {
        return TheDefault();
    }
    static void SetDefault(Logger* _logger) {
        TheDefault() = _logger;
    }
protected:
    static Logger*& TheDefault() {
        static Logger* theDefault = 0;
        return theDefault;
    }

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
    virtual void Log(const char* chars) {
        ::std::cerr << chars;
    }
    virtual void LogLn() {
        ::std::cerr << ::std::endl;
        ::std::cerr.flush();
    }
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(__CRONO_LOGGER_FUNCTION__)
#define __CRONO_LOGGER_FUNCTION__ __FUNCTION__
#endif // !defined(__CRONO_LOGGER_FUNCTION__)

#if !defined(CRONO_LOGGER_FUNCTION)
#define CRONO_LOGGER_FUNCTION \
    ::crono::io::Logger::Function(__CRONO_LOGGER_FUNCTION__)
#endif // !defined(CRONO_LOGGER_LOCATION)

#if !defined(CRONO_LOGGER_LOCATION)
#define CRONO_LOGGER_LOCATION \
    ::crono::io::Logger::Location(__CRONO_LOGGER_FUNCTION__, __FILE__, __LINE__)
#endif // !defined(CRONO_LOGGER_LOCATION)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_INIT_LOGGER(logger_) { \
::crono::io::Logger* logger = logger_; \
if ((logger)) { logger->Init(); } }

#define CRONO_FINI_LOGGER(logger_) { \
::crono::io::Logger* logger = logger_; \
if ((logger)) { logger->Fini(); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_SET_LOGGER_LEVEL(logger_, level_) { \
::crono::io::Logger* logger = logger_; \
if ((logger)) { logger->EnableFor(level_); } }

#define CRONO_GET_LOGGER_LEVEL(logger_) \
((logger_)?(logger_->enabled_for()):(::crono::io::Logger::level\
(::crono::io::Logger::LevelsNone)))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_LOG_LOCATION(logger_, level_, message_) { \
::crono::io::Logger* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::crono::io::Logger::Message message; \
   logger->Log(level_, CRONO_LOGGER_LOCATION, message << message_); } }

#define CRONO_LOG(logger_, level_, message_) { \
::crono::io::Logger* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::crono::io::Logger::Message message; \
   logger->Log(level_, CRONO_LOGGER_FUNCTION, message << message_); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_LOGGING_LEVELS ::crono::io::Logger::Level
#define CRONO_LOGGING_LEVELS_ALL ::crono::io::Logger::LevelsAll
#define CRONO_LOGGING_LEVELS_NONE ::crono::io::Logger::LevelsNone
#define CRONO_LOGGING_LEVELS_FATAL ::crono::io::Logger::LevelsFatal
#define CRONO_LOGGING_LEVELS_ERROR ::crono::io::Logger::LevelsError
#define CRONO_LOGGING_LEVELS_WARN ::crono::io::Logger::LevelsWarn
#define CRONO_LOGGING_LEVELS_INFO ::crono::io::Logger::LevelsInfo
#define CRONO_LOGGING_LEVELS_DEBUG ::crono::io::Logger::LevelsDebug
#define CRONO_LOGGING_LEVELS_TRACE ::crono::io::Logger::LevelsTrace

#if !defined(CRONO_USE_LOGGER)
#define CRONO_DEFAULT_LOGGER ::crono::io::Logger::GetDefault()
#endif // !defined(CRONO_USE_LOGGER)
#define CRONO_SET_DEFAULT_LOGGER(to) ::crono::io::Logger::SetDefault(to)

#define CRONO_LOGGER_INIT() CRONO_INIT_LOGGER(CRONO_DEFAULT_LOGGER)
#define CRONO_LOGGER_FINI() CRONO_FINI_LOGGER(CRONO_DEFAULT_LOGGER)

#define CRONO_SET_LOGGING_LEVEL(level)  CRONO_SET_LOGGER_LEVEL(CRONO_DEFAULT_LOGGER, level)
#define CRONO_GET_LOGGING_LEVEL(level)  (level = CRONO_GET_LOGGER_LEVEL(CRONO_DEFAULT_LOGGER))

#define CRONO_LOG_LOCATION_FATAL(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelFatal, message)
#define CRONO_LOG_LOCATION_ERROR(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelError, message)
#define CRONO_LOG_LOCATION_WARN(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelWarn, message)
#define CRONO_LOG_LOCATION_INFO(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelInfo, message)
#define CRONO_LOG_LOCATION_DEBUG(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelDebug, message)
#define CRONO_LOG_LOCATION_TRACE(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelTrace, message)

#define CRONO_LOG_FATAL(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelFatal, message)
#define CRONO_LOG_ERROR(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelError, message)
#define CRONO_LOG_WARN(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelWarn, message)
#define CRONO_LOG_INFO(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelInfo, message)
#define CRONO_LOG_DEBUG(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelDebug, message)
#define CRONO_LOG_TRACE(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelTrace, message)

} // namespace io
} // namespace crono 

#endif // _CRONO_IO_LOGGER_HPP 
