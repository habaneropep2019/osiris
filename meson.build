project('osiris', 'cpp',
        default_options : ['prefix=/opt/osiris', 'cpp_std=c++11'],
        license : 'GPL-2.0-only',
        license_files: ['LICENSE.GPL'],
        version : '2.4.2',
)

osiris_install_prefix = get_option('prefix')

project_defines = [
    '-DQT_NO_IMAGEIO_MNG',
    '-DQT_NO_SM_SUPPORT',
    '-DOSIRIS_INSTALL_PREFIX=' + osiris_install_prefix,
]

build_multithread = get_option('multi-thread').enabled()
build_singlethread = get_option('single-thread').enabled()

if not (build_multithread or build_singlethread)
    error('Both -Dmulti-thread and -Dsingle-thread disabled. Not building libosiris')
endif

if get_option('gif').enabled()
    project_defines += '-DQT_BUILTIN_GIF_READER=1'
endif

if get_option('jpeg').disabled()
    project_defines += '-DQT_NO_IMAGEIO_JPEG'
endif

if get_option('mng').disabled()
    project_defines += '-DQT_NO_IMAGEIO_MNG'
endif

if get_option('xft').enabled()
    project_defines += '-DQT_XFT'
else
    project_defines += '-DQT_NO_XKB'
endif

install_dir = get_option('prefix') / 'bin'
lib_install_dir = get_option('prefix') / 'lib'
include_install_dir = get_option('prefix') / 'include/osiris'

osiris_assets_install_dir = get_option('prefix') / 'share/osiris'
designer_assets_install_dir = get_option('prefix') / 'share/designer'

dialog_header_path = 'src/dialogs'
kernel_header_path = 'src/kernel'
network_header_path = 'src/network'
tools_header_path = 'src/tools'

tools_source_path = 'src/tools'
kernel_source_path = 'src/kernel'
widgets_source_path = 'src/widgets'
dialog_source_path = 'src/dialogs'
iconview_source_path = 'src/iconview'
workspaces_source_path = 'src/workspace'
network_source_path = 'src/network'
canvas_source_path = 'src/canvas'
table_source_path = 'src/table'
xml_source_path = 'src/xml'
opengl_source_path = 'src/opengl'

osiris_include_directories = [
    'src/canvas',
    'src/dialogs',
    'src/iconview',
    'src/kernel',
    'src/network',
    'src/opengl',
    'src/table',
    'src/tools',
    'src/widgets',
    'src/workspace',
    'src/xml',
]

#
# Build and install the moc tool
#

moc_source_path = 'src/moc'
moc_sources = [
    moc_source_path / 'mocgen.cpp',
    tools_source_path / 'qbuffer.cpp',
    tools_source_path / 'qcollection.cpp',
    tools_source_path / 'qcstring.cpp',
    tools_source_path / 'qdatastream.cpp',
    tools_source_path / 'qdatetime.cpp',
    tools_source_path / 'qfile.cpp',
    tools_source_path / 'qgarray.cpp',
    tools_source_path / 'qgdict.cpp',
    tools_source_path / 'qglist.cpp',
    tools_source_path / 'qglobal.cpp',
    tools_source_path / 'qgvector.cpp',
    tools_source_path / 'qiodevice.cpp',
    tools_source_path / 'qregexp.cpp',
    tools_source_path / 'qstring.cpp',
    tools_source_path / 'qtextcodec.cpp',
    tools_source_path / 'qtextstream.cpp',
    tools_source_path / 'qutfcodec.cpp',
    tools_source_path / 'qfile_unix.cpp'
]

moc_include_directories = [
    osiris_include_directories,
    moc_source_path,
    tools_header_path,
]

moc_compile_args = [
    '-Wno-unused',
    '-Wno-parentheses',
    '-w',
    '-DQT_NO_CODECS',
    '-DQT_LITE_UNICODE',
    '-std=c++11'
]

cc = meson.get_compiler('cpp')

m_dep = cc.find_library('m', required : true)
z_dep = cc.find_library('z', required : true)

moc_exe = executable('moc',
            moc_sources,
            dependencies : [z_dep],
            include_directories : moc_include_directories,
            cpp_args : moc_compile_args,
            install : true,
            install_dir : install_dir,
)

