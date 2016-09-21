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
#   File: crono.pri
#
# Author: $author$
#   Date: 9/21/2016
########################################################################
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

########################################################################
# nadir
NADIR_PKG = $${CRONO_PKG}/../nadir
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

nadir_LIBS += \

########################################################################
crono_INCLUDEPATH += \
$${CRONO_SRC} \
$${nadir_INCLUDEPATH} \

crono_DEFINES += \
BUILD_CONFIG=$${BUILD_CONFIG} \

########################################################################
crono_LIBS += \
-L$${CRONO_LIB}/libcrono \
-lcrono \
