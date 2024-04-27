sources = [
    'main.cpp',
    'progressbar.cpp',
]

progressbar_moc_file = custom_target('example_progressbar_mocfile_0',
    depends : [ moc_exe ],
    input : 'progressbar.h',
    output : 'moc_progressbar.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += progressbar_moc_file

executable('progressbar',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/progressbar',
            link_with : [default_osirislib],
)