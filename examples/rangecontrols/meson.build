sources = [
    'main.cpp',
    'rangecontrols.cpp',
]

rangecontrols_moc_file = custom_target('example_rangecontrols_mocfile_0',
    depends : [ moc_exe ],
    input : 'rangecontrols.h',
    output : 'moc_rangecontrols.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += rangecontrols_moc_file

executable('rangecontrols',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/rangecontrols',
            link_with : [default_osirislib],
)