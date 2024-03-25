sources = [
    'main.cpp',
    'life.cpp',
    'moc_life.cpp',
    'lifedlg.cpp',
    'moc_lifedlg.cpp',
]

run_command(moc_exe, 'life.h', '-o', 'moc_life.cpp', check : true)
run_command(moc_exe, 'lifedlg.h', '-o', 'moc_lifedlg.cpp', check : true)

executable('life',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)