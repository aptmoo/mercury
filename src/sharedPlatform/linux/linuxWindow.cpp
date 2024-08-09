#include "linuxWindow.h"
#include "GLFW/glfw3.h"

namespace hg
{
    static uint8_t s_WindowCount = 0;

    LinuxWindow::LinuxWindow(const WindowDesc& desc)
    {
        if(s_WindowCount == 0)
        {
            glfwInit();
        }
        
        m_pWindowHandle = glfwCreateWindow(desc.Width, desc.Height, desc.Title.c_str(), nullptr, nullptr);

        s_WindowCount++;
    }

    LinuxWindow::~LinuxWindow()
    {
        s_WindowCount--;
        if(s_WindowCount == 0)
        {
            glfwTerminate();
        }
    }
} // namespace hg
