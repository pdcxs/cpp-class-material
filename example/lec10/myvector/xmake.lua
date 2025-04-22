add_rules("mode.debug", "mode.release")
set_plat("mingw")

target("myvector")
    set_kind("binary")
    add_files("src/*.cpp")

