project "gameDLL"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    targetname "basegame"
    targetdir "../bin/%{prj.targetname}"
    objdir "../bin-int/"

    files
    {
        "../src/gamedll/**.h",
        "../src/gamedll/**.cpp",
    }

    includedirs
    {
        "../src/",
        "../src/shared/",
        "../src/gamedll/"
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