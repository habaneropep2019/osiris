sources = [ 
    'main.cpp',
    'lcdrange.cpp',
    'moc_lcdrange.cpp',
]

run_command(moc_exe, 'lcdrange.h', '-o', 'moc_lcdrange.cpp', check : true)

executable('t7',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)