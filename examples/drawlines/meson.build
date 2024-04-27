sources = [
    'connect.cpp',
]

executable('connect',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/drawlines',
            link_with : [default_osirislib],
)