moc_header_file_roots = [
    [kernel_source_path, 'qabstractlayout'],
    [kernel_source_path, 'qaccel'],
    [kernel_source_path, 'qapplication'],
    [kernel_source_path, 'qasyncio'],
    [kernel_source_path, 'qclipboard'],
    [kernel_source_path, 'qdialog'],
    [kernel_source_path, 'qdragobject'],
    [kernel_source_path, 'qguardedptr'],
    [kernel_source_path, 'qlayout'],
    [kernel_source_path, 'qtranslator'],
    [kernel_source_path, 'qnetworkprotocol'],
    [kernel_source_path, 'qsemimodal'],
    [kernel_source_path, 'qsessionmanager'],
    [kernel_source_path, 'qsignalmapper'],
    [kernel_source_path, 'qsizegrip'],
    [kernel_source_path, 'qsocketnotifier'],
    [kernel_source_path, 'qsound'],
    [kernel_source_path, 'qstyle'],
    [kernel_source_path, 'qstylesheet'],
    [kernel_source_path, 'qtimer'],
    [kernel_source_path, 'qlocalfs'],
    [kernel_source_path, 'qurloperator'],
    [kernel_source_path, 'qwidget'],
    [widgets_source_path, 'qbuttongroup'],
    [widgets_source_path, 'qbutton'],
    [widgets_source_path, 'qcheckbox'],
    [widgets_source_path, 'qcdestyle'],
    [widgets_source_path, 'qcombobox'],
    [widgets_source_path, 'qcommonstyle'],
    [widgets_source_path, 'qdial'],
    [widgets_source_path, 'qframe'],
    [widgets_source_path, 'qgrid'],
    [widgets_source_path, 'qgroupbox'],
    [widgets_source_path, 'qhbuttongroup'],
    [widgets_source_path, 'qheader'],
    [widgets_source_path, 'qhgroupbox'],
    [widgets_source_path, 'qhbox'],
    [widgets_source_path, 'qlabel'],
    [widgets_source_path, 'qlcdnumber'],
    [widgets_source_path, 'qlineedit'],
    [widgets_source_path, 'qlistbox'],
    [widgets_source_path, 'qlistview'],
    [widgets_source_path, 'qmainwindow'],
    [widgets_source_path, 'qmenubar'],
    [widgets_source_path, 'qmotifstyle'],
    [widgets_source_path, 'qmotifplusstyle'],
    [widgets_source_path, 'qmultilineedit'],
    [widgets_source_path, 'qplatinumstyle'],
    [widgets_source_path, 'qpopupmenu'],
    [widgets_source_path, 'qprogressbar'],
    [widgets_source_path, 'qpushbutton'],
    [widgets_source_path, 'qradiobutton'],
    [widgets_source_path, 'qscrollbar'],
    [widgets_source_path, 'qscrollview'],
    [widgets_source_path, 'qsgistyle'],
    [widgets_source_path, 'qslider'],
    [widgets_source_path, 'qspinbox'],
    [widgets_source_path, 'qsplitter'],
    [widgets_source_path, 'qstatusbar'],
    [widgets_source_path, 'qtabbar'],
    [widgets_source_path, 'qtabwidget'],
    [widgets_source_path, 'qtableview'],
    [widgets_source_path, 'qtextbrowser'],
    [widgets_source_path, 'qtextview'],
    [widgets_source_path, 'qtoolbar'],
    [widgets_source_path, 'qtoolbutton'],
    [widgets_source_path, 'qtooltip'],
    [widgets_source_path, 'qvalidator'],
    [widgets_source_path, 'qvbox'],
    [widgets_source_path, 'qvbuttongroup'],
    [widgets_source_path, 'qvgroupbox'],
    [widgets_source_path, 'qwidgetstack'],
    [widgets_source_path, 'qwindowsstyle'],
    [widgets_source_path, 'qaction'],
    [dialog_source_path, 'qcolordialog'],
    [dialog_source_path, 'qfiledialog'],
    [dialog_source_path, 'qfontdialog'],
    [dialog_source_path, 'qmessagebox'],
    [dialog_source_path, 'qprogressdialog'],
    [dialog_source_path, 'qtabdialog'],
    [dialog_source_path, 'qwizard'],
    [dialog_source_path, 'qinputdialog'],
    [dialog_source_path, 'qprintdialog'],
    [iconview_source_path, 'qiconview'],
    [workspaces_source_path, 'qworkspace'],
    [network_source_path, 'qdns'],
    [network_source_path, 'qftp'],
    [network_source_path, 'qserversocket'],
    [network_source_path, 'qsocket'],
    [canvas_source_path, 'qcanvas'],
    [table_source_path, 'qtable'],
    [opengl_source_path, 'qgl'],
]

moc_generated_files = []

foreach root_tuple : moc_header_file_roots
    directory_path = root_tuple[0]
    filename_root = root_tuple[1]

    src_header_file = directory_path / (filename_root + '.h')

    target_name = root_tuple[1] + '_moc'
    moc_generated_files += custom_target(target_name,
          input : src_header_file,
          output : 'moc_' + filename_root + '.cpp',
          command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
          build_by_default : true)

endforeach

#
# Generate moc files from *.cpp. Some *.cpp files use Q_OBJECT, etc and
# need their implementation generated. The resulting .moc file is then
# included at the bottom of the source file
#
# Command: moc <filename>.cpp -o <filename.moc>
#
moc_source_file_roots = [
    [dialog_source_path, 'qcolordialog'],
    [dialog_source_path, 'qfiledialog'],
    [iconview_source_path, 'qiconview'],
    [kernel_source_path, 'qmovie'],
    [kernel_source_path, 'qthread_unix'],
    [opengl_source_path, 'qgl_x11'],
    [widgets_source_path, 'qeffects'],
    [widgets_source_path, 'qmainwindow'],
    [widgets_source_path, 'qtoolbar'],
    [widgets_source_path, 'qtooltip'],
    [widgets_source_path, 'qwhatsthis'],
    [workspaces_source_path, 'qworkspace'],
]

foreach root_tuple : moc_source_file_roots
    directory_path = root_tuple[0]
    filename_root = root_tuple[1]

    src_header_file = directory_path / (filename_root + '.cpp')

    target_name = root_tuple[1] + '_moc_cpp'
    moc_generated_files += custom_target(target_name,
          input : src_header_file,
          output : filename_root + '.moc',
          command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
          build_by_default : true)

endforeach

tools_sources = [
    tools_source_path / 'qdir_unix.cpp',
    tools_source_path / 'qfile_unix.cpp',
    tools_source_path / 'qfileinfo_unix.cpp',
    tools_source_path / 'qbig5codec.cpp',
    tools_source_path / 'qbitarray.cpp',
    tools_source_path / 'qbuffer.cpp',
    tools_source_path / 'qcollection.cpp',
    tools_source_path / 'qcstring.cpp',
    tools_source_path / 'qdatastream.cpp',
    tools_source_path / 'qdatetime.cpp',
    tools_source_path / 'qdir.cpp',
    tools_source_path / 'qeucjpcodec.cpp',
    tools_source_path / 'qeuckrcodec.cpp',
    tools_source_path / 'qfile.cpp',
    tools_source_path / 'qfileinfo.cpp',
    tools_source_path / 'qgarray.cpp',
    tools_source_path / 'qgbkcodec.cpp',
    tools_source_path / 'qgcache.cpp',
    tools_source_path / 'qgdict.cpp',
    tools_source_path / 'qglist.cpp',
    tools_source_path / 'qglobal.cpp',
    tools_source_path / 'qgvector.cpp',
    tools_source_path / 'qiodevice.cpp',
    tools_source_path / 'qjiscodec.cpp',
    tools_source_path / 'qjpunicode.cpp',
    tools_source_path / 'qmap.cpp',
    tools_source_path / 'qregexp.cpp',
    tools_source_path / 'qrtlcodec.cpp',
    tools_source_path / 'qsjiscodec.cpp',
    tools_source_path / 'qstring.cpp',
    tools_source_path / 'qstringlist.cpp',
    tools_source_path / 'qtextcodec.cpp',
    tools_source_path / 'qtextstream.cpp',
    tools_source_path / 'qtsciicodec.cpp',
    tools_source_path / 'qutfcodec.cpp'
]

