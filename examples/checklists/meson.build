sources = [ 
    'main.cpp',
    'checklists.cpp',
    'moc_checklists.cpp',
]

run_command(moc_exe, 'checklists.h', '-o', 'moc_checklists.cpp', check : true)

executable('checklists',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)