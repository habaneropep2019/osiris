sources = [
    'main.cpp',
    'listendnd.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_iconview_mocfile_0',
    depends : [ moc_exe ],
    input : 'listendnd.h',
    output : 'moc_listendnd.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('iconview',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/iconview',
            link_with : [default_osirislib],
)