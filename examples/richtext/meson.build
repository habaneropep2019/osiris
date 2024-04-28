sources = [
    'main.cpp',
    'richtext.cpp',
]

richtext_moc_file = custom_target('example_richtext_mocfile_0',
    depends : [ moc_exe ],
    input : 'richtext.h',
    output : 'moc_richtext.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += richtext_moc_file

executable('richtext',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/richtext',
            link_with : [default_osirislib],
)

install_data('marble.png',
             install_dir : examples_install_dir + '/richtext',
             install_tag : 'bin-example',
)