sources = [
    'tagreader.cpp',
    'structureparser.cpp',
]

include_paths = [
    '.',
    '../../../include',
]

executable('tagreader',
            sources,
            include_directories : include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/xml/tagreader-with-features',
            link_with : [default_osirislib],
)

install_data('fnord.xml',
             install_dir : examples_install_dir + '/xml/tagreader-with-features',
             install_tag : 'bin-example',
)