kernel_sources = [
    kernel_source_path / 'qpsprinter.cpp',
    kernel_source_path / 'qthread_unix.cpp',
    kernel_source_path / 'qapplication_x11.cpp',
    kernel_source_path / 'qclipboard_x11.cpp',
    kernel_source_path / 'qcolor_x11.cpp',
    kernel_source_path / 'qcursor_x11.cpp',
    kernel_source_path / 'qdnd_x11.cpp',
    kernel_source_path / 'qmotifdnd_x11.cpp',
    kernel_source_path / 'qfont_x11.cpp',
    kernel_source_path / 'qpixmap_x11.cpp',
    kernel_source_path / 'qprinter_x11.cpp',
    kernel_source_path / 'qpaintdevice_x11.cpp',
    kernel_source_path / 'qpainter_x11.cpp',
    kernel_source_path / 'qregion_x11.cpp',
    kernel_source_path / 'qsound_x11.cpp',
    kernel_source_path / 'qwidget_x11.cpp',
    kernel_source_path / 'qwidgetcreate_x11.cpp',
    kernel_source_path / 'qabstractlayout.cpp',
    kernel_source_path / 'qaccel.cpp',
    kernel_source_path / 'qapplication.cpp',
    kernel_source_path / 'qasyncimageio.cpp',
    kernel_source_path / 'qasyncio.cpp',
    kernel_source_path / 'qbitmap.cpp',
    kernel_source_path / 'qclipboard.cpp',
    kernel_source_path / 'qcolor.cpp',
    kernel_source_path / 'qcolor_p.cpp',
    kernel_source_path / 'qconnection.cpp',
    kernel_source_path / 'qcursor.cpp',
    kernel_source_path / 'qdialog.cpp',
    kernel_source_path / 'qdragobject.cpp',
    kernel_source_path / 'qdrawutil.cpp',
    kernel_source_path / 'qdropsite.cpp',
    kernel_source_path / 'qevent.cpp',
    kernel_source_path / 'qfocusdata.cpp',
    kernel_source_path / 'qfont.cpp',
    kernel_source_path / 'qfontdatabase.cpp',
    kernel_source_path / 'qguardedptr.cpp',
    kernel_source_path / 'qiconset.cpp',
    kernel_source_path / 'qimage.cpp',
    kernel_source_path / 'qjpegio.cpp',
    kernel_source_path / 'qlayout.cpp',
    kernel_source_path / 'qlayoutengine.cpp',
    kernel_source_path / 'qtranslator.cpp',
    kernel_source_path / 'qmetaobject.cpp',
    kernel_source_path / 'qmime.cpp',
    kernel_source_path / 'qmngio.cpp',
    kernel_source_path / 'qmovie.cpp',
    kernel_source_path / 'qnetworkprotocol.cpp',
    kernel_source_path / 'qobject.cpp',
    kernel_source_path / 'qpainter.cpp',
    kernel_source_path / 'qpalette.cpp',
    kernel_source_path / 'qpaintdevicemetrics.cpp',
    kernel_source_path / 'qpicture.cpp',
    kernel_source_path / 'qpixmap.cpp',
    kernel_source_path / 'qpixmapcache.cpp',
    kernel_source_path / 'qpngio.cpp',
    kernel_source_path / 'qpointarray.cpp',
    kernel_source_path / 'qpoint.cpp',
    kernel_source_path / 'qpolygonscanner.cpp',
    kernel_source_path / 'qprinter.cpp',
    kernel_source_path / 'qrect.cpp',
    kernel_source_path / 'qregion.cpp',
    kernel_source_path / 'qrichtext.cpp',
    kernel_source_path / 'qsemimodal.cpp',
    kernel_source_path / 'qsignal.cpp',
    kernel_source_path / 'qsignalmapper.cpp',
    kernel_source_path / 'qsimplerichtext.cpp',
    kernel_source_path / 'qsize.cpp',
    kernel_source_path / 'qsizegrip.cpp',
    kernel_source_path / 'qstyle.cpp',
    kernel_source_path / 'qsocketnotifier.cpp',
    kernel_source_path / 'qsound.cpp',
    kernel_source_path / 'qstylesheet.cpp',
    kernel_source_path / 'qtimer.cpp',
    kernel_source_path / 'qurl.cpp',
    kernel_source_path / 'qlocalfs.cpp',
    kernel_source_path / 'qurloperator.cpp',
    kernel_source_path / 'qurlinfo.cpp',
    kernel_source_path / 'qwidget.cpp',
    kernel_source_path / 'qwmatrix.cpp',
    kernel_source_path / 'qvariant.cpp',
]

