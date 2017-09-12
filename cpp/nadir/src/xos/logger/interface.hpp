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
///   File: interface.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_INTERFACE_HPP
#define _XOS_LOGGER_INTERFACE_HPP

#include "xos/logger/output.hpp"

namespace xos {
namespace logger {

typedef logger::output interface_implements;
///////////////////////////////////////////////////////////////////////
///  class: interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS interface: virtual public interface_implements {
public:
    typedef interface_implements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() {
        return true;
    }
    virtual bool fini() {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() {
        return true;
    }
    virtual bool unlock() {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::log;
    virtual void log
    (const level& _level, const location& _location, const message& _message) {
        ::xos::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            log(_location);
            log(_message);
            log_ln();
        }
    }
    virtual void log
    (const level& _level, const function& _function, const message& _message) {
        ::xos::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            log(_function);
            log(_message);
            log_ln();
        }
    }
    virtual void log
    (const level& _level, const message& _message) {
        ::xos::lock lock(*this);
        if ((this->is_enabled_for(_level))) {
            log(_message);
            log_ln();
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static interface* set_default(interface* to) {
        the_default() = to;
        return the_default();
    }
    static interface* get_default() {
        return the_default();
    }
protected:
    static interface*& the_default() {
        static interface* the_default = 0;
        return the_default;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef interface base_implements;
typedef xos::base base_extends;
///////////////////////////////////////////////////////////////////////
///  class: base
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS base: virtual public base_implements, public base_extends {
public:
    typedef base_implements Implements;
    typedef base_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// constructor: base
    ///////////////////////////////////////////////////////////////////////
    base(xos::locked& locked, level level): m_locked(locked), m_level(level) {
        interface*& the_default = Implements::the_default();
        if (!(the_default)) {
            the_default = this;
        }
    }
    base(xos::locked& locked): m_locked(locked), m_level(enabled_for_default()) {
        interface*& the_default = Implements::the_default();
        if (!(the_default)) {
            the_default = this;
        }
    }
    base(level level): m_locked(*this), m_level(level) {
        interface*& the_default = Implements::the_default();
        if (!(the_default)) {
            the_default = this;
        }
    }
    base(const base& copy): m_locked(copy.locked()), m_level(copy.m_level) {
        interface*& the_default = Implements::the_default();
        if (!(the_default)) {
            the_default = this;
        }
    }
    base(): m_locked(*this), m_level(enabled_for_default()) {
        interface*& the_default = Implements::the_default();
        if (!(the_default)) {
            the_default = this;
        }
    }
    virtual ~base() {
        interface*& the_default = Implements::the_default();
        if ((the_default) && (the_default != this)) {
            the_default = 0;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual level enable_for(const level& _level) {
        level enabled_for = this->enabled_for();
        m_level = _level;
        return enabled_for;
    }
    virtual level enabled_for() const {
        return m_level;
    }
    virtual bool is_enabled_for(const level& _level) const {
        if ((_level) && (_level == (_level & m_level))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() {
        if (&m_locked != this) {
            return m_locked.lock(); }
        return true;
    }
    virtual bool unlock() {
        if (&m_locked != this) {
            return m_locked.unlock(); }
        return true;
    }
    virtual xos::locked& locked() const {
        if (&m_locked != this) {
            return ((xos::locked&)m_locked); }
        return ((xos::locked&)*this);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    xos::locked& m_locked;
    level m_level;
};

} // namespace logger
} // namespace xos 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_INIT_LOGGER(logger_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) { logger->init(); } }

#define XOS_FINI_LOGGER(logger_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) { logger->fini(); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_SET_LOGGER_LEVEL(logger_, level_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)) { logger->enable_for(level_); } }

#define XOS_GET_LOGGER_LEVEL(logger_) \
((logger_)?(logger_->enabled_for()):(::xos::logger::level\
(::xos::logger::levels_none)))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_LOCATION(logger_, level_, message_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, XOS_LOGGER_LOCATION, message << message_); } }

#define XOS_LOG_FUNCTION(logger_, level_, message_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, XOS_LOGGER_FUNCTION, message << message_); } }

#define XOS_LOG_PLAIN(logger_, level_, message_) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, message << message_); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_IF_LOG_LOCATION(logger_, level_, message_) { \
if ((this->is_logged())) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, XOS_LOGGER_LOCATION, message << message_); } } }

#define XOS_IF_LOG_FUNCTION(logger_, level_, message_) { \
if ((this->is_logged())) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, XOS_LOGGER_FUNCTION, message << message_); } } }

