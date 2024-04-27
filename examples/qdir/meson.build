sources = [
    'main.cpp',
    'qdir.cpp',
    '../dirview/dirview.cpp',
]

generated_moc_files = [dirview_moc_file]

generated_moc_files += custom_target('example_qdir_mocfile_0',
    depends : [ moc_exe ],
    input : 'qdir.h',
    output : 'moc_qdir.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('qdir',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/qdir',
            link_with : [default_osirislib],
)