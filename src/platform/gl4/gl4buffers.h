#ifndef HG_GL4BUFFERS_H
#define HG_GL4BUFFERS_H
#include "gfx/buffers.h"

class GL4StaticVertexBuffer : public StaticVertexBuffer
{
private:
    unsigned int gl_ID;
public:
    // ctors/dtor
    GL4StaticVertexBuffer(void* data);
    GL4StaticVertexBuffer(void* data, unsigned int totalSize);
    ~GL4StaticVertexBuffer();

    // Overrides
    void Bind() override;
    void Unbind() override;

    // This function is only available on OpenGL. Use casting to acess it.
    unsigned int GetID() { return gl_ID; }
};

class GL4IndexBuffer : public IndexBuffer
{
private:
    unsigned int gl_ID;
public:
    // ctors/dtor
    GL4IndexBuffer(unsigned int* data, unsigned int count);
    GL4IndexBuffer();

    // Overrides
    void Bind() override;
    void Unbind() override;

    // This function is only available on OpenGL. Use casting to acess it.
    unsigned int GetID() { return gl_ID; }
};

#endif