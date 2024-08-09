#ifndef SHARED_NULL_WINDOW_H
#define SHARED_NULL_WINDOW_H
#include "core/window.h"

namespace hg
{
    class NullWindow : public IWindow
    {
    public:
        NullWindow(){};
        virtual ~NullWindow() override {};

        virtual void Update() override;

        virtual int GetHeight() override { return 0; };
        virtual int GetWidth() override { return 0; };
        virtual void SetSize(int width, int height) override {};

        virtual void *GetNativeHandle() override { return nullptr; };
    };    
} // namespace hg


#endif