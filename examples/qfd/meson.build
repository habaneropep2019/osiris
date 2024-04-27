sources = [
    'main.cpp',
    'fontdisplayer.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_qfd_mocfile_0',
    depends : [ moc_exe ],
    input : 'fontdisplayer.h',
    output : 'moc_fontdisplayer.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('qfd',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/qfd',
            link_with : [default_osirislib],
)