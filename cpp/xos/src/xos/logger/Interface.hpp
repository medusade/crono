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
///   File: Interface.hpp
///
/// Author: $author$
///   Date: 8/8/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_INTERFACE_HPP
#define _XOS_LOGGER_INTERFACE_HPP

#include "xos/logger/Output.hpp"

namespace xos {
namespace logger {

typedef logger::Output InterfaceImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Interface: virtual public InterfaceImplements {
public:
    typedef InterfaceImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Init() {
        return true;
    }
    virtual bool Fini() {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() {
        return true;
    }
    virtual bool Unlock() {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Log;
    virtual void Log
    (const Level& _level, const Location& _location, const Message& _message) {
        ::xos::Lock lock(*this);
        if ((this->IsEnabledFor(_level))) {
            Log(_location);
            Log(_message);
            LogLn();
        }
    }
    virtual void Log
    (const Level& _level, const Function& _function, const Message& _message) {
        ::xos::Lock lock(*this);
        if ((this->IsEnabledFor(_level))) {
            Log(_function);
            Log(_message);
            LogLn();
        }
    }
    virtual void Log
    (const Level& _level, const Message& _message) {
        ::xos::Lock lock(*this);
        if ((this->IsEnabledFor(_level))) {
            Log(_message);
            LogLn();
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static Interface* SetDefault(Interface* to) {
        TheDefault() = to;
        return TheDefault();
    }
    static Interface* GetDefault() {
        return TheDefault();
    }
    static Interface* Default() {
        return TheDefault();
    }
protected:
    static Interface*& TheDefault() {
        static Interface* theDefault = 0;
        return theDefault;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef Interface BaseImplements;
typedef xos::Base BaseExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Base
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Base: virtual public BaseImplements, public BaseExtends {
public:
    typedef BaseImplements Implements;
    typedef BaseExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: Base
    ///////////////////////////////////////////////////////////////////////
    Base(xos::Locked& locked, Level level): m_locked(locked), m_level(level) {
        Interface*& theDefault = TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    Base(xos::Locked& locked): m_locked(locked), m_level(EnabledForDefault()) {
        Interface*& theDefault = TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    Base(Level level): m_locked(*this), m_level(level) {
        Interface*& theDefault = TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    Base(const Base& copy): m_locked(copy.Locked()), m_level(copy.m_level) {
        Interface*& theDefault = TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    Base(): m_locked(*this), m_level(EnabledForDefault()) {
        Interface*& theDefault = TheDefault();
        if (!(theDefault)) {
            theDefault = this;
        }
    }
    virtual ~Base() {
        Interface*& theDefault = TheDefault();
        if ((theDefault) && (theDefault != this)) {
            theDefault = 0;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Level EnableFor(const Level& _level) {
        Level enabledFor = this->EnabledFor();
        m_level = _level;
        return enabledFor;
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
    virtual bool Lock() {
        if (&m_locked != this) {
            return m_locked.Lock(); }
        return true;
    }
    virtual bool Unlock() {
        if (&m_locked != this) {
            return m_locked.Unlock(); }
        return true;
    }
    virtual xos::Locked& Locked() const {
        if (&m_locked != this) {
            return ((xos::Locked&)m_locked); }
        return ((xos::Locked&)*this);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    xos::Locked& m_locked;
    Level m_level;
};

} // namespace logger
} // namespace xos 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_INIT_LOGGER(logger_) { \
::xos::logger::Interface* logger = logger_; \
if ((logger)) { logger->Init(); } }

#define XOS_FINI_LOGGER(logger_) { \
::xos::logger::Interface* logger = logger_; \
if ((logger)) { logger->Fini(); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_SET_LOGGER_LEVEL(logger_, level_) { \
::xos::logger::Interface* logger = logger_; \
if ((logger)) { logger->EnableFor(level_); } }

#define XOS_GET_LOGGER_LEVEL(logger_) \
((logger_)?(logger_->enabled_for()):(::xos::logger::level\
(::xos::logger::LevelsNone)))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_LOCATION(logger_, level_, message_) { \
::xos::logger::Interface* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::xos::logger::Message message; \
   logger->Log(level_, XOS_LOGGER_LOCATION, message << message_); } }

#define XOS_LOG_FUNCTION(logger_, level_, message_) { \
::xos::logger::Interface* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::xos::logger::Message message; \
   logger->Log(level_, XOS_LOGGER_FUNCTION, message << message_); } }

#define XOS_LOG_PLAIN(logger_, level_, message_) { \
::xos::logger::Interface* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::xos::logger::Message message; \
   logger->Log(level_, message << message_); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_IF_LOG_LOCATION(logger_, level_, message_) { \
if ((this->IsLogged())) { \
::xos::logger::Interface* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::xos::logger::Message message; \
   logger->Log(level_, XOS_LOGGER_LOCATION, message << message_); } } }

#define XOS_IF_LOG_FUNCTION(logger_, level_, message_) { \
if ((this->IsLogged())) { \
::xos::logger::Interface* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::xos::logger::Message message; \
   logger->Log(level_, XOS_LOGGER_FUNCTION, message << message_); } } }

#define XOS_IF_LOG_PLAIN(logger_, level_, message_) { \
if ((this->IsLogged())) { \
::xos::logger::Interface* logger = logger_; \
if ((logger)?(logger->IsEnabledFor(level_)):(false)) {\
   ::xos::logger::Message message; \
   logger->Log(level_, message << message_); } } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_USE_LOGGER)
#define XOS_DEFAULT_LOGGER ::xos::logger::Interface::GetDefault()
#endif // !defined(XOS_USE_LOGGER)
#define XOS_SET_DEFAULT_LOGGER(to) ::xos::logger::Interface::SetDefault(to)

#define XOS_LOGGER_INIT() XOS_INIT_LOGGER(XOS_DEFAULT_LOGGER)
#define XOS_LOGGER_FINI() XOS_FINI_LOGGER(XOS_DEFAULT_LOGGER)

#define XOS_SET_LOGGING_LEVEL(level)  XOS_SET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER, level)
#define XOS_GET_LOGGING_LEVEL(level)  (level = XOS_GET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_LOCATION_FATAL(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelFatal, message)
#define XOS_LOG_LOCATION_ERROR(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelError, message)
#define XOS_LOG_LOCATION_WARN(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelWarn, message)
#define XOS_LOG_LOCATION_INFO(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelInfo, message)
#define XOS_LOG_LOCATION_DEBUG(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelDebug, message)
#define XOS_LOG_LOCATION_TRACE(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelTrace, message)

#define XOS_LOG_FUNCTION_FATAL(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelFatal, message)
#define XOS_LOG_FUNCTION_ERROR(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelError, message)
#define XOS_LOG_FUNCTION_WARN(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelWarn, message)
#define XOS_LOG_FUNCTION_INFO(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelInfo, message)
#define XOS_LOG_FUNCTION_DEBUG(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelDebug, message)
#define XOS_LOG_FUNCTION_TRACE(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelTrace, message)

#define XOS_LOG_PLAIN_FATAL(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelFatal, message)
#define XOS_LOG_PLAIN_ERROR(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelError, message)
#define XOS_LOG_PLAIN_WARN(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelWarn, message)
#define XOS_LOG_PLAIN_INFO(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelInfo, message)
#define XOS_LOG_PLAIN_DEBUG(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelDebug, message)
#define XOS_LOG_PLAIN_TRACE(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelTrace, message)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_IF_LOG_LOCATION_FATAL(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelFatal, message)
#define XOS_IF_LOG_LOCATION_ERROR(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelError, message)
#define XOS_IF_LOG_LOCATION_WARN(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelWarn, message)
#define XOS_IF_LOG_LOCATION_INFO(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelInfo, message)
#define XOS_IF_LOG_LOCATION_DEBUG(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelDebug, message)
#define XOS_IF_LOG_LOCATION_TRACE(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelTrace, message)

#define XOS_IF_LOG_FUNCTION_FATAL(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelFatal, message)
#define XOS_IF_LOG_FUNCTION_ERROR(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelError, message)
#define XOS_IF_LOG_FUNCTION_WARN(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelWarn, message)
#define XOS_IF_LOG_FUNCTION_INFO(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelInfo, message)
#define XOS_IF_LOG_FUNCTION_DEBUG(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelDebug, message)
#define XOS_IF_LOG_FUNCTION_TRACE(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::LevelTrace, message)

#define XOS_IF_LOG_PLAIN_FATAL(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelFatal, message)
#define XOS_IF_LOG_PLAIN_ERROR(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelError, message)
#define XOS_IF_LOG_PLAIN_WARN(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelWarn, message)
#define XOS_IF_LOG_PLAIN_INFO(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelInfo, message)
#define XOS_IF_LOG_PLAIN_DEBUG(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelDebug, message)
#define XOS_IF_LOG_PLAIN_TRACE(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::LevelTrace, message)

#if defined(XOS_PLAIN_LOGGING)
#define XOS_LOG_FATAL XOS_LOG_PLAIN_FATAL
#define XOS_LOG_ERROR XOS_LOG_PLAIN_ERROR
#define XOS_LOG_WARN  XOS_LOG_PLAIN_WARN
#define XOS_LOG_INFO  XOS_LOG_PLAIN_INFO
#define XOS_LOG_DEBUG XOS_LOG_PLAIN_DEBUG
#define XOS_LOG_TRACE XOS_LOG_PLAIN_TRACE
#else // defined(XOS_PLAIN_LOGGING)
#if defined(XOS_FUNCTION_LOGGING)
#define XOS_LOG_FATAL XOS_LOG_FUNCTION_FATAL
#define XOS_LOG_ERROR XOS_LOG_FUNCTION_ERROR
#define XOS_LOG_WARN  XOS_LOG_FUNCTION_WARN
#define XOS_LOG_INFO  XOS_LOG_FUNCTION_INFO
#define XOS_LOG_DEBUG XOS_LOG_FUNCTION_DEBUG
#define XOS_LOG_TRACE XOS_LOG_FUNCTION_TRACE
#else // defined(XOS_FUNCTION_LOGGING)
#define XOS_LOG_FATAL XOS_LOG_LOCATION_FATAL
#define XOS_LOG_ERROR XOS_LOG_LOCATION_ERROR
#define XOS_LOG_WARN  XOS_LOG_LOCATION_WARN
#define XOS_LOG_INFO  XOS_LOG_LOCATION_INFO
#define XOS_LOG_DEBUG XOS_LOG_LOCATION_DEBUG
#define XOS_LOG_TRACE XOS_LOG_LOCATION_TRACE
#endif // defined(XOS_FUNCTION_LOGGING)
#endif // defined(XOS_PLAIN_LOGGING)

#if defined(XOS_PLAIN_LOGGING)
#define XOS_IF_LOG_FATAL XOS_IF_LOG_PLAIN_FATAL
#define XOS_IF_LOG_ERROR XOS_IF_LOG_PLAIN_ERROR
#define XOS_IF_LOG_WARN  XOS_IF_LOG_PLAIN_WARN
#define XOS_IF_LOG_INFO  XOS_IF_LOG_PLAIN_INFO
#define XOS_IF_LOG_DEBUG XOS_IF_LOG_PLAIN_DEBUG
#define XOS_IF_LOG_TRACE XOS_IF_LOG_PLAIN_TRACE
#else // defined(XOS_PLAIN_LOGGING)
#if defined(XOS_FUNCTION_LOGGING)
#define XOS_IF_LOG_FATAL XOS_IF_LOG_FUNCTION_FATAL
#define XOS_IF_LOG_ERROR XOS_IF_LOG_FUNCTION_ERROR
#define XOS_IF_LOG_WARN  XOS_IF_LOG_FUNCTION_WARN
#define XOS_IF_LOG_INFO  XOS_IF_LOG_FUNCTION_INFO
#define XOS_IF_LOG_DEBUG XOS_IF_LOG_FUNCTION_DEBUG
#define XOS_IF_LOG_TRACE XOS_IF_LOG_FUNCTION_TRACE
#else // defined(XOS_FUNCTION_LOGGING)
#define XOS_IF_LOG_FATAL XOS_IF_LOG_LOCATION_FATAL
#define XOS_IF_LOG_ERROR XOS_IF_LOG_LOCATION_ERROR
#define XOS_IF_LOG_WARN  XOS_IF_LOG_LOCATION_WARN
#define XOS_IF_LOG_INFO  XOS_IF_LOG_LOCATION_INFO
#define XOS_IF_LOG_DEBUG XOS_IF_LOG_LOCATION_DEBUG
#define XOS_IF_LOG_TRACE XOS_IF_LOG_LOCATION_TRACE
#endif // defined(XOS_FUNCTION_LOGGING)
#endif // defined(XOS_PLAIN_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_LOCATION_MESSAGE_FATAL(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelFatal, message)
#define XOS_LOG_LOCATION_MESSAGE_ERROR(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelError, message)
#define XOS_LOG_LOCATION_MESSAGE_WARN(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelWarn, message)
#define XOS_LOG_LOCATION_MESSAGE_INFO(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelInfo, message)
#define XOS_LOG_LOCATION_MESSAGE_DEBUG(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelDebug, message)
#define XOS_LOG_LOCATION_MESSAGE_TRACE(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelTrace, message)

#define XOS_LOG_FUNCTION_MESSAGE_FATAL(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelFatal, message)
#define XOS_LOG_FUNCTION_MESSAGE_ERROR(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelError, message)
#define XOS_LOG_FUNCTION_MESSAGE_WARN(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelWarn, message)
#define XOS_LOG_FUNCTION_MESSAGE_INFO(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelInfo, message)
#define XOS_LOG_FUNCTION_MESSAGE_DEBUG(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelDebug, message)
#define XOS_LOG_FUNCTION_MESSAGE_TRACE(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelTrace, message)

#define XOS_LOG_PLAIN_MESSAGE_FATAL(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelFatal, message)
#define XOS_LOG_PLAIN_MESSAGE_ERROR(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelError, message)
#define XOS_LOG_PLAIN_MESSAGE_WARN(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelWarn, message)
#define XOS_LOG_PLAIN_MESSAGE_INFO(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelInfo, message)
#define XOS_LOG_PLAIN_MESSAGE_DEBUG(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelDebug, message)
#define XOS_LOG_PLAIN_MESSAGE_TRACE(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::MessageLevelTrace, message)

#if defined(XOS_PLAIN_MESSAGE_LOGGING)
#define XOS_LOG_MESSAGE_FATAL XOS_LOG_PLAIN_MESSAGE_FATAL
#define XOS_LOG_MESSAGE_ERROR XOS_LOG_PLAIN_MESSAGE_ERROR
#define XOS_LOG_MESSAGE_WARN  XOS_LOG_PLAIN_MESSAGE_WARN
#define XOS_LOG_MESSAGE_INFO  XOS_LOG_PLAIN_MESSAGE_INFO
#define XOS_LOG_MESSAGE_DEBUG XOS_LOG_PLAIN_MESSAGE_DEBUG
#define XOS_LOG_MESSAGE_TRACE XOS_LOG_PLAIN_MESSAGE_TRACE
#else // defined(XOS_PLAIN_MESSAGE_LOGGING)
#if defined(XOS_LOCATION_MESSAGE_LOGGING)
#define XOS_LOG_MESSAGE_FATAL XOS_LOG_LOCATION_MESSAGE_FATAL
#define XOS_LOG_MESSAGE_ERROR XOS_LOG_LOCATION_MESSAGE_ERROR
#define XOS_LOG_MESSAGE_WARN  XOS_LOG_LOCATION_MESSAGE_WARN
#define XOS_LOG_MESSAGE_INFO  XOS_LOG_LOCATION_MESSAGE_INFO
#define XOS_LOG_MESSAGE_DEBUG XOS_LOG_LOCATION_MESSAGE_DEBUG
#define XOS_LOG_MESSAGE_TRACE XOS_LOG_LOCATION_MESSAGE_TRACE
#else // defined(XOS_LOCATION_MESSAGE_LOGGING)
#define XOS_LOG_MESSAGE_FATAL XOS_LOG_FUNCTION_MESSAGE_FATAL
#define XOS_LOG_MESSAGE_ERROR XOS_LOG_FUNCTION_MESSAGE_ERROR
#define XOS_LOG_MESSAGE_WARN  XOS_LOG_FUNCTION_MESSAGE_WARN
#define XOS_LOG_MESSAGE_INFO  XOS_LOG_FUNCTION_MESSAGE_INFO
#define XOS_LOG_MESSAGE_DEBUG XOS_LOG_FUNCTION_MESSAGE_DEBUG
#define XOS_LOG_MESSAGE_TRACE XOS_LOG_FUNCTION_MESSAGE_TRACE
#endif // defined(XOS_LOCATION_MESSAGE_LOGGING)
#endif // defined(XOS_PLAIN_MESSAGE_LOGGING)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _XOS_LOGGER_INTERFACE_HPP
