#include "context.h"
#include "api.h"
#include "gl4/gl4context.h"

Scope<Context> Context::Create(void* windowHandle)
{
    switch (GraphicsAPI::GetAPI())
    {
    case GraphicsAPIType::NONE:
        break;
    case GraphicsAPIType::OPENGL:
        return MakeScope<GL4Context>(windowHandle);
        break;
    default:
        break;
    }
}