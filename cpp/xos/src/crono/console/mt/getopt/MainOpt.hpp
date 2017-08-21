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
///   Date: 8/20/2017
///////////////////////////////////////////////////////////////////////
#ifndef _CRONO_CONSOLE_MT_GETOPT_MAINOPT_HPP
#define _CRONO_CONSOLE_MT_GETOPT_MAINOPT_HPP

#include "crono/console/getopt/MainOpt.hpp"
#include "fila/console/mt/getopt/MainOpt.hpp"

namespace crono {
namespace console {
namespace mt {
namespace getopt {

typedef crono::console::getopt::MainOptT
<fila::console::mt::getopt::MainOpt> MainOptImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOptT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainOptImplements>

class _EXPORT_CLASS MainOptT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainOptT<> MainOpt;

} // namespace getopt
} // namespace mt 
} // namespace console 
} // namespace crono 

#endif // _CRONO_CONSOLE_MT_GETOPT_MAINOPT_HPP 
