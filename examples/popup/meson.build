sources = [
    'main.cpp',
    'popup.cpp',
    'moc_popup.cpp',
]

run_command(moc_exe, 'popup.h', '-o', 'moc_popup.cpp', check : true)

executable('popup',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)