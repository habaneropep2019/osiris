sources = [
    'main.cpp',
    'cpu_waster.cpp',
    'progress.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_progress_mocfile_0',
    depends : [ moc_exe ],
    input : 'cpu_waster.h',
    output : 'moc_cpu_waster.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('progress',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/progress',
            link_with : [default_osirislib],
)