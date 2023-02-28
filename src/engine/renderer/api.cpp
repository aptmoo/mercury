#include "api.h"
#include "util/instrumentor.h"

GraphicsAPIType GraphicsAPI::s_API;

ScopePtr<GraphicsAPI> GraphicsAPI::Create()
{
    HG_PROFILE_FUNCTION();
    
    switch (s_API)
    {
    case GraphicsAPIType::NONE:
        break;
    default:
        break;
    }
}