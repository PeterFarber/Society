workspace "Society"
	architecture "x64"
	configurations { 
		"Debug", 
		"Release", 
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Society"
	location "Society"
	kind "SharedLib"
	language "C++"
	buildoptions { "-std=c++11" } 

	targetdir("_bin/" .. outputdir .. "/%{prj.name}")
	objdir("_obj/" .. outputdir .. "/%{prj.name}")

	pchheader "scpch.h"
	pchsource "Society/src/scpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SC_PLATFORM_WINDOWS",
			"SC_BUILD_DLL"
		}

	filter {"system:macosx"}
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

	
	postbuildcommands {
		("{COPYDIR} %{cfg.buildtarget.relpath} ../_bin/" .. outputdir .. "/Sandbox")
	}


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	buildoptions { "-std=c++11" } 

	targetdir("_bin/" .. outputdir .. "/%{prj.name}")
	objdir("_obj/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Society/vendor/spdlog/include",
		"Society/src"
	}

	links {
		"Society"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SC_PLATFORM_WINDOWS"
		}

	filter {"system:macosx"}
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

--[[	
	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

		


	include {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SC_PLATFORM_WINDOWS",
			"SC_BUILD_DLL"
		}

		postbuildcommands {
			("{COPYDIR} %{cfg.buildtarget.relpath} ../_bin/" .. outputdir .. "/Sandbox")
		}

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		SC_PLATFORM_WINDOWS;SC_BUILD_DLL;*/
--]]