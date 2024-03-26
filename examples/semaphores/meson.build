sources = [
    'main.cpp',
]

run_command(moc_exe, 'main.cpp', '-o', 'moc_main.cpp', check : true)

executable('semaphore',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib_mt],
)