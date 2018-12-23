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
///   File: MainLogger.hpp
///
/// Author: $author$
///   Date: 2/19/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_CONSOLE_MAINLOGGER_HPP
#define _CRONO_CONSOLE_MAINLOGGER_HPP

#include "crono/console/Main.hpp"
#include "crono/io/Logger.hpp"

namespace crono {
namespace console {

typedef io::Logger MainLoggerTImplements;
typedef io::LoggerExtend MainLoggerTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainLoggerT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MainLoggerTImplements, class TExtends = MainLoggerTExtends>
class MainLoggerT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Extends::Level Level;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainLoggerT(Main& main, Level level): Extends(level), m_main(main) {
    }
    MainLoggerT(Main& main): m_main(main) {
    }
    virtual ~MainLoggerT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() {
        return m_main.Lock();
    }
    virtual bool Unlock() {
        return m_main.Unlock();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Main& m_main;
};
typedef MainLoggerT<> MainLogger;

} // namespace console 
} // namespace crono 

#endif // _CRONO_CONSOLE_MAINLOGGER_HPP 
        

