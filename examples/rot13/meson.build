sources = [
    'main.cpp',
    'rot13.cpp',
    'moc_rot13.cpp',
]

run_command(moc_exe, 'rot13.h', '-o', 'moc_rot13.cpp', check : true)

executable('rot13',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)