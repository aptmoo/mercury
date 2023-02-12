/*
staticbuffers.h: static opengl buffers.
*/

#ifndef HG_STATICBUFFERS_H
#define HG_STATICBUFFERS_H

class VertexBuffer
{
private:
    unsigned int gl_ID;
public:
    /*
    @brief Vertex buffer constructor.
    data_size should be the type size times the data size.
    Data should be some kind of array.

    Make sure data_size and the actual size of data match up!
    protip:
    sizeof(vertices[0]) * num_vertices
    */
    VertexBuffer(unsigned int data_size, void* data);
    
    /*
    @brief Vertex buffer destructor.
    Deletes buffers on the gpu.
    */
    ~VertexBuffer();

    /*
    @brief Bind vertex buffer.
    */
    void Bind();

    /*
    @brief Unbind vertex buffer.
    */
    void Unbind();

    /*
    @brief Return openGL id.
    */
    unsigned int GetID();
};

class IndexBuffer
{
private:
    unsigned int gl_ID;
public:
    IndexBuffer(unsigned int count, unsigned int* data);
    ~IndexBuffer();

    void Bind();
    void Unbind();

    unsigned int GetID();
};

#endif