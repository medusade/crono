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
#   File: crono.pri
#
# Author: $author$
#   Date: 12/23/2018, 12/26/2020
#
# Os specific QtCreator .pri file for crono
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
CRONO_OS = macosx
} else {
contains(UNAME,Linux) {
CRONO_OS = linux
} else {
CRONO_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,CRONO_OS) {
CRONO_BUILD = $${CRONO_OS}
} else {
CRONO_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,CRONO_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(CRONO_OS,macosx) {
} else {
contains(CRONO_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(CRONO_OS,windows) {
} else {
} # contains(CRONO_OS,windows)
} # contains(CRONO_OS,linux)
} # contains(CRONO_OS,macosx)

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${CRONO_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# nadir
NADIR_THIRDPARTY_PKG_MAKE_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_MAKE_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PKG_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_PKG_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_PRJ_BLD = $${OTHER_BLD}/$${NADIR_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_BLD}/lib
#NADIR_LIB = $${NADIR_PKG_BLD}/lib
NADIR_LIB = $${NADIR_PRJ_BLD}/lib
#NADIR_LIB = $${CRONO_LIB}

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_NAME} \
-l$${NADIR_NAME} \

########################################################################
# patrona
PATRONA_THIRDPARTY_PKG_MAKE_BLD = $${PATRONA_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PRJ_MAKE_BLD = $${PATRONA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PKG_BLD = $${PATRONA_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PRJ_BLD = $${PATRONA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
PATRONA_PKG_BLD = $${OTHER_BLD}/$${PATRONA_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
PATRONA_PRJ_BLD = $${OTHER_BLD}/$${PATRONA_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PKG_MAKE_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PKG_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PRJ_BLD}/lib
#PATRONA_LIB = $${PATRONA_PKG_BLD}/lib
PATRONA_LIB = $${PATRONA_PRJ_BLD}/lib
#PATRONA_LIB = $${CRONO_LIB}

# patrona LIBS
#
patrona_LIBS += \
-L$${PATRONA_LIB}/lib$${PATRONA_NAME} \
-l$${PATRONA_NAME} \

########################################################################
# crono

# crono INCLUDEPATH
#
crono_INCLUDEPATH += \

# crono DEFINES
#
crono_DEFINES += \

# crono LIBS
#
crono_LIBS += \
$${patrona_LIBS} \
$${nadir_LIBS} \
$${rostra_LIBS} \
$${build_crono_LIBS} \
-lpthread \
-ldl \

contains(CRONO_OS,linux) {
crono_LIBS += \
-lrt
} else {
}
