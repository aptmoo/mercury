#ifndef APPLICATION_APP_H
#define APPLICATION_APP_H
#include "shared/gamemanager.h"

namespace hg
{
    class Application
    {
    public:
        void Run();
    private:
        void RunInternal();
        bool m_Running = false;

        CGameManager m_Manager;
    };
} // namespace hg


#endif