#define XOS_IF_LOG_PLAIN(logger_, level_, message_) { \
if ((this->is_logged())) { \
::xos::logger::interface* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::xos::logger::message message; \
   logger->log(level_, message << message_); } } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if !defined(XOS_USE_LOGGER)
#define XOS_DEFAULT_LOGGER ::xos::logger::interface::get_default()
#endif // !defined(XOS_USE_LOGGER)
#define XOS_SET_DEFAULT_LOGGER(to) ::xos::logger::interface::set_default(to)

#define XOS_LOGGER_INIT() XOS_INIT_LOGGER(XOS_DEFAULT_LOGGER)
#define XOS_LOGGER_FINI() XOS_FINI_LOGGER(XOS_DEFAULT_LOGGER)

#define XOS_SET_LOGGING_LEVEL(level)  XOS_SET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER, level)
#define XOS_GET_LOGGING_LEVEL(level)  (level = XOS_GET_LOGGER_LEVEL(XOS_DEFAULT_LOGGER))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_LOCATION_FATAL(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_fatal, message)
#define XOS_LOG_LOCATION_ERROR(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_error, message)
#define XOS_LOG_LOCATION_WARN(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_warn, message)
#define XOS_LOG_LOCATION_INFO(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_info, message)
#define XOS_LOG_LOCATION_DEBUG(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_debug, message)
#define XOS_LOG_LOCATION_TRACE(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_trace, message)

#define XOS_LOG_FUNCTION_FATAL(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_fatal, message)
#define XOS_LOG_FUNCTION_ERROR(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_error, message)
#define XOS_LOG_FUNCTION_WARN(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_warn, message)
#define XOS_LOG_FUNCTION_INFO(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_info, message)
#define XOS_LOG_FUNCTION_DEBUG(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_debug, message)
#define XOS_LOG_FUNCTION_TRACE(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_trace, message)

#define XOS_LOG_PLAIN_FATAL(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_fatal, message)
#define XOS_LOG_PLAIN_ERROR(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_error, message)
#define XOS_LOG_PLAIN_WARN(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_warn, message)
#define XOS_LOG_PLAIN_INFO(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_info, message)
#define XOS_LOG_PLAIN_DEBUG(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_debug, message)
#define XOS_LOG_PLAIN_TRACE(message) XOS_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_trace, message)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_LOG_LOCATION_DEBUG_TRACE(cond, message) \
{ if ((cond)) { XOS_LOG_LOCATION_DEBUG(message); } \
  else { XOS_LOG_LOCATION_TRACE(message); } }

#define XOS_LOG_FUNCTION_DEBUG_TRACE(cond, message) \
{ if ((cond)) { XOS_LOG_FUNCTION_DEBUG(message); } \
  else { XOS_LOG_FUNCTION_TRACE(message); } }

