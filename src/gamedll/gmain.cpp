#include "gmain.h"
#include "shared/appinterface.h"
#include "shared/gameinterface.h"
#include <iostream>

hg::IAppInterface *s_AppInterface;

struct TestGameInterface : public hg::IGameInterface
{
    TestGameInterface(){};
    virtual ~TestGameInterface() override {};

    virtual void Init() override { }
    virtual void Update() override { }
};

static TestGameInterface s_GameInterface;

extern "C" void* GDLL_SetupInterfaces(void* iface)
{
    s_AppInterface = (hg::IAppInterface*)iface;
    return &s_GameInterface;
}