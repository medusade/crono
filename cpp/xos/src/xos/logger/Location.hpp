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
///   File: Location.hpp
///
/// Author: $author$
///   Date: 8/8/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_LOCATION_HPP
#define _XOS_LOGGER_LOCATION_HPP

#include "xos/logger/Function.hpp"

namespace xos {
namespace logger {

typedef StringImplements LocationImplements;
typedef String LocationExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Location
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Location
: virtual public LocationImplements, public LocationExtends {
public:
    typedef LocationImplements Implements;
    typedef LocationExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: Location
    ///////////////////////////////////////////////////////////////////////
    Location
    (const String& functionName, const String& fileName, size_t lineNumber)
    : m_functionName(functionName),
      m_fileName(fileName), m_lineNumber(lineNumber) {
    }
    Location
    (const char* functionName, const char* fileName, size_t lineNumber)
    : m_functionName(functionName),
      m_fileName(fileName), m_lineNumber(lineNumber) {
    }
    Location(const Location& copy)
    : m_functionName(copy.m_functionName),
      m_fileName(copy.m_fileName), m_lineNumber(copy.m_lineNumber) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline String FunctionName() const { return m_functionName; }
    inline String FileName() const { return m_fileName; }
    inline String LineNumber() const {
        String::from_unsigned from(m_lineNumber);
        String s(from);
        return s;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_functionName;
    String m_fileName;
    size_t m_lineNumber;
};

} // namespace logger 
} // namespace xos 

#endif // _XOS_LOGGER_LOCATION_HPP 
