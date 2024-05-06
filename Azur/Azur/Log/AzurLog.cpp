#include <spdlog/sinks/stdout_color_sinks.h>

#include "AzurLog.h"

namespace Azur {
    std::shared_ptr<spdlog::logger> AzurLog::m_CoreLogger;

    std::shared_ptr<spdlog::logger>AzurLog::m_ClientLogger;


    void AzurLog::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
//        spdlog::st
        m_CoreLogger = spdlog::stdout_color_mt("Azur");
        m_CoreLogger->set_level(spdlog::level::trace);
        m_ClientLogger = spdlog::stdout_color_mt("APP");
        m_ClientLogger->set_level(spdlog::level::trace);
    }
}
