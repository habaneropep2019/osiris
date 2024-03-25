sources = [
    'main.cpp',
    'globjwin.cpp',
    'moc_globjwin.cpp',
    'gltexobj.cpp',
    'moc_gltexobj.cpp',
]

run_command(moc_exe, 'globjwin.h', '-o', 'moc_globjwin.cpp', check : true)
run_command(moc_exe, 'gltexobj.h', '-o', 'moc_gltexobj.cpp', check : true)

executable('texture',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            dependencies : [gl_dep, glu_dep],
            install : false,
            link_with : [osirislib],
)