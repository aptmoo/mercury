#ifndef HG_DEFS_H
#define HG_DEFS_H
#include <memory>

template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T, typename... TArgs>
constexpr Scope<T> MakeScope(TArgs&&... args)
{
    return std::make_unique<T>(std::forward<TArgs>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;

template <typename T, typename... TArgs>
constexpr Ref<T> MakeRef(TArgs &&...args)
{
    return std::make_shared<T>(std::forward<TArgs>(args)...);
}

#endif