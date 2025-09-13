add_rules("mode.debug", "mode.release")
if is_plat("widows") then
    set_plat("mingw")
end
add_requires("raylib")

target("particle")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("raylib")
