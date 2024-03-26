sources = [
    'main.cpp',
    'xform.cpp',
    'moc_xform.cpp',
]

run_command(moc_exe, 'xform.h', '-o', 'moc_xform.cpp', check : true)

executable('xform',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)