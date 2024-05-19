#include <iostream>
#include <dlfcn.h>
#include <string>

#include "shared/appinterface.h"
#include "shared/gameinterface.h"
#include "shared/args.h"

class TestAppInterface : public hg::IAppInterface
{
public:
    TestAppInterface(){};
    virtual ~TestAppInterface() override {}

    virtual void TestPrint() override { std::cout << "Test by app, called by gameDLL!\n"; };
};

int main(int argc, char const *argv[])
{
    hg::Args args(argc, argv);
    for(int i = 0; i < args.GetSize(); i++)
    {
        std::cout << args[i] << '\n';
    }

    std::string game = "./libgame.so";

    TestAppInterface iface;
    hg::IGameInterface* gameIface;
    void* dllHandle = dlopen(game.c_str(), RTLD_NOW);
    // Lmaoooo
    void*(*getIface)(void) = (void*(*)(void))dlsym(dllHandle, "GDLL_GetInterface");
    void(*setIface)(void*) = (void(*)(void*))dlsym(dllHandle, "GDLL_SetInterface");
    setIface(&iface);
    gameIface = (hg::IGameInterface*)getIface();
    gameIface->TestPrint();
    dlclose(dllHandle);
    return 0;
}
