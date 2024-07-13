/**
 * @file appinterface.h
 * @brief Simple app interface.
 * @version 0.1
 * @date 2024-07-13
 * 
 */

#ifndef SHARED_APPINTERFACE_H
#define SHARED_APPINTERFACE_H
#include <string>

namespace hg
{  
    struct IAppInterface
    {
        virtual ~IAppInterface() = default;
    };
} // namespace hg

#endif