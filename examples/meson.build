std_include_paths = [
    '../../src/compat',
    '../../src/canvas',
    '../../src/dialogs',
    '../../src/iconview',
    '../../src/kernel',
    '../../src/network',
    '../../src/opengl',
    '../../src/table',
    '../../src/tools',
    '../../src/widgets',
    '../../src/workspace',
    '../../src/xml',
    '.',
]

std_cpp_args = []

thread_support = get_option('multi-thread').enabled()

if thread_support
    std_cpp_args += '-DQT_THREAD_SUPPORT'
endif

examples_install_dir = meson.source_root() + '/bin/examples'

#
# These are placeholders for moc file targets
# They are shared among more than one example
#
dirview_moc_file = ''
aclock_moc_file = ''
dclock_moc_file = ''
buttongroup_moc_file = ''
lineedits_moc_file = ''
listboxcombo_moc_file = ''
checklists_moc_file = ''
progressbar_moc_file = ''
rangecontrols_moc_file = ''
richtext_moc_file = ''

subdir('aclock')
subdir('action')
subdir('addressbook')
subdir('application')
subdir('biff')
subdir('box')
subdir('buttongroups')
subdir('canvas')
subdir('checklists')
subdir('cursor')
subdir('customlayout')
subdir('dclock')
subdir('desktop')
subdir('dirview')
subdir('dragdrop')
subdir('drawdemo')
subdir('drawlines')
subdir('fileiconview')
subdir('forever')
subdir('ftpclient')
subdir('gear')
subdir('glpixmap')
if thread_support
    subdir('guithreads')
endif
subdir('hello')
subdir('helpviewer')
subdir('httpd')
subdir('i18n')
subdir('iconview')
subdir('layout')
subdir('life')
subdir('lineedits')
subdir('listbox')
subdir('listboxcombo')
subdir('listviews')
subdir('mail')
subdir('mdi')
subdir('menu')
subdir('movies')
subdir('networkprotocol')
subdir('overlay')
subdir('overlay_x11')
subdir('picture')
subdir('popup')
subdir('progress')
subdir('progressbar')
subdir('qdir')
subdir('qfd')
subdir('qmag')
subdir('qwerty')
subdir('rangecontrols')
subdir('richtext')
subdir('rot13')
subdir('scribble')
subdir('scrollview')
if thread_support
    subdir('semaphores')
endif
subdir('sharedbox')
subdir('showimg')
subdir('sound')
subdir('splitter')
subdir('statistics')
subdir('tabdialog')
subdir('table')
subdir('tetrix')
subdir('texture')
subdir('themes')
subdir('tictac')
subdir('tooltip')
#
# Not built. `sysRemove` needs to be implemented
#
# subdir('trayicon')
subdir('validator')
subdir('widgets')
subdir('wizard')
subdir('xform')
subdir('xml')
subdir('xmlquotes')