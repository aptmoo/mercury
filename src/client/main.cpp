#include <iostream>
#include <dlfcn.h>

#include "shared/appinterface.h"
#include "shared/gameinterface.h"

class TestAppInterface : public IAppInterface
{
public:
    TestAppInterface(){};
    virtual ~TestAppInterface() override {}

    virtual void TestPrint() override { std::cout << "Test by app, called by gameDLL!\n"; };
};

int main(int argc, char const *argv[])
{
    TestAppInterface iface;
    IGameInterface* gameIface;
    void* dllHandle = dlopen("./libgame.so", RTLD_NOW);
    // Lmaoooo
    void*(*fcnHandle)(void*) = (void*(*)(void*))dlsym(dllHandle, "GDLL_GetInterface");
    gameIface = (IGameInterface*)fcnHandle(&iface);
    gameIface->TestPrint();
    dlclose(dllHandle);
    return 0;
}
