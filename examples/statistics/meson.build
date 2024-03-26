sources = [
    'main.cpp',
    'statistics.cpp',
    'moc_statistics.cpp',
]

run_command(moc_exe, 'statistics.h', '-o', 'moc_statistics.cpp', check : true)

executable('statistics',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)