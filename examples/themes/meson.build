sources = [
    'main.cpp',
    'metal.cpp',
    'themes.cpp',
    'moc_themes.cpp',
    'wood.cpp',
    '../buttongroups/buttongroups.cpp',
    '../buttongroups/moc_buttongroups.cpp',
    '../lineedits/lineedits.cpp',
    '../lineedits/moc_lineedits.cpp',
    '../listboxcombo/listboxcombo.cpp',
    '../listboxcombo/moc_listboxcombo.cpp',
    '../checklists/checklists.cpp',
    '../checklists/moc_checklists.cpp',
    '../progressbar/progressbar.cpp',
    '../progressbar/moc_progressbar.cpp',
    '../rangecontrols/rangecontrols.cpp',
    '../rangecontrols/moc_rangecontrols.cpp',
    '../richtext/richtext.cpp',
    '../richtext/moc_richtext.cpp',
]

run_command(moc_exe, 'themes.h', '-o', 'moc_themes.cpp', check : true)

executable('themes',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : false,
            link_with : [default_osirislib],
)