add_rules("mode.debug", "mode.release")
set_plat("mingw")
add_requires("raylib")

target("particle")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("raylib")
