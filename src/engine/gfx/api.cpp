#include "api.h"
#include "gl4/gl4api.h"

GraphicsAPIType GraphicsAPI::s_API;

Scope<GraphicsAPI> GraphicsAPI::Create()
{
    switch (GraphicsAPI::GetAPI())
    {
    case GraphicsAPIType::NONE:
        break;
    case GraphicsAPIType::OPENGL:
        return MakeScope<GL4GraphicsAPI>();
        break;
    default:
        break;
    }
}

void GraphicsAPI::SetAPI(const GraphicsAPIType& api)
{
    s_API = api;
}

GraphicsAPIType GraphicsAPI::GetAPI()
{
    return s_API;
}