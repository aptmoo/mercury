#include "gcommon.h"
#include "core/appinterface.h"
#include "core/gameinterface.h"
#include <iostream>

struct SandboxInterface : public hg::IGameInterface
{
    SandboxInterface(){};
    virtual ~SandboxInterface() override {};

    virtual void Init() override { std::cout << "Inited sandbox!\n"; }
    virtual void Update() override { s_AppIFace->Shutdown(); }
};

static SandboxInterface s_GameInterface;

extern "C" void* GDLL_SetupInterfaces(void* iface)
{
    s_AppIFace = (hg::IAppInterface*)iface;
    return &s_GameInterface;
}