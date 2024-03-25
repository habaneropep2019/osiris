sources = [
    'main.cpp',
    'fontdisplayer.cpp',
    'moc_fontdisplayer.cpp',
]

run_command(moc_exe, 'fontdisplayer.h', '-o', 'moc_fontdisplayer.cpp', check : true)

executable('qfd',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)