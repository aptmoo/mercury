#ifndef HG_GFX_API_H
#define HG_GFX_API_H
#include "util/defs.h"

enum class GraphicsAPIType
{   
    NONE = 0,
    OPENGL = 1,
    VULKAN = 2
};

class GraphicsAPI
{
private:
    // The static api. Has public getters/setters.
    // Maybe implement a per-instance api type?
    static GraphicsAPIType s_API;
public:

    /*
    @brief Default virtual destructor.
    */
    virtual ~GraphicsAPI() = default;

    /*
    @brief Initialize this graphics api instance.
    This assumes there is already a window in place.
    */
    virtual void Init() = 0;

    /*
    @brief Shut down this instance.
    */
    virtual void Shutdown() = 0;

    // Rendering funcs
    // TODO: Add more rendering funcions to API

    /*
    @brief Set the viewport size.
    */
    virtual void Viewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h) = 0;

    /*
    @brief Set the clear color.
    TODO: Add vec3/vec4 once the math stuff is done
    */
    virtual void SetClearColor(float r, float g, float b, float a) = 0;

    /*
    @brief Clear the current screen buffer.
    */
    virtual void Clear() = 0;

    /*
    @brief Draw currently bound arrays.
    Will assume the draw mode to be triangles.

    May or may not work on modern API's.

    TODO: implement line mode
    TODO: Check compatibility.
    */
    virtual void DrawArrays(unsigned int first, unsigned int count) = 0;

    /*
    @brief Draw currently bound indexed arrays.
    Will assume the draw mode to be triangles.
    TODO: implement line mode
    */
    virtual void DrawElements(unsigned int count) = 0;

    /*
    @brief Create a API instance.
    Dont forget to set the API type using SetAPI!
    */
    static Scope<GraphicsAPI> Create();

    /*
    @brief Set the static api type.
    This MUST be called before Create or Init!
    */
    static void SetAPI(const GraphicsAPIType& api);

    /*
    @brief Get the static api type.
    */
    static GraphicsAPIType GetAPI();
};

#endif