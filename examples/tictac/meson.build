sources = [
    'main.cpp',
    'tictac.cpp',
    'moc_tictac.cpp',
]

run_command(moc_exe, 'tictac.h', '-o', 'moc_tictac.cpp', check : true)

executable('tictac',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)