# Porting Qt 1.x/2.x applications to Osiris

## Porting from Qt 2.x to Osiris

- `QT_VERSION_STR` is now `OSIRIS_VERSION_STR`
- `QT_VERSION` is now `OSIRIS_VERSION`
- `qVersion` should be replaced with `oVersion`
- `libqt{mt}` is now `libosiris{mt}`. See notes 1, 2 below.
- `*.ui` files should be renamed to `*.ui2`
- Calls to `moc` should be changed to `moc2`
- Calls to `uic` should be changed to `uic2`
- You should use pkg-config where possible in your build systems to check for Osiris, rather than manual checks.
- References/usage of Qt Designer should now be Osiris Originator.

- Osiris is incrementing the Qt version number - so the last release of Qt2 was 2.3.2. Osiris starts off with 2.4.0 and moves on in the 2.x line. This avoids potential problems with newer Qt applications.

1. **Why the library name change?** While Osiris is a fork of Qt, we need to differentiate between Osiris and modern Qt to prevent conflicts. Changing the library name makes this simple. Note that when porting legacy applications, you *should not* simply simlink libqt to libosiris. You'll need to recompile your application to use Osiris, and should use the modern name to avoid using the wrong library and the ensuing confusion.
2. **Compiler flags:** Instead of `-lqt`, use `-losiris`, etc.

## Porting from Qt 1.x to Osiris

This is generally a pretty easy and straightforward task. Almost all changes show up as compiler errors, so you likely won't spend much time (if any) chasing down odd silent bugs/failures. Read the section on Porting from Qt 2.x to Osiris above for some changes that are important, and then read the porting guide kept in doc/html/osiris/porting.html.

# Porting Osiris to other platforms

A brief overview of porting Osiris to other platforms. Bug reports should be submitted to the Osiris project, _not_ Qt!

Generally, you will need a X11R7 (or newer) compliant Xlib. Motif is not usable. You may run into issues with how threads are implemented in other Unix-like systems.


## PATCHES

Patches and bug reports are more than welcome. Please submit them on the Osiris project's website, currently [here](https://centre.libranext.com/libranext/osiris)
