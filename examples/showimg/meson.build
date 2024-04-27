sources = [
    'main.cpp',
    'imagefip.cpp',
    'imagetexteditor.cpp',
    'showimg.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_showimg_mocfile_0',
    depends : [ moc_exe ],
    input : 'imagefip.h',
    output : 'moc_imagefip.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_showimg_mocfile_1',
    depends : [ moc_exe ],
    input : 'imagetexteditor.h',
    output : 'moc_imagetexteditor.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_showimg_mocfile_2',
    depends : [ moc_exe ],
    input : 'showimg.h',
    output : 'moc_showimg.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('showimg',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/showing',
            link_with : [default_osirislib],
)