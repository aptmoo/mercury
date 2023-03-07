#include "gl4buffers.h"
#include "glad/gl.h"

GL4StaticVertexBuffer::GL4StaticVertexBuffer(void* data)
{
    glCreateBuffers(1, &gl_ID);
    glNamedBufferData(gl_ID, sizeof(data), data, GL_STATIC_DRAW);
}

GL4StaticVertexBuffer::GL4StaticVertexBuffer(void* data, unsigned int totalSize)
{
    glCreateBuffers(1, &gl_ID);
    glNamedBufferData(gl_ID, totalSize, data, GL_STATIC_DRAW);
}

GL4StaticVertexBuffer::~GL4StaticVertexBuffer()
{
    glDeleteBuffers(1, &gl_ID);
}

void GL4StaticVertexBuffer::Bind()
{
    // Not needed for DSA
}

void GL4StaticVertexBuffer::Unbind()
{
    // Not needed for DSA
}

GL4IndexBuffer::GL4IndexBuffer(unsigned int* data, unsigned int count)
{
    glCreateBuffers(1, &gl_ID);
    glNamedBufferData(1, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

GL4IndexBuffer::~GL4IndexBuffer()
{
    glDeleteBuffers(1, &gl_ID);
}

void GL4IndexBuffer::Bind()
{
    // Not needed for DSA
}

void GL4IndexBuffer::Unbind()
{
    // Not needed for DSA
}
