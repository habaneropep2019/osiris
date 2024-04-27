sources = [
    'forever.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_forever_mocfile_0',
    depends : [ moc_exe ],
    input : 'forever.h',
    output : 'moc_forever.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('forever',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/forever',
            link_with : [default_osirislib],
)