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
#   File: crono.pri
#
# Author: $author$
#   Date: 9/4/2017
#
# QtCreator .pri file for crono executable crono
########################################################################

crono_exe_TARGET = crono

########################################################################
crono_exe_INCLUDEPATH += \
$${crono_INCLUDEPATH} \

crono_exe_DEFINES += \
$${crono_DEFINES} \

########################################################################
# crono
crono_exe_HEADERS += \
$${CRONO_SRC}/xos/app/console/mt/hello/Main.hpp \
$${CRONO_SRC}/xos/console/mt/Main_main.hpp \

crono_exe_SOURCES += \
$${CRONO_SRC}/xos/app/console/mt/hello/Main.cpp \
$${CRONO_SRC}/xos/console/mt/Main_main.cpp \

########################################################################
crono_exe_LIBS += \
$${crono_LIBS} \



