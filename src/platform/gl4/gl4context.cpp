#include "gl4context.h"
#include "util/instrumentor.h"

// gl includes
#include <GLFW/glfw3.h>
#include "glad/gl.h"

GL4Context::GL4Context(void* windowHandle) 
    : m_WindowHandle(windowHandle) {};

void GL4Context::Init()
{
    HG_PROFILE_FUNCTION();

    glfwMakeContextCurrent((GLFWwindow*)m_WindowHandle);

    // TODO: Logging you lazy fuck
    gladLoadGL(glfwGetProcAddress);
}

void GL4Context::Shutdown()
{
    // No profiling empty functions
}

void GL4Context::Swap()
{
    // no profiling in elementary rendering operations!
    glfwSwapBuffers((GLFWwindow*)m_WindowHandle);
}