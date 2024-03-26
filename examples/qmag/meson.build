sources = [
    'main.cpp',
    'qmag.cpp',
    'moc_qmag.cpp',
]

run_command(moc_exe, 'qmag.h', '-o', 'moc_qmag.cpp', check : true)

executable('qmag',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)