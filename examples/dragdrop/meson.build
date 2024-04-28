sources = [
    'main.cpp',
    'dropsite.cpp',
    'secret.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_dragdrop_mocfile_0',
    depends : [ moc_exe ],
    input : 'dropsite.h',
    output : 'moc_dropsite.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('dragdrop',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/dragdrop',
            link_with : [default_osirislib],
)

install_data('trolltech.bmp', 'trolltech.gif',
             install_dir : examples_install_dir + '/dragdrop',
             install_tag : 'bin-example',
)