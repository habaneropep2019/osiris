[[_TOC_]]

# Osiris releases

#### Osiris 2.4.1

Osiris 2.4.1 is a maintenance release. As a reminder, Osiris is a fork of Qt version 2.3.2. Osiris 2.4.1 is the second Osiris release since the fork. It should be largely source compatible for applications written for Qt2. It is likely not binary compatible. In other words, you'll likely have to recompile your application against Osiris. Application binaries that were compiled for Qt2 likely cannot 'drop in' click and run with Osiris without first recompiling them.

- Added support for Clang/Clang++. Clang is automatically used if detected. Should work with Clang 14+
- Fixed examples/httpd: main() missing type specifier (should have been int, none present)
- Removed the need for the environment variable OSIRISDIR in the configure script, making it easier to use
- Removed configs for long obsolete platforms and platforms that have no planned support in Osiris.
- Bumped OSIRIS_VER and OSIRIS_VER_STR to reflect new Osiris release 2.4.1
- Fixed a bug in qtextbrowser that would cause a segfault when forwardStack was empty. This bug was introduced in Qt 2.1.0, with a release date of April 2000. That's a bugfix almost 23 years later!
- Modified qclipboard_x11 to enable QT_CLIPBOARD_DEBUG macro when configure is run with -debug. This provides some useful output when debugging clipboard issues and removes the need to manually edit a file to uncomment a macro.
- Added missing header file check in configure for libjpeg
- Fixed the libXft header file check in configure

#### Osiris 2.4.0

Osiris 2.4.0 is a fork of Qt 2.3.2. This is a bugfix and security fix release. Osiris is mostly source-compatible. It is likely not binary compatible.

- Imported compile-time fixes from ZFreeKit
- Renamed QTDIR environment variable to OSIRISDIR to avoid some complications on systems with newer and/or existing Qt installations.
- Removed legacy mostly proprietary *nix platforms that likely will never be supported by Osiris.
- Fixed some issues with the configure script that also checks for some of the needed libraries
- Fixed an issue with FreeType2 during build
- Changed from -lpthread to -pthread as -lpthread is deprecated
- Removed src/3rdparty from source tree
- Removed support for bundled zlib and libpng - now uses only the system version
- Changed compiler/linker flags to correctly use system zlib
- Changed the About Qt dialog message in qmessagebox.cpp
- Changed QT_VERSION_STR to OSIRIS_VERSION_STR
- Changed QT_VERSION to OSIRIS_VERSION
- Added information in Porting.md relevant to moving from Qt2.x to Osiris
- You can and should use oVersion instead of qVersion when writing new programs. oVersion will always return a version equal to or greater than 2.4.0
- Bumped QT_VERSION, OSIRIS_VERSION to 240, QT_VERSION_STR and OSIRIS_VERSION_STR to 2.4.0
- Updated documentation to show oVersion as being the newer example to use.
- Import some bugfixes from invent.kde.org, credits to Martin Tobias Holmedahl Sandsmark and Helio Chissini de Castro. Note: The invent.kde.org copy of Qt2 uses CMake, and is mostly an update to Qt 2.3.2 to get it running on a modern system. This is true for Osiris as well, but Osiris aims to add some new functionality that will likely not be added to the KDE Invent repository. In addition, we plan to switch to Meson, IF we switch build systems. Not saying their version is bad, because it is not. Just different purposes for the different copies, but doesn't mean code can't be shared either.

# Legacy Qt Changelogs

Kept for historical reference. Time has not been taken to correct formatting, but the information is still there.

#### Qt 2.3.2

Qt 2.3.2 is a bugfix release. It keeps both forward and backward
compatibility (source and binary) with Qt 2.3.1


****************************************************************************
*			    General					   *
****************************************************************************

- Improved build on
	Unixware CC
	Solaris-64 / Forte 6
	gcc 3.0
	VisualAge C++ 5.0.2

- Popup menus on Unix/X11
	Popup menus on X11 since Qt 2.2.4 did not grab the keyboard
	anymore, but relied on and enforced the application to have
	focus. This worked around an X11 bug where deadkeys did not
	work while the keyboard was grabbed. This release reverts the
	workaround and introduces a proper fix using the Xkb
	extension.

