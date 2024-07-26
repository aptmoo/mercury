#include "gcommon.h"
#include "core/appinterface.h"
#include "core/gameinterface.h"
#include <iostream>

struct TestGameInterface : public hg::IGameInterface
{
    TestGameInterface(){};
    virtual ~TestGameInterface() override {};

    virtual void Init() override { std::cout << "Inited BaseGame!\n"; }
    virtual void Update() override { s_AppIFace->Shutdown(); }
};

static TestGameInterface s_GameInterface;

extern "C" void* GDLL_SetupInterfaces(void* iface)
{
    s_AppIFace = (hg::IAppInterface*)iface;
    return &s_GameInterface;
}