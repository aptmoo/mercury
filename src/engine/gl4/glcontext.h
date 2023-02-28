#ifndef HG_GLAPI_H
#define HG_GLAPI_H
#include "renderer/context.h"
#include <GLFW/glfw3.h>

class GLContext : public GraphicsContext
{
private:
    GLFWwindow* m_WindowHandle;
public:
    GLContext(void* handle);

    void Init() override;

    void Swap() override;
};

#endif