sources = [
    'main.cpp',
    'hello.cpp',
    'moc_hello.cpp',
]

run_command(moc_exe, 'hello.h', '-o', 'moc_hello.cpp', check : true)

executable('hello',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)