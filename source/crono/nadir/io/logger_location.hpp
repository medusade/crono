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
///   File: logger_location.hpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_NADIR_IO_LOGGER_LOCATION_HPP
#define _CRONO_NADIR_IO_LOGGER_LOCATION_HPP

#include "crono/nadir/io/logger_level.hpp"

namespace crono {
namespace io {

typedef char_string::Implements logger_functiont_implements;
typedef char_string logger_functiont_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger_functiont
///////////////////////////////////////////////////////////////////////
template
<class TImplements = logger_functiont_implements,
 class TExtends = logger_functiont_extends>

class _EXPORT_CLASS logger_functiont
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger_functiont(const char* name): Extends(name) {
    }
    logger_functiont(const logger_functiont& copy): Extends(copy) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef logger_functiont<> logger_function;

typedef char_string::Implements logger_locationt_implements;
typedef char_string logger_locationt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger_locationt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = logger_locationt_implements,
 class TExtends = logger_locationt_extends>

class _EXPORT_CLASS logger_locationt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger_locationt
    (const char* function_name, const char* file_name, size_t line_number)
    : function_name_(function_name),
      file_name_(file_name),
      line_number_(line_number) {
        combine();
    }
    logger_locationt(const logger_locationt& copy)
    : function_name_(copy.function_name_),
      file_name_(copy.file_name_),
      line_number_(copy.line_number_) {
        combine();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline logger_locationt& combine() {
        this->assign(file_name());
        this->append("["); this->append(line_number()); this->append("] ");
        this->append(function_name());
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline char_string function_name() const { return function_name_; }
    inline char_string file_name() const { return file_name_; }
    inline char_string line_number() const {
        return char_string().assign_unsigned(line_number_);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    char_string function_name_;
    char_string file_name_;
    size_t line_number_;
};
typedef logger_locationt<> logger_location;

} // namespace io
} // namespace crono 

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#if defined(_MSC_VER)
#define __CRONO_LOGGER_FUNCTION__ __FUNCTION__
#else // defined(_MSC_VER)
#endif // defined(_MSC_VER)

#if !defined(__CRONO_LOGGER_FUNCTION__)
#define __CRONO_LOGGER_FUNCTION__ __FUNCTION__
#endif // !defined(__CRONO_LOGGER_FUNCTION__)

#if !defined(CRONO_LOGGER_FUNCTION)
#define CRONO_LOGGER_FUNCTION \
    ::crono::io::logger_function(__CRONO_LOGGER_FUNCTION__)
#endif // !defined(CRONO_LOGGER_LOCATION)

#if !defined(CRONO_LOGGER_LOCATION)
#define CRONO_LOGGER_LOCATION \
    ::crono::io::logger_location(__CRONO_LOGGER_FUNCTION__, __FILE__, __LINE__)
#endif // !defined(CRONO_LOGGER_LOCATION)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // _CRONO_NADIR_IO_LOGGER_LOCATION_HPP
