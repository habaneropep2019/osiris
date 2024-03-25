sources = [
    'main.cpp',
    'application.cpp',
    'moc_application.cpp',
]

run_command(moc_exe, 'application.h', '-o', 'moc_application.cpp', check : true)

executable('mdi',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)