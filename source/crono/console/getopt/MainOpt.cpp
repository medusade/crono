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
///   File: MainOpt.cpp
///
/// Author: $author$
///   Date: 12/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_CONSOLE_GETOPT_MAIN_HPP
#include "crono/console/getopt/MainOpt.hpp"
#include "patrona/console/getopt/Main.hpp"

namespace crono {
namespace console {
namespace getopt {

typedef ::patrona::console::getopt::MainImplements MainImplements;
typedef ::patrona::console::getopt::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main() {
    }
    virtual ~Main() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#endif // _CRONO_CONSOLE_GETOPT_MAIN_HPP

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
            case CRONO_MAIN_LOGGING_OPTARG_C_ALL:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_ALL | CRONO_LOGGING_MESSAGE_LEVELS_ALL);
                break;
            case '0':
            case CRONO_MAIN_LOGGING_OPTARG_C_NONE:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_NONE | CRONO_LOGGING_MESSAGE_LEVELS_NONE);
                break;

            case '1':
            case CRONO_MAIN_LOGGING_OPTARG_C_FATAL:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_FATAL | CRONO_LOGGING_MESSAGE_LEVELS_FATAL);
                break;
            case '2':
            case CRONO_MAIN_LOGGING_OPTARG_C_ERROR:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_ERROR | CRONO_LOGGING_MESSAGE_LEVELS_ERROR);
                break;
            case '3':
            case CRONO_MAIN_LOGGING_OPTARG_C_WARN:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_WARN | CRONO_LOGGING_MESSAGE_LEVELS_WARN);
                break;
            case '4':
            case CRONO_MAIN_LOGGING_OPTARG_C_INFO:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_INFO | CRONO_LOGGING_MESSAGE_LEVELS_INFO);
                break;
            case '5':
            case CRONO_MAIN_LOGGING_OPTARG_C_DEBUG:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_DEBUG | CRONO_LOGGING_MESSAGE_LEVELS_DEBUG);
                break;
            case '6':
            case CRONO_MAIN_LOGGING_OPTARG_C_TRACE:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_TRACE | CRONO_LOGGING_MESSAGE_LEVELS_TRACE);
                break;

            case CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_FATAL:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_FATAL | CRONO_LOGGING_MESSAGE_LEVELS_FATAL);
                break;
            case CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_ERROR:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_LEVELS_ERROR | CRONO_LOGGING_MESSAGE_LEVELS_ERROR);
                break;
            case CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_WARN:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_MESSAGE_LEVELS_WARN);
                break;
            case CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_INFO:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_MESSAGE_LEVELS_INFO);
                break;
            case CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_DEBUG:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_MESSAGE_LEVELS_DEBUG);
                break;
            case CRONO_MAIN_LOGGING_OPTARG_C_MESSAGE_TRACE:
                CRONO_SET_LOGGING_LEVEL(CRONO_LOGGING_MESSAGE_LEVELS_TRACE);
                break;

            default:
                err = OnInvalidOptionArg
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
        case CRONO_MAIN_LOGGING_OPTVAL_C:
            err = OnLoggingOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case CRONO_MAIN_LOGGING_OPTVAL_C:
            optarg = CRONO_MAIN_LOGGING_OPTARG;
            chars = CRONO_MAIN_LOGGING_OPTUSE;
            break;
        default:
            chars = Extends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = CRONO_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            CRONO_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Arguments(const char_t**& argv) {
        static const char_t* _args = CRONO_MAIN_ARGS;
        static const char_t* _argv[] = {
            CRONO_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

#ifndef _CRONO_CONSOLE_GETOPT_MAIN_HPP
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace getopt
} // namespace console 
} // namespace crono 
#endif //_CRONO_CONSOLE_GETOPT_MAIN_HPP
