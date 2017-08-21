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
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 8/15/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_CONSOLE_GETOPT_MAINOPT_HPP
#define _CRONO_CONSOLE_GETOPT_MAINOPT_HPP

#include "nadir/console/getopt/MainOpt.hpp"
#include "xos/logger/Interface.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define MAIN_LOGGING_OPT "logging-level"
#define MAIN_LOGGING_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define MAIN_LOGGING_OPTARG_RESULT 0
#define MAIN_LOGGING_OPTARG_S_ALL "(a)all"
#define MAIN_LOGGING_OPTARG_S_NONE "(n)none"
#define MAIN_LOGGING_OPTARG_S_FATAL "(f)fatal"
#define MAIN_LOGGING_OPTARG_S_ERROR "(e)error"
#define MAIN_LOGGING_OPTARG_S_WARN "(w)warn"
#define MAIN_LOGGING_OPTARG_S_INFO "(i)info"
#define MAIN_LOGGING_OPTARG_S_DEBUG "(d)debug"
#define MAIN_LOGGING_OPTARG_S_TRACE "(t)trace}"
#define MAIN_LOGGING_OPTARG "{ " \
    MAIN_LOGGING_OPTARG_S_ALL " | " \
    MAIN_LOGGING_OPTARG_S_NONE " | " \
    MAIN_LOGGING_OPTARG_S_FATAL " | " \
    MAIN_LOGGING_OPTARG_S_ERROR " | " \
    MAIN_LOGGING_OPTARG_S_WARN " | " \
    MAIN_LOGGING_OPTARG_S_INFO " | " \
    MAIN_LOGGING_OPTARG_S_DEBUG " | " \
    MAIN_LOGGING_OPTARG_S_TRACE  " }"
#define MAIN_LOGGING_OPTARG_C_ALL 'a'
#define MAIN_LOGGING_OPTARG_C_NONE 'n'
#define MAIN_LOGGING_OPTARG_C_FATAL 'f'
#define MAIN_LOGGING_OPTARG_C_ERROR 'e'
#define MAIN_LOGGING_OPTARG_C_WARN 'w'
#define MAIN_LOGGING_OPTARG_C_INFO 'i'
#define MAIN_LOGGING_OPTARG_C_DEBUG 'd'
#define MAIN_LOGGING_OPTARG_C_TRACE 't'
#define MAIN_LOGGING_OPTARG_C_MESSAGE_FATAL 'F'
#define MAIN_LOGGING_OPTARG_C_MESSAGE_ERROR 'E'
#define MAIN_LOGGING_OPTARG_C_MESSAGE_WARN 'W'
#define MAIN_LOGGING_OPTARG_C_MESSAGE_INFO 'I'
#define MAIN_LOGGING_OPTARG_C_MESSAGE_DEBUG 'D'
#define MAIN_LOGGING_OPTARG_C_MESSAGE_TRACE 'T'
#define MAIN_LOGGING_OPTUSE ""
#define MAIN_LOGGING_OPTVAL_S "l:"
#define MAIN_LOGGING_OPTVAL_C 'l'
#define MAIN_LOGGING_OPTION \
   {MAIN_LOGGING_OPT, \
    MAIN_LOGGING_OPTARG_REQUIRED, \
    MAIN_LOGGING_OPTARG_RESULT, \
    MAIN_LOGGING_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_CONSOLE_MAIN_OPTIONS_CHARS \
    MAIN_LOGGING_OPTVAL_S \
    NADIR_CONSOLE_MAIN_OPTIONS_CHARS

#define CRONO_CONSOLE_MAIN_OPTIONS_OPTIONS \
    MAIN_LOGGING_OPTION \
    NADIR_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define CRONO_CONSOLE_MAIN_ARGS 0
#define CRONO_CONSOLE_MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace crono {
namespace console {
namespace getopt {

typedef nadir::console::getopt::MainOpt MainOptImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOptT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainOptImplements>

class _EXPORT_CLASS MainOptT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnLoggingOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        char c = 0;
        if ((optarg) && (c = optarg[0]) && (!optarg[1])) {
            switch(c) {

            case '7':
            case MAIN_LOGGING_OPTARG_C_ALL:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_ALL | XOS_LOGGING_MESSAGE_LEVELS_ALL);
                break;
            case '0':
            case MAIN_LOGGING_OPTARG_C_NONE:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_NONE | XOS_LOGGING_MESSAGE_LEVELS_NONE);
                break;

            case '1':
            case MAIN_LOGGING_OPTARG_C_FATAL:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_FATAL | XOS_LOGGING_MESSAGE_LEVELS_FATAL);
                break;
            case '2':
            case MAIN_LOGGING_OPTARG_C_ERROR:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_ERROR | XOS_LOGGING_MESSAGE_LEVELS_ERROR);
                break;
            case '3':
            case MAIN_LOGGING_OPTARG_C_WARN:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_WARN | XOS_LOGGING_MESSAGE_LEVELS_WARN);
                break;
            case '4':
            case MAIN_LOGGING_OPTARG_C_INFO:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_INFO | XOS_LOGGING_MESSAGE_LEVELS_INFO);
                break;
            case '5':
            case MAIN_LOGGING_OPTARG_C_DEBUG:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_DEBUG | XOS_LOGGING_MESSAGE_LEVELS_DEBUG);
                break;
            case '6':
            case MAIN_LOGGING_OPTARG_C_TRACE:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_TRACE | XOS_LOGGING_MESSAGE_LEVELS_TRACE);
                break;

            case MAIN_LOGGING_OPTARG_C_MESSAGE_FATAL:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_FATAL | XOS_LOGGING_MESSAGE_LEVELS_FATAL);
                break;
            case MAIN_LOGGING_OPTARG_C_MESSAGE_ERROR:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_LEVELS_ERROR | XOS_LOGGING_MESSAGE_LEVELS_ERROR);
                break;
            case MAIN_LOGGING_OPTARG_C_MESSAGE_WARN:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_MESSAGE_LEVELS_WARN);
                break;
            case MAIN_LOGGING_OPTARG_C_MESSAGE_INFO:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_MESSAGE_LEVELS_INFO);
                break;
            case MAIN_LOGGING_OPTARG_C_MESSAGE_DEBUG:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_MESSAGE_LEVELS_DEBUG);
                break;
            case MAIN_LOGGING_OPTARG_C_MESSAGE_TRACE:
                XOS_SET_LOGGING_LEVEL(XOS_LOGGING_MESSAGE_LEVELS_TRACE);
                break;

            default:
                err = this->OnInvalidOptionArg
                (optval, optarg, optname, optind, argc, argv, env);
                break;
            }
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case MAIN_LOGGING_OPTVAL_C:
            err = OnLoggingOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Implements::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case MAIN_LOGGING_OPTVAL_C:
            optarg = MAIN_LOGGING_OPTARG;
            chars = MAIN_LOGGING_OPTUSE;
            break;
        default:
            chars = Implements::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = CRONO_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            CRONO_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    virtual const char_t* Arguments(const char_t**& argv) {
        static const char_t* _args = CRONO_CONSOLE_MAIN_ARGS;
        static const char_t* _argv[] = {
            CRONO_CONSOLE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainOptT<> MainOpt;

} // namespace getopt
} // namespace console 
} // namespace crono 

#endif // _CRONO_CONSOLE_GETOPT_MAINOPT_HPP 
