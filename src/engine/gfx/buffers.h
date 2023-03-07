#ifndef HG_BUFFERS_H
#define HG_BUFFERS_H
#include "util/defs.h"

#include <string>
#include <vector>

enum class ElementType
{
    NONE, FLOAT, INT, BOOL
};

struct BufferElement
{
    ElementType Type;
    unsigned int Count;
    bool Normalized;

    static std::size_t GetSizeOfType(ElementType type);
};

class BufferLayout
{
private:
    unsigned int m_Stride;
    std::vector<BufferElement> m_Elements;

    /**
     * @brief Internal add element type.
     * 
     * @param type 
     * @param count 
     * @param normalized 
     */
    void AddElement(ElementType type, unsigned int count, bool normalized);
public:
    /**
     * @brief Get the Elements object
     * 
     * @return std::vector<BufferElement> 
     */
    std::vector<BufferElement> GetElements() { return m_Elements; }

    // TODO: add more types
    /**
     * @brief Add a float element, times count.
     * 
     * @param count 
     */
    void AddFloat(unsigned int count);

    /**
     * @brief Add a int element, times count.
     * 
     * @param count 
     */
    void AddInt(unsigned int count);
};

/**
 * @note Note that binding is optional in most modern api's.
 * OpenGL only requires binding when not using DSA.
 * Mercury's GL4 implementation uses DSA.
 * 
 */

class StaticVertexBuffer
{
public:
    virtual ~StaticVertexBuffer() = default;

    /**
     * @brief Bind this buffer. What more do you want from me?
     * 
     */
    virtual void Bind() = 0;

    /**
     * @brief Unbind this buffer. 
     * In OpenGL the "null buffer" 0 gets bound.
     */
    virtual void Unbind() = 0;

    /**
     * @briefCreate an vertex buffer.
     * It should be noted that count is the amount of vertices, not the total size!
     * This is because the implementation must use the sizeof(&data) trick.
     * Yes, its awful. Yes, Bjarne haunts my home. Deal with it!
     * 
     * These two funcs need accompanying construcors.
     * 
     * @param data 
     * @return Ref<StaticVertexBuffer> 
     */
    static Ref<StaticVertexBuffer> Create(void* data);

    // Better one, to at least partially compensate for my previous coding sin.
    static Ref<StaticVertexBuffer> Create(void *data, unsigned int totalSize);
};

using VertexBuffer = StaticVertexBuffer;

class IndexBuffer
{
public:
    virtual ~IndexBuffer() = default;

    /*
    @brief Bind this buffer.
    */
    virtual void Bind() = 0;

    /*
    @brief Unbind this buffer.
    */
    virtual void Unbind() = 0;

    /*
    @brief Return the ID of this buffer.
    Returns 0 by default, since this only gets used by OpenGL.
    */
    virtual unsigned int GetID() { return 0; };

    /*
    @brief Get the amount of indices in this buffer.
    Implementations should hold the count(see comment below).
    */
    virtual unsigned int GetCount() = 0;

    /*
    @brief Create an index buffer.
    It should be noted that count is the amount of indices, not the total size!
    Count is not kept in the base class to both keep our lord and saviour Bjarne happy and avoid "brittle" base classes.
    */
    static Ref<IndexBuffer> Create(unsigned int* data, unsigned int count);
};

#endif