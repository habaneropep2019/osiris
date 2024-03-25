sources = [
    'main.cpp',
    'listendnd.cpp',
    'moc_listendnd.cpp',
]

run_command(moc_exe, 'listendnd.h', '-o', 'moc_listendnd.cpp', check : true)

executable('iconview',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)