sources = [ 
    'cursor.cpp',
]

executable('cursor',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/cursor',
            link_with : [default_osirislib],
)