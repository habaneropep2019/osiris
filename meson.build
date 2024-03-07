project('osiris', 'cpp', default_options : 'prefix=/opt')

project_defines = '-DQT_NO_IMAGEIO_MNG -DQT_NO_SM_SUPPORT'

if get_option('gif').enabled()
    project_defines += ' -DQT_BUILTIN_GIF_READER=1'
endif

if get_option('jpeg').disabled()
    project_defines += ' -DQT_NO_IMAGEIO_JPEG'
endif

if get_option('mng').disabled()
    project_defines += ' -DQT_NO_IMAGEIO_MNG'
endif

if get_option('xft').enabled()
    project_defines += ' -DQT_XFT'
else
    project_defines += ' -DQT_NO_XKB'
endif

if get_option('multithread').enabled()
    project_defines += ' -DQT_THREAD_SUPPORT'
endif

tools_source_path = 'src/tools'
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

kernel_source_path = 'src/kernel'
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
    kernel_source_path / 'qnpsupport.cpp',
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
    kernel_source_path / 'moc_qabstractlayout.cpp',
    kernel_source_path / 'moc_qaccel.cpp',
    kernel_source_path / 'moc_qapplication.cpp',
    kernel_source_path / 'moc_qasyncio.cpp',
    kernel_source_path / 'moc_qclipboard.cpp',
    kernel_source_path / 'moc_qdialog.cpp',
    kernel_source_path / 'moc_qdragobject.cpp',
    kernel_source_path / 'moc_qguardedptr.cpp',
    kernel_source_path / 'moc_qlayout.cpp',
    kernel_source_path / 'moc_qtranslator.cpp',
    kernel_source_path / 'moc_qnetworkprotocol.cpp',
    kernel_source_path / 'moc_qsemimodal.cpp',
    kernel_source_path / 'moc_qsessionmanager.cpp',
    kernel_source_path / 'moc_qsignalmapper.cpp',
    kernel_source_path / 'moc_qsizegrip.cpp',
    kernel_source_path / 'moc_qsocketnotifier.cpp',
    kernel_source_path / 'moc_qsound.cpp',
    kernel_source_path / 'moc_qstyle.cpp',
    kernel_source_path / 'moc_qstylesheet.cpp',
    kernel_source_path / 'moc_qtimer.cpp',
    kernel_source_path / 'moc_qlocalfs.cpp',
    kernel_source_path / 'moc_qurloperator.cpp',
    kernel_source_path / 'moc_qwidget.cpp'
]

widgets_source_path = 'src/widgets'
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
    widgets_source_path / 'moc_qbuttongroup.cpp',
    widgets_source_path / 'moc_qbutton.cpp',
    widgets_source_path / 'moc_qcheckbox.cpp',
    widgets_source_path / 'moc_qcdestyle.cpp',
    widgets_source_path / 'moc_qcombobox.cpp',
    widgets_source_path / 'moc_qcommonstyle.cpp',
    widgets_source_path / 'moc_qdial.cpp',
    widgets_source_path / 'moc_qframe.cpp',
    widgets_source_path / 'moc_qgrid.cpp',
    widgets_source_path / 'moc_qgroupbox.cpp',
    widgets_source_path / 'moc_qhbuttongroup.cpp',
    widgets_source_path / 'moc_qheader.cpp',
    widgets_source_path / 'moc_qhgroupbox.cpp',
    widgets_source_path / 'moc_qhbox.cpp',
    widgets_source_path / 'moc_qlabel.cpp',
    widgets_source_path / 'moc_qlcdnumber.cpp',
    widgets_source_path / 'moc_qlineedit.cpp',
    widgets_source_path / 'moc_qlistbox.cpp',
    widgets_source_path / 'moc_qlistview.cpp',
    widgets_source_path / 'moc_qmainwindow.cpp',
    widgets_source_path / 'moc_qmenubar.cpp',
    widgets_source_path / 'moc_qmotifstyle.cpp',
    widgets_source_path / 'moc_qmotifplusstyle.cpp',
    widgets_source_path / 'moc_qmultilineedit.cpp',
    widgets_source_path / 'moc_qplatinumstyle.cpp',
    widgets_source_path / 'moc_qpopupmenu.cpp',
    widgets_source_path / 'moc_qprogressbar.cpp',
    widgets_source_path / 'moc_qpushbutton.cpp',
    widgets_source_path / 'moc_qradiobutton.cpp',
    widgets_source_path / 'moc_qscrollbar.cpp',
    widgets_source_path / 'moc_qscrollview.cpp',
    widgets_source_path / 'moc_qsgistyle.cpp',
    widgets_source_path / 'moc_qslider.cpp',
    widgets_source_path / 'moc_qspinbox.cpp',
    widgets_source_path / 'moc_qsplitter.cpp',
    widgets_source_path / 'moc_qstatusbar.cpp',
    widgets_source_path / 'moc_qtabbar.cpp',
    widgets_source_path / 'moc_qtabwidget.cpp',
    widgets_source_path / 'moc_qtableview.cpp',
    widgets_source_path / 'moc_qtextbrowser.cpp',
    widgets_source_path / 'moc_qtextview.cpp',
    widgets_source_path / 'moc_qtoolbar.cpp',
    widgets_source_path / 'moc_qtoolbutton.cpp',
    widgets_source_path / 'moc_qtooltip.cpp',
    widgets_source_path / 'moc_qvalidator.cpp',
    widgets_source_path / 'moc_qvbox.cpp',
    widgets_source_path / 'moc_qvbuttongroup.cpp',
    widgets_source_path / 'moc_qvgroupbox.cpp',
    widgets_source_path / 'moc_qwidgetstack.cpp',
    widgets_source_path / 'moc_qwindowsstyle.cpp',
    widgets_source_path / 'moc_qaction.cpp'
]

