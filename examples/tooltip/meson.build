sources = [
    'main.cpp',
    'tooltip.cpp',
    'moc_tooltip.cpp',
]

run_command(moc_exe, 'tooltip.h', '-o', 'moc_tooltip.cpp', check : true)

executable('tooltip',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)