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
///   File: location.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_LOCATION_HPP
#define _XOS_LOGGER_LOCATION_HPP

#include "xos/logger/function.hpp"

namespace xos {
namespace logger {

typedef string_implements location_implements;
typedef string location_extends;
///////////////////////////////////////////////////////////////////////
///  class: location
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS location
: virtual public location_implements, public location_extends {
public:
    typedef location_implements Implements;
    typedef location_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// constructor: location
    ///////////////////////////////////////////////////////////////////////
    location
    (const string& function_name, const string& file_name, size_t line_number)
    : m_function_name(function_name),
      m_file_name(file_name), m_line_number(line_number) {
    }
    location
    (const char* function_name, const char* file_name, size_t line_number)
    : m_function_name(function_name),
      m_file_name(file_name), m_line_number(line_number) {
    }
    location(const location& copy)
    : m_function_name(copy.m_function_name),
      m_file_name(copy.m_file_name), m_line_number(copy.m_line_number) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline string function_name() const { return m_function_name; }
    inline string file_name() const { return m_file_name; }
    inline string line_number() const {
        string::from_unsigned from(m_line_number);
        string s(from);
        return s;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string m_function_name;
    string m_file_name;
    size_t m_line_number;
};

} // namespace logger
} // namespace xos 

#endif // _XOS_LOGGER_LOCATION_HPP 
