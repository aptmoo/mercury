#include "clientApp.h"

namespace hg
{
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
        if(m_Running)
            return;
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

    }

    void ClientApplication::Render()
    {

    }
} // namespace hg
