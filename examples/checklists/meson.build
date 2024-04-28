sources = [ 
    'main.cpp',
    'checklists.cpp',
]

checklists_moc_file = custom_target('example_checklists_mocfile_0',
    depends : [ moc_exe ],
    input : 'checklists.h',
    output : 'moc_checklists.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += checklists_moc_file

executable('checklists',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/checklists',
            link_with : [default_osirislib],
)