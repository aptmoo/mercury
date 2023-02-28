#include "glwindow.h"
#include <stdexcept>

static unsigned int s_WindowCounter = 0;

GLWindow::GLWindow(const WindowDesc& desc)
{
    if(s_WindowCounter <= 0)
        if(!glfwInit())
            throw std::runtime_error("Failed to init GLFW!");
    
}