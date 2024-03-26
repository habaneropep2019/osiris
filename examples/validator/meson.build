sources = [
    'main.cpp',
    'motor.cpp',
    'moc_motor.cpp',
    'vw.cpp',
    'moc_vw.cpp',
]

run_command(moc_exe, 'motor.h', '-o', 'moc_motor.cpp', check : true)
run_command(moc_exe, 'vw.h', '-o', 'moc_vw.cpp', check : true)

executable('validator',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)