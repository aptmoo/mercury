/*
buffers.h: A bunch of generic opengl buffers.
*/

#ifndef HG_BUFFERS_H
#define HG_BUFFERS_H

// std includes
#include <vector>

struct BufferLayoutElement
{
    BufferLayoutElement(unsigned int type, unsigned int count, unsigned int normalized)
        : gl_Type(type), gl_Count(count), gl_Normalized(normalized) {}

    unsigned int gl_Type;
    unsigned int gl_Count;
    unsigned int gl_Normalized;

    static unsigned int GetSizeOfGLType(unsigned int type);
};

class BufferLayout
{
private:
    unsigned int m_Stride;
    std::vector<BufferLayoutElement> m_Elements;

public:
    BufferLayout() : m_Stride(0) {};

    // The AddType functions are not templated to avoid polluting the global namespace with opengl

    /*
    @brief Add float element.
    */
    void AddFloat(unsigned int count);

    /*
    @brief Add unsigned int element.
    */
    void AddUInt(unsigned int count);

    /*
    @brief Returns a copy of the internal element vector
    */
    std::vector<BufferLayoutElement> GetElementVector() const { return m_Elements; }

    /*
    @brief Returns the stride(total size) of the layout.
    */
    unsigned int GetStride() const { return m_Stride; }
};

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
    @note This has no use in modern DSA OpenGL.
    */
    void Bind() const;

    /*
    @brief Unbind vertex buffer.
    @note This has no use in modern DSA OpenGL.
    */
    void Unbind() const;

    /*
    @brief Return openGL id.
    */
    unsigned int GetID() const;
};

class IndexBuffer
{
private:
    unsigned int gl_ID;
public:
    /*
    
    */
    IndexBuffer(unsigned int count, unsigned int* data);

    /*
    @brief Index destructor.
    */
    ~IndexBuffer();

    /*
    @brief Bind element buffer.
    @note This has no use in modern DSA OpenGL.
    */
    void Bind() const;

    /*
    @brief Unbind element buffer.
    @note This has no use in modern DSA OpenGL.
    */
    void Unbind() const;

    /*
    @brief Return openGL id.
    */
    unsigned int GetID() const;
};

#endif