sources = [
    'main.cpp',
    'richtext.cpp',
    'moc_richtext.cpp',
]

run_command(moc_exe, 'richtext.h', '-o', 'moc_richtext.cpp', check : true)

executable('richtext',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)