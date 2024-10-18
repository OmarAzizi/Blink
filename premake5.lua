workspace "Blink"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "Blink"
		location "Blink"
		kind "SharedLib"
		language "C++"
	
		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
		pchheader "blinkpch.h"
		pchsource "Blink/src/blinkpch.cpp"

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
				"BLINK_PLATFORM_WINDOWS",
				"BLINK_BUILD_DLL"
			}
	
		filter "configurations:Debug"
			defines "BLINK_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "BLINK_RELEASE"
			optimize "On"
	
	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
	
		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
		files {
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
	
		includedirs {
			"Blink/vendor/spdlog/include",
			"Blink/src"
		}
	
		links {
			"Blink"
		}
	
		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"
	
			defines {
				"BLINK_PLATFORM_WINDOWS"
			}
	
			postbuildcommands {
				("{COPYFILE} ../bin/" .. outputdir .. "/Blink/Blink.dll ../bin/" .. outputdir .. "/Sandbox/")
			}
	
		filter "configurations:Debug"
			defines "BLINK_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "BLINK_RELEASE"
			optimize "On"