sources = [
    'main.cpp',
    'tabdialog.cpp',
    'moc_tabdialog.cpp',
]

run_command(moc_exe, 'tabdialog.h', '-o', 'moc_tabdialog.cpp', check : true)

executable('tabdialog',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)