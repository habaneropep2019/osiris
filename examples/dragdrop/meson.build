sources = [
    'main.cpp',
    'dropsite.cpp',
    'moc_dropsite.cpp',
    'secret.cpp',
]

run_command(moc_exe, 'dropsite.h', '-o', 'moc_dropsite.cpp', check : true)

executable('dragdrop',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)