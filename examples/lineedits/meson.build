sources = [
    'main.cpp',
    'lineedits.cpp',
    'moc_lineedits.cpp',
]

run_command(moc_exe, 'lineedits.h', '-o', 'moc_lineedits.cpp', check : true)

executable('lineedits',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)