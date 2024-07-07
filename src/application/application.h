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

        /**
         * @brief Get the current active app.
         * 
         * @return Application* 
         */
        static Application* Get();

        /**
         * @brief Run app.
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