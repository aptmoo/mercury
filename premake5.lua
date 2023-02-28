workspace "mercury"
   configurations { "Debug", "Release" }

project "engine"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/"

   includedirs {"./src/engine/", "./include/", "./src/ext/"}

   filter { "system:linux", "action:gmake" }
      buildoptions { "--std=gnu++17 -Winvalid-pch" }
      libdirs {"lib/", "/usr/lib/"}


   links { "m", "glfw", "vulkan", "GL", "dl", "X11", "pthread", "Xxf86vm", "Xrandr", "Xi" }

   defines { "GLFW_INCLUDE_NONE" }

   files { "src/engine/**.cpp", "src/engine/*.c", "src/ext/**.cpp", "src/ext/**.c" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"