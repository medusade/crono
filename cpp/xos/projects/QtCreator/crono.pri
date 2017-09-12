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
#   Date: 8/5/2017
########################################################################

OTHER_PKG = ../../../../../../../..
OTHER_BLD = ..

########################################################################
# rostra
ROSTRA_PKG = $${OTHER_PKG}/rostra/cpp/xos
ROSTRA_PRJ = $${ROSTRA_PKG}
ROSTRA_SRC = $${ROSTRA_PKG}/src

rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

rostra_DEFINES += \

rostra_LIBS += \

########################################################################
# nadir
NADIR_PKG = $${OTHER_PKG}/nadir/cpp/xos
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

nadir_LIBS += \

########################################################################
# patrona
PATRONA_PKG = $${OTHER_PKG}/patrona/cpp/xos
PATRONA_PRJ = $${PATRONA_PKG}
PATRONA_SRC = $${PATRONA_PKG}/src

patrona_INCLUDEPATH += \
$${PATRONA_SRC} \

patrona_DEFINES += \

patrona_LIBS += \

########################################################################
# fila
FILA_PKG = $${OTHER_PKG}/fila/cpp/xos
FILA_PRJ = $${FILA_PKG}
FILA_SRC = $${FILA_PKG}/src

fila_INCLUDEPATH += \
$${FILA_SRC} \

fila_DEFINES += \

fila_LIBS += \

########################################################################
# crono
CRONO_PKG = ../../../../..
CRONO_BLD = ../..

CRONO_PRJ = $${CRONO_PKG}
CRONO_BIN = $${CRONO_BLD}/bin
CRONO_LIB = $${CRONO_BLD}/lib
CRONO_SRC = $${CRONO_PKG}/src

CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
crono_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
crono_DEFINES += RELEASE_BUILD
}

crono_INCLUDEPATH += \
$${CRONO_SRC} \
$${fila_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${rostra_INCLUDEPATH} \

crono_DEFINES += \
BUILD_CONFIG=$${BUILD_CONFIG} \
$${rostra_DEFINES} \
$${nadir_DEFINES} \
$${patrona_DEFINES} \
$${fila_DEFINES} \


crono_LIBS += \
-L$${CRONO_LIB}/libcrono \
-lcrono \
