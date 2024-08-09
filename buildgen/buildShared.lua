project "shared"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    targetdir "../lib/"
    objdir "../bin-int/"

    files
    {
        "../src/shared/**.h",
        "../src/shared/**.cpp",

        "../src/sharedPlatform/null/**.h",
        "../src/sharedPlatform/null/**.cpp"
    }

    includedirs
    {
        "../src/shared/",
        "../src/sharedPlatform/",
        "../ext/",
    }

    libdirs
    {
        "../lib/"
    }

    filter "system:linux"
        defines { "SYSTEM_LINUX" }
        libdirs { "/lib/", "/usr/lib" }
        links { "GLFW", "dl", "m", "pthread" }
        files { "../src/sharedPlatform/linux/**.h", "../src/sharedPlatform/linux/**.cpp",}
    
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
  
     filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"