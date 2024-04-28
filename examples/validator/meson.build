sources = [
    'main.cpp',
    'motor.cpp',
    'vw.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_validator_mocfile_0',
    depends : [ moc_exe ],
    input : 'motor.h',
    output : 'moc_motor.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_validator_mocfile_1',
    depends : [ moc_exe ],
    input : 'vw.h',
    output : 'moc_vw.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('validator',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/validator',
            link_with : [default_osirislib],
)