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
            install : false,
            link_with : [osirislib],
)