widgets_sources = [
    widgets_source_path / 'qbuttongroup.cpp',
    widgets_source_path / 'qbutton.cpp',
    widgets_source_path / 'qcdestyle.cpp',
    widgets_source_path / 'qcheckbox.cpp',
    widgets_source_path / 'qcombobox.cpp',
    widgets_source_path / 'qcommonstyle.cpp',
    widgets_source_path / 'qdial.cpp',
    widgets_source_path / 'qframe.cpp',
    widgets_source_path / 'qgrid.cpp',
    widgets_source_path / 'qgroupbox.cpp',
    widgets_source_path / 'qhbuttongroup.cpp',
    widgets_source_path / 'qheader.cpp',
    widgets_source_path / 'qhgroupbox.cpp',
    widgets_source_path / 'qhbox.cpp',
    widgets_source_path / 'qinterlacestyle.cpp',
    widgets_source_path / 'qlabel.cpp',
    widgets_source_path / 'qlcdnumber.cpp',
    widgets_source_path / 'qlineedit.cpp',
    widgets_source_path / 'qlistbox.cpp',
    widgets_source_path / 'qlistview.cpp',
    widgets_source_path / 'qmainwindow.cpp',
    widgets_source_path / 'qmenubar.cpp',
    widgets_source_path / 'qmenudata.cpp',
    widgets_source_path / 'qmotifstyle.cpp',
    widgets_source_path / 'qmotifplusstyle.cpp',
    widgets_source_path / 'qmultilineedit.cpp',
    widgets_source_path / 'qplatinumstyle.cpp',
    widgets_source_path / 'qpopupmenu.cpp',
    widgets_source_path / 'qprogressbar.cpp',
    widgets_source_path / 'qpushbutton.cpp',
    widgets_source_path / 'qradiobutton.cpp',
    widgets_source_path / 'qrangecontrol.cpp',
    widgets_source_path / 'qscrollbar.cpp',
    widgets_source_path / 'qscrollview.cpp',
    widgets_source_path / 'qsgistyle.cpp',
    widgets_source_path / 'qslider.cpp',
    widgets_source_path / 'qspinbox.cpp',
    widgets_source_path / 'qsplitter.cpp',
    widgets_source_path / 'qstatusbar.cpp',
    widgets_source_path / 'qtabbar.cpp',
    widgets_source_path / 'qtabwidget.cpp',
    widgets_source_path / 'qtableview.cpp',
    widgets_source_path / 'qtextbrowser.cpp',
    widgets_source_path / 'qtextview.cpp',
    widgets_source_path / 'qtoolbar.cpp',
    widgets_source_path / 'qtoolbutton.cpp',
    widgets_source_path / 'qtooltip.cpp',
    widgets_source_path / 'qvalidator.cpp',
    widgets_source_path / 'qvbox.cpp',
    widgets_source_path / 'qvbuttongroup.cpp',
    widgets_source_path / 'qvgroupbox.cpp',
    widgets_source_path / 'qwhatsthis.cpp',
    widgets_source_path / 'qwidgetstack.cpp',
    widgets_source_path / 'qwindowsstyle.cpp',
    widgets_source_path / 'qaction.cpp',
    widgets_source_path / 'qeffects.cpp',
]

dialogs_sources = [
    dialog_source_path / 'qprintdialog.cpp',
    dialog_source_path / 'qcolordialog.cpp',
    dialog_source_path / 'qfiledialog.cpp',
    dialog_source_path / 'qfontdialog.cpp',
    dialog_source_path / 'qmessagebox.cpp',
    dialog_source_path / 'qprogressdialog.cpp',
    dialog_source_path / 'qtabdialog.cpp',
    dialog_source_path / 'qwizard.cpp',
    dialog_source_path / 'qinputdialog.cpp',
]

iconview_sources = [
    iconview_source_path / 'qiconview.cpp',
]

workspace_sources = [ 
    workspaces_source_path / 'qworkspace.cpp',
]

network_sources = [
    network_source_path / 'qdns.cpp',
    network_source_path / 'qftp.cpp',
    network_source_path / 'qhostaddress.cpp',
    network_source_path / 'qnetwork.cpp',
    network_source_path / 'qserversocket.cpp',
    network_source_path / 'qsocket.cpp',
    network_source_path / 'qsocketdevice.cpp',
    network_source_path / 'qsocketdevice_unix.cpp',
]

canvas_sources = [
    canvas_source_path / 'qcanvas.cpp',
]

table_sources = [
    table_source_path / 'qtable.cpp',
]

xml_sources = [
    xml_source_path / 'qxml.cpp',
    xml_source_path / 'qdom.cpp'
]

opengl_sources = [
    opengl_source_path / 'qgl.cpp',
    opengl_source_path / 'qgl_x11.cpp',
]

x11_dep = dependency('X11', 'x11', required : true)
xft_dep = dependency('xft', required : true)
fontconfig_dep = dependency('fontconfig', required : true)
xext_dep = dependency('xext', required : true)
glu_dep = dependency('glu', required : true)
gl_dep = dependency('gl', required : true)
xmu_dep = dependency('xmu', required : true)
glx_dep = dependency('glx', required : true)
png_dep = dependency('libpng', required : true)
jpeg_dep = dependency('libjpeg', required : true)
sm_dep = dependency('sm', required : true)
ice_sound_dep =  dependency('ice', required : true)
freetype2_dep =  dependency('freetype2', required : true)

osiris_deps = [
    x11_dep,
    gl_dep,
    xft_dep,
    fontconfig_dep,
    xext_dep,
    m_dep,
    z_dep,
    glu_dep,
    xmu_dep,
    glx_dep,
    png_dep,
    jpeg_dep,
    sm_dep,
    ice_sound_dep,
    freetype2_dep
]

osiris_sources = tools_sources

osiris_sources += kernel_sources
osiris_sources += widgets_sources
osiris_sources += dialogs_sources
osiris_sources += iconview_sources
osiris_sources += workspace_sources
osiris_sources += network_sources
osiris_sources += canvas_sources
osiris_sources += table_sources
osiris_sources += xml_sources
osiris_sources += opengl_sources
osiris_sources += moc_generated_files

osiris_lib_version = meson.project_version()
osiris_lib_postfix = osiris_lib_version

default_osirislib = []

if get_option('single-thread').enabled()
    osirislib = shared_library('osiris',
                               osiris_sources,
                               cpp_args : project_defines,
                               include_directories : osiris_include_directories,
                               dependencies : osiris_deps,
                               install : true,
                               install_dir : lib_install_dir,
                               version : osiris_lib_version,
                               soversion : osiris_lib_postfix,
    )
    default_osirislib = osirislib
endif

if get_option('multi-thread').enabled()
    defines = project_defines
    defines += '-DQT_THREAD_SUPPORT'
    osirislib_mt = shared_library('osiris-mt',
                                  osiris_sources,
                                  cpp_args : defines,
                                  include_directories : osiris_include_directories,
                                  dependencies : osiris_deps,
                                  install : true,
                                  install_dir : lib_install_dir,
                                  version : osiris_lib_version,
                                  soversion : osiris_lib_postfix,
    )
    default_osirislib = osirislib_mt
