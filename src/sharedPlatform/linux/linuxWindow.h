#ifndef SHARED_LINUX_WINDOW_H
#define SHARED_LINUX_WINDOW_H
#include "core/window.h"

namespace hg
{
    class LinuxWindow : public IWindow
    {
    public:
        LinuxWindow(const WindowDesc& desc);
        virtual ~LinuxWindow() override;

        virtual void Update() override;

        virtual int GetHeight() override;
        virtual int GetWidth() override;
        virtual void SetSize(int width, int height) override;

        virtual void *GetNativeHandle() override { return m_pWindowHandle; };
    private:
        struct
        {
            int width, height;
            std::string title; 
        } m_WindowData;

        void* m_pWindowHandle;
    };
} // namespace hg


#endif