- Miscellaneous
	Many bug fixes including but not limited to potential
	crashes, memory leaks, possible endless loops, layout and
	drawing errors. ASSERT macro does no longer cause problems
	within blocks.

****************************************************************************
*			   Library					   *
****************************************************************************

- QActionGroup
	when adding an action to an action group, propagate the
	"enabled" state of the group

- QApplication:
	win32 only: fixed double clicking on masked widgets with
	WMouseNoMask
	win32 only: Dispatch Enter/Leave events even if the
	corresponding mouse move is for a widget that is blocked by a
	modal event loop
	x11 only: improved timestamp handling (less GrabInvalidTime
	situations)
	x11 only: fixed clipboard race condition that could hang the
	X-server

- QChildEvent
	always report ChildRemoved events, even if the posted
	ChildInsert event was not sent (due to object reparenting or
	destruction)

- QClipboard
	X11 only: some clipboard bugs fixed. Less server roundtrips.

- QColor
	x11 only: improved 8bpp color allocation

- QComboBox
	invalidate cached sizehint on font and style changes
	reset focus policy when changing the editable property
	disallow empty strings to be inserted in edit mode

- QDialog
	leave What's This? mode when closing a modal dialog. Fixed
	auto default behaviour for stacked dialogs. Do not recalculate
	the dialog size again in showExtension() if the extension is
	already visible

- QDir
	better floppy disk recognition
	unix only: Make QDir::System accept unix system files (FIFOs,
	sockets, devices)

- QDnd
	win32 only: Fixed drag'n'drop auto scrolling with Qt
	applications as drag sources

- QDns
	handle error situations more gracefully

- QDom
	escape the ">" in the combination "]]>" (according to XML
	specification section 2.4)
	fixed an infinite loop case in the parser

- QDomNode
	fixed ownerDocument()

- QDomNodeList
	potential crash fixed

- QFileDialog (builtin dialog)
	try to avoid putting the home dir path twice in the paths
	combobox.  Fixed possible free memory read.  Fixed removing
	directories.
	unix only: ~ works as directory

- QFtp
	set state StdDone properly
	made remove and rename work

- QFont
	fixed chinese GBK and GB codec detection
	better locale detection (LC_ALL, LC_CTYPE)

- QFontDialog
	provide at least "any" as charset, in case there is no charset

- QGLWidget
	x11 only: Fixed some problems with rendering to pixmaps
	on various X servers with visuals that differ from the default
	visual

- QGVector
	do not trigger CHECK_PTR when v.vec[i] = 0

- QHeader
	respect isUpdatesEnabled() properly

- QIconView
	fixed crash on destructing an item while it is in rename mode

- QIODevice
	fixed return value of QIODevice::readLine() for sequential
	access

- QImage
	added parameter check in ctor for existing image buffer (div
	by zero)
	jpegio: fixed possible crash with null images

- QImageIo
	fixes for animated GIFs that "restore image" after the *first*
	frame

- QKeyEvent
	x11 only: isAutoRepeat() fixed for SGI and certain Linux
	X-Servers that do not generate repeated key events with the
	exact same timestamp

- QLabel
	handle setPixmap( *pixmap() ) gracefully

- QLayout
	respect maximiumSize() in heightForWidth()

- QLineEdit
	fixed cursor and selection position after del(). Override
	accelerators for the regular shortcuts such as
	CTRL+Key_Z(undo) and CTRL+Key_Y(redo). Disabled doubleclick
	word selection in password mode in order to not expose the
	number of words and their length

- QListBox
	invalidate cached sizehint on font and style changes. Memory leak
	on changeItem with invalided indices fixed.

- QListView
	fixed possible crash when deleting subitems. Invalidate cached
	sizehint on font and style changes

- QMenubar
	fixed an out-of-bounds read when clicking in an empty area. No
	more confusion when using the mouse wheel on it

- QMovie
	fixed bitBlt area on animation

- QMotifStyle
	allow scaling of the exclusive indicator

