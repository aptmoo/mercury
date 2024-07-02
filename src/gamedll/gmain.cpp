#include "gmain.h"
#include "shared/appinterface.h"
#include "shared/gameinterface.h"
#include <iostream>

hg::IAppInterface *s_AppInterface;

class TestGameInterface : public hg::IGameInterface
{
public:
    TestGameInterface(){};
    virtual ~TestGameInterface() override {};

    virtual void TestPrint() override { std::cout << "Hello from GameDLL new, called by app!\n"; };

    virtual void Init() override { std::cout << "Init!\n"; }
    virtual void Update() override { s_AppInterface->Print("Update!\n"); }
};

static TestGameInterface s_GameInterface;

extern "C" void* GDLL_SetupInterfaces(void* iface)
{
    s_AppInterface = (hg::IAppInterface*)iface;
    return &s_GameInterface;
}