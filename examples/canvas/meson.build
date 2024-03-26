sources = [ 
    'main.cpp',
    'canvas.cpp',
    'moc_canvas.cpp',
]

run_command(moc_exe, 'canvas.h', '-o', 'moc_canvas.cpp', check : true)

executable('canvas',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)