add_rules("mode.debug", "mode.release")

add_requires("lua 5.4")

set_languages("c++23")

target("ilua")
    set_kind("shared")
    add_files("src/**.mpp", { public = true })
    --add_files("src/function/*.mpp")
    --add_files("src/lua/*.mpp")
    add_packages("lua")

target("hello")
    set_kind("binary")
    add_files("examples/main.cpp")
    add_deps("ilua")
    add_packages("lua")
