########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   File: libcrono.pri
#
# Author: $author$
#   Date: 3/23/2018
#
# QtCreator .pri file for crono library libcrono
########################################################################

########################################################################
# libcrono

# libcrono TARGET
#
libcrono_TARGET = crono
libcrono_TEMPLATE = lib
libcrono_CONFIG += staticlib

# libcrono INCLUDEPATH
#
libcrono_INCLUDEPATH += \
$${crono_INCLUDEPATH} \

# libcrono DEFINES
#
libcrono_DEFINES += \
$${crono_DEFINES} \

########################################################################
# libcrono OBJECTIVE_HEADERS
#
#libcrono_OBJECTIVE_HEADERS += \
#$${CRONO_SRC}/crono/base/Base.hh \

# libcrono OBJECTIVE_SOURCES
#
#libcrono_OBJECTIVE_SOURCES += \
#$${CRONO_SRC}/crono/base/Base.mm \

########################################################################
# libcrono HEADERS
#
libcrono_HEADERS += \
$${CRONO_SRC}/crono/base/Acquired.hpp \
$${CRONO_SRC}/crono/base/Attached.hpp \
$${CRONO_SRC}/crono/base/Base.hpp \
$${CRONO_SRC}/crono/base/Created.hpp \
$${CRONO_SRC}/crono/base/Joined.hpp \
$${CRONO_SRC}/crono/base/Locked.hpp \
$${CRONO_SRC}/crono/base/Waited.hpp \
\
$${CRONO_SRC}/crono/io/Logger.hpp \
$${CRONO_SRC}/crono/io/LoggerEnabled.hpp \
$${CRONO_SRC}/crono/io/LoggerOutput.hpp \
\
$${CRONO_SRC}/crono/mt/apple/osx/Mutex.hpp \
$${CRONO_SRC}/crono/mt/Logger.hpp \
$${CRONO_SRC}/crono/mt/microsoft/windows/Mutex.hpp \
$${CRONO_SRC}/crono/mt/Mutex.hpp \
$${CRONO_SRC}/crono/mt/os/Mutex.hpp \
$${CRONO_SRC}/crono/mt/os/Os.hpp \
$${CRONO_SRC}/crono/mt/posix/Mutex.hpp \
\
$${CRONO_SRC}/crono/console/getopt/Main.hpp \
$${CRONO_SRC}/crono/console/getopt/MainOpt.hpp \
$${CRONO_SRC}/crono/console/Main.hpp \
$${CRONO_SRC}/crono/console/Main_main.hpp \
$${CRONO_SRC}/crono/console/MainLogger.hpp \
\
$${CRONO_SRC}/crono/lib/Version.hpp \
$${CRONO_SRC}/crono/lib/crono/Version.hpp \

# libcrono SOURCES
#
libcrono_SOURCES += \
$${CRONO_SRC}/crono/base/Acquired.cpp \
$${CRONO_SRC}/crono/base/Attached.cpp \
$${CRONO_SRC}/crono/base/Base.cpp \
$${CRONO_SRC}/crono/base/Created.cpp \
$${CRONO_SRC}/crono/base/Joined.cpp \
$${CRONO_SRC}/crono/base/Locked.cpp \
$${CRONO_SRC}/crono/base/Waited.cpp \
\
$${CRONO_SRC}/crono/io/Logger.cpp \
$${CRONO_SRC}/crono/io/LoggerEnabled.cpp \
$${CRONO_SRC}/crono/io/LoggerOutput.cpp \
\
$${CRONO_SRC}/crono/mt/os/Mutex.cpp \
$${CRONO_SRC}/crono/mt/os/Os.cpp \
\
$${CRONO_SRC}/crono/console/getopt/Main.cpp \
$${CRONO_SRC}/crono/console/getopt/MainOpt.cpp \
$${CRONO_SRC}/crono/console/MainLogger.cpp \
\
$${CRONO_SRC}/crono/lib/crono/Version.cpp \

########################################################################
