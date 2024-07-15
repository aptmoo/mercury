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

        virtual ~ClientApplication() override;
    };
} // namespace hg


#endif