sources = [
    'main.cpp',
    'httpd.cpp',
    'moc_httpd.cpp',
    'httpinfo.cpp',
    'moc_httpinfo.cpp',
]

run_command(moc_exe, 'httpd.h', '-o', 'moc_httpd.cpp', check : true)
run_command(moc_exe, 'httpinfo.h', '-o', 'moc_httpinfo.cpp', check : true)

executable('httpd',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)