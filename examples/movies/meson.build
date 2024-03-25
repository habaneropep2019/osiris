sources = [
    'main.cpp',
    'movie_screen.cpp',
    'moc_movie_screen.cpp',
    'movie_starter.cpp',
    'moc_movie_starter.cpp',
]

run_command(moc_exe, 'movie_screen.h', '-o', 'moc_movie_screen.cpp', check : true)
run_command(moc_exe, 'movie_starter.h', '-o', 'moc_movie_starter.cpp', check : true)

executable('movies',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)