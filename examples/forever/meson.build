sources = [
    'forever.cpp',
    'moc_forever.cpp',
]

run_command(moc_exe, 'forever.h', '-o', 'moc_forever.cpp', check : true)

executable('forever',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)