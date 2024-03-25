sources = [
    'main.cpp',
    'rangecontrols.cpp',
    'moc_rangecontrols.cpp',
]

run_command(moc_exe, 'rangecontrols.h', '-o', 'moc_rangecontrols.cpp', check : true)

executable('rangecontrols',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)