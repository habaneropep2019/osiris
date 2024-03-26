sources = [
    'main.cpp',
    'globjwin.cpp',
    'moc_globjwin.cpp',
    'glteapots.cpp',
    'moc_glteapots.cpp',
]

run_command(moc_exe, 'globjwin.h', '-o', 'moc_globjwin.cpp', check : true)
run_command(moc_exe, 'glteapots.h', '-o', 'moc_glteapots.cpp', check : true)

executable('overlay',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            dependencies : [gl_dep, glu_dep],
            install : false,
            link_with : [default_osirislib],
)