sources = [ 
    'main.cpp',
]

executable('t3',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-tutorial',
            install_dir : tutorial_install_dir + '/t3',
            link_with : [default_osirislib],
)