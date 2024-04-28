sources = [ 
    'main.cpp',
    'lcdrange.cpp',
]

generated_moc_file = custom_target('tutorial_7_mocfile',
    depends : [ moc_exe ],
    input : 'lcdrange.h',
    output : 'moc_lcdrange.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_file

executable('t7',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-tutorial',
            install_dir : tutorial_install_dir + '/t7',
            link_with : [default_osirislib],
)