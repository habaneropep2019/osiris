sources = [
    'main.cpp',
    'imagefip.cpp',
    'moc_imagefip.cpp',
    'imagetexteditor.cpp',
    'moc_imagetexteditor.cpp',
    'showimg.cpp',
    'moc_showimg.cpp',
]

run_command(moc_exe, 'imagefip.h', '-o', 'moc_imagefip.cpp', check : true)
run_command(moc_exe, 'imagetexteditor.h', '-o', 'moc_imagetexteditor.cpp', check : true)
run_command(moc_exe, 'showimg.h', '-o', 'moc_showimg.cpp', check : true)

executable('showimg',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [osirislib],
)