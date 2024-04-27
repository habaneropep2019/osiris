sources = [
    'main.cpp',
    'dirview.cpp',
]

dirview_moc_file = custom_target('example_dirview_mocfile_0',
    depends : [ moc_exe ],
    input : 'dirview.h',
    output : 'moc_dirview.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += dirview_moc_file

executable('dirview',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/dirview',
            link_with : [default_osirislib],
)