project "sandboxDLL"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    targetname "sandbox"
    targetdir "../bin/%{prj.targetname}"
    objdir "../bin-int/"

    files
    {
        "../src/sandbox/**.h",
        "../src/sandbox/**.cpp",
    }

    includedirs
    {
        "../src/",
        "../src/sandbox/"
    }

    libdirs
    {
        "../lib/"
    }

    links
    {
        "shared"
    }

    filter "system:linux"
        defines { "SYSTEM_LINUX" }
        links { "dl", "m" }
        libdirs { "/lib/", "/usr/lib" }
    
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
  
     filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"