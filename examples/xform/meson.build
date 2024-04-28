sources = [
    'main.cpp',
    'xform.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_xform_mocfile_0',
    depends : [ moc_exe ],
    input : 'xform.h',
    output : 'moc_xform.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('xform',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/xform',
            link_with : [default_osirislib],
)

install_data('image.any', 'picture.any',
             install_dir : examples_install_dir + '/xform',
             install_tag : 'bin-example',
)