#define XOS_LOG_PLAIN_DEBUG_TRACE(cond, message) \
{ if ((cond)) { XOS_LOG_PLAIN_DEBUG(message); } \
  else { XOS_LOG_PLAIN_TRACE(message); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_IF_LOG_LOCATION_FATAL(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_fatal, message)
#define XOS_IF_LOG_LOCATION_ERROR(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_error, message)
#define XOS_IF_LOG_LOCATION_WARN(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_warn, message)
#define XOS_IF_LOG_LOCATION_INFO(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_info, message)
#define XOS_IF_LOG_LOCATION_DEBUG(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_debug, message)
#define XOS_IF_LOG_LOCATION_TRACE(message) XOS_IF_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::level_trace, message)

#define XOS_IF_LOG_FUNCTION_FATAL(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_fatal, message)
#define XOS_IF_LOG_FUNCTION_ERROR(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_error, message)
#define XOS_IF_LOG_FUNCTION_WARN(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_warn, message)
#define XOS_IF_LOG_FUNCTION_INFO(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_info, message)
#define XOS_IF_LOG_FUNCTION_DEBUG(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_debug, message)
#define XOS_IF_LOG_FUNCTION_TRACE(message) XOS_IF_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::level_trace, message)

#define XOS_IF_LOG_PLAIN_FATAL(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_fatal, message)
#define XOS_IF_LOG_PLAIN_ERROR(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_error, message)
#define XOS_IF_LOG_PLAIN_WARN(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_warn, message)
#define XOS_IF_LOG_PLAIN_INFO(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_info, message)
#define XOS_IF_LOG_PLAIN_DEBUG(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_debug, message)
#define XOS_IF_LOG_PLAIN_TRACE(message) XOS_IF_LOG_PLAIN(XOS_DEFAULT_LOGGER, ::xos::logger::level_trace, message)

#if defined(XOS_PLAIN_LOGGING)
#define XOS_LOG_FATAL XOS_LOG_PLAIN_FATAL
#define XOS_LOG_ERROR XOS_LOG_PLAIN_ERROR
#define XOS_LOG_WARN  XOS_LOG_PLAIN_WARN
#define XOS_LOG_INFO  XOS_LOG_PLAIN_INFO
#define XOS_LOG_DEBUG XOS_LOG_PLAIN_DEBUG
#define XOS_LOG_TRACE XOS_LOG_PLAIN_TRACE
#define XOS_LOG_DEBUG_TRACE XOS_LOG_PLAIN_DEBUG_TRACE
#else // defined(XOS_PLAIN_LOGGING)
#if defined(XOS_FUNCTION_LOGGING)
#define XOS_LOG_FATAL XOS_LOG_FUNCTION_FATAL
#define XOS_LOG_ERROR XOS_LOG_FUNCTION_ERROR
#define XOS_LOG_WARN  XOS_LOG_FUNCTION_WARN
#define XOS_LOG_INFO  XOS_LOG_FUNCTION_INFO
#define XOS_LOG_DEBUG XOS_LOG_FUNCTION_DEBUG
#define XOS_LOG_TRACE XOS_LOG_FUNCTION_TRACE
#define XOS_LOG_DEBUG_TRACE XOS_LOG_FUNCTION_DEBUG_TRACE
#else // defined(XOS_FUNCTION_LOGGING)
#define XOS_LOG_FATAL XOS_LOG_LOCATION_FATAL
#define XOS_LOG_ERROR XOS_LOG_LOCATION_ERROR
#define XOS_LOG_WARN  XOS_LOG_LOCATION_WARN
#define XOS_LOG_INFO  XOS_LOG_LOCATION_INFO
#define XOS_LOG_DEBUG XOS_LOG_LOCATION_DEBUG
#define XOS_LOG_TRACE XOS_LOG_LOCATION_TRACE
#define XOS_LOG_DEBUG_TRACE XOS_LOG_LOCATION_DEBUG_TRACE
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
#define XOS_LOG_LOCATION_MESSAGE_FATAL(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_fatal, message)
#define XOS_LOG_LOCATION_MESSAGE_ERROR(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_error, message)
#define XOS_LOG_LOCATION_MESSAGE_WARN(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_warn, message)
#define XOS_LOG_LOCATION_MESSAGE_INFO(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_info, message)
#define XOS_LOG_LOCATION_MESSAGE_DEBUG(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_debug, message)
#define XOS_LOG_LOCATION_MESSAGE_TRACE(message) XOS_LOG_LOCATION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_trace, message)

#define XOS_LOG_FUNCTION_MESSAGE_FATAL(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_fatal, message)
#define XOS_LOG_FUNCTION_MESSAGE_ERROR(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_error, message)
#define XOS_LOG_FUNCTION_MESSAGE_WARN(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_warn, message)
#define XOS_LOG_FUNCTION_MESSAGE_INFO(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_info, message)
#define XOS_LOG_FUNCTION_MESSAGE_DEBUG(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_debug, message)
#define XOS_LOG_FUNCTION_MESSAGE_TRACE(message) XOS_LOG_FUNCTION(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_trace, message)

#define XOS_LOG_PLAIN_MESSAGE_FATAL(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_fatal, message)
#define XOS_LOG_PLAIN_MESSAGE_ERROR(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_error, message)
#define XOS_LOG_PLAIN_MESSAGE_WARN(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_warn, message)
#define XOS_LOG_PLAIN_MESSAGE_INFO(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_info, message)
#define XOS_LOG_PLAIN_MESSAGE_DEBUG(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_debug, message)
#define XOS_LOG_PLAIN_MESSAGE_TRACE(message) XOS_LOG(XOS_DEFAULT_LOGGER, ::xos::logger::message_level_trace, message)

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
