#include "glapi.h"
#include "glad/gl.h"

void GLGraphicsAPI::Init()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
}

void GLGraphicsAPI::Close()
{
    // :)
}

void GLGraphicsAPI::SetViewport(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
    glViewport(x,  y, w, h);
}

void GLGraphicsAPI::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}