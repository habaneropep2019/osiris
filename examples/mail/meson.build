sources = [
    'main.cpp',
    'composer.cpp',
    'smtp.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_mail_mocfile_0',
    depends : [ moc_exe ],
    input : 'composer.h',
    output : 'moc_composer.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_mail_mocfile_1',
    depends : [ moc_exe ],
    input : 'smtp.h',
    output : 'moc_smtp.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('mail',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/mail',
            link_with : [default_osirislib],
)