#ifndef SHARED_GAMEMANAGER_H
#define SHARED_GAMEMANAGER_H
#include "types.h"

#include "appinterface.h"
#include "gameinterface.h"

namespace hg
{
    class GameManager
    {
    public:
        GameManager();
        ~GameManager();

        void Load(const std::string& gameName);
        void UnLoad();

        void SetupInterfaces(IAppInterface* interface);

        IGameInterface* const operator->()
        {
            return m_Interface;
        }

        IGameInterface* const GetPtr()
        {
            return m_Interface;
        }

        // Probably a bad idea
        GameManager(const GameManager&) = delete;
    private:
        struct GameManagerImpl;
        Scope<GameManagerImpl> m_Impl;

        IGameInterface* m_Interface;
    };
} // namespace hg

#endif