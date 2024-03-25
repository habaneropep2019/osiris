sources = [
    'main.cpp',
    'scribble.cpp',
    'moc_scribble.cpp',
]

run_command(moc_exe, 'scribble.h', '-o', 'moc_scribble.cpp', check : true)

executable('scribble',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)