#include "renderer/api.h"

#include <stdexcept>
#include <iostream>

int main(int argc, char const *argv[])
{
    GraphicsAPI::SetAPI(GraphicsAPIType::VULKAN);
    ScopePtr<GraphicsAPI> api = GraphicsAPI::Create();
    api->Init();   
    return 0;
}