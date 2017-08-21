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
///   File: Output.hpp
///
/// Author: $author$
///   Date: 8/8/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_OUTPUT_HPP
#define _XOS_LOGGER_OUTPUT_HPP

#include "xos/logger/Stdio.hpp"
#include "xos/logger/Enabled.hpp"

namespace xos {
namespace logger {

typedef Enabled OutputImplements;
///////////////////////////////////////////////////////////////////////
///  Class: Output
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Output: virtual public OutputImplements {
public:
    typedef OutputImplements Implements;
protected:
    ///////////////////////////////////////////////////////////////////////
    /// Function: Log/LogLn
    ///////////////////////////////////////////////////////////////////////
    virtual void Log(const Location& _location) {
        Log(_location.FileName().c_str());
        Log("[");
        Log(_location.LineNumber().c_str());
        Log("]");
        Log(" ");
        Log(_location.FunctionName().c_str());
        Log(": ");
    }
    virtual void Log(const Function& _function) {
        Log(_function.c_str());
        Log(": ");
    }
    virtual void Log(const Message& _message) {
        Log(_message.c_str());
    }
    virtual void Log(const char* chars, size_t length) {
        if ((chars) && (length)) {
            for (char c = *(chars); length; --length, c = *(++chars)) {
                ::std::cerr << c;
            }
        }
    }
    virtual void Log(const char* chars) {
        ::std::cerr << chars;
    }
    virtual void LogLn() {
        ::std::cerr << ::std::endl;
        ::std::cerr.flush();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace logger 
} // namespace xos 

#endif // _XOS_LOGGER_OUTPUT_HPP 
