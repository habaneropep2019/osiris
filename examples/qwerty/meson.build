sources = [
    'main.cpp',
    'qwerty.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_qwerty_mocfile_0',
    depends : [ moc_exe ],
    input : 'qwerty.h',
    output : 'moc_qwerty.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('qwerty',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/qwerty',
            link_with : [default_osirislib],
)

file_list = [
    'ANSI_X3.110-1983.map',
    'ANSI_X3.110-1983.txt',
    'eucJP.txt',
    'IBM277.map',
    'IBM277.txt',
    'koi8.txt',
    'latin1.txt',
    'msunicode.txt',
    'unicode.txt',
]

install_data(file_list,
             install_dir : examples_install_dir + '/qwerty',
             install_tag : 'bin-example',
)