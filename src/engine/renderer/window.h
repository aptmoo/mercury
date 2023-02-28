#ifndef HG_WINDOW_H
#define HG_WINDOW_H
#include "util/defs.h"

#include <string>

struct WindowDesc
{
    std::string name;
    unsigned int w, h;
};

class Window
{
private:

public:
    /*
    Note: The ctor/dtor should be declared by subclasses.
    */

    virtual ~Window() = default;

    /*
    @brief Present/swap the current buffer.
    */
    virtual void Present() = 0;

    /*
    @brief Base get handle function.
    Returns a void pointer to a platform specific object.
    */
    virtual void* GetNativeHandle() = 0;

    /*
    */
    static ScopePtr<Window> Create(const WindowDesc& desc);
};

#endif