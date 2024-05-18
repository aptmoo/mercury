#include "gmain.h"
#include "shared/appinterface.h"
#include "shared/gameinterface.h"
#include <iostream>

class TestGameInterface : public IGameInterface
{
public:
    TestGameInterface(){};
    virtual ~TestGameInterface() override {};

    virtual void TestPrint() override { std::cout << "Hello from GameDLL, called by app!\n"; };
};

static IAppInterface *s_AppInterface;
static TestGameInterface s_GameInterface;

extern "C" void* GDLL_GetInterface(void* appInterface)
{
    s_AppInterface = (IAppInterface*)appInterface;
    s_AppInterface->TestPrint();
    return &s_GameInterface;
}