sources = [
    'main.cpp',
    'listboxcombo.cpp',
    'moc_listboxcombo.cpp',
]

run_command(moc_exe, 'listboxcombo.h', '-o', 'moc_listboxcombo.cpp', check : true)

executable('listboxcombo',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)