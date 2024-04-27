sources = [
    'main.cpp',
]

executable('guithreads',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/guithreads',
            link_with : [osirislib_mt],
)