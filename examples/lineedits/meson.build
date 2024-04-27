sources = [
    'main.cpp',
    'lineedits.cpp',
]

lineedits_moc_file = custom_target('example_lineedits_mocfile_0',
    depends : [ moc_exe ],
    input : 'lineedits.h',
    output : 'moc_lineedits.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += lineedits_moc_file

executable('lineedits',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/lineedits',
            link_with : [default_osirislib],
)