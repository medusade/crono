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
///   File: Logger.hpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_IO_LOGGER_HPP
#define _CRONO_IO_LOGGER_HPP

#if defined(USE_NADIR_BASE)
#include "crono/io/nadir/Logger.hpp"
#else // defined(USE_NADIR_BASE)
#include "crono/io/LoggerOutput.hpp"

namespace crono {
namespace io {

typedef LoggerOutput LoggerImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Logger: virtual public LoggerImplements {
public:
    typedef LoggerImplements Implements;

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
    using Implements::Log;
    virtual void Log
    (const Level& _level, const Location& _location, const Message& _message) {
        ::patrona::Locker lock(*this);
        if ((this->IsEnabledFor(_level))) {
            Log(_location);
            Log(_message);
            LogLn();
        }
    }
    virtual void Log
    (const Level& _level, const Function& _function, const Message& _message) {
        ::patrona::Locker lock(*this);
        if ((this->IsEnabledFor(_level))) {
            Log(_function);
            Log(_message);
            LogLn();
        }
    }
    virtual void Log
    (const Level& _level, const Message& _message) {
        ::patrona::Locker lock(*this);
        if ((this->IsEnabledFor(_level))) {
            Log(_message);
            LogLn();
        }
    }

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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////
///  Class: LoggerExtend
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS LoggerExtend: virtual public Logger, public Base {
public:
    typedef Logger Implements;
    typedef Base Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LoggerExtend(Level level): m_level(level) {
    }
    LoggerExtend(const LoggerExtend& copy): m_level(copy.m_level) {
    }
    LoggerExtend(): m_level(EnabledForDefault()) {
    }
    virtual ~LoggerExtend() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void EnableFor(const Level& _level) {
        m_level = _level;
    }
    virtual Level EnabledFor() const {
        return m_level;
    }
    virtual bool IsEnabledFor(const Level& _level) const {
        if ((_level) && (_level == (_level & m_level))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Level m_level;
};

} // namespace io
} // namespace crono 

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

#define CRONO_LOG_FUNCTION(logger_, level_, message_) { \
::crono::io::Logger* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::crono::io::Logger::Message message; \
   logger->Log(level_, CRONO_LOGGER_FUNCTION, message << message_); } }

#define CRONO_LOG_PLAIN(logger_, level_, message_) { \
::crono::io::Logger* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::crono::io::Logger::Message message; \
   logger->Log(level_, message << message_); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(CRONO_USE_LOGGER)
#define CRONO_DEFAULT_LOGGER ::crono::io::Logger::GetDefault()
#endif // !defined(CRONO_USE_LOGGER)
#define CRONO_SET_DEFAULT_LOGGER(to) ::crono::io::Logger::SetDefault(to)

#define CRONO_LOGGER_INIT() CRONO_INIT_LOGGER(CRONO_DEFAULT_LOGGER)
#define CRONO_LOGGER_FINI() CRONO_FINI_LOGGER(CRONO_DEFAULT_LOGGER)

#define CRONO_SET_LOGGING_LEVEL(level)  CRONO_SET_LOGGER_LEVEL(CRONO_DEFAULT_LOGGER, level)
#define CRONO_GET_LOGGING_LEVEL(level)  (level = CRONO_GET_LOGGER_LEVEL(CRONO_DEFAULT_LOGGER))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_LOG_LOCATION_FATAL(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelFatal, message)
#define CRONO_LOG_LOCATION_ERROR(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelError, message)
#define CRONO_LOG_LOCATION_WARN(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelWarn, message)
#define CRONO_LOG_LOCATION_INFO(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelInfo, message)
#define CRONO_LOG_LOCATION_DEBUG(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelDebug, message)
#define CRONO_LOG_LOCATION_TRACE(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelTrace, message)

#define CRONO_LOG_FUNCTION_FATAL(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelFatal, message)
#define CRONO_LOG_FUNCTION_ERROR(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelError, message)
#define CRONO_LOG_FUNCTION_WARN(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelWarn, message)
#define CRONO_LOG_FUNCTION_INFO(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelInfo, message)
#define CRONO_LOG_FUNCTION_DEBUG(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelDebug, message)
#define CRONO_LOG_FUNCTION_TRACE(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelTrace, message)

#define CRONO_LOG_PLAIN_FATAL(message) CRONO_LOG_PLAIN(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelFatal, message)
#define CRONO_LOG_PLAIN_ERROR(message) CRONO_LOG_PLAIN(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelError, message)
#define CRONO_LOG_PLAIN_WARN(message) CRONO_LOG_PLAIN(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelWarn, message)
#define CRONO_LOG_PLAIN_INFO(message) CRONO_LOG_PLAIN(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelInfo, message)
#define CRONO_LOG_PLAIN_DEBUG(message) CRONO_LOG_PLAIN(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelDebug, message)
#define CRONO_LOG_PLAIN_TRACE(message) CRONO_LOG_PLAIN(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::LevelTrace, message)

#define CRONO_LOG_LOCATION_DEBUG_TRACE(cond, message) \
{ if ((cond)) { CRONO_LOG_LOCATION_DEBUG(message); } \
  else { CRONO_LOG_LOCATION_TRACE(message); } }

#define CRONO_LOG_FUNCTION_DEBUG_TRACE(cond, message) \
{ if ((cond)) { CRONO_LOG_FUNCTION_DEBUG(message); } \
  else { CRONO_LOG_FUNCTION_TRACE(message); } }

#define CRONO_LOG_PLAIN_DEBUG_TRACE(cond, message) \
{ if ((cond)) { CRONO_LOG_PLAIN_DEBUG(message); } \
  else { CRONO_LOG_PLAIN_TRACE(message); } }

#if defined(CRONO_PLAIN_LOGGING)
#define CRONO_LOG_FATAL CRONO_LOG_PLAIN_FATAL
#define CRONO_LOG_ERROR CRONO_LOG_PLAIN_ERROR
#define CRONO_LOG_WARN  CRONO_LOG_PLAIN_WARN
#define CRONO_LOG_INFO  CRONO_LOG_PLAIN_INFO
#define CRONO_LOG_DEBUG CRONO_LOG_PLAIN_DEBUG
#define CRONO_LOG_TRACE CRONO_LOG_PLAIN_TRACE
#define CRONO_LOG_DEBUG_TRACE CRONO_LOG_PLAIN_DEBUG_TRACE
#else // defined(CRONO_PLAIN_LOGGING)
#if defined(CRONO_FUNCTION_LOGGING)
#define CRONO_LOG_FATAL CRONO_LOG_FUNCTION_FATAL
#define CRONO_LOG_ERROR CRONO_LOG_FUNCTION_ERROR
#define CRONO_LOG_WARN  CRONO_LOG_FUNCTION_WARN
#define CRONO_LOG_INFO  CRONO_LOG_FUNCTION_INFO
#define CRONO_LOG_DEBUG CRONO_LOG_FUNCTION_DEBUG
#define CRONO_LOG_TRACE CRONO_LOG_FUNCTION_TRACE
#define CRONO_LOG_DEBUG_TRACE CRONO_LOG_FUNCTION_DEBUG_TRACE
#else // defined(CRONO_FUNCTION_LOGGING)
#define CRONO_LOG_FATAL CRONO_LOG_LOCATION_FATAL
#define CRONO_LOG_ERROR CRONO_LOG_LOCATION_ERROR
#define CRONO_LOG_WARN  CRONO_LOG_LOCATION_WARN
#define CRONO_LOG_INFO  CRONO_LOG_LOCATION_INFO
#define CRONO_LOG_DEBUG CRONO_LOG_LOCATION_DEBUG
#define CRONO_LOG_TRACE CRONO_LOG_LOCATION_TRACE
#define CRONO_LOG_DEBUG_TRACE CRONO_LOG_LOCATION_DEBUG_TRACE
#endif // defined(CRONO_FUNCTION_LOGGING)
#endif // defined(CRONO_PLAIN_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_LOG_LOCATION_MESSAGE_FATAL(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelFatal, message)
#define CRONO_LOG_LOCATION_MESSAGE_ERROR(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelError, message)
#define CRONO_LOG_LOCATION_MESSAGE_WARN(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelWarn, message)
#define CRONO_LOG_LOCATION_MESSAGE_INFO(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelInfo, message)
#define CRONO_LOG_LOCATION_MESSAGE_DEBUG(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelDebug, message)
#define CRONO_LOG_LOCATION_MESSAGE_TRACE(message) CRONO_LOG_LOCATION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelTrace, message)

#define CRONO_LOG_FUNCTION_MESSAGE_FATAL(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelFatal, message)
#define CRONO_LOG_FUNCTION_MESSAGE_ERROR(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelError, message)
#define CRONO_LOG_FUNCTION_MESSAGE_WARN(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelWarn, message)
#define CRONO_LOG_FUNCTION_MESSAGE_INFO(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelInfo, message)
#define CRONO_LOG_FUNCTION_MESSAGE_DEBUG(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelDebug, message)
#define CRONO_LOG_FUNCTION_MESSAGE_TRACE(message) CRONO_LOG_FUNCTION(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelTrace, message)

#define CRONO_LOG_PLAIN_MESSAGE_FATAL(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelFatal, message)
#define CRONO_LOG_PLAIN_MESSAGE_ERROR(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelError, message)
#define CRONO_LOG_PLAIN_MESSAGE_WARN(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelWarn, message)
#define CRONO_LOG_PLAIN_MESSAGE_INFO(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelInfo, message)
#define CRONO_LOG_PLAIN_MESSAGE_DEBUG(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelDebug, message)
#define CRONO_LOG_PLAIN_MESSAGE_TRACE(message) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::Logger::MessageLevelTrace, message)

#if defined(CRONO_PLAIN_MESSAGE_LOGGING)
#define CRONO_LOG_MESSAGE_FATAL CRONO_LOG_PLAIN_MESSAGE_FATAL
#define CRONO_LOG_MESSAGE_ERROR CRONO_LOG_PLAIN_MESSAGE_ERROR
#define CRONO_LOG_MESSAGE_WARN  CRONO_LOG_PLAIN_MESSAGE_WARN
#define CRONO_LOG_MESSAGE_INFO  CRONO_LOG_PLAIN_MESSAGE_INFO
#define CRONO_LOG_MESSAGE_DEBUG CRONO_LOG_PLAIN_MESSAGE_DEBUG
#define CRONO_LOG_MESSAGE_TRACE CRONO_LOG_PLAIN_MESSAGE_TRACE
#else // defined(CRONO_PLAIN_MESSAGE_LOGGING)
#if defined(CRONO_LOCATION_MESSAGE_LOGGING)
#define CRONO_LOG_MESSAGE_FATAL CRONO_LOG_LOCATION_MESSAGE_FATAL
#define CRONO_LOG_MESSAGE_ERROR CRONO_LOG_LOCATION_MESSAGE_ERROR
#define CRONO_LOG_MESSAGE_WARN  CRONO_LOG_LOCATION_MESSAGE_WARN
#define CRONO_LOG_MESSAGE_INFO  CRONO_LOG_LOCATION_MESSAGE_INFO
#define CRONO_LOG_MESSAGE_DEBUG CRONO_LOG_LOCATION_MESSAGE_DEBUG
#define CRONO_LOG_MESSAGE_TRACE CRONO_LOG_LOCATION_MESSAGE_TRACE
#else // defined(CRONO_LOCATION_MESSAGE_LOGGING)
#define CRONO_LOG_MESSAGE_FATAL CRONO_LOG_FUNCTION_MESSAGE_FATAL
#define CRONO_LOG_MESSAGE_ERROR CRONO_LOG_FUNCTION_MESSAGE_ERROR
#define CRONO_LOG_MESSAGE_WARN  CRONO_LOG_FUNCTION_MESSAGE_WARN
#define CRONO_LOG_MESSAGE_INFO  CRONO_LOG_FUNCTION_MESSAGE_INFO
#define CRONO_LOG_MESSAGE_DEBUG CRONO_LOG_FUNCTION_MESSAGE_DEBUG
#define CRONO_LOG_MESSAGE_TRACE CRONO_LOG_FUNCTION_MESSAGE_TRACE
#endif // defined(CRONO_LOCATION_MESSAGE_LOGGING)
#endif // defined(CRONO_PLAIN_MESSAGE_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_LOG_FATAL)
#define XOS_LOG_FATAL(message) CRONO_LOG_FATAL(message)
#endif // !defined(XOS_LOG_FATAL)

#if !defined(XOS_LOG_ERROR)
#define XOS_LOG_ERROR(message) CRONO_LOG_ERROR(message)
#endif // !defined(XOS_LOG_ERROR)

#if !defined(XOS_LOG_WARN)
#define XOS_LOG_WARN(message) CRONO_LOG_WARN(message)
#endif // !defined(XOS_LOG_WARN)

#if !defined(XOS_LOG_INFO)
#define XOS_LOG_INFO(message) CRONO_LOG_INFO(message)
#endif // !defined(XOS_LOG_INFO)

#if !defined(XOS_LOG_DEBUG)
#define XOS_LOG_DEBUG(message) CRONO_LOG_DEBUG(message)
#endif // !defined(XOS_LOG_DEBUG)

#if !defined(XOS_LOG_TRACE)
#define XOS_LOG_TRACE(message) CRONO_LOG_TRACE(message)
#endif // !defined(XOS_LOG_TRACE)

#if !defined(XOS_LOG_DEBUG_TRACE)
#define XOS_LOG_DEBUG_TRACE(cond, message) CRONO_LOG_DEBUG_TRACE(cond, message)
#endif // !defined(XOS_LOG_DEBUG_TRACE)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(LOG_FATAL)
#define LOG_FATAL(message) CRONO_LOG_FATAL(message)
#endif // !defined(LOG_FATAL)

#if !defined(LOG_ERROR)
#define LOG_ERROR(message) CRONO_LOG_ERROR(message)
#endif // !defined(LOG_ERROR)

#if !defined(LOG_WARN)
#define LOG_WARN(message) CRONO_LOG_WARN(message)
#endif // !defined(LOG_WARN)

#if !defined(LOG_INFO)
#define LOG_INFO(message) CRONO_LOG_INFO(message)
#endif // !defined(LOG_INFO)

#if !defined(LOG_DEBUG)
#define LOG_DEBUG(message) CRONO_LOG_DEBUG(message)
#endif // !defined(LOG_DEBUG)

#if !defined(LOG_TRACE)
#define LOG_TRACE(message) CRONO_LOG_TRACE(message)
#endif // !defined(LOG_TRACE)

#if !defined(LOG_DEBUG_TRACE)
#define LOG_DEBUG_TRACE(cond, message) CRONO_LOG_DEBUG_TRACE(cond, message)
#endif // !defined(LOG_DEBUG_TRACE)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // defined(USE_NADIR_BASE)

#endif // _CRONO_IO_LOGGER_HPP 
