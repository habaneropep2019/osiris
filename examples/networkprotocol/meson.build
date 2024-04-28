sources = [
    'main.cpp',
    'http.cpp',
    'nntp.cpp',
    'view.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_networkprotocol_mocfile_0',
    depends : [ moc_exe ],
    input : 'http.h',
    output : 'moc_http.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_networkprotocol_mocfile_1',
    depends : [ moc_exe ],
    input : 'nntp.h',
    output : 'moc_nntp.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_networkprotocol_mocfile_2',
    depends : [ moc_exe ],
    input : 'view.h',
    output : 'moc_view.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('networkprotocol',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/neteworkprotocol',
            link_with : [default_osirislib],
)