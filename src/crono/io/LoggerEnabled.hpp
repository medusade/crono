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
///   File: LoggerEnabled.hpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_IO_LOGGERENABLED_HPP
#define _CRONO_IO_LOGGERENABLED_HPP

#if defined(USE_NADIR_BASE)
#else // defined(USE_NADIR_BASE)
#include "crono/base/Base.hpp"
#include "crono/base/Locked.hpp"

namespace crono {
namespace io {

typedef Locked LoggerEnabledImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LoggerEnabled
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS LoggerEnabled: virtual public LoggerEnabledImplements {
public:
    typedef LoggerEnabledImplements Implements;

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

        LevelAll   = ((LevelTrace << 1) - 1),

        MessageLevelNone  = 0,

        MessageLevelFatal = (LevelTrace << 1),
        MessageLevelError = (MessageLevelFatal << 1),
        MessageLevelWarn  = (MessageLevelError << 1),
        MessageLevelInfo  = (MessageLevelWarn << 1),
        MessageLevelDebug = (MessageLevelInfo << 1),
        MessageLevelTrace = (MessageLevelDebug << 1),

        MessageLevelAll   = ((LevelAll << LevelTrace))
    };
    typedef Level Levels;
    enum {
        LevelsNone  = 0,

        LevelsFatal = 1,
        LevelsError = (((LevelsFatal + 1) << 1) - 1),
        LevelsWarn  = (((LevelsError + 1) << 1) - 1),
        LevelsInfo  = (((LevelsWarn + 1) << 1) - 1),
        LevelsDebug = (((LevelsInfo + 1) << 1) - 1),
        LevelsTrace = (((LevelsDebug + 1) << 1) - 1),

        LevelsAll   = LevelsTrace,

        MessageLevelsNone  = 0,

        MessageLevelsFatal = (((LevelsFatal) << LevelTrace)),
        MessageLevelsError = (((LevelsError) << LevelTrace)),
        MessageLevelsWarn  = (((LevelsWarn) << LevelTrace)),
        MessageLevelsInfo  = (((LevelsInfo) << LevelTrace)),
        MessageLevelsDebug = (((LevelsDebug) << LevelTrace)),
        MessageLevelsTrace = (((LevelsTrace) << LevelTrace)),

        MessageLevelsAll   = MessageLevelsTrace
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void EnableFor(const Level& _level) {}
    virtual Level EnabledFor() const { return EnabledForDefault(); }
    virtual bool IsEnabledFor(const Level& _level) const {
        Level enabledFor = EnabledFor();
        if ((_level) && (_level == (_level & enabledFor))) {
            return true;
        }
        return false;
    }
    virtual Level EnabledForDefault() const {
#if defined(TRACE_BUILD)
        return LevelsTrace;
#else // defined(TRACE_BUILD)
#if defined(DEBUG_BUILD)
        return LevelsDebug;
#else // defined(DEBUG_BUILD)
        return LevelsError;
#endif // defined(DEBUG_BUILD)
#endif // defined(TRACE_BUILD)
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace io 
} // namespace crono 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_LOGGING_LEVELS ::crono::io::LoggerEnabled::Level
#define CRONO_LOGGING_LEVELS_ALL ::crono::io::LoggerEnabled::LevelsAll
#define CRONO_LOGGING_LEVELS_NONE ::crono::io::LoggerEnabled::LevelsNone
#define CRONO_LOGGING_LEVELS_FATAL ::crono::io::LoggerEnabled::LevelsFatal
#define CRONO_LOGGING_LEVELS_ERROR ::crono::io::LoggerEnabled::LevelsError
#define CRONO_LOGGING_LEVELS_WARN ::crono::io::LoggerEnabled::LevelsWarn
#define CRONO_LOGGING_LEVELS_INFO ::crono::io::LoggerEnabled::LevelsInfo
#define CRONO_LOGGING_LEVELS_DEBUG ::crono::io::LoggerEnabled::LevelsDebug
#define CRONO_LOGGING_LEVELS_TRACE ::crono::io::LoggerEnabled::LevelsTrace

#define CRONO_LOGGING_MESSAGE_LEVELS ::crono::io::LoggerEnabled::MessageLevel
#define CRONO_LOGGING_MESSAGE_LEVELS_ALL ::crono::io::LoggerEnabled::MessageLevelsAll
#define CRONO_LOGGING_MESSAGE_LEVELS_NONE ::crono::io::LoggerEnabled::MessageLevelsNone
#define CRONO_LOGGING_MESSAGE_LEVELS_FATAL ::crono::io::LoggerEnabled::MessageLevelsFatal
#define CRONO_LOGGING_MESSAGE_LEVELS_ERROR ::crono::io::LoggerEnabled::MessageLevelsError
#define CRONO_LOGGING_MESSAGE_LEVELS_WARN ::crono::io::LoggerEnabled::MessageLevelsWarn
#define CRONO_LOGGING_MESSAGE_LEVELS_INFO ::crono::io::LoggerEnabled::MessageLevelsInfo
#define CRONO_LOGGING_MESSAGE_LEVELS_DEBUG ::crono::io::LoggerEnabled::MessageLevelsDebug
#define CRONO_LOGGING_MESSAGE_LEVELS_TRACE ::crono::io::LoggerEnabled::MessageLevelsTrace

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
#endif // defined(USE_NADIR_BASE)

#endif // _CRONO_IO_LOGGERENABLED_HPP 
