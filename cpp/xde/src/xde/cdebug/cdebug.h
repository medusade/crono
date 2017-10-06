/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cdebug.h
 *
 * Author: $author$
 *   Date: 9/27/2017
 **********************************************************************
 */
#ifndef _XDE_CDEBUG_CDEBUG_H
#define _XDE_CDEBUG_CDEBUG_H

#include "xde/cplatform/cplatform.h"

#include <stdio.h>

/**
 **********************************************************************
 *   Enum: TDEBUG_LEVELS
 *
 * Author: $author$
 *   Date: 11/13/2007
 **********************************************************************
 */
typedef UINT TDEBUG_LEVELS;
enum {
    DEBUG_LEVELS_NONE  = 0,

    DEBUG_LEVELS_ERROR,
    DEBUG_LEVELS_WARN,
    DEBUG_LEVELS_INFO,
    DEBUG_LEVELS_FUNC,
    DEBUG_LEVELS_TRACE,

    NEXT_DEBUG_LEVELS,
    DEBUG_LEVELS  = (NEXT_DEBUG_LEVELS - 1)
};

/**
 **********************************************************************
 *   Enum: TDEBUG_LEVEL
 *
 * Author: $author$
 *   Date: 11/13/2007
 **********************************************************************
 */
typedef UINT TDEBUG_LEVEL;
enum {
    DEBUG_LEVEL_NONE  = 0,

    DEBUG_LEVEL_ERROR = (1 << (DEBUG_LEVELS_ERROR-1)),
    DEBUG_LEVEL_WARN  = (1 << (DEBUG_LEVELS_WARN-1)),
    DEBUG_LEVEL_INFO  = (1 << (DEBUG_LEVELS_INFO-1)),
    DEBUG_LEVEL_FUNC  = (1 << (DEBUG_LEVELS_FUNC-1)),
    DEBUG_LEVEL_TRACE = (1 << (DEBUG_LEVELS_TRACE-1)),

    NEXT_DEBUG_LEVEL  = (1 << (NEXT_DEBUG_LEVELS-1)),
    ALL_DEBUG_LEVELS  = (NEXT_DEBUG_LEVEL - 1)
};

/**
 **********************************************************************
 **********************************************************************
 */
#if !defined(DB_PRINTF)
#define DB_PRINTF(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#else /* !defined(DB_PRINTF) */
#if !defined(NO_CDEBUG_PRINTF)
#define CDEBUG_PRINTF DB_PRINTF
#else /* !defined(NO_CDEBUG_PRINTF) */
#endif /* !defined(NO_CDEBUG_PRINTF) */
#endif /* !defined(DB_PRINTF) */

#define DEBUG_LEVELS g_debugLevels

/**
 **********************************************************************
 **********************************************************************
 */

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(DEBUG_EXPORT)
PLATFORM_EXPORT extern
#else /* defined(DEBUG_EXPORT) */
PLATFORM_IMPORT extern
#endif /* defined(DEBUG_EXPORT) */
TDEBUG_LEVEL DEBUG_LEVELS;

#if defined(CDEBUG_PRINTF)
extern int CDEBUG_PRINTF(const char* format, ...);
#else /* defined(CDEBUG_PRINTF) */
#endif /* defined(CDEBUG_PRINTF) */
#if defined(__cplusplus)

}
#endif /* defined(__cplusplus) */

/**
 **********************************************************************
 **********************************************************************
 */
#if defined(WINDOWS)
/* Windows
 */
#if (_MSC_VER <= MSC_VER_6)
#define DB_FUNCTION __FUNCTION__
#if !defined(DF)
#define DF(name) static const char __FUNCTION__[]=""#name;
#endif /* !defined(DF) */
#else /* (_MSC_VER <= MSC_VER_6) */
#define DB_FUNCTION __FUNCTION__
#define DF(name)
#endif /* (_MSC_VER <= MSC_VER_6) */
#define CDB_FUNCTION (strrchr(__FUNCTION__,':')?(strrchr(__FUNCTION__,':')+1):(__FUNCTION__))
#else /* defined(WINDOWS) */
/* Unix
 */
#if defined(DB_USE_PRETTY_FUNCTION)
#define DB_FUNCTION __PRETTY_FUNCTION__
#else
#define DB_FUNCTION __FUNCTION__
#endif /* defined(DB_USE_PRETTY_FUNCTION) */
#define DF(name)
#define CDB_FUNCTION __FUNCTION__
#endif /* defined(WINDOWS) */

/**
 **********************************************************************
 **********************************************************************
 */
