project "clientApp"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    -- TODO: Game name in buildgen?
    targetname "game"
    targetdir "../bin/"
    objdir "../bin-int/"

    files
    {
        "../src/clientApp/**.h",
        "../src/clientApp/**.cpp",
    }

    includedirs
    {
        "../src/",
        "../src/clientApp/"
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