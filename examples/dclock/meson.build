sources = [
    'main.cpp',
    'dclock.cpp',
    'moc_dclock.cpp',
]

run_command(moc_exe, 'dclock.h', '-o', 'moc_dclock.cpp', check : true)

executable('dclock',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)