dialog_source_path = 'src/dialogs'
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
    dialog_source_path / 'moc_qcolordialog.cpp',
    dialog_source_path / 'moc_qfiledialog.cpp',
    dialog_source_path / 'moc_qfontdialog.cpp',
    dialog_source_path / 'moc_qmessagebox.cpp',
    dialog_source_path / 'moc_qprogressdialog.cpp',
    dialog_source_path / 'moc_qtabdialog.cpp',
    dialog_source_path / 'moc_qwizard.cpp',
    dialog_source_path / 'moc_qinputdialog.cpp',
    dialog_source_path / 'moc_qprintdialog.cpp'
]

iconview_source_path = 'src/iconview'
iconview_sources = [
    iconview_source_path / 'qiconview.cpp',
    # TODO: Does this need to be generated?
    iconview_source_path / 'moc_qiconview.cpp'
]

workspaces_source_path = 'src/workspace'
workspace_sources = [ 
    workspaces_source_path / 'qworkspace.cpp',
    # TODO: Does this need to be generated?
    workspaces_source_path / 'moc_qworkspace.cpp'
]

network_source_path = 'src/network'
network_sources = [
    network_source_path / 'qdns.cpp',
    network_source_path / 'qftp.cpp',
    network_source_path / 'qhostaddress.cpp',
    network_source_path / 'qnetwork.cpp',
    network_source_path / 'qserversocket.cpp',
    network_source_path / 'qsocket.cpp',
    network_source_path / 'qsocketdevice.cpp',
    network_source_path / 'qsocketdevice_unix.cpp',
    network_source_path / 'moc_qdns.cpp',
    network_source_path / 'moc_qftp.cpp',
    network_source_path / 'moc_qserversocket.cpp',
    network_source_path / 'moc_qsocket.cpp'
]

canvas_source_path = 'src/canvas'
canvas_sources = [
    canvas_source_path / 'qcanvas.cpp',
    canvas_source_path / 'moc_qcanvas.cpp'
]

table_source_path = 'src/table'
table_sources = [
    table_source_path / 'qtable.cpp',
    table_source_path / 'moc_qtable.cpp'
]

xml_source_path = 'src/xml'
xml_sources = [
    xml_source_path / 'qxml.cpp',
    xml_source_path / 'qdom.cpp'
]

opengl_source_path = 'src/opengl'
opengl_sources = [
    opengl_source_path / 'qgl.cpp',
    opengl_source_path / 'qgl_x11.cpp',
    opengl_source_path / 'moc_qgl.cpp'
]

osiris_include_directories = [
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
    'include',
]

x11_dep = dependency('X11', required : true)
xft_dep = dependency('xft', required : true)
xext_dep = dependency('xext', required : true)
glu_dep = dependency('glu', required : true)
gl_dep = dependency('gl', required : true)
xmu_dep = dependency('xmu', required : true)
glx_dep = dependency('glx', required : true)
png_dep = dependency('png', 'libpng', required : true)
jpeg_dep = dependency('jpeg', 'libjpeg', required : true)
sm_dep = dependency('sm', required : true)
ice_sound_dep =  dependency('ice', required : true)
freetype2_dep =  dependency('freetype2', required : true)

cc = meson.get_compiler('cpp')

m_dep = cc.find_library('m', required : true)
z_dep = cc.find_library('z', required : true)

