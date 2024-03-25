sources = [
    'main.cpp',
    'listviews.cpp',
    'moc_listviews.cpp',
]

run_command(moc_exe, 'listviews.h', '-o', 'moc_listviews.cpp', check : true)

executable('listviews',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)