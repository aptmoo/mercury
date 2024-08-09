#include "window.h"
#include "null/nullWindow.h"

namespace hg
{
    Scope<IWindow> IWindow::Create(const WindowDesc &desc)
    {
        return MakeScope<NullWindow>();
    }
} // namespace hg
