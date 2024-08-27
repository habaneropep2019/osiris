sources = [
    'main.cpp',
    'metal.cpp',
    'themes.cpp',
    'wood.cpp',
    '../buttongroups/buttongroups.cpp',
    '../lineedits/lineedits.cpp',
    '../listboxcombo/listboxcombo.cpp',
    '../checklists/checklists.cpp',
    '../progressbar/progressbar.cpp',
    '../rangecontrols/rangecontrols.cpp',
    '../richtext/richtext.cpp',
]

generated_moc_files = [
    buttongroup_moc_file,
    lineedits_moc_file,
    listboxcombo_moc_file,
    checklists_moc_file,
    progressbar_moc_file,
    rangecontrols_moc_file,
    richtext_moc_file,
]

generated_moc_files += custom_target('example_themes_mocfile_0',
    depends : [ moc_exe ],
    input : 'themes.h',
    output : 'moc_themes.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('themes',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/themes',
            link_with : [default_osirislib],
)

file_list = [
    'fileopen.xpm',
    'marble.xpm',
    'metal.xpm',
    'qt.bmp',
    'osirislogo.png',
    'stone1.xpm',
    'stonebright.xpm',
    'stonedark.xpm',
    'trolltech.gif',
]

install_data(file_list,
             install_dir : examples_install_dir + '/themes',
             install_tag : 'bin-example',
)