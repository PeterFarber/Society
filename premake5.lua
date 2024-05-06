include "dependencies.lua"

workspace "Society"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
--[[
	flags
	{
		"MultiProcessorCompile"
	}
]]--

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	-- include "Hazel/vendor/GLFW"
	-- include "Hazel/vendor/Glad"
group ""

group "Core"
	include "Society"
group ""

group "Tools"
group ""

group "Misc"
	include "Sandbox"
group ""