- QPainter
	x11 only: fixed possible crashes on recursive repaints
	x11 only: Fixed  crash with drawText(0, 0, QString::null, 1),
	i.e. length too long on a null string
	win32 only: free brush resources as early as possible

- QPicture
	fixed format version when using the default constructor

- QPixmap
	xForm() now respects the optimization settings of the
	pixmap

- QPopupMenu
	x11 only:	reintroduced grabbing for popup windows as
	it was in qt 2.3. Not doing grabbing was a workaround
	for a X11 deadkey problem which was now solved properly
	using the xkb extension.
	More sanity checks with the timed submenus

- QPrintDialog (builtin dialog)
	disabled Ok button if no printer or file is selected
	unix only: better printer recognition on IRIX

- QPrinter
	win32 only: more workarounds for broken printer drivers

- QPSPrinter
	fixed for 8bit grayscale images.  Several fixes for font
	embedding (duplicated glyph names, russian true type
	fonts). Fixed postscript font name mapping for
	Japanese. Improved postscript font name substitution for
	Chinese.

- QRegion
	x11 only: fixed crash when creating a region from an empty
	point array

- QRichText
	fixed some table drawing errors. Made links in multicells work
	properly. Completed the set of entities

- QSGIStyle
	handle palette changes better
	


- QSimpleRichText
	fixed 16bit clipping problem when printing with high
	resolutions. Improved table pagebreaking when printing

- QSlider
	avoid wheel event propagation by accepting the event

- QSocket
	made it safe to delete the socket in the slot connected to the
	"emit error( ErrConnectionRefused );" signal. This fixes a crash in
	QFtp if you got a connection refused

- QSocketDevice
	win32 only: lazy getpeername()

- QStatusBar
	fixed bottom pixel of the border drawing bug

- QString
	larger buffer for sprintf  (512 bytes)

- QTable
	respect isUpdatesEnabled() properly. Fixed changing contents
	size when having cells with a span ignore non-left mouse
	buttons in cells (clicked() gets still emitted). Some
	performance optimizations. fixed focus policy (wheel focus).
	let up/down keys skip hidden rows. Some workaround for
	QRegion range limitations on certain window systems. Take the
	pixmap of a header section into account when adjusting the
	size


- QTableView
	x11 only: obey window system hard clipping in paint events

- QTextStream
	made it possible to use stateful QTextEncoders (e.g. UTF-7)

- QThread
	win32 only: reset thread state in QThread::exit()
	unix only:  fixed usleep(1000000)

- QWaitCondition
	unix only: no more missleading error messages if the wait
	timed out

- QToolButton
	small memory leak fixed

- QToolTip
	fixed a bug where tooltips did not appear when no widget had
	focus

- QUrl
	handle file:// correctly
	encode the passwords, so that you can have a password with an
	'@' in it

- QUrlInfo
	make two null QUrlInfo objects be the same for operator==

- QVariant
	fixed memory leak in some conversions

- QWidget
	x11 only: fixed subtile DnD and mouse tracking issues when
	reparenting widgets
	win32 only: closed a memory leak
	x11 only: fixed showMaximize()
	x11 only: fixed deferred map handling (calling hide()/show()
	many times subsequently on the same widget)

- QWizard
	closed a memory leak

- QWorkspace
	do not hide the maximize controls when inserting a tool window
	in maximized state. Improved focus handling


****************************************************************************
*			   Extensions					   *
****************************************************************************


****************************************************************************
*			      Other					   *
****************************************************************************

- moc
	fixed namespace handling for MSVC

- trayicon (win32 only)
	try harder to show an icon on different color depths

- motif dnd (x11 only)
	report coordinates relative to the widget

- netscape plugin extension
	win32: various fixes

- Qt Designer
	do not crash when trying to load ui files from Qt 3.0
	fixed template paths

****************************************************************************
*               Changes that might affect runtime behavior                 *
****************************************************************************


****************************************************************************
*		    Qt/Embedded-specific changes		           *
****************************************************************************

- Painting on rotated displays optimized

- QWidget::scroll() optimized

- Implemented keyboard grabbing in the server

- Working 4bpp grayscale driver

