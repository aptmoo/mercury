#ifndef HG_DEFS_H
#define HG_DEFS_H
#include <memory>

template<typename T>
using ScopePtr = std::unique_ptr<T>;

template<typename T, typename... TArgs>
constexpr ScopePtr<T> CreateScopePtr(TArgs&&... args)
{
    return std::make_unique<T>(std::forward<TArgs>(args)...);
}

#endif