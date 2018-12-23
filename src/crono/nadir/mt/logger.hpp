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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_MT_LOGGER_HPP
#define _CRONO_NADIR_MT_LOGGER_HPP

#include "crono/nadir/io/logger.hpp"
#include "crono/nadir/mt/os/mutex.hpp"

namespace crono {
namespace mt {

typedef io::loggert_implements loggert_implements;
typedef io::logger_extend loggert_extends;
///////////////////////////////////////////////////////////////////////
///  Class: loggert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = loggert_implements, class TExtends = loggert_extends>

class _EXPORT_CLASS loggert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    loggert(os::mutex& mutex): mutex_(mutex) {
    }
    loggert() {
    }
    virtual ~loggert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() {
        return mutex_.lock();
    }
    virtual bool unlock() {
        return mutex_.unlock();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    os::mutex mutex_;
};
typedef loggert<> logger;

} // namespace mt 
} // namespace crono 

#endif // _CRONO_NADIR_MT_LOGGER_HPP 
