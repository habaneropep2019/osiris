sources = [
    'main.cpp',
    'gearwidget.cpp',
    'rubberbandwidget.cpp',
]

executable('overlayx11',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            dependencies : [x11_dep, gl_dep],
            link_with : [osirislib],
)