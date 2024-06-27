#include "application.h"
#include "shared/args.h"

int main(int argc, char const *argv[])
{
    hg::Args args(argc, argv);
    hg::ApplicationDesc desc;
    desc.Args = args;
    desc.Name = "App";
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
