sources = [
    'drawdemo.cpp',
    'moc_drawdemo.cpp',
]

run_command(moc_exe, 'drawdemo.h', '-o', 'moc_drawdemo.cpp', check : true)

executable('drawdemo',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)