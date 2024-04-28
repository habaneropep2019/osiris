sources = [ 
    'main.cpp',
    'cannon.cpp',
    'lcdrange.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('tutorial_9_mocfile_0',
    depends : [ moc_exe ],
    input : 'lcdrange.h',
    output : 'moc_lcdrange.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('tutorial_9_mocfile_1',
    depends : [ moc_exe ],
    input : 'cannon.h',
    output : 'moc_cannon.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('t9',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-tutorial',
            install_dir : tutorial_install_dir + '/t9',
            link_with : [default_osirislib],
)