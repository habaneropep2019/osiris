sources = [
    'main.cpp',
    'mywidget.cpp',
]

generated_moc_files = []

generated_moc_files += custom_target('example_i18n_mocfile_0',
    depends : [ moc_exe ],
    input : 'mywidget.h',
    output : 'moc_mywidget.cpp',
    command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
    build_by_default : true)

sources += generated_moc_files

executable('i18n',
            sources,
            include_directories : std_include_paths,
            cpp_args : std_cpp_args,
            install : true,
            install_tag : 'bin-example',
            install_dir : examples_install_dir + '/i18n',
            link_with : [default_osirislib],
)

file_list = [
    'mywidget_cs.po',
    'mywidget_cs.qm',
    'mywidget_de.po',
    'mywidget_de.qm',
    'mywidget_el.po',
    'mywidget_el.qm',
    'mywidget_en.qm',
    'mywidget_eo.po',
    'mywidget_eo.qm',
    'mywidget_fr.po',
    'mywidget_fr.qm',
    'mywidget_it.po',
    'mywidget_it.qm',
    'mywidget_jp.po',
    'mywidget_jp.qm',
    'mywidget_ko.po',
    'mywidget_ko.qm',
    'mywidget_no.po',
    'mywidget_no.qm',
    'mywidget_ru.po',
    'mywidget_ru.qm',
    'mywidget_zh.po',
    'mywidget_zh.qm',
    'mywidget.po',
]

install_data(file_list,
             install_dir : examples_install_dir + '/i18n',
             install_tag : 'bin-example',
)