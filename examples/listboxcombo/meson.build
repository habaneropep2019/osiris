sources = [
    'main.cpp',
    'listboxcombo.cpp',
]

listboxcombo_moc_file = custom_target('example_listboxcombo_mocfile_0',
    depends : [ moc_exe ],
    input : 'listboxcombo.h',
    output : 'moc_listboxcombo.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += listboxcombo_moc_file

executable('listboxcombo',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/listboxcombo',
            link_with : [default_osirislib],
)

install_data('fileopen.xpm', 'osirislogo.png',
             install_dir : examples_install_dir + '/listboxcombo',
             install_tag : 'bin-example',
)