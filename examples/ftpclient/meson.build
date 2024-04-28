sources = [
    'main.cpp',
    'ftpmainwindow.cpp',
    'ftpview.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_ftpclient_mocfile_0',
    depends : [ moc_exe ],
    input : 'ftpmainwindow.h',
    output : 'moc_ftpmainwindow.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_ftpclient_mocfile_1',
    depends : [ moc_exe ],
    input : 'ftpview.h',
    output : 'moc_ftpview.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('ftpclient',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/ftpclient',
            link_with : [default_osirislib],
)