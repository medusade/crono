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
///   Date: 9/23/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_MT_LOGGER_HPP
#define _CRONO_MT_LOGGER_HPP

#include "crono/io/Logger.hpp"
#include "crono/mt/Mutex.hpp"

namespace crono {
namespace mt {

typedef io::Logger LoggerTImplements;
typedef Base LoggerTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LoggerT
///////////////////////////////////////////////////////////////////////
template
<class TExtends = LoggerTExtends, class TImplements = LoggerTImplements>

class _EXPORT_CLASS LoggerT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef io::Logger::Level Level;
    static const Level LevelNone = io::Logger::LevelNone;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LoggerT(Mutex& mutex, Level level)
    : m_mutex(mutex), m_level(level) {
    }
    LoggerT(Mutex& mutex)
    : m_mutex(mutex), m_level(LevelNone) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ~LoggerT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() {
        return m_mutex.Lock();
    }
    virtual bool Unlock() {
        return m_mutex.Unlock();
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
    Mutex& m_mutex;
    Level m_level;
};
typedef LoggerT<> Logger;

} // namespace mt 
} // namespace crono 

#endif // _CRONO_MT_LOGGER_HPP 
        

