#pragma once

#include "evpp/platform_config.h"

#define ENABLE_LOGGING 0

#ifdef __cplusplus
#define GOOGLE_GLOG_DLL_DECL         
#define GLOG_NO_ABBREVIATED_SEVERITIES

//#include <glog/logging.h>

#ifdef GOOGLE_STRIP_LOG

#if GOOGLE_STRIP_LOG == 0
#define LOG_TRACE LOG(INFO)
#define LOG_DEBUG LOG(INFO)
#define LOG_INFO  LOG(INFO)
#define DLOG_TRACE LOG(INFO) << __PRETTY_FUNCTION__ << " this=" << this << " "
#else
#define LOG_TRACE if (false) LOG(INFO)
#define LOG_DEBUG if (false) LOG(INFO)
#define LOG_INFO  if (false) LOG(INFO)
#define DLOG_TRACE if (false) LOG(INFO)
#endif

#if GOOGLE_STRIP_LOG <= 1
#define LOG_WARN  LOG(WARNING)
#define DLOG_WARN LOG(WARNING) << __PRETTY_FUNCTION__ << " this=" << this << " "
#else
#define LOG_WARN  if (false) LOG(WARNING)
#define DLOG_WARN if (false) LOG(WARNING)
#endif

#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)

#else

#define WARNING 1
#define LOG_EVERY_N(...)  if(ENABLE_LOGGING) std::cout
#define LOG_TRACE if(ENABLE_LOGGING) std::cout << std::endl  << __FILE__ << ":" << __LINE__ << " "
#define LOG_DEBUG if(ENABLE_LOGGING) std::cout << std::endl<< __FILE__ << ":" << __LINE__ << " "
#define LOG_INFO  if(ENABLE_LOGGING) std::cout << std::endl<< __FILE__ << ":" << __LINE__ << " "
#define LOG_WARN  if(ENABLE_LOGGING) std::cout << std::endl<< __FILE__ << ":" << __LINE__ << " "
#define LOG_ERROR if(ENABLE_LOGGING) std::cout << std::endl<< __FILE__ << ":" << __LINE__ << " "
#define LOG_FATAL if(ENABLE_LOGGING) std::cout << std::endl<< __FILE__ << ":" << __LINE__ << " "
#define CHECK_NOTnullptr(val) LOG_ERROR << "'" #val "' Must be non nullptr";
#endif
#endif // end of define __cplusplus

//#ifdef _DEBUG
//#ifdef assert
//#undef assert
//#endif
//#define assert(expr)  { if (!(expr)) { LOG_FATAL << #expr ;} }
//#endif

#ifndef LOG
#define LOG(...) if(ENABLE_LOGGING) std::cout
#endif
#define DLOG_TRACE if(ENABLE_LOGGING) LOG_TRACE
#define DLOG_WARN if(ENABLE_LOGGING) LOG_TRACE