#ifndef HG_CONTEXT_H
#define HG_CONTEXT_H
#include "util/defs.h"

class GraphicsContext
{
private:

public:
    virtual ~GraphicsContext() = default;

    virtual void Init() = 0;
    virtual void Swap() = 0;

    static ScopePtr<GraphicsContext> Create(void* windowHandle);
};

#endif