endif

#
# Install headers
#

dialog_headers = [
    dialog_header_path / 'qcolordialog.h',
    dialog_header_path / 'qfiledialog.h',
    dialog_header_path / 'qfontdialog.h',
    dialog_header_path / 'qmessagebox.h',
    dialog_header_path / 'qprogressdialog.h',
    dialog_header_path / 'qtabdialog.h',
    dialog_header_path / 'qwizard.h',
    dialog_header_path / 'qinputdialog.h',
]

kernel_headers = [
    kernel_header_path / 'qabstractlayout.h',
    kernel_header_path / 'qaccel.h',
    kernel_header_path / 'qapplication.h',
    kernel_header_path / 'qasyncimageio.h',
    kernel_header_path / 'qasyncio.h',
    kernel_header_path / 'qbitmap.h',
    kernel_header_path / 'qbrush.h',
    kernel_header_path / 'qclipboard.h',
    kernel_header_path / 'qcolor.h',
    kernel_header_path / 'qconnection.h',
    kernel_header_path / 'qcursor.h',
    kernel_header_path / 'qdialog.h',
    kernel_header_path / 'qdragobject.h',
    kernel_header_path / 'qdrawutil.h',
    kernel_header_path / 'qdropsite.h',
    kernel_header_path / 'qevent.h',
    kernel_header_path / 'qfocusdata.h',
    kernel_header_path / 'qfont.h',
    kernel_header_path / 'qfontinfo.h',
    kernel_header_path / 'qfontmetrics.h',
    kernel_header_path / 'qguardedptr.h',
    kernel_header_path / 'qgif.h',
    kernel_header_path / 'qiconset.h',
    kernel_header_path / 'qimage.h',
    kernel_header_path / 'qkeycode.h',
    kernel_header_path / 'qjpegio.h',
    kernel_header_path / 'qlayout.h',
    kernel_header_path / 'qtranslator.h',
    kernel_header_path / 'qmetaobject.h',
    kernel_header_path / 'qmime.h',
    kernel_header_path / 'qmngio.h',
    kernel_header_path / 'qmovie.h',
    kernel_header_path / 'qnamespace.h',
    kernel_header_path / 'qnetworkprotocol.h',
    kernel_header_path / 'qobject.h',
    kernel_header_path / 'qobjectdefs.h',
    kernel_header_path / 'qobjectdict.h',
    kernel_header_path / 'qobjectlist.h',
    kernel_header_path / 'qpaintdevice.h',
    kernel_header_path / 'qpaintdevicedefs.h',
    kernel_header_path / 'qpainter.h',
    kernel_header_path / 'qpalette.h',
    kernel_header_path / 'qpaintdevicemetrics.h',
    kernel_header_path / 'qpen.h',
    kernel_header_path / 'qpicture.h',
    kernel_header_path / 'qpixmap.h',
    kernel_header_path / 'qpixmapcache.h',
    kernel_header_path / 'qpngio.h',
    kernel_header_path / 'qpointarray.h',
    kernel_header_path / 'qpoint.h',
    kernel_header_path / 'qpolygonscanner.h',
    kernel_header_path / 'qprinter.h',
    kernel_header_path / 'qrect.h',
    kernel_header_path / 'qregion.h',
    kernel_header_path / 'qsemimodal.h',
    kernel_header_path / 'qsessionmanager.h',
    kernel_header_path / 'qsignal.h',
    kernel_header_path / 'qsignalmapper.h',
    kernel_header_path / 'qsignalslotimp.h',
    kernel_header_path / 'qsimplerichtext.h',
    kernel_header_path / 'qsize.h',
    kernel_header_path / 'qsizegrip.h',
    kernel_header_path / 'qsizepolicy.h',
    kernel_header_path / 'qsocketnotifier.h',
    kernel_header_path / 'qsound.h',
    kernel_header_path / 'qstyle.h',
    kernel_header_path / 'qstylesheet.h',
    kernel_header_path / 'qthread.h',
    kernel_header_path / 'qtimer.h',
    kernel_header_path / 'qurl.h',
    kernel_header_path / 'qlocalfs.h',
    kernel_header_path / 'qurloperator.h',
    kernel_header_path / 'qurlinfo.h',
    kernel_header_path / 'qwidget.h',
    kernel_header_path / 'qwidgetintdict.h',
    kernel_header_path / 'qwidgetlist.h',
    kernel_header_path / 'qwindowdefs.h',
    kernel_header_path / 'qwmatrix.h',
    kernel_header_path / 'qvariant.h',
    kernel_header_path / 'qt.h',
    kernel_header_path / 'qt_x11.h',
    kernel_header_path / 'qsession.h',
    kernel_header_path /  'qsharedmemory.h',
    kernel_header_path /  'qvfbhdr.h',
    kernel_header_path /  'qwindow.h'
]

if get_option('qt1compat').enabled()
    kernel_headers += kernel_header_path / 'q1xcompatibility.h'
endif

network_headers = [
    network_header_path / 'qdns.h',
    network_header_path / 'qftp.h',
    network_header_path / 'qhostaddress.h',
    network_header_path / 'qnetwork.h',
    network_header_path / 'qserversocket.h',
    network_header_path / 'qsocket.h',
    network_header_path / 'qsocketdevice.h'
]


