sources = [
    'main.cpp',
    'widgets.cpp',
    'moc_widgets.cpp',
    '../aclock/aclock.cpp',
    '../aclock/moc_aclock.cpp',
    '../dclock/dclock.cpp',
    '../dclock/moc_dclock.cpp',
]

run_command(moc_exe, 'widgets.h', '-o', 'moc_widgets.cpp', check : true)

executable('widgets',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)