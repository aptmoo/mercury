#ifndef CLIENTAPP_H
#define CLIENTAPP_H
#include "shared/types.h"
#include "shared/application.h"
#include "shared/args.h"

#include <string>

namespace hg
{
    class ClientApplication final : public IBaseApplication
    {
    public:
        ClientApplication(const BaseAppDesc& desc);
        virtual ~ClientApplication() override;

        void Run() override;

        bool IsRunning() { return m_Running; };
        void Shutdown() { m_Running = false; };

    private:
        void Render();
        void Update();

        bool m_Running = false;
        BaseAppDesc m_Desc;
    };
} // namespace hg


#endif