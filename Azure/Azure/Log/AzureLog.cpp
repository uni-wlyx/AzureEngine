#include <spdlog/sinks/stdout_color_sinks.h>

#include "AzureLog.h"

namespace Azure {
    std::shared_ptr<spdlog::logger> AzureLog::m_CoreLogger;

    std::shared_ptr<spdlog::logger>AzureLog::m_ClientLogger;


    void AzureLog::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
//        spdlog::st
        m_CoreLogger = spdlog::stdout_color_mt("Azure");
        m_CoreLogger->set_level(spdlog::level::trace);
        m_ClientLogger = spdlog::stdout_color_mt("APP");
        m_ClientLogger->set_level(spdlog::level::trace);
    }
}
