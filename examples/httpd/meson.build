sources = [
    'main.cpp',
    'httpd.cpp',
    'httpinfo.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_httpd_mocfile_0',
    depends : [ moc_exe ],
    input : 'httpd.h',
    output : 'moc_httpd.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_httpd_mocfile_1',
    depends : [ moc_exe ],
    input : 'httpinfo.h',
    output : 'moc_httpinfo.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('httpd',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/httpd',
            link_with : [default_osirislib],
)