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
///   File: Created.hpp
///
/// Author: $author$
///   Date: 9/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_BASE_CREATED_HPP
#define _CRONO_BASE_CREATED_HPP

#include "crono/base/Attached.hpp"

namespace crono {

///////////////////////////////////////////////////////////////////////
///  Enum: CreateStatus
///////////////////////////////////////////////////////////////////////
enum CreateStatus {
    DestroySuccess,
    CreateSuccess = DestroySuccess,
    CreateFailed,
    DestroyFailed
};

typedef ImplementBase CreateException_implements;
typedef Base CreateException_extends;
///////////////////////////////////////////////////////////////////////
///  Class: CreateExceptiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = CreateException_implements,
 class TExtends = CreateException_extends>

class _EXPORT_CLASS CreateExceptiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CreateExceptiont(CreateStatus status): m_status(status) {}
    virtual ~CreateExceptiont() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual CreateStatus Status() const { return m_status; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    CreateStatus m_status;
};
typedef CreateExceptiont<> CreateException;


typedef ImplementBase CreatorImplements;
///////////////////////////////////////////////////////////////////////
///  Class: CreatorT
///////////////////////////////////////////////////////////////////////
template <class TImplements = CreatorImplements>
class _EXPORT_CLASS CreatorT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create() { return false; }
    virtual bool Destroy() { return false; }
    virtual bool Destroyed() {
        if ((IsCreated())) {
            return Destroy();
        }
        return true; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsCreated(bool isTrue = true) { return false; }
    virtual bool IsCreated() const { return false; }
    virtual bool IsDestroyed() const { return !IsCreated(); }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CreatorT<> Creator;

typedef Creator CreatedImplements;
typedef Base CreatedExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CreatedT
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TImplements = AttacherT
  <TAttached, TUnattached, VUnattached, CreatedImplements>,
 class TExtends = AttachedT
 <TAttached, TUnattached, VUnattached, TImplements, CreatedExtends> >

class _EXPORT_CLASS CreatedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TAttached Attached;
    static const TUnattached Unattached = VUnattached;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CreatedT(Attached attachedTo, bool isCreated)
    : Extends(attachedTo), m_isCreated(isCreated) {
    }
    CreatedT(const CreatedT& copy)
    : Extends(copy.attachedTo()), m_isCreated(false) {
    }
    CreatedT()
    : Extends(((Attached)Unattached)), m_isCreated(false) {
    }
    virtual ~CreatedT() {
        if (!(this->Destroyed())) {
            CreateException e(DestroyFailed);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached AttachCreated
    (Attached attachedTo, bool isCreated = true) {
        attachedTo = this->Attach(attachedTo);
        this->SetIsCreated(isCreated);
        return attachedTo;
    }
    virtual Attached DetachCreated(bool& isCreated){
        Attached detached = this->Detach();
        isCreated = this->IsCreated();
        this->SetIsCreated(false);
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached Attach(Attached attachedTo) {
        attachedTo = Extends::Attach(attachedTo);
        this->SetIsCreated(false);
        return attachedTo;
    }
    virtual Attached Detach(){
        Attached detached = Extends::Detach();
        this->SetIsCreated(false);
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsCreated(bool isTrue = true) {
        m_isCreated = isTrue;
        return m_isCreated;
    }
    virtual bool IsCreated() const {
        return m_isCreated;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_isCreated;
};

} // namespace crono

#endif // _CRONO_BASE_CREATED_HPP 
