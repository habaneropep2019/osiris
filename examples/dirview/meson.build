sources = [
    'main.cpp',
    'dirview.cpp',
    'moc_dirview.cpp',
]

run_command(moc_exe, 'dirview.h', '-o', 'moc_dirview.cpp', check : true)

executable('dirview',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)