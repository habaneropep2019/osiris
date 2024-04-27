sources = [
    'main.cpp',
    'scrollview.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_scrollview_mocfile_0',
    depends : [ moc_exe ],
    input : 'scrollview.h',
    output : 'moc_scrollview.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('scrollview',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/scrollview',
            link_with : [default_osirislib],
)

install_data('bg.ppm',
             install_dir : examples_install_dir + '/scrollview',
             install_tag : 'bin-example',
)