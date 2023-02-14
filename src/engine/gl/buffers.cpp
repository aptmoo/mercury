#include "buffers.h"
// Ext includes
#include <glad/gl.h>

unsigned int BufferLayoutElement::GetSizeOfGLType(unsigned int type)
{
    switch(type)
    {
        case GL_UNSIGNED_INT : return sizeof(GLuint); break;
        case GL_FLOAT : return sizeof(GLfloat); break;
        default: break;
    }
    return 0;
}

void BufferLayout::AddFloat(unsigned int count)
{
    m_Elements.emplace_back(GL_FLOAT, count, GL_FALSE);
    m_Stride += count * BufferLayoutElement::GetSizeOfGLType(GL_FLOAT);
}

void BufferLayout::AddUInt(unsigned int count)
{
    m_Elements.emplace_back(GL_UNSIGNED_INT, count, GL_FALSE);
    m_Stride += count * BufferLayoutElement::GetSizeOfGLType(GL_UNSIGNED_INT);
}

VertexBuffer::VertexBuffer(unsigned int data_size, void* data)
{
    glCreateBuffers(1, &gl_ID);
    glNamedBufferData(gl_ID, data_size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &gl_ID);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, gl_ID);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int VertexBuffer::GetID() const
{
    return gl_ID;
}

IndexBuffer::IndexBuffer(unsigned int count, unsigned int* data)
{
    glCreateBuffers(1, &gl_ID);
    glNamedBufferData(gl_ID, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &gl_ID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gl_ID);
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::GetID() const
{
    return gl_ID;
}