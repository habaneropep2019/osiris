
sources = [ 
    'main.cpp',
    'aclock.cpp',
    'moc_aclock.cpp',
]

run_command(moc_exe, 'aclock.h', '-o', 'moc_aclock.cpp', check : true)

executable('aclock',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)