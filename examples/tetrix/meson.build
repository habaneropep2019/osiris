sources = [
    'main.cpp',
    'gtetrix.cpp',
    'qdragapp.cpp',
    'moc_qdragapp.cpp',
    'qtetrix.cpp',
    'moc_qtetrix.cpp',
    'qtetrixb.cpp',
    'moc_qtetrixb.cpp',
    'tpiece.cpp',
]

run_command(moc_exe, 'qdragapp.h', '-o', 'moc_qdragapp.cpp', check : true)
run_command(moc_exe, 'qtetrix.h', '-o', 'moc_qtetrix.cpp', check : true)
run_command(moc_exe, 'qtetrixb.h', '-o', 'moc_qtetrixb.cpp', check : true)

executable('tetrix',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)