#include "gl4api.h"
#include "glad/gl.h"

void GL4GraphicsAPI::Init()
{

}

void GL4GraphicsAPI::Shutdown()
{
    // Crickets...
}

void GL4GraphicsAPI::Viewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{   
    glViewport(x, y, w, h);
}

void GL4GraphicsAPI::SetClearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void GL4GraphicsAPI::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void GL4GraphicsAPI::DrawArrays(unsigned int first, unsigned int count)
{
    glDrawArrays(GL_TRIANGLES, first, count);
}

void GL4GraphicsAPI::DrawElements(unsigned int count)
{
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}
