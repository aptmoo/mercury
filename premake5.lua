workspace "mercury"
   configurations { "Debug", "Release" }

project "mercuryengine"
   kind "StaticLib"
   language "C++"
   targetdir "lib/"


   includedirs {"./src/engine/", "./include/", "./src/ext/"}

   filter { "system:linux", "action:gmake" }
      buildoptions { "--std=gnu++17" }
      libdirs {"lib/", "/usr/lib/"}


   links { "m" }

   files { "src/engine/**.cpp", "src/engine/**.c", "src/ext/**.c", "src/ext/**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

project "server"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/"


   includedirs {"./src/engine/", "./include/", "./src/ext/"}

   filter { "system:linux", "action:gmake" }
      buildoptions { "--std=gnu++17 -Winvalid-pch" }
      libdirs {"lib/", "/usr/lib/"}


   links { "m", "mercuryengine" }

   files { "src/server/**.cpp", "src/server/*.c" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"