tools_headers = [
    tools_header_path / 'qarray.h',
    tools_header_path / 'qasciicache.h',
    tools_header_path / 'qasciidict.h',
    tools_header_path / 'qbig5codec.h',
    tools_header_path / 'qbitarray.h',
    tools_header_path / 'qbuffer.h',
    tools_header_path / 'qcache.h',
    tools_header_path / 'qcollection.h',
    tools_header_path / 'qcstring.h',
    tools_header_path / 'qdatastream.h',
    tools_header_path / 'qdatetime.h',
    tools_header_path / 'qdict.h',
    tools_header_path / 'qdir.h',
    tools_header_path / 'qeucjpcodec.h',
    tools_header_path / 'qeuckrcodec.h',
    tools_header_path / 'qfile.h',
    tools_header_path / 'qfileinfo.h',
    tools_header_path / 'qkoi8codec.h',
    tools_header_path / 'qfeatures.h',
    tools_header_path / 'qgarray.h',
    tools_header_path / 'qgbkcodec.h',
    tools_header_path / 'qgcache.h',
    tools_header_path / 'qgdict.h',
    tools_header_path / 'qgeneric.h',
    tools_header_path / 'qglist.h',
    tools_header_path / 'qglobal.h',
    tools_header_path / 'qgvector.h',
    tools_header_path / 'qintcache.h',
    tools_header_path / 'qintdict.h',
    tools_header_path / 'qiodevice.h',
    tools_header_path / 'qjiscodec.h',
    tools_header_path / 'qjpunicode.h',
    tools_header_path / 'qlist.h',
    tools_header_path / 'qmap.h',
    tools_header_path / 'qmodules.h',
    tools_header_path / 'qptrdict.h',
    tools_header_path / 'qqueue.h',
    tools_header_path / 'qregexp.h',
    tools_header_path / 'qrtlcodec.h',
    tools_header_path / 'qshared.h',
    tools_header_path / 'qsjiscodec.h',
    tools_header_path / 'qsortedlist.h',
    tools_header_path / 'qsmartptr.h',
    tools_header_path / 'qstack.h',
    tools_header_path / 'qvaluestack.h',
    tools_header_path / 'qstring.h',
    tools_header_path / 'qstringlist.h',
    tools_header_path / 'qstrlist.h',
    tools_header_path / 'qstrvec.h',
    tools_header_path / 'qtextcodec.h',
    tools_header_path / 'qtextstream.h',
    tools_header_path / 'qtl.h',
    tools_header_path / 'qtsciicodec.h',
    tools_header_path / 'qutfcodec.h',
    tools_header_path / 'qvector.h',
    tools_header_path / 'qvaluelist.h',
    tools_header_path / 'qconfig-dist.h',
    tools_header_path / 'qconfig-large.h',
    tools_header_path / 'qconfig-medium.h',
    tools_header_path / 'qconfig-minimal.h',
    tools_header_path / 'qconfig-small.h',
    tools_header_path / 'qconfig.h',

]

widgets_header_path = 'src/widgets'

widgets_headers = [
    widgets_header_path / 'qbuttongroup.h',
    widgets_header_path / 'qbutton.h',
    widgets_header_path / 'qcheckbox.h',
    widgets_header_path / 'qcdestyle.h',
    widgets_header_path / 'qcombobox.h',
    widgets_header_path / 'qcommonstyle.h',
    widgets_header_path / 'qdial.h',
    widgets_header_path / 'qframe.h',
    widgets_header_path / 'qgrid.h',
    widgets_header_path / 'qgroupbox.h',
    widgets_header_path / 'qhbuttongroup.h',
    widgets_header_path / 'qheader.h',
    widgets_header_path / 'qhgroupbox.h',
    widgets_header_path / 'qhbox.h',
    widgets_header_path / 'qinterlacestyle.h',
    widgets_header_path / 'qlabel.h',
    widgets_header_path / 'qlcdnumber.h',
    widgets_header_path / 'qlineedit.h',
    widgets_header_path / 'qlistbox.h',
    widgets_header_path / 'qlistview.h',
    widgets_header_path / 'qmainwindow.h',
    widgets_header_path / 'qmenubar.h',
    widgets_header_path / 'qmenudata.h',
    widgets_header_path / 'qmotifstyle.h',
    widgets_header_path / 'qmotifplusstyle.h',
    widgets_header_path / 'qmultilineedit.h',
    widgets_header_path / 'qplatinumstyle.h',
    widgets_header_path / 'qpopupmenu.h',
    widgets_header_path / 'qprogressbar.h',
    widgets_header_path / 'qpushbutton.h',
    widgets_header_path / 'qradiobutton.h',
    widgets_header_path / 'qrangecontrol.h',
    widgets_header_path / 'qscrollbar.h',
    widgets_header_path / 'qscrollview.h',
    widgets_header_path / 'qsgistyle.h',
    widgets_header_path / 'qslider.h',
    widgets_header_path / 'qspinbox.h',
    widgets_header_path / 'qsplitter.h',
    widgets_header_path / 'qstatusbar.h',
    widgets_header_path / 'qtabbar.h',
    widgets_header_path / 'qtabwidget.h',
    widgets_header_path / 'qtableview.h',
    widgets_header_path / 'qtextbrowser.h',
    widgets_header_path / 'qtextview.h',
    widgets_header_path / 'qtoolbar.h',
    widgets_header_path / 'qtoolbutton.h',
    widgets_header_path / 'qtooltip.h',
    widgets_header_path / 'qvalidator.h',
    widgets_header_path / 'qvbox.h',
    widgets_header_path / 'qvbuttongroup.h',
    widgets_header_path / 'qvgroupbox.h',
    widgets_header_path / 'qwhatsthis.h',
    widgets_header_path / 'qwidgetstack.h',
    widgets_header_path / 'qwindowsstyle.h',
    widgets_header_path / 'qaction.h'
]

xml_header_path = 'src/xml'
xml_headers = [
    xml_header_path / 'qxml.h',
    xml_header_path / 'qdom.h'
]

workspace_header_path = 'src/workspace'
workspace_headers = [
    workspace_header_path / 'qworkspace.h'
]

canvas_header_path = 'src/canvas'
canvas_headers = [
    canvas_header_path / 'qcanvas.h'
]

iconview_header_path = 'src/iconview'
iconview_headers = [
    iconview_header_path / 'qiconview.h'
]

table_header_path = 'src/table'
table_headers = [
    table_header_path / 'qtable.h'
]

opengl_header_path = 'src/opengl'
opengl_headers = [
    opengl_header_path / 'qgl.h'
]

