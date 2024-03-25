#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <string>

namespace zge::core {

enum class LogSeverity { kTrace, kDebug, kInfo, kWarning, kError, kFatal };

void Log(const std::string& log_msg,
         LogSeverity severity = LogSeverity::kInfo);  // namespace zge::core

}  // namespace zge::core
#endif  // __LOGGER_H__
