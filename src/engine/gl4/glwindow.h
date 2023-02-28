#ifndef HG_GLWINDOW_H
#define HG_GLWINDOW_H
#include "renderer/window.h"
#include "glcontext.h"

class GLWindow : public Window
{
private:
    GLFWwindow* m_Window;
    ScopePtr<GraphicsContext> m_ContextHandle;
public:
    GLWindow(const WindowDesc& desc);
    virtual ~GLWindow();

    void Present() override;

    void* GetNativeHandle() { return (void*)m_Window; }
};

#endif