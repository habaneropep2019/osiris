sources = [
    'main.cpp',
    'splitter.cpp',
]

executable('splitter',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/splitter',
            link_with : [default_osirislib],
)