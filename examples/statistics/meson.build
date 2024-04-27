sources = [
    'main.cpp',
    'statistics.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_statistics_mocfile_0',
    depends : [ moc_exe ],
    input : 'statistics.h',
    output : 'moc_statistics.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('statistics',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/statistics',
            link_with : [default_osirislib],
)