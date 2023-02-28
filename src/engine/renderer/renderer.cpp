#include "renderer.h"

ScopePtr<GraphicsAPI> Renderer::s_RenderAPI;

void Renderer::Init(GraphicsAPIType api)
{
    s_RenderAPI->SetAPI(api);
    s_RenderAPI->Init();
}