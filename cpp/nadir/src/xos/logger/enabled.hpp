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
///   File: enabled.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_ENABLED_HPP
#define _XOS_LOGGER_ENABLED_HPP

#include "xos/logger/level.hpp"
#include "xos/base/locked.hpp"

namespace xos {
namespace logger {

typedef locked enabled_implements;
///////////////////////////////////////////////////////////////////////
///  class: enabled
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS enabled: virtual public enabled_implements {
public:
    typedef enabled_implements Implements;

    ///////////////////////////////////////////////////////////////////////
    /// function: enable_for/enabled_for
    ///////////////////////////////////////////////////////////////////////
    virtual level enable_for(const level& _level) {
        level enabled_for = this->enabled_for();
        return enabled_for;
    }
    virtual level enabled_for() const {
        level enabled_for = this->enabled_for_default();
        return enabled_for;
    }
    virtual bool is_enabled_for(const level& _level) const {
        level enabled_for = this->enabled_for();
        if ((_level) && (_level == (_level & enabled_for))) {
            return true;
        }
        return false;
    }
    virtual level enabled_for_default() const {
#if defined(TRACE_BUILD)
        return levels_trace;
#else // defined(tRACE_BUILD)
#if defined(DEBUG_BUILD)
        return levels_debug;
#else // defined(dEBUG_BUILD)
        return levels_error;
#endif // defined(dEBUG_BUILD)
#endif // defined(tRACE_BUILD)
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
} // namespace logger
} // namespace xos 

#endif // _XOS_LOGGER_ENABLED_HPP 
