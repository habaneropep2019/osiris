sources = [ 
    'main.cpp',
    'centralwidget.cpp',
    'mainwindow.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_addressbook_mocfile_0',
    depends : [ moc_exe ],
    input : 'centralwidget.h',
    output : 'moc_centralwidget.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_addressbook_mocfile_1',
    depends : [ moc_exe ],
    input : 'mainwindow.h',
    output : 'moc_mainwindow.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('addressbook',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/addressbook',
            link_with : [default_osirislib],
)

install_data('fileopen.xpm', 'fileprint.xpm', 'filesave.xpm',
             install_dir : examples_install_dir + '/addressbook',
             install_tag : 'bin-example',
)