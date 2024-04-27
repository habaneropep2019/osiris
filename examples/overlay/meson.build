sources = [
    'main.cpp',
    'globjwin.cpp',
    'glteapots.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_overlay_mocfile_0',
    depends : [ moc_exe ],
    input : 'globjwin.h',
    output : 'moc_globjwin.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_overlay_mocfile_1',
    depends : [ moc_exe ],
    input : 'glteapots.h',
    output : 'moc_glteapots.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('overlay',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            dependencies : [gl_dep, glu_dep],
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/overlay',
            link_with : [default_osirislib],
)