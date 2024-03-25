sources = [
    'main.cpp',
    'helpwindow.cpp',
    'moc_helpwindow.cpp',
]

run_command(moc_exe, 'helpwindow.h', '-o', 'moc_helpwindow.cpp', check : true)

executable('helpviewer',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)