
#ifndef AZURELOG_H
#define AZURELOG_H

#include <memory>
#include <spdlog/spdlog.h>

#include "Azure/Core.h"

namespace Azure {
    /**
     * 日志类，封装spdlog
     */
    class AZURE_API AzureLog {
    public:
        static void Init();;

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return m_CoreLogger; }

        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return m_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> m_CoreLogger;
        static std::shared_ptr<spdlog::logger> m_ClientLogger;
    };
}

#define AZ_CORE_TRACE(...)   ::Azure::AzureLog::GetCoreLogger()->trace(__VA_ARGS__)
#define AZ_CORE_INFO(...)    ::Azure::AzureLog::GetCoreLogger()->info(__VA_ARGS__)
#define AZ_CORE_WARN(...)    ::Azure::AzureLog::GetCoreLogger()->warn(__VA_ARGS__)
#define AZ_CORE_ERROR(...)   ::Azure::AzureLog::GetCoreLogger()->error(__VA_ARGS__)
//#define AZ_CORE_FATAL(...)   ::Azure::AzureLog::GetCoreLogger()->(__VA_ARGS__)

#define AZ_TRACE(...)   ::Azure::AzureLog::GetClientLogger()->trace(__VA_ARGS__)
#define AZ_INFO(...)    ::Azure::AzureLog::GetClientLogger()->info(__VA_ARGS__)
#define AZ_WARN(...)    ::Azure::AzureLog::GetClientLogger()->warn(__VA_ARGS__)
#define AZ_ERROR(...)   ::Azure::AzureLog::GetClientLogger()->error(__VA_ARGS__)

#endif //AZURELOG_H
