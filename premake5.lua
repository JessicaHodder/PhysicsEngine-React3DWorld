projectName = "React3DWork"

workspace "React3DWork"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}"

group "IMAT2912"

project "React3DWork"
	location "%{prj.name}"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/")
	objdir ("build/")
	debugdir "%{prj.name}"
	
		files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp",
		"vendor/stb_image/stb_image.cpp"
	}

	includedirs
	{
		"%{prj.name}/include",
		"vendor/renderer/include",
		"vendor/reactphysics3d/include",
		"vendor/glm/",
		"vendor/spdlog/include",
		"vendor/glfw/include",
		"vendor/Glad/include",
		"vendor/stb_image"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		
	libdirs 
	{
		"./vendor/renderer/lib/Debug"
	}
		
	links 
	{
		"Renderer",
		"ReactPhysics3d",
		"GLFW",
		"Glad"
	}
	

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		
	includedirs
	{
		"%{prj.name}/include",
		"vendor/renderer/include",
		"vendor/reactphysics3d/include",
		"vendor/glm/",
		"vendor/spdlog/include",
		"vendor/glfw/include",
		"vendor/Glad/include",
		"vendor/stb_image"
	}
	
	libdirs 
	{
		"./vendor/renderer/lib/Release"
	}

	links 
	{
		"Renderer",
		"ReactPhysics3d",
		"GLFW",
		"Glad"
	}
	
group "Vendor"
	include "vendor/glfw"
	include "vendor/Glad"
	include "vendor/reactphysics3d"

		
			-- Clean Function --
newaction {
   trigger     = "clean",
   description = "clean the build",
   execute     = function ()
      os.rmdir("./build")
	  os.rmdir("./bin")
	  os.remove(projectName .. "/" .. projectName .. ".vcxproj")
	  os.remove(projectName .. "/" .. projectName .. ".vcxproj.user")
	  os.remove(projectName .. "/" .. projectName .. ".vcxproj.filters")
	  os.remove("*.sln")
   end
}