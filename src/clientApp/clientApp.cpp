#include "clientApp.h"

namespace hg
{
    static ClientApplication* s_pInstance;

    struct ClientAppInterface : IAppInterface
    {
        virtual void Shutdown() override { ClientApplication::GetInstance().Shutdown(); }
    };

    ClientApplication::ClientApplication(const AppDesc& desc)
    {
        s_pInstance = this;
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

    ClientApplication& ClientApplication::GetInstance()
    {
        return *s_pInstance;
    }
} // namespace hg
