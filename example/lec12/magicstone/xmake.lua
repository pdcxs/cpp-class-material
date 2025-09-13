add_rules("mode.debug", "mode.release")
if is_plat("widows") then
    set_plat("mingw")
end

target("magicstone")
    set_kind("binary")
    add_files("src/*.cpp")
