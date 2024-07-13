#ifndef SHARED_GAMEMANAGER_H
#define SHARED_GAMEMANAGER_H
#include "types.h"

#include "appinterface.h"
#include "gameinterface.h"

namespace hg
{
    class GameDLLManager
    {
    public:
        GameDLLManager();
        ~GameDLLManager();

        void Load(const std::string& path);
        void Unload();

        void SetupInterfaces(IAppInterface* interface);

        IGameInterface* const operator->()
        {
            return m_Interface;
        }

        IGameInterface* const GetInterface()
        {
            return m_Interface;
        }

        // Probably a bad idea
        GameDLLManager(const GameDLLManager&) = delete;
    private:
        struct GameManagerImpl;
        Scope<GameManagerImpl> m_Impl;

        IGameInterface* m_Interface;
    };
} // namespace hg

#endif