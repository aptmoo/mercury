workspace "mercury"
    architecture "x86_64"   -- TODO: Implement multiarch builds

    configurations
    {
        "Debug",
        "Release",
    }

group "CoreEngine"  
    include "buildShared.lua"
    include "buildclientApp.lua"
    include "buildGame.lua"
group ""

group "Tools"
group ""