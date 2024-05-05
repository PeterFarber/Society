

project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"
	buildoptions { "-std=c++11" } 

	targetdir("%{wks.location}/_bin/" .. outputdir .. "/%{prj.name}")
	objdir("%{wks.location}/_obj/" .. outputdir .. "/%{prj.name}")


	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"%{wks.location}/Society/vendor/spdlog/include",
		"%{wks.location}/Society/src"
	}

	links {
		"Society"
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