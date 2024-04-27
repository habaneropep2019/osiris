sources = [
    'main.cpp',
    'widgets.cpp',
    '../aclock/aclock.cpp',
    '../dclock/dclock.cpp',
]

generated_moc_files = [aclock_moc_file, dclock_moc_file]

generated_moc_files += custom_target('example_widgets_mocfile_0',
    depends : [ moc_exe ],
    input : 'widgets.h',
    output : 'moc_widgets.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('widgets',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/widgets',
            link_with : [default_osirislib],
)

file_list = [
    'qt.bmp',
    'qt.png',
    'trolltech.bmp',
    'trolltech.gif',
    'tt-logo.png',
]

install_data(file_list,
             install_dir : examples_install_dir + '/widgets',
             install_tag : 'bin-example',
)