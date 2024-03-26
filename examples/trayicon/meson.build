sources = [
    'main.cpp',
    'trayicon.cpp',
    'moc_trayicon.cpp',
]

run_command(moc_exe, 'trayicon.h', '-o', 'moc_trayicon.cpp', check : true)

executable('trayicon',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)