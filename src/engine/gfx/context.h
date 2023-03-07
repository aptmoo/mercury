#ifndef HG_CONTEXT_H
#define HG_CONTEXT_H
#include "util/defs.h"

class Context
{
public:
    virtual ~Context() = default;

    virtual void Init() = 0;
    virtual void Shutdown() = 0;

    virtual void Swap() = 0;

    static Scope<Context> Create(void* windowHandle);
};

#endif