sources = [
    'main.cpp',
    'helpwindow.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_helpviewer_mocfile_0',
    depends : [ moc_exe ],
    input : 'helpwindow.h',
    output : 'moc_helpwindow.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('helpviewer',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/helpviewer',
            link_with : [default_osirislib],
)

install_data('back.xpm', 'forward.xpm', 'home.xpm',
             install_dir : examples_install_dir + '/helpviewer',
             install_tag : 'bin-example',
)