compat_header_path = 'src/compat'
compat_headers = [
    compat_header_path / 'qapp.h',
    compat_header_path / 'qbitarry.h',
    compat_header_path / 'qbttngrp.h',
    compat_header_path / 'qchkbox.h',
    compat_header_path / 'qclipbrd.h',
    compat_header_path / 'qcollect.h',
    compat_header_path / 'qcombo.h',
    compat_header_path / 'qconnect.h',
    compat_header_path / 'qdatetm.h',
    compat_header_path / 'qdrawutl.h',
    compat_header_path / 'qdstream.h',
    compat_header_path / 'qfiledef.h',
    compat_header_path / 'qfiledlg.h',
    compat_header_path / 'qfileinf.h',
    compat_header_path / 'qfontdta.h',
    compat_header_path / 'qfontinf.h',
    compat_header_path / 'qfontmet.h',
    compat_header_path / 'qgrpbox.h',
    compat_header_path / 'qintcach.h',
    compat_header_path / 'qiodev.h',
    compat_header_path / 'qlcdnum.h',
    compat_header_path / 'qlined.h',
    compat_header_path / 'qmenudta.h',
    compat_header_path / 'qmetaobj.h',
    compat_header_path / 'qmlined.h',
    compat_header_path / 'qmsgbox.h',
    compat_header_path / 'qmultilinedit.h',
    compat_header_path / 'qobjcoll.h',
    compat_header_path / 'qobjdefs.h',
    compat_header_path / 'qpaintd.h',
    compat_header_path / 'qpaintdc.h',
    compat_header_path / 'qpdevmet.h',
    compat_header_path / 'qpmcache.h',
    compat_header_path / 'qpntarry.h',
    compat_header_path / 'qpopmenu.h',
    compat_header_path / 'qprndlg.h',
    compat_header_path / 'qprogbar.h',
    compat_header_path / 'qprogdlg.h',
    compat_header_path / 'qpsprn.h',
    compat_header_path / 'qpushbt.h',
    compat_header_path / 'qradiobt.h',
    compat_header_path / 'qrangect.h',
    compat_header_path / 'qscrbar.h',
    compat_header_path / 'qsocknot.h',
    compat_header_path / 'qtabdlg.h',
    compat_header_path / 'qtablevw.h',
    compat_header_path / 'qtstream.h',
    compat_header_path / 'qwidcoll.h',
    compat_header_path / 'qwindefs.h'
]

extension_header_path = 'extensions'
extension_headers = [
    extension_header_path / 'xt/src/qxt.h',
]

unix_headers = [
    dialog_header_path / 'qprintdialog.h',
    kernel_header_path / 'qfontdatabase.h',
]

osiris_includes = dialog_headers

osiris_includes += kernel_headers
osiris_includes += tools_headers
osiris_includes += widgets_headers
osiris_includes += xml_headers
osiris_includes += workspace_headers
osiris_includes += canvas_headers
osiris_includes += iconview_headers
osiris_includes += table_headers
osiris_includes += opengl_headers
osiris_includes += compat_headers
osiris_includes += network_headers
osiris_includes += extension_headers

unix_os_list = [
    'linux',
    'netbsd',
    'openbsd',
    'freebsd',
    'darwin',
    'dragonfly',
]

if unix_os_list.contains(build_machine.system())
    osiris_includes += unix_headers
endif

install_headers(osiris_includes, install_dir : include_install_dir)

#
# Build and install qutil library
#

qutil_source_path = 'tools/designer/util'
qutil_include_path = 'tools/designer/util'
qutil_sources = [
    qutil_source_path / 'qprocess.cpp',
    qutil_source_path / 'qprocess_unix.cpp',
]

qutil_include_directories = [
    osiris_include_directories
]

qprocess_moc_file = custom_target('qprocess_moc',
        depends : moc_exe,
        input : qutil_include_path / 'qprocess.h',
        output : 'moc_qprocess.cpp',
        command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
        build_by_default : true)

qutil_sources += qprocess_moc_file

qutil_lib = shared_library('qutil',
                            qutil_sources,
                            cpp_args : ['-fPIC', '-w'],
                            include_directories : qutil_include_directories,
                            dependencies : [z_dep],
                            link_with : default_osirislib,
                            install : true,
                            install_dir : lib_install_dir,
                            version : osiris_lib_version,
                            soversion : osiris_lib_postfix,
)

#
# Build and install uic tool
#

uic_source_path = 'tools/designer/uic'
uic_sources = [
    uic_source_path / 'uic.cpp',
    uic_source_path / '../shared/widgetdatabase.cpp',
    uic_source_path / '../shared/domtool.cpp',
    uic_source_path / '../integration/kdevelop/kdewidgets.cpp'
]

uic_include_directories = [
    uic_source_path / '../shared',
    uic_source_path / '../util',
    osiris_include_directories,
]

uic_exe = executable('uic',
            uic_sources,
            dependencies : [z_dep],
            include_directories : uic_include_directories,
            cpp_args : [],
            install : true,
            link_with : default_osirislib,
            install_dir : install_dir,
)

#
# Build and install designer tool
#

designer_source_path = 'tools/designer/designer'
designer_include_directories = [
    osiris_include_directories,
    designer_source_path / '../shared',
    qutil_include_path,
    designer_source_path,
]

ui_file_names = [
    'listboxeditor',
    'connectioneditor',
    'editslots',
    'newform',
    'listvieweditor',
    'connectionviewer',
    'customwidgeteditor',
    'texteditpreview',
    'listviewpreview',
    'paletteeditor',
    'radiopreview',
    'checkboxpreview',
    'widgetpreview',
    'iconvieweditor',
    'preferences',
    'helpdialog',
    'topicchooser',
    'multilineeditor',
    'formsettings',
    'about',
    'pixmapfunction',
    'createtemplate',
]

generated_ui_files = []

