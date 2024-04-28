workspace "mercury"
    architecture "x86_64"   -- TODO: Implement multiarch builds

    configurations
    {
        "Debug",
        "Release",
    }

group "CoreEngine"  
    include "buildShared.lua"
group ""

group "Tools"
group ""