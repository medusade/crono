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
///   File: output.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_OUTPUT_HPP
#define _XOS_LOGGER_OUTPUT_HPP

#include "xos/logger/stdio.hpp"
#include "xos/logger/enabled.hpp"

namespace xos {
namespace logger {

typedef enabled output_implements;
///////////////////////////////////////////////////////////////////////
///  class: output
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS output: virtual public output_implements {
public:
    typedef output_implements implements;
protected:
    ///////////////////////////////////////////////////////////////////////
    /// function: log/log_ln
    ///////////////////////////////////////////////////////////////////////
    virtual void log(const location& _location) {
        log(_location.file_name().c_str());
        log("[");
        log(_location.line_number().c_str());
        log("]");
        log(" ");
        log(_location.function_name().c_str());
        log(": ");
    }
    virtual void log(const function& _function) {
        log(_function.c_str());
        log(": ");
    }
    virtual void log(const message& _message) {
        log(_message.c_str());
    }
    virtual void log(const char* chars, size_t length) {
        if ((chars) && (length)) {
            for (char c = *(chars); length; --length, c = *(++chars)) {
                ::std::cerr << c;
            }
        }
    }
    virtual void log(const char* chars) {
        ::std::cerr << chars;
    }
    virtual void log_ln() {
        ::std::cerr << ::std::endl;
        ::std::cerr.flush();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace logger
} // namespace xos 

#endif // _XOS_LOGGER_OUTPUT_HPP 
