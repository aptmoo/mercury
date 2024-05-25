#include "application.h"

namespace hg
{
    void Application::Run()
    {
        if(m_Running)
            return;     // Avoid running again before shutown
        
        m_Running = true;
        RunInternal();
    }

    void Application::RunInternal()
    {
        while (m_Running)
        {
            
        }
    }
} // namespace hg
