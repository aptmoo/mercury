#ifndef SHARED_APPINTERFACE_H
#define SHARED_APPINTERFACE_H
#include <string>

namespace hg
{  
    class IAppInterface
    {
    public:
        virtual ~IAppInterface() = default;

        virtual void Print(const std::string& str) = 0;
    };
} // namespace hg

#endif