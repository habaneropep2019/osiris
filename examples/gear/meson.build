sources = [
    'gear.cpp',
]

executable('gear',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            dependencies : [gl_dep],
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/gear',
            link_with : [default_osirislib],
)