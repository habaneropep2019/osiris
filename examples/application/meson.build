sources = [ 
    'main.cpp',
    'application.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_application_mocfile_0',
    depends : [ moc_exe ],
    input : 'application.h',
    output : 'moc_application.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('application',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/application',
            link_with : [default_osirislib],
)

install_data('fileopen.xpm', 'fileprint.xpm', 'filesave.xpm',
             install_dir : examples_install_dir + '/application',
             install_tag : 'bin-example',
)