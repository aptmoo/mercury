#include "application.h"

#include <iostream>

namespace hg
{
    static Application* s_Application;

    class AppInterface : public IAppInterface
    {
    public:
        virtual void Print(const std::string& str)
        {
            std::cout << str;
        }
    };
    
    static AppInterface s_AppInterface;

    Application::Application(const ApplicationDesc& desc)
    {
        s_Application = this;
        m_Desc = desc;
    }

    Application::~Application()
    {

    }

    Application* Application::Get()
    {
        return s_Application;
    }

    void Application::Run()
    {
        if(m_Running)
            return;     // Avoid running again before shutdown
        m_Running = true;

        if(m_Desc.Args.at(0).empty())
        {
            m_Manager.Load("basegame");
        }
        else
        {
            m_Manager.Load(m_Desc.Args.at(0));
        }

        m_Manager.SetupInterfaces(&s_AppInterface);
        m_Manager->Init();
        while (m_Running)
        {
            m_Manager->Update();
        }

        m_Running = false;
    }


} // namespace hg
