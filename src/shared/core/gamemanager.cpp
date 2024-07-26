#include "gamemanager.h"
#include <string>
#include <functional>
#include <iostream>

namespace hg
{
    #if defined(SYSTEM_LINUX) || defined(__linux__) // VSCode will get pissed off if you dont do this.
    #include <dlfcn.h>
    struct GameDLLManager::GameManagerImpl
    {
        GameManagerImpl(){};
        ~GameManagerImpl()
        {
            this->Unload();
        };

        void Load(const std::string& path)
        {
            m_LibHandle = dlopen(path.c_str(), RTLD_NOW);
            if(!m_LibHandle)
            {
                std::cout << dlerror() << '\n'; // TODO: Logging!
                return;
            }
            
            setupInterface = (void*(*)(void*))dlsym(m_LibHandle, "GDLL_SetupInterfaces");
            if(!setupInterface)
            {
                std::cout << dlerror() << '\n'; // TODO: Logging!
                return;
            }
        }

        IGameInterface* SetupInterfaces(IAppInterface* appInterface)
        {
            return (IGameInterface*)setupInterface(appInterface);
        }

        void Unload()
        {
            if(m_LibHandle)
                dlclose(m_LibHandle);
            setupInterface = nullptr;
        }
    private:
        void* m_LibHandle = nullptr;;
        void*(*setupInterface)(void*);
    };
    #endif

    GameDLLManager::GameDLLManager()
        : m_Impl(new GameManagerImpl())
    {

    }

    GameDLLManager::~GameDLLManager()
    {
        m_Impl->Unload();
    }

    void GameDLLManager::Load(const std::string& path)
    {
        m_Impl->Load(path);
    }
    
    void GameDLLManager::Unload()
    {
        m_Impl->Unload();
    }

    void GameDLLManager::SetupInterfaces(IAppInterface* appInterface)
    {
        m_Interface = m_Impl->SetupInterfaces(appInterface);
    }
} // namespace hg
