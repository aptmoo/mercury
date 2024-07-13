/**
 * @file types.h
 * @brief Commonly used types and type aliases.
 * @version 0.1
 * @date 2024-07-13
 */

#ifndef SHARED_TYPES_H
#define SHARED_TYPES_H
#include <memory>

namespace hg
{
    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename ... TArgs>
    Ref<T> MakeRef(TArgs&&... args)
    {
        return std::make_shared<T>(std::forward<TArgs>(args)...);
    }

    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T, typename ... TArgs>
    Ref<T> MakeScope(TArgs&&... args)
    {
        return std::make_unique<T>(std::forward<TArgs>(args)...);
    }
} // namespace hg

#endif