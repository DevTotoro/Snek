SDL2 = "%{wks.location}/vendor/SDL2-2.26.5"

workspace "Snek"
	architecture "x86"
	configurations { "Debug", "Release" }

	targetdir "build/bin/%{cfg.buildcfg}"
	objdir "build/obj/%{cfg.buildcfg}"

project "Snek"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++latest"

	files { "src/**.h", "src/**.cpp" }

	includedirs { "src", "%{SDL2}/include" }

	libdirs "%{SDL2}/lib/x86"

	links { "SDL2.lib", "SDL2main.lib" }

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		defines "NDEBUG"
		optimize "On"
		