sources = [
    'main.cpp',
    'listbox.cpp',
    'moc_listbox.cpp',
]

run_command(moc_exe, 'listbox.h', '-o', 'moc_listbox.cpp', check : true)

executable('listbox',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)