sources = [
    'main.cpp',
    'http.cpp',
    'moc_http.cpp',
    'nntp.cpp',
    'moc_nntp.cpp',
    'view.cpp',
    'moc_view.cpp',
]

run_command(moc_exe, 'http.h', '-o', 'moc_http.cpp', check : true)
run_command(moc_exe, 'nntp.h', '-o', 'moc_nntp.cpp', check : true)
run_command(moc_exe, 'view.h', '-o', 'moc_view.cpp', check : true)

executable('networkprotocol',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)