- Screensaver can be customized to allow suspending, dimming
  backlights, etc.

- Touchpanel driver provides more stable position and uses less CPU

- QWidget::showFullScreen() fixed

- Fonts include Euro character



#### Qt 2.3.1


Qt 2.3.1 is a bugfix release. It keeps both forward and backward
compatibility (source and binary) with Qt 2.3.0


****************************************************************************
*			    General					   *
****************************************************************************

- correctly reinitialize internal data structures on QApplication destruction to
  allow the sequential creation of multiple QApplication objects.

- Some bugfixes for the new support for Xft (antialiased fonts on X11)
	correct clipping when drawing with Xft
	correctly handle family names starting with a number
	handle case when no Xft font could be loaded
	correctly report bounding rectangles of strings

- Printing on Windows
	work around a bug in some HP printer drivers
	correctly map between Qt and Windows page sizes

- Improved build on HP/UX, AIX and SCO

****************************************************************************
*			   Library					   *
****************************************************************************

- QAction
	use unique object names for generated objects

- QCanvasView
	even less flicker

- QClipboard on Windows
	keep clipboard contents even after application exit

- QDns:
	fixed a crash.

- QFont
	correctly report fixed pitch on Windows
	make inFont work correctly on X11

- QFontDataBase on X11:
	report correct sizes when monitor resolution != 75 dpi
	some fixes for asian character sets

- QImageIO
	fixed saving of paletted PNGs

- QLineEdit
	fixed keyboard selection after undo/redo

- QListBox
	fix numRows() and numCols() for empty listboxes	

- QMovie
	some performance optimizations

- QPainter on X11
	fixed clipping problems occuring in some cases in paint events
	fix drawText when using scaled painters

- QPopupMenu on Windows:
	child widgets now receive mouse events
	fix placement of menus

- QPrintDialog on X11
	more tolerant parsing of /etc/printcap

- QPrinter on X11
	search some more places for embeddable fonts
	produce smaller postscript when printing grayscale images

- QRichText
	fixed a problem in the HTML parser
	handle translated painters correctly
	fixed endless loop occurring rarely when printing long tables

- QString
	fixed toULong for base != 10

- QThread
	some smaller fixes in QWaitCondition and sleep functions
	don't lock application mutex for console applications

- QToolBar
	fixed moving of toolbars between main windows
	Insert toolbuttons with associated popup menus as a submenu in the
	extension popup

- QUrl / QFileDialog
	delete files with special characters
	improved processed processing of filenames on different platforms
	allow digits in protocol names

- QUrlOperator
	some memory leaks are fixed (one of them caused a segmentation
	fault if FTP was used and the FTP server timed out)

- QWidget
	preserve Widget flags when toggling to and from FullScreen mode.
	fixed some focus issues with the menubar's Alt-mode (clearFocus() 
	did not always behave as desired).
	X11 only: fixed mouse move event compression when using
	QWidget::scroll().

- QWizard
	correct update of finished and next button

- QWorkSpace
	fixed minimize/maximize behaviour, hide maximize controls when the
	workspace gets hidden
	some focus handling fixes

- Windows event processing
	Use mouse position at event generation time rather than processing
	time.


****************************************************************************
*			   Extensions					   *
****************************************************************************

- OpenGL
	workaround for some Windows OpenGL drivers

- Browser plugins
	fixed OpenGL handling in plugins

****************************************************************************
*			      Other					   *
****************************************************************************

- Turn off Windows 2000 fading effects on color depths of less than 32 bit

- Designer:
	clear namespace when deleting widgets

- fix some memory leaks in the network module

- Better support for VNC

****************************************************************************
*               Changes that might affect runtime behavior                 *
****************************************************************************

- QWheelEvent
	make accept the default state for QWheelEvent as documented

- QPrinter on Windows
	unknown page sizes now return QPrinter::Custom instead of the
	wrong QPrinter::A4

****************************************************************************
*		    Qt/Embedded-specific changes		           *
****************************************************************************

