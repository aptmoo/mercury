#ifndef SHARED_WINDOW_H
#define SHARED_WINDOW_H
#include "types.h"
#include <string>

namespace hg
{
    struct WindowDesc
    {
        std::string Title;
        int Width, Height;
    };

    class IWindow
    {
    public:
        virtual ~IWindow() = default;

        virtual void Update() = 0;

        virtual int GetHeight() = 0;
        virtual int GetWidth() = 0;
        virtual void SetSize(int width, int height) = 0;

        virtual void* GetNativeHandle() = 0;

        static Scope<IWindow> Create(const WindowDesc& desc);
    };
} // namespace hg


#endif