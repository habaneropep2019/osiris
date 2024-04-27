sources = [
    'tagreader.cpp',
    'structureparser.cpp',
]

include_paths = [
    '.',
    '../../../src/dialogs',
    '../../../src/iconview',
    '../../../src/kernel',
    '../../../src/network',
    '../../../src/opengl',
    '../../../src/table',
    '../../../src/tools',
    '../../../src/widgets',
    '../../../src/workspace',
    '../../../src/xml',
]

executable('tagreader',
            sources,
            include_directories : include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/xml/tagreader',
            link_with : [default_osirislib],
)

install_data('animals.xml',
             install_dir : examples_install_dir + '/xml/tagreader',
             install_tag : 'bin-example',
)