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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 5/4/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_IO_LOGGER_HPP
#define _CRONO_NADIR_IO_LOGGER_HPP

#include "crono/nadir/io/logger_stdio.hpp"

namespace crono {
namespace io {

typedef locked loggert_implements;
///////////////////////////////////////////////////////////////////////
///  Class: loggert
///////////////////////////////////////////////////////////////////////
template
<typename TChar = char, typename TEndChar = TChar, TEndChar VEndChar = 0,
 class TImplements = loggert_implements>

class _EXPORT_CLASS loggert: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TChar char_t;
    typedef TEndChar end_char_t;
    enum { end_char = VEndChar };

    typedef logger_location location;
    typedef logger_function function;
    typedef logger_message message;

    typedef logger_level level;
    enum {
        level_none  = logger_level_none,
        level_fatal = logger_level_fatal,
        level_error = logger_level_error,
        level_warn  = logger_level_warn,
        level_info  = logger_level_info,
        level_debug = logger_level_debug,
        level_trace = logger_level_trace,
        all_level   = all_logger_level,
        level_all   = all_level,

        message_level_none  = logger_message_level_none,
        message_level_fatal = logger_message_level_fatal,
        message_level_error = logger_message_level_error,
        message_level_warn  = logger_message_level_warn,
        message_level_info  = logger_message_level_info,
        message_level_debug = logger_message_level_debug,
        message_level_trace = logger_message_level_trace,
        all_message_level   = all_logger_message_level,
        message_level_all   = all_message_level
    };
    enum {
        levels_none  = logger_levels_none,
        levels_fatal = logger_levels_fatal,
        levels_error = logger_levels_error,
        levels_warn  = logger_levels_warn,
        levels_info  = logger_levels_info,
        levels_debug = logger_levels_debug,
        levels_trace = logger_levels_trace,
        all_levels   = all_logger_levels,
        levels_all   = all_levels,

