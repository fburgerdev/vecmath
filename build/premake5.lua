-- premake5.lua
ROOT = ".."
-- workspace
workspace "math"
   configurations { "debug", "fast", "dist" }
-- library
project "math"
   -- staticlib
   kind "StaticLib"
   -- cpp
   language "C++"
   cppdialect "C++20"
   -- file
   files { 
      ROOT .. "/src/**.hpp",
      ROOT .. "/src/**.cpp",
      ROOT .. "/vendor/**.hpp",
      ROOT .. "/vendor/**.cpp",
   }
   includedirs {
      ROOT .. "/src",
      ROOT .. "/vendor",
   }
   -- library
   links {}
   -- binary
   objdir(ROOT .. "/bin/obj")
   -- debug
   debugger "GDB"
   -- config
   filter "configurations:debug"
      symbols "On"
      targetdir(ROOT .. "/lib/debug")
   filter "configurations:fast"
      optimize "On"
      linkoptions{ "-Ofast" }
      targetdir(ROOT .. "/lib/fast")
   filter "configurations:dist"
      optimize "On"
      linkoptions { "-static", "-Ofast" }
      targetdir(ROOT .. "/lib/dist")
-- test
project "test"
   -- console
   kind "ConsoleApp"
   -- cpp
   language "C++"
   cppdialect "C++20"
   -- files
   files {
      ROOT .. "/test/**.hpp",
      ROOT .. "/test/**.cpp",
   }
   includedirs {
      ROOT .. "/src",
      ROOT .. "/vendor",
      ROOT .. "/test",
   }
   -- library
   links {}
   -- binary
   objdir(ROOT .. "/bin/obj")
   -- debug
   debugger "GDB"
   -- config
   filter "configurations:debug"
      symbols "On"
      targetdir(ROOT .. "/bin/debug")
   filter "configurations:fast"
      optimize "On"
      targetdir(ROOT .. "/bin/fast")
      linkoptions{ "-Ofast" }
   filter "configurations:dist"
      optimize "On"
      linkoptions { "-static", "-Ofast" }
      targetdir(ROOT .. "/bin/dist")