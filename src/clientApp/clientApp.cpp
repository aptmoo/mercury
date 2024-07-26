#include "clientApp.h"

namespace hg
{
    struct ClientAppInterface : IAppInterface
    {
        virtual void Shutdown() override { IBaseApplication::GetInstance().Shutdown(); }
    };

    ClientApplication::ClientApplication(const BaseAppDesc& desc)
    {
        SetInstance(this);
        m_Desc = desc;
    }

    ClientApplication::~ClientApplication()
    {

    }

    void ClientApplication::Run()
    {
        static ClientAppInterface s_Interface;

        std::string gamename = m_Desc.Args.GetOrDefault("gamedir", "basegame");
        m_GameDLL.Load("./"+gamename+"/lib"+gamename+".so");
        m_GameDLL.SetupInterfaces(&s_Interface);

        m_GameDLL->Init();

        if (m_Running) return;
            m_Running = true;

        while(m_Running)
        {
            this->Update();
            this->Render();
        }

        m_Running = false;
    }

    void ClientApplication::Update()
    {
        m_GameDLL->Update();
    }

    void ClientApplication::Render()
    {

    }
} // namespace hg
