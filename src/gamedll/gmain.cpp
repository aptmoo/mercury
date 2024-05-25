#include "gmain.h"
#include "shared/appinterface.h"
#include "shared/gameinterface.h"
#include <iostream>

class TestGameInterface : public hg::IGameInterface
{
public:
    TestGameInterface(){};
    virtual ~TestGameInterface() override {};

    virtual void TestPrint() override { std::cout << "Hello from GameDLL new, called by app!\n"; };

    virtual void Init() override { std::cout << "Init!\n"; }
    virtual void Update() override { std::cout << "Update!\n"; }
};

static hg::IAppInterface *s_AppInterface;
static TestGameInterface s_GameInterface;

extern "C" void* GDLL_SetupInterfaces(void* iface)
{
    s_AppInterface = (hg::IAppInterface*)iface;
    s_AppInterface->TestPrint();
    return &s_GameInterface;
}