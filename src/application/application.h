#ifndef APPLICATION_APP_H
#define APPLICATION_APP_H
#include "shared/gamemanager.h"
#include "shared/args.h"

#include <string>

namespace hg
{
    struct ApplicationDesc
    {
        std::string Name = "DefaultName";
        hg::Args Args;
    };

    class Application
    {
    public:
        Application(const ApplicationDesc& desc = ApplicationDesc());
        ~Application();

        Application* Get();

        /**
         * @brief Run app. Calls RunInternal to avoid "rerunning"
         * 
         */
        void Run();
    private:
        bool m_Running = false;

        ApplicationDesc m_Desc;
        GameManager m_Manager;
    };
} // namespace hg


#endif