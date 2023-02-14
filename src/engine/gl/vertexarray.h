/*
vertexarray.h: openGL vertex array.
*/

#ifndef HG_VERTEXARRAY_H
#define HG_VERTEXARRAY_H
// Engine include
#include "gl/buffers.h"

class VertexArray
{
private:
    unsigned int gl_ID;
public:
    VertexArray();
    ~VertexArray();

    /*
    @brief Add buffers to this vertex array.
    */
    void AddBuffer(const VertexBuffer& vertex_buffer, const BufferLayout& layout, const IndexBuffer& index_buffer);

    /*
    @brief Bind this vertex array.
    */
    void Bind() const;

    /*
    @brief Unbind this vertex array.
    */
    void Unbind() const;
};

#endif