sources = [
    'sound.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_sound_mocfile_0',
    depends : [ moc_exe ],
    input : 'sound.h',
    output : 'moc_sound.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('sound',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/sound',
            link_with : [default_osirislib],
)