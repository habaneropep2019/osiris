sources = [
    'sound.cpp',
    'moc_sound.cpp',
]

run_command(moc_exe, 'sound.h', '-o', 'moc_sound.cpp', check : true)

executable('sound',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)