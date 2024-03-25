sources = [ 
    'main.cpp',
    'buttongroups.cpp',
    'moc_buttongroups.cpp',
]

run_command(moc_exe, 'buttongroups.h', '-o', 'moc_buttongroups.cpp', check : true)

executable('buttongroups',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)