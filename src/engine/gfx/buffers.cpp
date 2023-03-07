#include "buffers.h"
#include "api.h"

Ref<StaticVertexBuffer> Create(void* data)
{
    // TODO: opengl implementation
    switch (GraphicsAPI::GetAPI())
    {
    case GraphicsAPIType::NONE:
        break;
        break;
    default:
        break;
    }
}

Ref<StaticVertexBuffer> Create(void *data, unsigned int totalSize)
{
    // TODO: opengl implementation
    switch (GraphicsAPI::GetAPI())
    {
    case GraphicsAPIType::NONE:
        break;
        break;
    default:
        break;
    }
}

Ref<IndexBuffer> Create(unsigned int *data, unsigned int count)
{
    // TODO: opengl implementation
    switch (GraphicsAPI::GetAPI())
    {
    case GraphicsAPIType::NONE:
        break;
        break;
    default:
        break;
    }
}