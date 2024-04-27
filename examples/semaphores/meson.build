sources = [
    'main.cpp',
    'semaphores.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_semaphores_mocfile_0',
    depends : [ moc_exe ],
    input : 'semaphores.h',
    output : 'moc_semaphores.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('semaphore',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/semaphores',
            link_with : [osirislib_mt],
)