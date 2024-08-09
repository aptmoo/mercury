workspace "mercury"
    architecture "x86_64"   -- TODO: Implement multiarch builds

    configurations
    {
        "Debug",
        "Release",
    }

group "Dependencies"
    include "buildGLFW.lua"
group ""

group "CoreEngine"  
    include "buildShared.lua"
    include "buildclientApp.lua"
    include "buildGame.lua"
    include "buildSandbox.lua"
group ""

group "Tools"
group ""