
#ifndef AZURLOG_H
#define AZURLOG_H

#include <memory>
#include <spdlog/spdlog.h>

#include "Azur/Core.h"

namespace Azure {
    /**
     * 日志类，封装spdlog
     */
    class AZUR_API AzurLog {
    public:
        static void Init();;

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return m_CoreLogger; }

        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return m_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> m_CoreLogger;
        static std::shared_ptr<spdlog::logger> m_ClientLogger;
    };
}

#define AZ_CORE_TRACE(...)   ::Azur::AzurLog::GetCoreLogger()->trace(__VA_ARGS__)
#define AZ_CORE_INFO(...)    ::Azure::AzurLog::GetCoreLogger()->info(__VA_ARGS__)
#define AZ_CORE_WARN(...)    ::Azur::AzurLog::GetCoreLogger()->warn(__VA_ARGS__)
#define AZ_CORE_ERROR(...)   ::Azur::AzurLog::GetCoreLogger()->error(__VA_ARGS__)
//#define AZ_CORE_FATAL(...)   ::Azur::AzurLog::GetCoreLogger()->(__VA_ARGS__)

#define AZ_TRACE(...)   ::Azur::AzurLog::GetClientLogger()->trace(__VA_ARGS__)
#define AZ_INFO(...)    ::Azur::AzurLog::GetClientLogger()->info(__VA_ARGS__)
#define AZ_WARN(...)    ::Azur::AzurLog::GetClientLogger()->warn(__VA_ARGS__)
#define AZ_ERROR(...)   ::Azur::AzurLog::GetClientLogger()->error(__VA_ARGS__)

#endif //AZURLOG_H
