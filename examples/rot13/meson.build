sources = [
    'main.cpp',
    'rot13.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_rot13_mocfile_0',
    depends : [ moc_exe ],
    input : 'rot13.h',
    output : 'moc_rot13.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('rot13',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/rot13',
            link_with : [default_osirislib],
)