osiris_deps = [
    x11_dep,
    gl_dep,
    xft_dep,
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

osirislib = shared_library('osiris',
                            osiris_sources,
                            cpp_args : project_defines,
                            include_directories : osiris_include_directories,
                            dependencies : osiris_deps,
                            install : true
)

#
# Install headers
#

dialog_header_path = 'src/dialogs'

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

kernel_header_path = 'src/kernel'

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

network_header_path = 'src/network'
network_headers = [
    network_header_path / 'qdns.h',
    network_header_path / 'qftp.h',
    network_header_path / 'qhostaddress.h',
    network_header_path / 'qnetwork.h',
    network_header_path / 'qserversocket.h',
    network_header_path / 'qsocket.h',
    network_header_path / 'qsocketdevice.h'
]

tools_header_path = 'src/tools'
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

install_headers(osiris_includes, install_dir : get_option('prefix') / 'osiris/include')

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
    'include',
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

executable('moc', 
            moc_sources,
            dependencies : [z_dep],
            include_directories : moc_include_directories,
            cpp_args : moc_compile_args,
            install : true,
            install_dir : get_option('prefix') / 'osiris/bin',
)

#
# Build and install qutil library
#

qutil_source_path = 'tools/designer/util'
qutil_include_path = 'tools/designer/util'
qutil_sources = [
    qutil_source_path / 'qprocess.cpp',
    qutil_source_path / 'qprocess_unix.cpp',
    qutil_source_path / 'moc_qprocess.cpp'
]

qutil_include_directories = [
    'include'
]

#
# Run moc on qprocess.h to generate moc_qprocess.cpp 
#

moc_exe = find_program('moc', dirs : [ get_option('prefix') / 'osiris/bin' ])

cmd = run_command(moc_exe, qutil_include_path / 'qprocess.h', '-o', qutil_source_path / 'moc_qprocess.cpp', check : true)

qutil_lib = shared_library('qutil',
                            qutil_sources,
                            cpp_args : ['-fPIC', '-w'],
                            include_directories : qutil_include_directories,
                            dependencies : [z_dep],
                            link_with : osirislib,
                            install : true
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
    'include'
]

executable('uic', 
            uic_sources,
            dependencies : [z_dep],
            include_directories : uic_include_directories,
            cpp_args : [],
            install : true,
            link_with : osirislib,
            install_dir : get_option('prefix') / 'osiris/bin',
)

#
# Build and install designer tool
#

designer_source_path = 'tools/designer/designer'
designer_include_directories = [
    'include',
    designer_source_path / '../shared',
    qutil_include_path
]

designer_sources = [
    designer_source_path / 'about.cpp',
    designer_source_path / 'asciivalidator.cpp',
    designer_source_path / 'checkboxpreview.cpp',
    designer_source_path / 'command.cpp',
    designer_source_path / 'config.cpp',
    designer_source_path / 'connectioneditor.cpp',
    designer_source_path / 'connectioneditorimpl.cpp',
    designer_source_path / 'connectionviewer.cpp',
    designer_source_path / 'connectionviewerimpl.cpp',
    designer_source_path / 'createtemplate.cpp',
    designer_source_path / 'customwidgeteditor.cpp',
    designer_source_path / 'customwidgeteditorimpl.cpp',
    designer_source_path / 'defs.cpp',
    designer_source_path / 'editslots.cpp',
    designer_source_path / 'editslotsimpl.cpp',
    designer_source_path / 'formlist.cpp',
    designer_source_path / 'formsettings.cpp',
    designer_source_path / 'formsettingsimpl.cpp',
    designer_source_path / 'formwindow.cpp',
    designer_source_path / 'help.cpp',
    designer_source_path / 'helpdialog.cpp',
    designer_source_path / 'helpdialogimpl.cpp',
    designer_source_path / 'hierarchyview.cpp',
    designer_source_path / 'iconvieweditor.cpp',
    designer_source_path / 'iconvieweditorimpl.cpp',
    designer_source_path / 'import.cpp',
    designer_source_path / 'layout.cpp',
    designer_source_path / 'listboxeditor.cpp',
    designer_source_path / 'listboxeditorimpl.cpp',
    designer_source_path / 'listvieweditor.cpp',
    designer_source_path / 'listvieweditorimpl.cpp',
    designer_source_path / 'listviewpreview.cpp',
    designer_source_path / 'main.cpp',
    designer_source_path / 'mainwindow.cpp',
    designer_source_path / 'metadatabase.cpp',
    designer_source_path / 'moc_about.cpp',
    designer_source_path / 'moc_asciivalidator.cpp',
    designer_source_path / 'moc_checkboxpreview.cpp',
    designer_source_path / 'moc_command.cpp',
    designer_source_path / 'moc_connectioneditor.cpp',
    designer_source_path / 'moc_connectioneditorimpl.cpp',
    designer_source_path / 'moc_connectionviewer.cpp',
    designer_source_path / 'moc_connectionviewerimpl.cpp',
    designer_source_path / 'moc_createtemplate.cpp',
    designer_source_path / 'moc_customwidgeteditor.cpp',
    designer_source_path / 'moc_customwidgeteditorimpl.cpp',
    designer_source_path / 'moc_editslots.cpp',
    designer_source_path / 'moc_editslotsimpl.cpp',
    designer_source_path / 'moc_formlist.cpp',
    designer_source_path / 'moc_formsettings.cpp',
    designer_source_path / 'moc_formsettingsimpl.cpp',
    designer_source_path / 'moc_formwindow.cpp',
    designer_source_path / 'moc_help.cpp',
    designer_source_path / 'moc_helpdialog.cpp',
    designer_source_path / 'moc_helpdialogimpl.cpp',
    designer_source_path / 'moc_hierarchyview.cpp',
    designer_source_path / 'moc_iconvieweditor.cpp',
    designer_source_path / 'moc_iconvieweditorimpl.cpp',
    designer_source_path / 'moc_import.cpp',
    designer_source_path / 'moc_layout.cpp',
    designer_source_path / 'moc_listboxeditor.cpp',
    designer_source_path / 'moc_listboxeditorimpl.cpp',
    designer_source_path / 'moc_listvieweditor.cpp',
    designer_source_path / 'moc_listvieweditorimpl.cpp',
    designer_source_path / 'moc_listviewpreview.cpp',
    designer_source_path / 'moc_mainwindow.cpp',
    designer_source_path / 'moc_multilineeditor.cpp',
    designer_source_path / 'moc_multilineeditorimpl.cpp',
    designer_source_path / 'moc_newform.cpp',
    designer_source_path / 'moc_newformimpl.cpp',
    designer_source_path / 'moc_orderindicator.cpp',
    designer_source_path / 'moc_paletteeditor.cpp',
    designer_source_path / 'moc_paletteeditorimpl.cpp',
    designer_source_path / 'moc_pixmapchooser.cpp',
    designer_source_path / 'moc_pixmapfunction.cpp',
    designer_source_path / 'moc_preferences.cpp',
    designer_source_path / 'moc_previewstack.cpp',
    designer_source_path / 'moc_propertyeditor.cpp',
    designer_source_path / 'moc_radiopreview.cpp',
    designer_source_path / 'moc_sizehandle.cpp',
    designer_source_path / 'moc_styledbutton.cpp',
    designer_source_path / 'moc_texteditpreview.cpp',
    designer_source_path / 'moc_topicchooser.cpp',
    designer_source_path / 'moc_topicchooserimpl.cpp',
    designer_source_path / 'moc_widgetfactory.cpp',
    designer_source_path / 'moc_widgetpreview.cpp',
    designer_source_path / 'multilineeditor.cpp',
    designer_source_path / 'multilineeditorimpl.cpp',
    designer_source_path / 'newform.cpp',
    designer_source_path / 'newformimpl.cpp',
    designer_source_path / 'orderindicator.cpp',
    designer_source_path / 'paletteeditor.cpp',
    designer_source_path / 'paletteeditorimpl.cpp',
    designer_source_path / 'pixmapchooser.cpp',
    designer_source_path / 'pixmapfunction.cpp',
    designer_source_path / 'preferences.cpp',
    designer_source_path / 'previewstack.cpp',
    designer_source_path / 'propertyeditor.cpp',
    designer_source_path / 'radiopreview.cpp',
    designer_source_path / 'resource.cpp',
    designer_source_path / 'sizehandle.cpp',
    designer_source_path / 'splashloader.cpp',
    designer_source_path / 'styledbutton.cpp',
    designer_source_path / 'texteditpreview.cpp',
    designer_source_path / 'topicchooser.cpp',
    designer_source_path / 'topicchooserimpl.cpp',
    designer_source_path / 'widgetfactory.cpp',
    designer_source_path / 'widgetpreview.cpp',
    designer_source_path / '../shared/widgetdatabase.cpp',
    designer_source_path / '../shared/domtool.cpp',
    designer_source_path / '../integration/kdevelop/kdewidgets.cpp',
]

designer_defines = []

executable('designer',
            designer_sources,
            dependencies : [z_dep],
            include_directories : designer_include_directories,
            cpp_args : designer_defines,
            install : true,
            link_with : [osirislib, qutil_lib],
            install_dir : get_option('prefix') / 'osiris/bin',
)
