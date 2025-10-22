add_rules("mode.debug", "mode.release")
if is_plat("widows") then
    set_plat("mingw")
end

target("josephus1")
    set_kind("binary")
    add_files("src/*.cpp")
    set_languages("c++17")

