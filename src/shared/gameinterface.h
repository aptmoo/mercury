#ifndef SHARED_GAMEINTERFACE_H
#define SHARED_GAMEINTERFACE_H

namespace hg
{
    struct IGameInterface
    {
        virtual ~IGameInterface() = default; 

        virtual void Init() = 0;
        virtual void Update() = 0;  // TODO: Update should have dt
    };
} // namespace hg

#endif