sources = [
    'main.cpp',
    'wizard.cpp',
    'moc_wizard.cpp',
]

run_command(moc_exe, 'wizard.h', '-o', 'moc_wizard.cpp', check : true)

executable('wizard',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)