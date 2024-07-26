#ifndef CLIENTAPP_H
#define CLIENTAPP_H
#include "core/types.h"
#include "core/application.h"
#include "core/args.h"
#include "core/gamemanager.h"

#include <string>

namespace hg
{
    class ClientApplication final : public IBaseApplication
    {
    public:
        ClientApplication(const BaseAppDesc& desc);
        virtual ~ClientApplication() override;

        void Run() override;

        virtual bool IsRunning() override { return m_Running; };
        virtual void Shutdown() override { m_Running = false; };

    private:
        void Render();
        void Update();

        GameDLLManager m_GameDLL;

        bool m_Running = false;
        BaseAppDesc m_Desc;
    };
} // namespace hg


#endif