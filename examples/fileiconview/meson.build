sources = [
    'main.cpp',
    'mainwindow.cpp',
    'moc_mainwindow.cpp',
    'qfileiconview.cpp',
    'moc_qfileiconview.cpp',
    '../dirview/dirview.cpp',
    '../dirview/moc_dirview.cpp',
]

include_paths = [
    '.',
    '../dirview',
    '../../../include',
]

run_command(moc_exe, 'mainwindow.h', '-o', 'moc_mainwindow.cpp', check : true)
run_command(moc_exe, 'qfileiconview.h', '-o', 'moc_qfileiconview.cpp', check : true)

executable('fileiconview',
            sources,
            include_directories : include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)