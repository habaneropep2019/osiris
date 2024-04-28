sources = [
    'main.cpp',
    'movie_screen.cpp',
    'movie_starter.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_movies_mocfile_0',
    depends : [ moc_exe ],
    input : 'movie_screen.h',
    output : 'moc_movie_screen.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

generated_moc_files += custom_target('example_movies_mocfile_1',
    depends : [ moc_exe ],
    input : 'movie_starter.h',
    output : 'moc_movie_starter.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('movies',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/movies',
            link_with : [default_osirislib],
)

install_data('trolltech.gif',
             install_dir : examples_install_dir + '/movies',
             install_tag : 'bin-example',
)