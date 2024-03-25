#include <log.h>
#include <boost/log/trivial.hpp>

void zge::core::Log(const std::string& log_msg, LogSeverity severity) {
  std::string severity_name;
  switch (severity) {
    case LogSeverity::kTrace:
      BOOST_LOG_TRIVIAL(trace) << log_msg;
      break;
    case LogSeverity::kDebug:
      BOOST_LOG_TRIVIAL(debug) << log_msg;
      break;
    case LogSeverity::kInfo:
      BOOST_LOG_TRIVIAL(info) << log_msg;
      break;
    case LogSeverity::kWarning:
      BOOST_LOG_TRIVIAL(warning) << log_msg;
      break;
    case LogSeverity::kError:
      BOOST_LOG_TRIVIAL(error) << log_msg;
      break;
    case LogSeverity::kFatal:
      BOOST_LOG_TRIVIAL(fatal) << log_msg;
      break;
  }
}