// TODO: Remove platform dependent stuff
#include <GLFW/glfw3.h>
#include "glad/gl.h"

#include "gfx/api.h"
#include "gfx/context.h"

#include "util/instrumentor.h"

#include <iostream>

void message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar const *message, void const *user_param)
{
    auto const src_str = [source]()
    {
        switch (source)
        {
        case GL_DEBUG_SOURCE_API:
            return "API";
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
            return "WINDOW SYSTEM";
        case GL_DEBUG_SOURCE_SHADER_COMPILER:
            return "SHADER COMPILER";
        case GL_DEBUG_SOURCE_THIRD_PARTY:
            return "THIRD PARTY";
        case GL_DEBUG_SOURCE_APPLICATION:
            return "APPLICATION";
        case GL_DEBUG_SOURCE_OTHER:
            return "OTHER";
        }
    }();

    auto const type_str = [type]()
    {
        switch (type)
        {
        case GL_DEBUG_TYPE_ERROR:
            return "ERROR";
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
            return "DEPRECATED_BEHAVIOR";
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
            return "UNDEFINED_BEHAVIOR";
        case GL_DEBUG_TYPE_PORTABILITY:
            return "PORTABILITY";
        case GL_DEBUG_TYPE_PERFORMANCE:
            return "PERFORMANCE";
        case GL_DEBUG_TYPE_MARKER:
            return "MARKER";
        case GL_DEBUG_TYPE_OTHER:
            return "OTHER";
        }
    }();

    auto const severity_str = [severity]()
    {
        switch (severity)
        {
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            return "NOTIFICATION";
        case GL_DEBUG_SEVERITY_LOW:
            return "LOW";
        case GL_DEBUG_SEVERITY_MEDIUM:
            return "MEDIUM";
        case GL_DEBUG_SEVERITY_HIGH:
            return "HIGH";
        }
    }();
    std::cout << src_str << ", " << type_str << ", " << severity_str << ", " << id << ": " << message << '\n';
}

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec2 aPos;\n"
                                 "out vec3 ourColor;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos, 1.0, 1.0);\n"
                                 "   ourColor = vec3(aPos, 0.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "in vec3 ourColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(ourColor, 1.0f);\n"
                                   "}\n\0";

int main(int argc, char const *argv[])
{
    HG_PROFILE_START("Hi", "Bye");
    glfwInit();

    // you know the drill
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Title", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    GraphicsAPI::SetAPI(GraphicsAPIType::OPENGL);
    Scope<Context> context = Context::Create(window);
    Scope<GraphicsAPI> api = GraphicsAPI::Create();

    context->Init();
    api->Init();

    api->SetClearColor(0.2f, 0.6f, 0.8f, 1.0f);

    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(message_callback, nullptr);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::printf("Vertex shader compilation failed:\n%s\n", infoLog);
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::printf("Fragment shader compilation failed:\n%s\n", infoLog);
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::printf("Shader program compilation failed:\n%s\n", infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glUseProgram(shaderProgram);

    // Triangle data
    float vertices[8] = 
    {
        -0.5f, -0.5f, // 0
        0.5f, -0.5f,  // 1
        0.5f, 0.5f,   // 2
        -0.5f, 0.5f   // 3
    };

    unsigned int indices[6] = 
    {
        0, 1, 2,
        2, 3, 0
    };

    void* voidvertices = (void*)vertices;

    // Opengl stuff.
    // TODO: You know what to do
    unsigned int va, vb, eb;
    glCreateVertexArrays(1, &va);
    glCreateBuffers(1, &vb);
    glCreateBuffers(1, &eb);

    glNamedBufferData(vb, 8 * sizeof(&voidvertices), voidvertices, GL_STATIC_DRAW);
    glNamedBufferData(eb, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    glEnableVertexArrayAttrib(va, 0);
    glVertexArrayAttribBinding(va, 0, 0);
    glVertexArrayAttribFormat(va, 0, 2, GL_FLOAT, GL_FALSE, 0);

    glVertexArrayVertexBuffer(va, 0, vb, 0, 2 * sizeof(float));
    glVertexArrayElementBuffer(va, eb);

    glBindVertexArray(va);

    while (!glfwWindowShouldClose(window))
    {
        api->Clear();
        api->DrawElements(6);
        context->Swap();
        glfwPollEvents();
    }
    

    context->Shutdown();

    glfwTerminate();
    HG_PROFILE_END();
    return 0;
}
