
project "Society"
	kind "StaticLib"
  language "C++"
	cppdialect "C++17"
	staticruntime "off"


	targetdir("%{wks.location}/_bin/" .. outputdir .. "/%{prj.name}")
	objdir("%{wks.location}/_obj/" .. outputdir .. "/%{prj.name}")

	pchheader "scpch.h"
	pchsource "src/scpch.cpp"

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src",
		"vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

	filter "system:macosx"
		buildoptions { "-std=c++11" } 
		disablewarnings {"deprecated-declarations"}

	filter "configurations:Debug"
		defines "SC_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "SC_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SC_DIST"
		optimize "On"

	-- postbuildcommands {
	-- 	("{COPYDIR} %{cfg.buildtarget.relpath} ../_bin/" .. outputdir .. "/Sandbox")
  -- }
