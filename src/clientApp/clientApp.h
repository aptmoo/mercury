#ifndef CLIENTAPP_H
#define CLIENTAPP_H
#include "core/types.h"
#include "core/args.h"
#include "core/gamemanager.h"

#include <string>

namespace hg
{
    struct AppDesc
    {
        std::string Name;
        int Width, Height;

        ParsedArgs Args;
    };

    class ClientApplication
    {
    public:
        ClientApplication(const AppDesc& desc);
        ~ClientApplication();

        void Run();

        bool IsRunning() { return m_Running; };
        void Shutdown() { m_Running = false; };

        static ClientApplication& GetInstance();
    private:
        void Render();
        void Update();

        GameDLLManager m_GameDLL;

        bool m_Running = false;
        AppDesc m_Desc;
    };
} // namespace hg


#endif