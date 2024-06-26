#include "gamemanager.h"
#include <string>
#include <functional>
#include <iostream>

namespace hg
{
    #if defined(SYSTEM_LINUX) || defined(__linux__) // VSCode will get pissed of if you dont do this.
    #include <dlfcn.h>
    struct GameManager::GameManagerImpl
    {
        GameManagerImpl(){};
        ~GameManagerImpl()
        {
            this->UnLoad();
        };

        void Load(const std::string& gamename)
        {
            std::string path = "./" + gamename + "/lib" + gamename + ".so";
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

        void UnLoad()
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

    GameManager::GameManager()
        : m_Impl(new GameManagerImpl())
    {

    }

    GameManager::~GameManager()
    {
        m_Impl->UnLoad();
    }

    void GameManager::Load(const std::string& gamename)
    {
        m_Impl->Load(gamename);
    }
    
    void GameManager::UnLoad()
    {
        m_Impl->UnLoad();
    }

    void GameManager::SetupInterfaces(IAppInterface* appInterface)
    {
        m_Interface = m_Impl->SetupInterfaces(appInterface);
    }
} // namespace hg
