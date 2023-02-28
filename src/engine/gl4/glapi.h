#ifndef HG_GLAPI_H
#define HG_GLAPI_H
#include "renderer/api.h"

class GLGraphicsAPI : public GraphicsAPI
{
private:

public:
    void Init() override;

    void Close() override;

    void SetViewport(unsigned int x, unsigned int y, unsigned int w, unsigned int h) override;

    void Clear() override;
};

#endif