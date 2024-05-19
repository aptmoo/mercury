#ifndef SHARED_GAMEINTERFACE_H
#define SHARED_GAMEINTERFACE_H

namespace hg
{
    class IGameInterface
    {
    public:
        virtual ~IGameInterface() = default;

        virtual void TestPrint() = 0;  
    };
} // namespace hg

#endif