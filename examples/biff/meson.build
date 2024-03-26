sources = [ 
    'main.cpp',
    'biff.cpp',
    'moc_biff.cpp',
    'bmp.cpp',
]

run_command(moc_exe, 'biff.h', '-o', 'moc_biff.cpp', check : true)

executable('biff',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)