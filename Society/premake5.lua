
project "Society"
    -- Set the project settings
	kind "SharedLib"
    language "C++"
	cppdialect "C++17"
	staticruntime "off"
	buildoptions { "-std=c++11" } 

    -- Set the output directory for the compiled binary
	targetdir("%{wks.location}/_bin/" .. outputdir .. "/%{prj.name}")
	objdir("%{wks.location}/_obj/" .. outputdir .. "/%{prj.name}")

    -- Set the precompiled header
	pchheader "scpch.h"
	pchsource "src/scpch.cpp"

    -- Add the source files
	files {
		"src/**.h",
		"src/**.cpp"
	}

    -- Add the include directories
	includedirs {
		"src",
		"vendor/spdlog/include"
	}

    -- Filter for MacOS
	filter {"system:macosx"}
		disablewarnings {"deprecated-declarations"}


    -- Filter for the different configurations
	filter "configurations:Debug"
		defines "SC_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "SC_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SC_DIST"
		optimize "On"

    -- Post build commands
	postbuildcommands {
		("{COPYDIR} %{cfg.buildtarget.relpath} ../_bin/" .. outputdir .. "/Sandbox")
	}