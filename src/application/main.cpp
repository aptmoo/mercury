#include "application.h"
#include "shared/args.h"

int main(int argc, char const *argv[])
{
    hg::CArgs args(argc, argv);
    hg::ApplicationDesc desc;
    desc.args = args;
    desc.name = "App";
    hg::Application app(desc);
    app.Run();

    // TestAppInterface iface;
    // hg::CGameManager manager;
    // manager.Load(gamename);
    // manager.SetupInterfaces(&iface);
    // manager->Init();
    // manager->Update();
    return 0;
}