foreach ui_file_name : ui_file_names
    path_root = designer_source_path / ui_file_name

    ui_path = path_root + '.ui'
    header_path = path_root + '.h'
    source_path = path_root + '.cpp'

    header_target_name = ui_file_name + '_header'
    source_target_name = ui_file_name + '_source'

    generated_ui_header = custom_target(header_target_name,
        depends : uic_exe,
        input : ui_path,
        output : ui_file_name + '.h',
        install_dir : designer_source_path,
        command : [uic_exe, '@INPUT@', '-o', '@OUTPUT@' ],
        build_by_default : true)

    generated_ui_source = custom_target(source_target_name,
        depends : [ uic_exe, generated_ui_header ],
        input : [ ui_path, generated_ui_header ],
        output : ui_file_name + '.cpp',
        command : [uic_exe, '@INPUT0@', '-i', '@INPUT1@', '-o', '@OUTPUT@'],
        build_by_default : true)

    moc_target_name = ui_file_name + '_moc'

    generated_moc_file = custom_target(moc_target_name,
        depends : [ moc_exe, generated_ui_header ],
        input : generated_ui_header,
        output : 'moc_ ' + ui_file_name + '.cpp',
        command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
        build_by_default : true)

    generated_ui_files += generated_ui_header
    generated_ui_files += generated_ui_source
    generated_ui_files += generated_moc_file

endforeach

designer_moc_files = [
    'command',
    'formwindow',
    'layout',
    'mainwindow',
    'pixmapchooser',
    'propertyeditor',
    'sizehandle',
    'orderindicator',
    'widgetfactory',
    'hierarchyview',
    'listboxeditorimpl',
    'connectioneditorimpl',
    'newformimpl',
    'formlist',
    'help',
    'editslotsimpl',
    'listvieweditorimpl',
    'connectionviewerimpl',
    'customwidgeteditorimpl',
    'paletteeditorimpl',
    'styledbutton',
    'previewstack',
    'iconvieweditorimpl',
    'helpdialogimpl',
    'topicchooserimpl',
    'multilineeditorimpl',
    'formsettingsimpl',
    'asciivalidator',
    'import',
]

generated_moc_files = []

foreach moc_file_root : designer_moc_files

    src_header_file = designer_source_path / (moc_file_root + '.h')
    dst_cpp_file = designer_source_path / ('moc_' + moc_file_root + '.cpp')

    target_name = moc_file_root + '_moc'

    generated_moc_files += custom_target(target_name,
        depends : [ moc_exe, generated_ui_files ],
        input : src_header_file,
        output : 'moc_' + moc_file_root + '.cpp',
        command : [moc_exe, '@INPUT@', '-o', '@OUTPUT@'],
        build_by_default : true)

endforeach

designer_sources = [
    designer_source_path / 'asciivalidator.cpp',
    designer_source_path / 'command.cpp',
    designer_source_path / 'config.cpp',
    designer_source_path / 'connectioneditorimpl.cpp',
    designer_source_path / 'connectionviewerimpl.cpp',
    designer_source_path / 'customwidgeteditorimpl.cpp',
    designer_source_path / 'defs.cpp',
    designer_source_path / 'editslotsimpl.cpp',
    designer_source_path / 'formlist.cpp',
    designer_source_path / 'formsettingsimpl.cpp',
    designer_source_path / 'formwindow.cpp',
    designer_source_path / 'help.cpp',
    designer_source_path / 'helpdialogimpl.cpp',
    designer_source_path / 'hierarchyview.cpp',
    designer_source_path / 'iconvieweditorimpl.cpp',
    designer_source_path / 'import.cpp',
    designer_source_path / 'layout.cpp',
    designer_source_path / 'listboxeditorimpl.cpp',
    designer_source_path / 'listvieweditorimpl.cpp',
    designer_source_path / 'main.cpp',
    designer_source_path / 'mainwindow.cpp',
    designer_source_path / 'metadatabase.cpp',
    designer_source_path / 'multilineeditorimpl.cpp',
    designer_source_path / 'newformimpl.cpp',
    designer_source_path / 'orderindicator.cpp',
    designer_source_path / 'paletteeditorimpl.cpp',
    designer_source_path / 'pixmapchooser.cpp',
    designer_source_path / 'previewstack.cpp',
    designer_source_path / 'propertyeditor.cpp',
    designer_source_path / 'resource.cpp',
    designer_source_path / 'sizehandle.cpp',
    designer_source_path / 'splashloader.cpp',
    designer_source_path / 'styledbutton.cpp',
    designer_source_path / 'topicchooserimpl.cpp',
    designer_source_path / 'widgetfactory.cpp',
    designer_source_path / '../shared/widgetdatabase.cpp',
    designer_source_path / '../shared/domtool.cpp',
    designer_source_path / '../integration/kdevelop/kdewidgets.cpp',
]

designer_sources += generated_moc_files
designer_sources += generated_ui_files

designer_defines = [
    '-DOSIRIS_INSTALL_PREFIX="' + osiris_assets_install_dir + '"',
    '-DDESIGNER_INSTALL_PREFIX="' + designer_assets_install_dir + '"',
    '-DDESIGNER=1',
]

executable('designer',
            designer_sources,
            dependencies : [z_dep],
            include_directories : designer_include_directories,
            cpp_args : designer_defines,
            install : true,
            link_with : [default_osirislib, qutil_lib],
            install_dir : install_dir,
)

if get_option('examples').enabled()
    subdir('examples')
endif

if get_option('tutorial').enabled()
    subdir('tutorial')
endif

pixmaps_install_dir = designer_assets_install_dir / 'pixmaps'

install_subdir('tools/designer/pics/large',
                install_dir : pixmaps_install_dir,
                install_tag : 'runtime',
                strip_directory : false,
)
install_subdir('tools/designer/pics/mini',
                install_dir : pixmaps_install_dir,
                install_tag : 'runtime',
                strip_directory : false,
)
install_subdir('tools/designer/pics/small',
                install_dir : pixmaps_install_dir,
                install_tag : 'runtime',
                strip_directory : false,
)

designer_docs_install_dir = designer_assets_install_dir / 'doc/html/'

install_subdir('doc/html/designer',
                install_dir : designer_docs_install_dir,
                install_tag : 'runtime',
                strip_directory : true,
)

osiris_docs_install_dir = osiris_assets_install_dir / 'doc/html/'

install_subdir('doc/html/osiris',
                install_dir : osiris_docs_install_dir,
                install_tag : 'runtime',
                strip_directory : true,
)
