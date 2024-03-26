sources = [ 
    'main.cpp',
    'centralwidget.cpp',
    'moc_centralwidget.cpp',
    'mainwindow.cpp',
    'moc_mainwindow.cpp',
]

run_command(moc_exe, 'centralwidget.h', '-o', 'moc_centralwidget.cpp', check : true)
run_command(moc_exe, 'mainwindow.h', '-o', 'moc_mainwindow.cpp', check : true)

executable('addressbook',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)