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
typedef io::LoggerExtend LoggerTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LoggerT
///////////////////////////////////////////////////////////////////////
template
<class TExtends = LoggerTExtends, class TImplements = LoggerTImplements>

class _EXPORT_CLASS LoggerT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::Level Level;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LoggerT(Mutex& mutex, Level level): Extends(level), m_mutex(mutex) {
    }
    LoggerT(Mutex& mutex) : m_mutex(mutex) {
    }
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
protected:
    Mutex& m_mutex;
};
typedef LoggerT<> Logger;

} // namespace mt 
} // namespace crono 

#endif // _CRONO_MT_LOGGER_HPP 
