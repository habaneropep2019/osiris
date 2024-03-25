sources = [
    'main.cpp',
    'qwerty.cpp',
    'moc_qwerty.cpp',
]

run_command(moc_exe, 'qwerty.h', '-o', 'moc_qwerty.cpp', check : true)

executable('qwerty',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)