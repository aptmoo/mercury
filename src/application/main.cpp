#include <iostream>
#include <dlfcn.h>
#include <string>

#include "shared/appinterface.h"
#include "shared/gameinterface.h"
#include "shared/args.h"
#include "shared/gamemanager.h"

class TestAppInterface : public hg::IAppInterface
{
public:
    TestAppInterface(){};
    virtual ~TestAppInterface() override {}

    virtual void TestPrint() override { std::cout << "Test by app, called by gameDLL!\n"; };
};

int main(int argc, char const *argv[])
{
    hg::CArgs args(argc, argv);

    std::string gamename;
    if(args.Size() > 0)
    {
        gamename = args[0];
    }
    else
        gamename = "basegame";

    TestAppInterface iface;
    hg::CGameManager manager;
    manager.Load(gamename);
    manager.SetupInterfaces(&iface);
    manager->Init();
    manager->Update();
    return 0;
}
