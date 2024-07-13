#ifndef CORE_H
#define CORE_H

#include <memory>

#ifdef AZURE_PLATFORM_WINDOWS
    #ifdef AZURE_EXPORT
        #define AZURE_API __declspec(dllexport)
    #else
        #define AZURE_API __declspec(dllimport)
    #endif
#endif

#ifdef AZ_ENABLE_ASSERTS
    #define AZ_ASSERT(x,...) {if(!(x)){AZ_ERROR("Assertion Failed:{0)",__VA_ARGS__);__debugbreak();}}
    #define AZ_CORE_ASSERT(x,...) {if(!(x)){AZ_CORE_ERROR("Assertion Failed:{0)",__VA_ARGS__);__debugbreak();}}
#else
    #define AZ_ASSERT(x,...)
    #define AZ_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1 << x)
//绑定系统事件
#define AZ_BIND_EVENT(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
//#define AZ_BIND_EVENT(fn) std::bind(&fn,this,std::placeholders::_1)

namespace Azure{
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

#endif //CORE_H
