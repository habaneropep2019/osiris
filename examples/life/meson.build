sources = [
    'main.cpp',
    'life.cpp',
    'lifedlg.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_life_mocfile_0',
    depends : [ moc_exe ],
    input : 'life.h',
    output : 'moc_life.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_life_mocfile_1',
    depends : [ moc_exe ],
    input : 'lifedlg.h',
    output : 'moc_lifedlg.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('life',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/life',
            link_with : [default_osirislib],
)