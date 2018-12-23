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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 11/6/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_CONSOLE_GETOPT_MAINOPT_HPP
#define _CRONO_CONSOLE_GETOPT_MAINOPT_HPP

#include "patrona/cpp/xos/console/getopt/MainOpt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_MAIN_LOGGING_OPT "logging-level"
#define CRONO_MAIN_LOGGING_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define CRONO_MAIN_LOGGING_OPTARG_RESULT 0
#define CRONO_MAIN_LOGGING_OPTARG "{(a)all | (n)none | (f)fatal | (e)error | (w)waring | (i)info | (d)debug | (t)trace}"
#define CRONO_MAIN_LOGGING_OPTARG_C_ALL 'a'
#define CRONO_MAIN_LOGGING_OPTARG_C_NONE 'n'
#define CRONO_MAIN_LOGGING_OPTARG_C_FATAL 'f'
#define CRONO_MAIN_LOGGING_OPTARG_C_ERROR 'e'
#define CRONO_MAIN_LOGGING_OPTARG_C_WARN 'w'
#define CRONO_MAIN_LOGGING_OPTARG_C_INFO 'i'
#define CRONO_MAIN_LOGGING_OPTARG_C_DEBUG 'd'
#define CRONO_MAIN_LOGGING_OPTARG_C_TRACE 't'
#define CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_FATAL 'F'
#define CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_ERROR 'E'
#define CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_WARN 'W'
#define CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_INFO 'I'
#define CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_DEBUG 'D'
#define CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_TRACE 'T'
#define CRONO_MAIN_LOGGING_OPTUSE ""
#define CRONO_MAIN_LOGGING_OPTVAL_S "l:"
#define CRONO_MAIN_LOGGING_OPTVAL_C 'l'
#define CRONO_MAIN_LOGGING_OPTION \
   {CRONO_MAIN_LOGGING_OPT, \
    CRONO_MAIN_LOGGING_OPTARG_REQUIRED, \
    CRONO_MAIN_LOGGING_OPTARG_RESULT, \
    CRONO_MAIN_LOGGING_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_MAIN_OPTIONS_CHARS \
    CRONO_MAIN_LOGGING_OPTVAL_S \
    MAIN_OPTIONS_CHARS

#define CRONO_MAIN_OPTIONS_OPTIONS \
    CRONO_MAIN_LOGGING_OPTION \
    MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_MAIN_ARGS 0
#define CRONO_MAIN_ARGV

namespace crono {
namespace console {
namespace getopt {

} // namespace getopt 
} // namespace console 
} // namespace crono 

#endif // _CRONO_CONSOLE_GETOPT_MAINOPT_HPP 
