sources = [
    'main.cpp',
    'mywidget.cpp',
    'moc_mywidget.cpp',
]

run_command(moc_exe, 'mywidget.h', '-o', 'moc_mywidget.cpp', check : true)

executable('i18n',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)