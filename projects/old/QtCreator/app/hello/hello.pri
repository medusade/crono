########################################################################
# Copyright (c) 1988-2016 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: hello.pri
#
# Author: $author$
#   Date: 9/22/2016
########################################################################

hello_TARGET = crono-hello

hello_INCLUDEPATH += \
$${crono_INCLUDEPATH} \

hello_DEFINES += \
$${crono_DEFINES} \

########################################################################
# nadir
hello_HEADERS += \
$${NADIR_SRC}/nadir/io/logger.hpp \
$${NADIR_SRC}/nadir/io/logger_stdio.hpp \
$${NADIR_SRC}/nadir/io/logger_level.hpp \

hello_SOURCES += \

########################################################################
# patrona
hello_HEADERS += \
$${PATRONA_SRC}/patrona/cpp/xos/console/getopt/Main.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/Main.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Locked.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Acquired.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Joined.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Waited.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Created.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Attached.hpp \

hello_SOURCES += \

########################################################################
hello_HEADERS += \
$${CRONO_SRC}/crono/base/nadir/Base.hpp \

hello_SOURCES += \

########################################################################
# base
hello_HEADERS += \
$${CRONO_SRC}/crono/base/Locked.hpp \
$${CRONO_SRC}/crono/base/Acquired.hpp \
$${CRONO_SRC}/crono/base/Joined.hpp \
$${CRONO_SRC}/crono/base/Waited.hpp \
$${CRONO_SRC}/crono/base/Created.hpp \
$${CRONO_SRC}/crono/base/Attached.hpp \
$${CRONO_SRC}/crono/base/Base.hpp \

hello_SOURCES += \
$${CRONO_SRC}/crono/base/Base.cpp \

########################################################################
# mt
hello_HEADERS += \
$${CRONO_SRC}/crono/mt/Logger.hpp \
$${CRONO_SRC}/crono/mt/apple/osx/Mutex.hpp \
$${CRONO_SRC}/crono/mt/posix/Mutex.hpp \
$${CRONO_SRC}/crono/mt/os/Mutex.hpp \
$${CRONO_SRC}/crono/mt/Mutex.hpp \
$${CRONO_SRC}/crono/mt/os/Os.hpp \

hello_SOURCES += \
$${CRONO_SRC}/crono/mt/Logger.cpp \
$${CRONO_SRC}/crono/mt/os/Mutex.cpp \
$${CRONO_SRC}/crono/mt/os/Os.cpp \

########################################################################
# io
hello_HEADERS += \
$${CRONO_SRC}/crono/io/Logger.hpp \
$${CRONO_SRC}/crono/io/LoggerOutput.hpp \
$${CRONO_SRC}/crono/io/LoggerEnabled.hpp \
$${CRONO_SRC}/crono/io/nadir/Logger.hpp \

hello_SOURCES += \
$${CRONO_SRC}/crono/io/LoggerOutput.cpp \
$${CRONO_SRC}/crono/io/LoggerEnabled.cpp \

########################################################################
hello_HEADERS += \
$${CRONO_SRC}/crono/console/getopt/Main.hpp \
$${CRONO_SRC}/crono/console/MainLogger.hpp \
$${CRONO_SRC}/crono/console/Main.hpp \
$${CRONO_SRC}/crono/console/Main_main.hpp \
$${CRONO_SRC}/crono/app/console/hello/Main.hpp \

hello_SOURCES += \
$${CRONO_SRC}/crono/app/console/hello/Main.cpp \
$${CRONO_SRC}/crono/console/MainLogger.cpp \

########################################################################
hello_LIBS += \
$${crono_LIBS} \

