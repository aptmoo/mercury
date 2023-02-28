#ifndef HG_RENDERAPI_H
#define HG_RENDERAPI_H
#include "util/defs.h"

enum class GraphicsAPIType
{
    NONE,
    VULKAN,
    OPENGL
};

/*
@class GraphicsAPI Base graphics api wrapper.
*/
class GraphicsAPI
{
private:
    static GraphicsAPIType s_API;
public:
    virtual ~GraphicsAPI() = default;

    /*
    @brief Base initialization function.
    */
    virtual void Init() = 0;

    /*
    @brief Shut down the renderer.
    */
    virtual void Close() = 0;

    /*
    @brief Base change viewport function.
    */
    virtual void SetViewport(unsigned int x, unsigned int y, unsigned int w, unsigned int h) = 0;

    /*
    @brief Base clear active buffer function
    */
    virtual void Clear() = 0;

    /*
    @brief Set the API to use.
    @warning Calling this more than once may lead to severe problems!
    */
    static void SetAPI(GraphicsAPIType api) { s_API = api; }

    /*
    @brief Get the API type.
    */
    static GraphicsAPIType GetAPIType() { return s_API; }

    /*
    Create an object based on the api.
    */
    static ScopePtr<GraphicsAPI> Create();
};

#endif