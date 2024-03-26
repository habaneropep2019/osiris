sources = [ 
    'main.cpp',
    'cannon.cpp',
    'moc_cannon.cpp',
    'lcdrange.cpp',
    'moc_lcdrange.cpp',
]

run_command(moc_exe, 'lcdrange.h', '-o', 'moc_lcdrange.cpp', check : true)
run_command(moc_exe, 'cannon.h', '-o', 'moc_cannon.cpp', check : true)

executable('t9',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)