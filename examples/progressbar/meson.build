sources = [
    'main.cpp',
    'progressbar.cpp',
    'moc_progressbar.cpp',
]

run_command(moc_exe, 'progressbar.h', '-o', 'moc_progressbar.cpp', check : true)

executable('progressbar',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)