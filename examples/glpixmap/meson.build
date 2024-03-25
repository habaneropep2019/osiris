sources = [
    'main.cpp',
    'glbox.cpp',
    'moc_glbox.cpp',
    'globjwin.cpp',
    'moc_globjwin.cpp',
]

run_command(moc_exe, 'glbox.h', '-o', 'moc_glbox.cpp', check : true)
run_command(moc_exe, 'globjwin.h', '-o', 'moc_globjwin.cpp', check : true)

executable('glixmap',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            dependencies : [gl_dep],
            install : false,
            link_with : [osirislib],
)