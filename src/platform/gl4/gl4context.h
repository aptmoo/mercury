#ifndef HG_GL4CONTEXT_H
#define HG_GL4CONTEXT_H
#include "util/defs.h"
#include "gfx/context.h"

class GL4Context : public Context
{
private:
    void* m_WindowHandle;

public:
    GL4Context(void* windowHandle);

    void Init() override;
    void Shutdown() override;

    void Swap() override;
};

#endif