########################################################################
# Copyright (c) 1988-2024 $organization$
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
#   Date: 2/27/2024
#
# os specific QtCreator project file for medusade framework crono
########################################################################
# Depends: rostra;nadir;patrona;fila

UNAME = $$system(uname)

contains(UNAME,Darwin) {
DARWIN_VERSION = $$system(sw_vers -productVersion)
} else {
contains(UNAME,Linux) {
LINUX_VERSION = $$system(uname -r)
} else {
contains(UNAME,Windows) {
WINDOWS_VERSION = $$system(ver)
} else {
} # contains(UNAME,Windows)
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(UNAME,Darwin) {
DARWIN_VERSION_NUMBER = $$system(echo $${DARWIN_VERSION} | cut -d'.' -f1)
contains(DARWIN_VERSION_NUMBER,15) {
DARWIN_VERSION_NAME = Sequoia
} else {
contains(DARWIN_VERSION_NUMBER,14) {
DARWIN_VERSION_NAME = Sonoma
} else {
contains(DARWIN_VERSION_NUMBER,13) {
DARWIN_VERSION_NAME = Ventura
} else {
contains(DARWIN_VERSION_NUMBER,12) {
DARWIN_VERSION_NAME = Monterey
} else {
contains(DARWIN_VERSION_NUMBER,11) {
DARWIN_VERSION_NAME = Bigsur
} else {
contains(DARWIN_VERSION_NUMBER,10) {
DARWIN_VERSION_NAME = Sierra
} else {
DARWIN_VERSION_NAME = Mavricks
} # contains(DARWIN_VERSION,10)
} # contains(DARWIN_VERSION,11)
} # contains(DARWIN_VERSION,12)
} # contains(DARWIN_VERSION,13)
} # contains(DARWIN_VERSION,14)
} # contains(DARWIN_VERSION,15)
} # contains(UNAME,Darwin)

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
contains(DARWIN_VERSION_NUMBER,15) {
#QMAKE_CXXFLAGS += -Werror -Wno-error=register
QMAKE_CXXFLAGS += -Wno-register
} else {
} # contains(DARWIN_VERSION_NUMBER,15)
contains(DARWIN_VERSION_NUMBER,14) {
QMAKE_CXXFLAGS += -Wno-dynamic-exception-spec
} else {
} # contains(DARWIN_VERSION_NUMBER,14)
contains(DARWIN_VERSION_NUMBER,11|12|13|14|15) {
QMAKE_CFLAGS += -Wno-implicit-function-declaration
} else {
} # contains(DARWIN_VERSION_NUMBER,11|12|13|14|15)
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
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${ROSTRA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${CRONO_LIB}
ROSTRA_LIB_NAME = $${ROSTRA_NAME}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_LIB_NAME} \
-l$${ROSTRA_LIB_NAME} \


########################################################################
# nadir
NADIR_THIRDPARTY_PKG_MAKE_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${NADIR_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PKG_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${NADIR_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_PKG_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
NADIR_PRJ_BLD = $${OTHER_BLD}/$${NADIR_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_BLD}/lib
NADIR_LIB = $${NADIR_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_PRJ_BLD}/lib
#NADIR_LIB = $${CRONO_LIB}
NADIR_LIB_NAME = $${NADIR_NAME}

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_LIB_NAME} \
-l$${NADIR_LIB_NAME} \


########################################################################
# patrona
PATRONA_THIRDPARTY_PKG_MAKE_BLD = $${PATRONA_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${PATRONA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PKG_BLD = $${PATRONA_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
PATRONA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${PATRONA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
PATRONA_PKG_BLD = $${OTHER_BLD}/$${PATRONA_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
PATRONA_PRJ_BLD = $${OTHER_BLD}/$${PATRONA_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PKG_MAKE_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PKG_BLD}/lib
#PATRONA_LIB = $${PATRONA_THIRDPARTY_PRJ_BLD}/lib
PATRONA_LIB = $${PATRONA_PKG_BLD}/lib
#PATRONA_LIB = $${PATRONA_PRJ_BLD}/lib
#PATRONA_LIB = $${CRONO_LIB}
PATRONA_LIB_NAME = $${PATRONA_NAME}

# patrona LIBS
#
patrona_LIBS += \
-L$${PATRONA_LIB}/lib$${PATRONA_LIB_NAME} \
-l$${PATRONA_LIB_NAME} \


########################################################################
# fila
FILA_THIRDPARTY_PKG_MAKE_BLD = $${FILA_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${FILA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PKG_BLD = $${FILA_THIRDPARTY_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${FILA_THIRDPARTY_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
FILA_PKG_BLD = $${OTHER_BLD}/$${FILA_PKG}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
FILA_PRJ_BLD = $${OTHER_BLD}/$${FILA_PRJ}/build/$${CRONO_BUILD}/QtCreator/$${BUILD_CONFIG}
#FILA_LIB = $${FILA_THIRDPARTY_PKG_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PKG_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_BLD}/lib
FILA_LIB = $${FILA_PKG_BLD}/lib
#FILA_LIB = $${FILA_PRJ_BLD}/lib
#FILA_LIB = $${CRONO_LIB}
FILA_LIB_NAME = $${FILA_NAME}

# fila LIBS
#
fila_LIBS += \
-L$${FILA_LIB}/lib$${FILA_LIB_NAME} \
-l$${FILA_LIB_NAME} \

########################################################################
# crono

# crono INCLUDEPATH
#
crono_INCLUDEPATH += \

# crono DEFINES
#
crono_DEFINES += \

# crono os LIBS
#
contains(CRONO_OS,macosx|linux) {
crono_os_LIBS += \
-lpthread \
-ldl
} else {
} # contains(CRONO_OS,macosx|linux)

contains(CRONO_OS,linux) {
crono_os_LIBS += \
-lrt
} else {
} # contains(CRONO_OS,linux)


# crono base LIBS
#
crono_base_LIBS += \
$${fila_LIBS} \
$${patrona_LIBS} \
$${nadir_LIBS} \
$${rostra_LIBS} \


# crono LIBS
#
crono_LIBS += \
$${crono_base_LIBS} \
$${build_crono_LIBS} \
$${crono_os_LIBS} \

########################################################################
