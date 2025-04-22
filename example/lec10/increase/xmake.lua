add_rules("mode.debug", "mode.release")
set_plat("mingw")

target("increase")
    set_kind("binary")
    add_files("src/*.cpp")

