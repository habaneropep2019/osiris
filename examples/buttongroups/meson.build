sources = [ 
    'main.cpp',
    'buttongroups.cpp',
]

buttongroup_moc_file = custom_target('example_buttongroups_mocfile_0',
    depends : [ moc_exe ],
    input : 'buttongroups.h',
    output : 'moc_buttongroups.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += buttongroup_moc_file

executable('buttongroups',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/buttongroups',
            link_with : [default_osirislib],
)