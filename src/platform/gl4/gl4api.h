#ifndef HG_GL4API_H
#define HG_GL4API_H
#include "util/defs.h"
#include "gfx/api.h"

class GL4GraphicsAPI final : public GraphicsAPI
{
public:
    // Override init funcs
    void Init() override;
    void Shutdown() override;

    // Overridde rendering funcs
    void Viewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h) override;
    void SetClearColor(float r, float g, float b, float a) override;
    void Clear() override;
    void DrawArrays(unsigned int first, unsigned int count) override;
    void DrawElements(unsigned int count) override;
};  

#endif