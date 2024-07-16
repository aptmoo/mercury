#ifndef CLIENTAPP_H
#define CLIENTAPP_H
#include "shared/types.h"
#include "shared/application.h"
#include "shared/args.h"

#include <string>

namespace hg
{
    class ClientApplication : IBaseApplication
    {
    public:
        ClientApplication(const BaseAppDesc& desc);
        virtual ~ClientApplication() override;

        void Run() override;
    private:
        BaseAppDesc m_Desc;
    };
} // namespace hg


#endif