        message_levels_none  = logger_message_levels_none,
        message_levels_fatal = logger_message_levels_fatal,
        message_levels_error = logger_message_levels_error,
        message_levels_warn  = logger_message_levels_warn,
        message_levels_info  = logger_message_levels_info,
        message_levels_debug = logger_message_levels_debug,
        message_levels_trace = logger_message_levels_trace,
        all_message_levels   = all_logger_message_levels,
        message_levels_all   = all_message_levels
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() { return true; }
    virtual bool fini() { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() { return true; }
    virtual bool unlock() { return true; }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const location& _location, const message& _message) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            this->log(_message.chars());
            this->logln();
        }
    }
    virtual void log
    (const level& _level, const function& _function, const message& _message) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_function);
            this->log(_message.chars());
            this->logln();
        }
    }
    virtual void log
    (const level& _level, const message& _message) {
        locker lock(*this);
        if ((this->is_enabled_for(_level))) {
            this->log(_message);
            this->logln();
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void enable_for(const level& _level) {}
    virtual level enabled_for() const { return enabled_for_default(); }
    virtual level enabled_for_default() const {
#if defined(TRACE_BUILD)
        return (levels_trace | message_levels_trace);
#else // defined(TRACE_BUILD)
#if defined(DEBUG_BUILD)
        return (levels_debug | message_levels_debug);
#else // defined(DEBUG_BUILD)
        return (levels_error | message_levels_error);
#endif // defined(DEBUG_BUILD)
#endif // defined(TRACE_BUILD)
    }
    virtual bool is_enabled_for(const level& _level) const {
        level _enabled_for = enabled_for();
        level anded = _enabled_for & _level;
        if ((_level) && (_level == (_enabled_for & _level))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static loggert* set_the_logger(loggert* to) {
        the_logger() = to;
        return the_logger();
    }
    static loggert* get_the_logger() {
        return the_logger();
    }
protected:
    static loggert*& the_logger() {
        static loggert *the_logger = 0;
        return the_logger;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log(const location& _location) {
        log(_location.file_name().chars());
        log("[");
        log(_location.line_number().chars());
        log("]");
        log(" ");
        log(_location.function_name().chars());
        log(": ");
    }
    virtual void log(const function& _function) {
        log(_function.chars());
        log(": ");
    }
    virtual void log(const message& _message) {
        log(_message.chars());
    }
    virtual void log(const char* chars) {
        ::std::cerr << chars;
    }
    virtual void logln() {
        ::std::cerr << ::std::endl;
        ::std::cerr.flush();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef loggert<> logger;

typedef logger logger_extendt_implements;
typedef base logger_extendt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger_extendt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = logger_extendt_implements,
 class TExtends = logger_extendt_extends>

class _EXPORT_CLASS logger_extendt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef logger_level level;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger_extendt()
    : old_logger_(this->the_logger()),
      enabled_for_(this->enabled_for_default()) {
        this->the_logger() = this;
    }
    virtual ~logger_extendt() {
        if (this == this->the_logger()) {
            this->the_logger() = old_logger_;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void enable_for(const level& _level) {
        enabled_for_ = _level;
    }
    virtual level enabled_for() const {
        return enabled_for_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    logger* old_logger_;
    level enabled_for_;
};
typedef logger_extendt<> logger_extend;

} // namespace io
} // namespace crono 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_SET_DEFAULT_LOGGER(to) ::crono::io::logger::set_the_logger(to)

#if !defined(CRONO_USE_LOGGER)
#define CRONO_DEFAULT_LOGGER ::crono::io::logger::get_the_logger()
#endif // !defined(CRONO_USE_LOGGER)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_INIT_LOGGER(logger_) { \
::crono::io::logger* logger = logger_; \
if ((logger)) { logger->init(); } }

#define CRONO_FINI_LOGGER(logger_) { \
::crono::io::logger* logger = logger_; \
if ((logger)) { logger->fini(); } }

#define CRONO_LOGGER_INIT() CRONO_INIT_LOGGER(CRONO_DEFAULT_LOGGER)
#define CRONO_LOGGER_FINI() CRONO_FINI_LOGGER(CRONO_DEFAULT_LOGGER)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_SET_LOGGER_LEVEL(logger_, level_) { \
::crono::io::logger* logger = logger_; \
if ((logger)) { logger->enable_for(level_); } }

#define CRONO_GET_LOGGER_LEVEL(logger_) \
((logger_)?(logger_->enabled_for()):(::crono::io::logger::level \
(::crono::io::logger::levels_none)))

#define CRONO_SET_LOGGING_LEVEL(level)  CRONO_SET_LOGGER_LEVEL(CRONO_DEFAULT_LOGGER, level)
#define CRONO_GET_LOGGING_LEVEL(level)  (level = CRONO_GET_LOGGER_LEVEL(CRONO_DEFAULT_LOGGER))

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_LOG_LOCATION(logger_, level_, message_) { \
::crono::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::crono::io::logger::message message; \
   logger->log(level_, CRONO_LOGGER_LOCATION, message << message_); } }

#define CRONO_LOG_FUNCTION(logger_, level_, message_) { \
::crono::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::crono::io::logger::message message; \
   logger->log(level_, CRONO_LOGGER_FUNCTION, message << message_); } }

#define CRONO_LOG_MESSAGE(logger_, level_, message_) { \
::crono::io::logger* logger = logger_; \
if ((logger)?(logger->is_enabled_for(level_)):(false)) {\
   ::crono::io::logger::message message; \
   logger->log(level_, message << message_); } }

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if defined(CRONO_LOCATION_LOGGING)
#define CRONO_LOG(logger_, level_, message_) CRONO_LOG_LOCATION(logger_, level_, message_)
#else // defined(CRONO_LOCATION_LOGGING)
#if defined(CRONO_FUNCTION_LOGGING)
#define CRONO_LOG(logger_, level_, message_) CRONO_LOG_FUNCTION(logger_, level_, message_)
#else // defined(CRONO_FUNCTION_LOGGING)
#define CRONO_LOG(logger_, level_, message_) CRONO_LOG_MESSAGE(logger_, level_, message_)
#endif // defined(CRONO_FUNCTION_LOGGING)
#endif // defined(CRONO_LOCATION_LOGGING)

#define CRONO_LOG_FATAL(message_) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::logger::level_fatal, message_)
#define CRONO_LOG_ERROR(message_) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::logger::level_error, message_)
#define CRONO_LOG_WARN(message_) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::logger::level_warn, message_)
#define CRONO_LOG_INFO(message_) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::logger::level_info, message_)
#define CRONO_LOG_DEBUG(message_) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::logger::level_debug, message_)
#define CRONO_LOG_TRACE(message_) CRONO_LOG(CRONO_DEFAULT_LOGGER, ::crono::io::logger::level_trace, message_)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _CRONO_NADIR_IO_LOGGER_HPP
