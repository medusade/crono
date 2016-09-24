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
///   File: Mutex.hpp
///
/// Author: $author$
///   Date: 9/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_MT_POSIX_MUTEX_HPP
#define _CRONO_MT_POSIX_MUTEX_HPP

#include "crono/mt/Mutex.hpp"
#include "crono/base/Created.hpp"
#include "crono/base/Attached.hpp"

#include <pthread.h>
#include <time.h>
#include <errno.h>

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#if !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#define PTHREAD_MUTEX_HAS_TIMEDLOCK
#endif // !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#endif // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )

namespace crono {
namespace mt {
namespace posix {

typedef pthread_mutex_t* MutexTAttachedT;
typedef CreatorT<mt::Mutex> MutexTAttacherImplements;
typedef AttacherT<MutexTAttachedT, int, 0, MutexTAttacherImplements> MutexTAttacher;
typedef AttachedT<MutexTAttachedT, int, 0, MutexTAttacher> MutexTAttached;
typedef CreatedT<MutexTAttachedT, int, 0, MutexTAttacher, MutexTAttached> MutexTCreated;
typedef MutexTAttacher MutexTImplements;
typedef MutexTCreated MutexTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MutexT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MutexTImplements, class TExtends = MutexTExtends>

class _EXPORT_CLASS MutexT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MutexT(pthread_mutex_t* attachedTo, bool isCreated)
    : Extends(attachedTo, isCreated) {
    }
    MutexT(pthread_mutex_t* attachedTo): Extends(attachedTo) {
    }
    MutexT(bool initallyLocked) {
        if (!(this->Create(initallyLocked))) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    MutexT() {
        if (!(this->Create())) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    virtual ~MutexT() {
        if (!(this->Destroyed())) {
            CreateException e(DestroyFailed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(bool initallyLocked) {
        if (!(initallyLocked)) {
            return this->Create();
        }
        return false;
    }
    virtual bool Create() {
        pthread_mutex_t* detached = 0;
        if ((detached = CreateAttached())) {
            this->SetIsCreated();
            return detached;
        }
        return false;
    }
    virtual bool Destroy() {
        pthread_mutex_t* detached = 0;
        if ((detached = this->Detach())) {
            if ((DestroyDetached(detached))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual pthread_mutex_t* CreateAttached() {
        pthread_mutex_t* detached = 0;
        if ((this->Destroyed())) {
            if ((detached = CreateDetached(m_mutexattr, m_mutex))) {
                this->Attach(detached);
                return detached;
            }
        }
        return 0;
    }
    virtual pthread_mutex_t* CreateDetached
    (pthread_mutexattr_t& mutexattr, pthread_mutex_t& mutex) const {
        int err = 0;
        if (!(err = pthread_mutexattr_init(&mutexattr))) {
            if (!(err = pthread_mutex_init(&mutex, &mutexattr))) {
                if ((err = pthread_mutexattr_destroy(&mutexattr))) {
                    if ((err = pthread_mutex_destroy(&mutex))) {
                    }
                    return 0;
                }
                return &mutex;
            }
            if ((err = pthread_mutexattr_destroy(&mutexattr))) {
            }
        }
        return 0;
    }
    virtual bool DestroyDetached(pthread_mutex_t* mutex) const {
        if ((mutex)) {
            int err = 0;
            if (!(err = pthread_mutex_destroy(mutex))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() {
        pthread_mutex_t* mutex = 0;
        int err = 0;
        if ((mutex = this->m_attachedTo)) {
            if (!(err = pthread_mutex_lock(mutex))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Unlock() {
        pthread_mutex_t* mutex = 0;
        int err = 0;
        if ((mutex = this->m_attachedTo)) {
            if (!(err = pthread_mutex_unlock(mutex))) {
                return true;
            }
        }
        return false;
    }
    virtual LockStatus TryLock() {
        pthread_mutex_t* mutex = 0;
        if ((mutex = this->m_attachedTo)) {
            int err = 0;
            if ((err =  pthread_mutex_trylock(mutex))) {
                switch(err) {
                case ETIMEDOUT:
                    return LockBusy;
                case EINTR:
                    return LockInterrupted;
                default:
                    return LockFailed;
                }
            } else {
                return LockSuccess;
            }
        }
        return LockFailed;
    }
    virtual LockStatus TimedLock(mseconds_t waitMilliseconds) {
        if (0 < (waitMilliseconds)) {
#if defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
            pthread_mutex_t* mutex = 0;
            if ((mutex = this->m_attachedTo)) {
                int err = 0;
                struct timespec untilTime;
                clock_gettime(CLOCK_REALTIME, &untilTime);
                untilTime.tv_sec +=  waitMilliseconds/1000;
                untilTime.tv_nsec +=  (waitMilliseconds%1000)*1000;
                if ((err = pthread_mutex_timedlock(mutex, &untilTime))) {
                    switch(err) {
                    case ETIMEDOUT:
                        return LockBusy;
                    case EINTR:
                        return LockInterrupted;
                    default:
                        return LockFailed;
                    }
                } else {
                    return LockSuccess;
                }
            }
#else // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
            return LockInvalid;
#endif // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
        } else {
            if (0 > (waitMilliseconds)) {
                return UntimedLock();
            } else {
                return TryLock();
            }
        }
        return LockFailed;
    }
    virtual LockStatus UntimedLock() {
        pthread_mutex_t* mutex = 0;
        if ((mutex = this->m_attachedTo)) {
            int err = 0;
            if ((err =  pthread_mutex_lock(mutex))) {
                switch(err) {
                case ETIMEDOUT:
                    return LockBusy;
                case EINTR:
                    return LockInterrupted;
                default:
                    return LockFailed;
                }
            } else {
                return LockSuccess;
            }
        }
        return LockFailed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    pthread_mutexattr_t m_mutexattr;
    pthread_mutex_t m_mutex;
};
typedef MutexT<> Mutex;

} // namespace posix 
} // namespace mt 
} // namespace crono 

#endif // _CRONO_MT_POSIX_MUTEX_HPP 
