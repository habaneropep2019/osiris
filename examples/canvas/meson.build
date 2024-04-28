sources = [ 
    'main.cpp',
    'canvas.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_canvas_mocfile_0',
    depends : [ moc_exe ],
    input : 'canvas.h',
    output : 'moc_canvas.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('canvas',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/canvas',
            link_with : [default_osirislib],
)

install_data('qt-trans.xpm', 'qtlogo.png', 'butterfly.png',
             install_dir : examples_install_dir + '/canvas',
             install_tag : 'bin-example',
)