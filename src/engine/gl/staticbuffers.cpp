#include "staticbuffers.h"
#include <glad/gl.h>

VertexBuffer::VertexBuffer(unsigned int data_size, void* data)
{
    glCreateBuffers(1, &gl_ID);
    glNamedBufferData(gl_ID, data_size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &gl_ID);
}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, gl_ID);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int VertexBuffer::GetID()
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

void IndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gl_ID);
}

void IndexBuffer::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::GetID()
{
    return gl_ID;
}