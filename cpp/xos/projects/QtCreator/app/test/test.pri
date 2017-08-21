########################################################################
# Copyright (c) 1988-2017 $organization$
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
#   File: test.pri
#
# Author: $author$
#   Date: 8/5/2017
########################################################################

test_TARGET = test

test_INCLUDEPATH += \
$${crono_INCLUDEPATH} \

test_DEFINES += \
$${crono_DEFINES} \

########################################################################
# nadir
test_HEADERS += \
$${NADIR_SRC}/xos/base/std/StringBase.hpp \
$${NADIR_SRC}/xos/base/StringBase.hpp \
$${NADIR_SRC}/xos/base/CharsBase.hpp \
$${NADIR_SRC}/xos/base/Base.hpp \
$${NADIR_SRC}/xos/console/IO.hpp \
$${NADIR_SRC}/xos/console/Main.hpp \
$${NADIR_SRC}/xos/console/Main_main.hpp \
$${NADIR_SRC}/xos/app/console/hello/Main.hpp \

test_SOURCES += \
$${NADIR_SRC}/xos/base/StringBase.cpp \
$${NADIR_SRC}/xos/base/CharsBase.cpp \
$${NADIR_SRC}/xos/base/Base.cpp \
$${NADIR_SRC}/xos/console/IO.cpp \

_test_SOURCES += \
$${NADIR_SRC}/xos/app/console/hello/Main.cpp \
$${NADIR_SRC}/xos/console/Main.cpp \
$${NADIR_SRC}/xos/console/Main_main.cpp \

########################################################################
# nadir
test_HEADERS += \
$${FILA_SRC}/xos/mt/posix/Mutex.hpp \

test_SOURCES += \
$${FILA_SRC}/xos/mt/posix/Mutex.cpp \

########################################################################
# crono
test_HEADERS += \
$${CRONO_SRC}/xos/mt/Logger.hpp \
$${CRONO_SRC}/xos/logger/Interface.hpp \
$${CRONO_SRC}/xos/logger/Output.hpp \
$${CRONO_SRC}/xos/logger/Stdio.hpp \
$${CRONO_SRC}/xos/logger/Enabled.hpp \
$${CRONO_SRC}/xos/logger/Message.hpp \
$${CRONO_SRC}/xos/logger/Location.hpp \
$${CRONO_SRC}/xos/logger/Function.hpp \
$${CRONO_SRC}/xos/logger/Level.hpp \

test_SOURCES += \
$${CRONO_SRC}/xos/mt/Logger.cpp \
$${CRONO_SRC}/xos/logger/Interface.cpp \
$${CRONO_SRC}/xos/logger/Output.cpp \
$${CRONO_SRC}/xos/logger/Stdio.cpp \
$${CRONO_SRC}/xos/logger/Enabled.cpp \
$${CRONO_SRC}/xos/logger/Message.cpp \
$${CRONO_SRC}/xos/logger/Location.cpp \
$${CRONO_SRC}/xos/logger/Function.cpp \
$${CRONO_SRC}/xos/logger/Level.cpp \

########################################################################
test_HEADERS += \
$${CRONO_SRC}/xos/app/console/mt/hello/Main.hpp \
$${CRONO_SRC}/xos/app/console/mt/hello/MainOpt.hpp \
$${CRONO_SRC}/crono/app/console/mt/hello/Main.hpp \
$${CRONO_SRC}/crono/app/console/mt/hello/MainOpt.hpp \
$${CRONO_SRC}/xos/console/mt/getopt/Main.hpp \
$${CRONO_SRC}/xos/console/mt/getopt/MainOpt.hpp \
$${CRONO_SRC}/crono/console/mt/getopt/Main.hpp \
$${CRONO_SRC}/crono/console/mt/getopt/MainOpt.hpp \
$${CRONO_SRC}/xos/console/getopt/Main.hpp \
$${CRONO_SRC}/xos/console/getopt/MainOpt.hpp \
$${CRONO_SRC}/crono/console/getopt/Main.hpp \
$${CRONO_SRC}/crono/console/getopt/MainOpt.hpp \
$${CRONO_SRC}/xos/console/mt/Main_main.hpp \
$${CRONO_SRC}/xos/console/Main_main.hpp \

test_SOURCES += \
$${CRONO_SRC}/xos/app/console/mt/hello/Main.cpp \
$${CRONO_SRC}/xos/app/console/mt/hello/MainOpt.cpp \
$${CRONO_SRC}/xos/console/mt/Main_main.cpp \

########################################################################
test_LIBS += \
$${crono_LIBS} \
