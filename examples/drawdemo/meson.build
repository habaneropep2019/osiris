sources = [
    'drawdemo.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_drawdemo_mocfile_0',
    depends : [ moc_exe ],
    input : 'drawdemo.h',
    output : 'moc_drawdemo.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('drawdemo',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/drawdemo',
            link_with : [default_osirislib],
)