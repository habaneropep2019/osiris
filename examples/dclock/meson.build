sources = [
    'main.cpp',
    'dclock.cpp',
]

dclock_moc_file = custom_target('example_dclock_mocfile_0',
    depends : [ moc_exe ],
    input : 'dclock.h',
    output : 'moc_dclock.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += dclock_moc_file

executable('dclock',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/dclock',
            link_with : [default_osirislib],
)