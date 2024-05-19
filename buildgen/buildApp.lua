project "app"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    targetname "game"
    targetdir "../bin/"
    objdir "../bin-int/"

    files
    {
        "../src/application/**.h",
        "../src/application/**.cpp",
    }

    includedirs
    {
        "../src/",
        "../src/application/"
    }

    libdirs
    {
        "../lib/"
    }

    links
    {
        "shared",
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