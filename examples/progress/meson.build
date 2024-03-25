sources = [
    'main.cpp',
    'cpu_waster.cpp',
    'moc_cpu_waster.cpp',
    'progress.cpp',
]

run_command(moc_exe, 'cpu_waster.h', '-o', 'moc_cpu_waster.cpp', check : true)

executable('progress',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)