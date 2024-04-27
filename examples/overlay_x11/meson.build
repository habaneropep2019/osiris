sources = [
    'main.cpp',
    'gearwidget.cpp',
    'rubberbandwidget.cpp',
]

executable('overlayx11',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/overlay_x11',
            dependencies : [x11_dep, gl_dep],
            link_with : [default_osirislib],
)

install_subdir('utilities',
             install_dir : examples_install_dir + '/overlay_x11',
             install_tag : 'bin-example',
)