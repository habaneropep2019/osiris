sources = [
    'main.cpp',
    'globjwin.cpp',
    'gltexobj.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_texture_mocfile_0',
    depends : [ moc_exe ],
    input : 'globjwin.h',
    output : 'moc_globjwin.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_texture_mocfile_1',
    depends : [ moc_exe ],
    input : 'gltexobj.h',
    output : 'moc_gltexobj.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('texture',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            dependencies : [gl_dep, glu_dep],
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/texture',
            link_with : [default_osirislib],
)

install_data('gllogo.bmp', 'qtlogo.bmp',
             install_dir : examples_install_dir + '/texture',
             install_tag : 'bin-example',
)