workspace "mercury"
   configurations { "Debug", "Release" }

project "engine"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/"

   includedirs {"src/engine/", "src/platform/", "include/", "src/ext/"}

   filter { "system:linux", "action:gmake" }
      buildoptions { "--std=gnu++17 -Winvalid-pch" }
      libdirs {"lib/", "/usr/lib/"}


   links { "glfw", "GL", "dl", "pthread" }

   defines { "GLFW_INCLUDE_NONE" }

   files { "src/engine/**.cpp", "src/engine/*.c", "src/platform/**.cpp", "src/platform/*.c", "src/ext/**.cpp", "src/ext/**.c" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"