#ifndef HG_RENDERER_H
#define HG_RENDERER_H

// engine include
#include "util/defs.h"
#include "api.h"


class Renderer
{
private:
    static ScopePtr<GraphicsAPI> s_RenderAPI;

public:
    static void Init(GraphicsAPIType api);
    static void Close();

    // TODO: add camera argument
    static void BeginFrame();
    static void EndFrame();

    // TODO: getters and setters for the several types of matrices.
};

#endif