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
///   File: mutex.hpp
///
/// Author: $author$
///   Date: 5/5/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_MT_MUTEX_HPP
#define _CRONO_NADIR_MT_MUTEX_HPP

#include "crono/nadir/base/base.hpp"

namespace crono {
namespace mt {

typedef nadir::creatort<nadir::locked> mutext_implements;
///////////////////////////////////////////////////////////////////////
///  Class: mutext
///////////////////////////////////////////////////////////////////////
template <class TImplements = mutext_implements>

class _EXPORT_CLASS mutext: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef mutext<> mutex;

} // namespace mt 
} // namespace crono 

#endif // _CRONO_NADIR_MT_MUTEX_HPP 
