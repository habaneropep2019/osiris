sources = [
    'main.cpp',
    'tictac.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_tictac_mocfile_0',
    depends : [ moc_exe ],
    input : 'tictac.h',
    output : 'moc_tictac.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('tictac',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/tictac',
            link_with : [default_osirislib],
)