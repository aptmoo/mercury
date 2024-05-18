project "client"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    targetname "game"
    targetdir "../bin/"
    objdir "../bin-int/"

    files
    {
        "../src/client/**.h",
        "../src/client/**.cpp",
    }

    includedirs
    {
        "../src/",
        "../src/client/"
    }

    libdirs
    {
        "../lib/"
    }

    links
    {

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