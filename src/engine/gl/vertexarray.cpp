#include "vertexarray.h"
// Ext includes
#include "glad/gl.h"

// engine include
#include "util/instrumentor.h"

VertexArray::VertexArray()
{
    glCreateVertexArrays(1, &gl_ID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &gl_ID);
}

void VertexArray::AddBuffer(const VertexBuffer& vertex_buffer, const BufferLayout& layout, const IndexBuffer& index_buffer)
{
    HG_PROFILE_FUNCTION();
    
    unsigned int offset = 0;
    std::vector<BufferLayoutElement> elements = layout.GetElementVector();
    for(unsigned int i = 0; i < elements.size(); i++)
    {
        BufferLayoutElement element = elements.at(i);
        glEnableVertexArrayAttrib(gl_ID, i);
        glVertexArrayAttribFormat(gl_ID, i, element.gl_Count, element.gl_Type, element.gl_Normalized, offset);
        glVertexArrayAttribBinding(gl_ID, i, 0);

        offset += element.gl_Count * BufferLayoutElement::GetSizeOfGLType(element.gl_Type);
    }

    glVertexArrayVertexBuffer(gl_ID, 0, vertex_buffer.GetID(), 0, layout.GetStride());
    glVertexArrayElementBuffer(gl_ID, index_buffer.GetID());
}

void VertexArray::Bind() const
{
    glBindVertexArray(gl_ID);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}