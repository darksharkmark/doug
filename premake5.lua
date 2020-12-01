workspace "doug"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "doug"
	location "doug"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs 
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"DOUG_PLATFORM_WINDOWS",
		"DOUG_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "DOUG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DOUG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DOUG_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"doug/vendor/spdlog/include",
		"doug/src"
	}

	links
	{
		"doug"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"DOUG_PLATFORM_WINDOWS",
	}

	filter "configurations:Debug"
		defines "DOUG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DOUG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DOUG_DIST"
		optimize "On"