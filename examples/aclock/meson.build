
sources = [ 
    'main.cpp',
    'aclock.cpp',
]

aclock_moc_file = custom_target('example_aclock_mocfile_0',
    depends : [ moc_exe ],
    input : 'aclock.h',
    output : 'moc_aclock.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += aclock_moc_file

executable('aclock',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/aclock',
            link_with : [default_osirislib],
)
