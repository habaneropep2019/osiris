sources = [
    'main.cpp',
    'scrollview.cpp',
    'moc_scrollview.cpp',
]

run_command(moc_exe, 'scrollview.h', '-o', 'moc_scrollview.cpp', check : true)

executable('scrollview',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)