sources = [
    'main.cpp',
    'wizard.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_wizard_mocfile_0',
    depends : [ moc_exe ],
    input : 'wizard.h',
    output : 'moc_wizard.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('wizard',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/wizard',
            link_with : [default_osirislib],
)