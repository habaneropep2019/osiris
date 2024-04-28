sources = [
    'main.cpp',
    'gtetrix.cpp',
    'qdragapp.cpp',
    'qtetrix.cpp',
    'qtetrixb.cpp',
    'tpiece.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_textrix_mocfile_0',
    depends : [ moc_exe ],
    input : 'qdragapp.h',
    output : 'moc_qdragapp.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_textrix_mocfile_1',
    depends : [ moc_exe ],
    input : 'qtetrix.h',
    output : 'moc_qtetrix.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_textrix_mocfile_2',
    depends : [ moc_exe ],
    input : 'qtetrixb.h',
    output : 'moc_qtetrixb.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('tetrix',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/tetrix',
            link_with : [default_osirislib],
)