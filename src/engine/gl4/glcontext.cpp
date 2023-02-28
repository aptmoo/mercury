#include "glcontext.h"
#include "glad/gl.h"
#include <stdexcept>

GLContext::GLContext(void* handle)
{
    m_WindowHandle = (GLFWwindow*)handle;
}

void GLContext::Init()
{
    if(!gladLoadGL(glfwGetProcAddress))
        throw std::runtime_error("Failed to init GLAD!");
}

void GLContext::Swap()
{
    glfwSwapBuffers(m_WindowHandle);
}