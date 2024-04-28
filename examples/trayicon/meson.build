sources = [
    'main.cpp',
    'trayicon.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_trayicon_mocfile_0',
    depends : [ moc_exe ],
    input : 'trayicon.h',
    output : 'moc_trayicon.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('trayicon',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/trayicon',
            link_with : [default_osirislib],
)