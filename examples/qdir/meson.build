sources = [
    'main.cpp',
    'qdir.cpp',
    'moc_qdir.cpp',
    '../dirview/dirview.cpp',
    '../dirview/moc_dirview.cpp',
]

run_command(moc_exe, 'qdir.h', '-o', 'moc_qdir.cpp', check : true)

executable('qdir',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)