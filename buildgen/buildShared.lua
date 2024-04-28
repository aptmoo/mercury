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
    }

    includedirs
    {
        "../src/shared/"
    }

    libdirs
    {
        "../lib/"
    }

    filter "system:linux"
        defines { "SYSTEM_LINUX" }
        libdirs { "/lib/", "/usr/lib" }
    
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
  
     filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"