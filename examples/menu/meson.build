sources = [
    'main.cpp',
    'menu.cpp',
    'moc_menu.cpp',
]

run_command(moc_exe, 'menu.h', '-o', 'moc_menu.cpp', check : true)

executable('menu',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)