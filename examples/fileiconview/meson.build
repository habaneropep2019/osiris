sources = [
    'main.cpp',
    'mainwindow.cpp',
    'qfileiconview.cpp',
    '../dirview/dirview.cpp',
]

include_paths = [
    std_include_paths,
    '../dirview',
]

generated_moc_files = [dirview_moc_file]

generated_moc_files += custom_target('example_fileiconview_mocfile_0',
    depends : [ moc_exe ],
    input : 'mainwindow.h',
    output : 'moc_mainwindow.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_fileiconview_mocfile_1',
    depends : [ moc_exe ],
    input : 'qfileiconview.h',
    output : 'moc_qfileiconview.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('fileiconview',
            sources,
            include_directories : include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/fileiconview',
            link_with : [default_osirislib],
)