sources = [
    'main.cpp',
    'composer.cpp',
    'moc_composer.cpp',
    'smtp.cpp',
    'moc_smtp.cpp',
]

run_command(moc_exe, 'composer.h', '-o', 'moc_composer.cpp', check : true)
run_command(moc_exe, 'smtp.h', '-o', 'moc_smtp.cpp', check : true)

executable('mail',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)