- USB Keyboard support improved.
- Printing support improved.
- Development support for non-Linux platforms (eg. with QVfb on FreeBSD).
- QWSServer/QWSWindow now have a more useable (and documented) API.
- Pixmap brush polygon fills are now supported.
- Fixed freezing of modal widgets inside manager events.
- Bug fixes in masked blit, scrolling, clipped alpha-blended images,
   focus handling, and QCopChannel::isRegistered().
- iPAQ buttons F1..F4 are now F9..F12 (F4 pops up Comboboxes!)
- Support for more mice.
- Fixes to compile with GCC 3.0snapshots.


#### Qt 2.3.0

Qt 2.3 introduces some new features as well as improvements over the
2.2.x series. This file will give an overview of the main changes
since version 2.2. For more detail see the online documentation which
is included in this distribution, and also available on
http://doc.trolltech.com/

The Qt version 2.3 series is binary compatible with the 2.2.x and
2.1.x series - applications compiled for 2.0, 2.1, or 2.2 will
continue to run with 2.3.

As with previous Qt releases, the API and functionality of Qt is
completely portable between Microsoft Windows, X11, and Qt/Embedded.
It is also portable between Windows 95, 98, NT and 2000.


****************************************************************************
*			    Overview					   *
****************************************************************************

The main reason for this Qt release is the latest development on the
Unix/X11 platform. The newly developed Xft extension included in XFree
4.0.2 finally enables applications to do antialiased font rendering on
X11. We feel that Qt users should get access to this feature as soon
as possible, that's why we offer a new Qt release supporting it. Most
other changes in Qt 2.3 are minor and could have gone into a
maintainance release. Applications developed with Qt 2.x should run
with Qt 2.3 without problems.

In addition, we extended printing support on Unix/X11. QPSPrinter is
now able to embed True Type and Postscript fonts into the generated
doument rather than relying on the installed printer fonts.


****************************************************************************
* 		New major features in existing classes			   *
****************************************************************************

- X11		Qt now has full support for antialiased fonts on X11 via 
		the Xft	extension.
		The only XServer supporting this feature is currently
		XFree86 (> 4.0.2). Applications running on other XServers
		will not see a difference and continue using the old font
		system.
		A new option -xft has been added to the configure script
		to enable or disable xft support at compile time.
		Xft support can be enabled or disabled at application 
		startup	time by setting the environment variable QT_XFT to 
		'true'.	Antaliased fonts are not enabled by default, as 
		most XServers still don't support it. Enabling/disabling 
		Xft support is completely transparent to the application 
		itself.

- QPSPrinter    True type and Postscript fonts used will now be embedded
		into the generated document. This will make fonts on the
		printer look exactly like the output on the screen if the
		application uses true type or postscript fonts.
		Added better support for printing of asian languages.
		Added a font replacement algorithm to get better looking
		results in the cases where font embedding is not possible.

- QImage	If you use the "PBM" format, the output will be a
		monochrome image. Use "PPM" if you want color.


QScrollView     new ResizePolicy "AutoOneFit"

****************************************************************************
*				New classes				   *
****************************************************************************

None

****************************************************************************
*				New examples				   *
****************************************************************************

- TrayIcon	A Windows only example showing how to install an icon
		in the system tray

****************************************************************************
*				Bug fixes				   *
****************************************************************************

- MS-Windows	Fixed some problems with text input of asian languages
		on Nt & Win2000.
		Disabled palette supports system settings better

- X11		Fixed a segfault in QFont with asian fontsets.
		Better support for people switching keyboards on the
		fly. Most keyboard input should now be recognised even if
		the locale of the keyboard and of the application do not 
		match.	

- Gif decoder	minor bugfixes

- QEffects	reduced flicker for blending and fixed direction bug for 
		scrolling sub-menus

- QFontDataBase	added a isFixedPitch() function

- QPrinter	don't invert margins when printing in full page mode on 
		windows.

- QPainter	MS-Windows only: Fixed some clipping issues on windows 
		when using several painters.

- QPSPrinter	The generated postscript will now cooperate well with
		post processing tools such as 'psnup'
		Center printed postscript correctly on the page when
		printing in landscape mode.

- QThread	Some fixes in wait().

- QWaitCondition  Return the correct value in wait


