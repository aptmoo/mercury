#ifndef SHARED_APPINTERFACE_H
#define SHARED_APPINTERFACE_H

namespace hg
{  
    class IAppInterface
    {
    public:
        virtual ~IAppInterface() = default;

        virtual void TestPrint() = 0;
    };
} // namespace hg

#endif