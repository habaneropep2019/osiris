sources = [
    'main.cpp',
    'ftpmainwindow.cpp',
    'moc_ftpmainwindow.cpp',
    'ftpview.cpp',
    'moc_ftpview.cpp',
]

run_command(moc_exe, 'ftpmainwindow.h', '-o', 'moc_ftpmainwindow.cpp', check : true)
run_command(moc_exe, 'ftpview.h', '-o', 'moc_ftpview.cpp', check : true)

executable('ftpclient',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)