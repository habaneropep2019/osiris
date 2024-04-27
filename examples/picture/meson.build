sources = [
    'main.cpp',
    'picture.cpp',
]

executable('picture',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/picture',
            link_with : [default_osirislib],
)

install_data('car_orig.pic', 'flag.bmp',
             install_dir : examples_install_dir + '/picture',
             install_tag : 'bin-example',
)