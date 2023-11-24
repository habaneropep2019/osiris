# Porting Qt 1.x/2.x applications to Osiris 2.4.1

## Changes

- `QT_VERSION_STR` is now `OSIRIS_VERSION_STR`
- `QT_VERSION` is now `OSIRIS_VERSION`
- `qVersion` should be replaced with `oVersion`
- `libqt{mt}` is now `libosiris{mt}`. See notes 1, 2 below.

- Osiris is incrementing the Qt version number - so the last release of Qt2 was 2.3.2. Osiris starts off with 2.4.0 and moves on in the 2.x line. This avoids potential problems with newer Qt applications.

1. **Why the library name change?** Simply put, we're trying to avoid the possibility of a collision between Osiris and other Qt versions (and other forks of Qt). It also helps differentiate between this fork and official Qt releases. Use of a compatability symlink is not recommended when porting applications to Osiris. Since a recompile is required anyways, you might as well update references to use libosiris.
2. **Compiler flags:** Instead of `-lqt`, use `-losiris`, etc.

## Notes on porting from Qt 1.x to Osiris

Most information in the Qt 2.3.2 HTML documentation is still correct. You should follow it as if you were porting from Qt1 to Qt2, with the changes noted above kept in mind.

# Porting Osiris to other platforms

A brief overview of porting Osiris to other platforms. Bug reports should be submitted to the Osiris project, _not_ Qt!

This is based on the original PORTING file included with Qt 2.3.2.

## REQUIREMENTS

The new platform needs Xlib for X11R7 or newer.  Motif should not be used.
If it is not a Unix system (for instance VMS) things may get complicated.
Porting to other Unixes is generally straight-forward.

Osiris requires that your C++ compiler supports multiple inheritance and
templates. The compiler must recognize the .cpp extension.  Exception
handling and RTTI (Run-Time Type Information) are not required.
Expect problems with old CFront-based compilers.

## PATCHES

Patches and bug reports are more than welcome. Please submit them on the Osiris project's website, currently [here](https://centre.libranext.com/libranext/osiris)

## PORTING INSTRUCTIONS

In the configs/ directory you will find several build configuration
files for all platforms previously support by Qt.  Start off with one the
existing files in configs/, rename it, and change it manually to
fit your system.  For example you may copy
	configs/solaris-cc-shared-debug
to
	configs/solaris-cxx-shared-debug
If possible try to modify all four configuration files.

Modify qt/src/tools/qglobal.h as required: you need to ensure that
_OS_whatever_ is defined.  We've done it for many platforms in the
past, those should be okay.  If you are using a compiler we don't
detect it's probably a good idea to add a _CC_whatever_ too (even
though you don't need it at once).  There are also some size-dependent
types (Q_UINT32 and so on), make sure they're right for your system.

Some compilers emit bad warnings when they compile Osiris.  If yours does,
and the code in Osiris is sane, please use a #pragma or two to shut your
compiler up.  (This is a good reason for wanting the _CC_whatever_
define above.) Alternatively try using compiler option flags.

You can then make a merge request on the Osiris project site and we'll work to include it in the next release.

For most Unix varieties, that's all.  Some may need some include file
tweaks.