#define DEBUG_LEVEL_ERROR_NAME "error: "
#define DEBUG_LEVEL_WARN_NAME "warning: "
#define DEBUG_LEVEL_INFO_NAME ""
#define DEBUG_LEVEL_FUNC_NAME ""
#define DEBUG_LEVEL_TRACE_NAME ""

#define GET_DEBUG_LEVELS() DEBUG_LEVELS
#define SET_DEBUG_LEVELS(n) DEBUG_LEVELS = (TDEBUG_LEVEL)((1 << n) - 1)
#define IS_DEBUGL(level) (DEBUG_LEVELS & level)
#define DEBUGL(level,type) \
    ((DEBUG_LEVELS & level) \
    && DB_PRINTF("%s:%d: %s", __FILE__, __LINE__, type))

#define IS_DBE IS_DEBUGL(DEBUG_LEVEL_ERROR)
#define IS_DBW IS_DEBUGL(DEBUG_LEVEL_WARN)
#define IS_DBI IS_DEBUGL(DEBUG_LEVEL_INFO)
#define IS_DBF IS_DEBUGL(DEBUG_LEVEL_FUNC)
#define IS_DBT IS_DEBUGL(DEBUG_LEVEL_TRACE)

#define DBE DEBUGL(DEBUG_LEVEL_ERROR, DEBUG_LEVEL_ERROR_NAME) && (DB_PRINTF("%s", DB_FUNCTION)||1) && DB_PRINTF
#define DBW DEBUGL(DEBUG_LEVEL_WARN, DEBUG_LEVEL_WARN_NAME) && (DB_PRINTF("%s", DB_FUNCTION)||1) && DB_PRINTF
#define DBI DEBUGL(DEBUG_LEVEL_INFO, DEBUG_LEVEL_INFO_NAME) && (DB_PRINTF("%s", DB_FUNCTION)||1) && DB_PRINTF
#define DBF DEBUGL(DEBUG_LEVEL_FUNC, DEBUG_LEVEL_FUNC_NAME) && (DB_PRINTF("%s", DB_FUNCTION)||1) && DB_PRINTF
#define DBT DEBUGL(DEBUG_LEVEL_TRACE, DEBUG_LEVEL_TRACE_NAME) && (DB_PRINTF("%s", DB_FUNCTION)||1) && DB_PRINTF

#if defined(__cplusplus)
#define CBB_CLASS "CBB_CLASS::"
#define CDBE DEBUGL(DEBUG_LEVEL_ERROR, DEBUG_LEVEL_ERROR_NAME) && (printf(" %s%s", CDB_CLASS, CDB_FUNCTION)||1) && printf
#define CDBW DEBUGL(DEBUG_LEVEL_WARN, DEBUG_LEVEL_WARN_NAME) && (printf(" %s%s", CDB_CLASS, CDB_FUNCTION)||1) && printf
#define CDBI DEBUGL(DEBUG_LEVEL_INFO, DEBUG_LEVEL_INFO_NAME) && (printf(" %s%s", CDB_CLASS, CDB_FUNCTION)||1) && printf
#define CDBF DEBUGL(DEBUG_LEVEL_FUNC, DEBUG_LEVEL_FUNC_NAME) && (printf(" %s%s", CDB_CLASS, CDB_FUNCTION)||1) && printf
#define CDBT DEBUGL(DEBUG_LEVEL_TRACE, DEBUG_LEVEL_TRACE_NAME) && (printf(" %s%s", CDB_CLASS, CDB_FUNCTION)||1) && printf
#endif /* defined(__cplusplus) */

/**
 **********************************************************************
 **********************************************************************
 */
#if !defined(DEFAULT_DEBUG_LEVELS)
#if defined(NO_DEBUG_LEVELS)
#define DEFAULT_DEBUG_LEVELS 0
#else /* defined(NO_DEBUG_LEVELS) */
#define DEFAULT_DEBUG_LEVELS DEBUG_LEVELS
#endif /* defined(NO_DEBUG_LEVELS) */
#endif /* !defined(DEFAULT_DEBUG_LEVELS) */

#if !defined(DEFAULT_DEBUG_LEVELS_VALUE)
#if defined(NO_DEBUG_LEVELS)
#define DEFAULT_DEBUG_LEVEL_VALUE 0
#else /* defined(NO_DEBUG_LEVELS) */
#define DEFAULT_DEBUG_LEVEL_VALUE ALL_DEBUG_LEVELS
#endif /* defined(NO_DEBUG_LEVELS) */
#endif /* !defined(DEFAULT_DEBUG_LEVELS_VALUE) */

/**
 **********************************************************************
 **********************************************************************
 */
#endif /* _XDE_CDEBUG_CDEBUG_H */
