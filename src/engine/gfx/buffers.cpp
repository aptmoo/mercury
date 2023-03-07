#include "buffers.h"
#include "api.h"
#include "gl4/gl4buffers.h"

std::size_t BufferElement::GetSizeOfType(ElementType type)
{
    switch (type)
    {
    case ElementType::NONE:
        return 0;
    case ElementType::FLOAT:
        return sizeof(float);
    case ElementType::INT:
        return sizeof(int);
    case ElementType::BOOL:
        return sizeof(bool);
    default:
        break;
    }

    return 0;
}

void BufferLayout::AddElement(ElementType type, unsigned int count, bool normalized)
{
    m_Stride += count * BufferElement::GetSizeOfType(type);
    m_Elements.emplace_back(type, count, normalized);
}

Ref<StaticVertexBuffer> Create(void* data)
{
    switch (GraphicsAPI::GetAPI())
    {
    case GraphicsAPIType::NONE:
        break;
    case GraphicsAPIType::OPENGL:
        return MakeRef<GL4StaticVertexBuffer>(data);
        break;
    default:
        break;
    }
}

Ref<StaticVertexBuffer> Create(void *data, unsigned int totalSize)
{
    switch (GraphicsAPI::GetAPI())
    {
    case GraphicsAPIType::NONE:
        break;
    case GraphicsAPIType::OPENGL:
        return MakeRef<GL4StaticVertexBuffer>(data, totalSize);
        break;
    default:
        break;
    }
}

Ref<IndexBuffer> Create(unsigned int *data, unsigned int count)
{
    switch (GraphicsAPI::GetAPI())
    {
    case GraphicsAPIType::NONE:
        break;
        return MakeRef<GL4IndexBuffer>(data, count);
        break;
    default:
        break;
    }
}